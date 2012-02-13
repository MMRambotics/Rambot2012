#include "TruePoint.h"


#define INT(name) (name) = GetInt();
#define ANGLE(name) (name) = GetKang();
#define PITCH(name) (name) = GetPitch();

static void ComTask(TruePoint *truePoint) {
    while (true) {
        truePoint->Process();
        Wait(0.0008);
    }
}

TruePoint::TruePoint():
    comTask("Compass", (FUNCPTR)ComTask),
    startSequence(),
    buffer(),
    packet()
{
    startSequence[0] = 0x0D;
    startSequence[1] = 0x0A;
    startSequence[2] = 0x7E;
    sequenceSum = startSequence[0] + startSequence[1] + startSequence[2];
    expectedSequenceByte = 0;
}

void TruePoint::AddToBuffer(char *bytes, int numBytes) {
    for (int i = 0; i < numBytes; i++) {
        buffer.push(bytes[i]);
    }
}

void TruePoint::Start() {
    comTask.Start((INT32)this);
}

void TruePoint::Stop() {
    comTask.Stop();
}

void TruePoint::Process() {
    if (buffer.size() == 0) return;
    char curByte = buffer.front();
    buffer.pop();

    // Check if we're continuing our header sequence.
    if (curByte == startSequence[expectedSequenceByte]) {
        expectedSequenceByte++;
        if (expectedSequenceByte == SEQUENCE_LENGTH) {
            // Ready for a new packet.
            expectedSequenceByte = 0;
            packetByteCount = 0;
            dataSize = 0;
            packetSum = sequenceSum;
            packet.clear();
            return;
        }
    }

    if (packetByteCount == 0) {                   // Our packet/command ID.
        currentPacketID = curByte;
    } else if (packetByteCount == 1) {            // The number of data bytes.
        dataSize = (int)curByte;
    } else if (packetByteCount == dataSize + 2) { // Trailer byte?
        if ((int)curByte == packetSum % 256) {    // Checksum.
            ProcessPacket();
        }
    } else {
        packet.push_back(curByte);
    }

    packetSum += (int)curByte;
    packetByteCount++;
}

void TruePoint::ProcessPacket() {
    if (currentPacketID != 0x70) return;
    packetIter = packet.begin();
    {
        ANGLE(roll);
        PITCH(pitch);
        ANGLE(azimuth);
        INT(accelY);  // Rightward acceleration
        INT(accelX);  // Forward acceleration
        INT(accelZ);  // Upward acceleration
        INT(magnetY); // Rightward magnetometer
        INT(magnetX); // Forward magnetometer
        INT(magnetZ); // Upward magnetometer
    }
}

float TruePoint::GetKang() {
    return GetInt() / 180.0;
}

float TruePoint::GetPitch() {
    float raw = GetInt();
    if (raw < 16384)
        return raw / 16384.0 * 90;
    else if (raw > 49152 && raw <= 65536)
        return (raw - 65536) / 16384.0 * 90;
    else
        return 0.0;
}

int TruePoint::GetInt() {
    char a = *(packetIter++);
    char b = *(packetIter++);

    // Little endian, least significant (tail) byte first.  Shift the second
    // byte one byte to the left, then OR the bytes to concatenate.
    UINT16 raw = a | (b << 8);
    return (int)raw;
}

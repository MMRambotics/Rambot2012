#ifndef _TRUE_POINT_H_
#define _TRUE_POINT_H_

#include "WPILib.h"
#include "SerialPort.h"
#include <vector>
#include <queue>

#define SEQUENCE_LENGTH 3

typedef vector<char> Packet;
typedef vector<char>::iterator PacketIter;

class TruePoint {
private:
    Task comTask;

    char startSequence[SEQUENCE_LENGTH];
    int expectedSequenceByte;
    int sequenceSum;

    queue<char> buffer;
    Packet packet;
    PacketIter packetIter;
    int packetByteCount;
    int dataSize;
    int currentPacketID;
    int packetSum;

    float GetKang();
    float GetPitch();
    int GetInt();
    void ProcessPacket();


public:
    TruePoint();
    void AddToBuffer(char *bytes, int numBytes);
    void Process();
    void Start();
    void Stop();

    float roll,
          pitch,
          azimuth;

    int accelX,
        accelY,
        accelZ,
        magnetX,
        magnetY,
        magnetZ;
};

#endif

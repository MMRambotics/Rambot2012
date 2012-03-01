#include "WPILib.h"

class RateEncoder : public PIDSource{
	Encoder *encoder;
	int counter;
	int data[10];
	float rpm;
	float multiplier;
	int totalCount;
public:
	RateEncoder(int a_channel, int b_channel, bool reverse_direction, float mult) {
		encoder = new Encoder(a_channel, b_channel, reverse_direction, Encoder::k2X);
		counter = 0;
		for(int i = 0; i < 10; i++) data[i] = 0;
		rpm = 0.0;
		multiplier = 1.0;
		totalCount = 0;
	}
	
	void Start() {
		encoder->Start();
	}
	
	void Reset() {
	    totalCount = 0;
		encoder->Reset();
	}
	
	void ProcessData() {
		data[counter++] = encoder->GetRaw() * (int) multiplier;
		totalCount += encoder->GetRaw() * (int) multiplier;
		encoder->Reset();
		if (counter > 9) counter = 0;
		float sum = 0.0;
		for(int i = 0; i < 10; i++) sum += data[i];
		sum /= 10.0;
		rpm = (sum / 0.02) / 24;
	}
	
	float GetRPM() {
		return rpm;
	}
	
	double PIDGet() {
		return GetRPM();
	}
	
	float GetCount() {
		return totalCount;
	}
};

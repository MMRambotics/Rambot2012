#include "WPILib.h"

class RateEncoder : public PIDSource{
	Encoder *encoder;
	int counter;
	int data[10];
	float rpm;
public:
	RateEncoder(int a_channel, int b_channel, bool reverse_direction) {
		encoder = new Encoder(a_channel, b_channel, reverse_direction);
		counter = 0;
		for(int i = 0; i < 10; i++) data[i] = 0;
		rpm = 0.0;
	}
	
	void Start() {
		encoder->Start();
	}
	
	void Reset() {
		encoder->Reset();
	}
	
	void ProcessData() {
		data[counter++] = encoder->GetRaw();
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
		return encoder->GetRaw();
	}
};

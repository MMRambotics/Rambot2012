#include "WPILib.h"

class PIDJaguar : public PIDOutput {
	Jaguar *jaguar;
	float previousOutput;
public:
	PIDJaguar(int port) {
		jaguar = new Jaguar(port);
		previousOutput = 0.0;
	}
	
	void Set(float power) {
		jaguar->Set(power);
	}
	
	void PIDWrite(float output) {
		Set(previousOutput + output);
		previousOutput = output;
	}
};

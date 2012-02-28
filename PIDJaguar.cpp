#include "WPILib.h"

class PIDJaguar : public PIDOutput {
	Jaguar *jaguar;
	float previousOutput;
	bool reverseOutput;
public:
	PIDJaguar(int port, bool reverse) {
		jaguar = new Jaguar(port);
		previousOutput = 0.0;
	}
	
	void Set(float power) {
	    if (reverseOutput) {
	        jaguar->Set(-power);
	    } else {
	        jaguar->Set(power);
	    }
	}
	
	void PIDWrite(float output) {
	    Set(previousOutput + output); 
		previousOutput = output;
	}
};

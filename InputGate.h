#ifndef _INPUTGATE_H
#define _INPUTGATE_H

#include "LogicGate.h"

class InputGate : public LogicGate
{
	public:
		InputGate();
		~InputGate();
		void SetInitialValue(bool val);
		bool GetOutput();
		LogicGate* GetClone();
	private:
		bool storedValue;
};

#endif
#include "InputGate.h"



InputGate::InputGate() : LogicGate(0)
{

}

InputGate::~InputGate()
{

}

void InputGate::SetInitialValue(bool val)
{
	storedValue = val;
}

bool InputGate::GetOutput()
{
	return storedValue;
}

LogicGate* InputGate::GetClone()
{
	if (!clone)
	{
		clone = new InputGate();
	}
	return clone;
}
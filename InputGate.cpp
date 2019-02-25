#include "InputGate.h"



InputGate::InputGate() : LogicGate(0)
{
	SetDistance(0);
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
		CloneOutputLinks();
		//clone->CreateOutput(outputLink->GetClone());
	}
	return clone;
}

InputGate* InputGate::GetInputGateClone()
{
	return (InputGate*)GetClone();
}
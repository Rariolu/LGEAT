#include "NOTGate.h"



NOTGate::NOTGate() : LogicGate(1)
{

}


NOTGate::~NOTGate()
{

}

bool NOTGate::GetOutput()
{
	if (memorised)
	{
		return memorisedValue;
	}
	return Memorise(!SourceVal(0));
}

LogicGate* NOTGate::GetClone()
{
	if (!clone)
	{
		clone = new NOTGate();
		clone->CreateInput(inputLinks[0]->GetClone(),0);
		CloneOutputLinks();
		//clone->CreateOutput(outputLink);
	}
	return clone;
}

void NOTGate::CreateInput(LogicGate* gate)
{

}
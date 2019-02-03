#include "NOTGate.h"



NOTGate::NOTGate() : LogicGate(1)
{

}


NOTGate::~NOTGate()
{

}

bool NOTGate::GetOutput()
{
	return !SourceVal(0);
}

LogicGate* NOTGate::GetClone()
{
	if (!clone)
	{
		return clone = new NOTGate();
	}
	return clone;
}
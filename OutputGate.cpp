#include "OutputGate.h"

OutputGate::OutputGate() : LogicGate(1)
{

}

OutputGate::~OutputGate()
{

}

bool OutputGate::GetOutput()
{
	return SourceVal(0);
}

LogicGate* OutputGate::GetClone()
{
	if (!clone)
	{
		clone = new OutputGate();
		clone->CreateInput(inputLinks[0]->GetClone(),0);
	}
	return clone;
}

OutputGate* OutputGate::GetOutputGateClone()
{
	return (OutputGate*)GetClone();
}
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
	return NULL;//TODO Fix this
}
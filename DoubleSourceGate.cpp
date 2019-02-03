#include "DoubleSourceGate.h"

DoubleSourceGate::DoubleSourceGate(DSOURCEGATE gate) : LogicGate(2), gateType(gate)
{

}

DoubleSourceGate::~DoubleSourceGate()
{

}

bool DoubleSourceGate::GetOutput()
{
	switch (gateType)
	{
		case AND:
			return SourceVal(0) && SourceVal(1);
		case OR:
			return SourceVal(0) || SourceVal(1);
		case NAND:
			return !(SourceVal(0) && SourceVal(1));
		case NOR:
			return !(SourceVal(0) || SourceVal(1));
		case XOR:
			return SourceVal(0) != SourceVal(1);
		case XNOR:
			return SourceVal(0) == SourceVal(1);
	}
	return false;
}

DSOURCEGATE DoubleSourceGate::GetGateType()
{
	return gateType;
}

void DoubleSourceGate::SetGateType(DSOURCEGATE gate)
{
	gateType = gate;
}

LogicGate* DoubleSourceGate::GetClone()
{
	if (!clone)
	{
		clone = new DoubleSourceGate(gateType);
	}
	return clone;
}
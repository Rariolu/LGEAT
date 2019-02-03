#ifndef _DOUBLESOURCEGATE_H
#define _DOUBLESOURCEGATE_H

#include "LogicGate.h"

enum DSOURCEGATE
{
	AND,
	OR,
	NAND,
	NOR,
	XOR,
	XNOR
};

class DoubleSourceGate : public LogicGate
{
	public:
		DoubleSourceGate(DSOURCEGATE gate);
		~DoubleSourceGate();
		bool GetOutput();
		DSOURCEGATE GetGateType();
		void SetGateType(DSOURCEGATE gate);
		LogicGate* GetClone();
	private:
		DSOURCEGATE gateType;
};

#endif
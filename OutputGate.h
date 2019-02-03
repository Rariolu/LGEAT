#ifndef _OUTPUTGATE_H
#define _OUTPUTGATE_H

#include "LogicGate.h"
class OutputGate : public LogicGate
{
	public:
		OutputGate();
		~OutputGate();
		bool GetOutput();
		LogicGate* GetClone();
};

#endif
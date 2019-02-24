#ifndef _NOTGATE_H
#define _NOTGATE_H

#include "LogicGate.h"

class NOTGate : public LogicGate
{
	public:
		NOTGate();
		~NOTGate();
		bool GetOutput();
		LogicGate* GetClone();
		void CreateInput(LogicGate* gate);
};

#endif
#ifndef _GENOME_H
#define _GENOME_H

#include "InputGate.h"
#include "DoubleSourceGate.h"
#include "OutputGate.h"

class Genome
{
	public:
		Genome(int inputs, int outputs);
		~Genome();
		bool GetOutput(int index);
		void AddGate(LogicGate* prev, LogicGate* next,LogicGate* gate);

	private:
		int inputCount;
		int outputCount;
		std::vector<LogicGate*> gates;
		std::vector<InputGate*> inputGates;
		std::vector<LogicGate*> intermediateGates;
		std::vector<OutputGate*> outputGates;
};

#endif
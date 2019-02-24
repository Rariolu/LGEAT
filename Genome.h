#ifndef _GENOME_H
#define _GENOME_H

#include "InputGate.h"
#include "DoubleSourceGate.h"
#include "OutputGate.h"
#include "NOTGate.h"
#include "Operations.h"

class Genome
{
	public:
		Genome(int inputs, int outputs);
		Genome(int inputs, int outputs, bool neww);
		~Genome();
		bool GetOutput(bool inputs[], int index);
		void ResetMemory();
		Genome* Clone();
		void SetGates(std::vector<LogicGate*> gatevec);
		void SetInputGates(std::vector<InputGate*> inputs);
		void SetIntermediateGates(std::vector<LogicGate*> intermediates);
		void SetOutputGates(std::vector<OutputGate*> outputs);
		void CreateDSourceGate(DSOURCEGATE dsource, int source1, int source2, int out);
		void CreateNOTGate(int source, int out);
		void CreateLink(int source, int out);
		void CreateLink(int source, int out, int inpindex);
		void Mutate();
	private:
		bool memorisedInputs = false;
		int inputCount;
		int outputCount;
		std::vector<LogicGate*> gates;
		std::vector<InputGate*> inputGates;
		std::vector<LogicGate*> intermediateGates;
		std::vector<OutputGate*> outputGates;
};

#endif
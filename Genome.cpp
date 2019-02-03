#include "Genome.h"

Genome::Genome(int inputs, int outputs)
{
	inputCount = inputs;
	outputCount = outputs;
	for (int i = 0; i < inputs; i++)
	{
		InputGate* inp = new InputGate();
		inputGates.push_back(inp);
		gates.push_back(inp);
	}
	for (int i = 0; i < outputs; i++)
	{
		OutputGate* out = new OutputGate();
		outputGates.push_back(out);
		gates.push_back(out);
	}
}

Genome::~Genome()
{

}

bool Genome::GetOutput(int index)
{
	return outputGates[index % outputCount]->GetOutput();
}


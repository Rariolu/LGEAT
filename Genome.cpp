#include "Genome.h"

Genome::Genome(int inputs, int outputs) : Genome(inputs,outputs,true)
{

}

Genome::Genome(int inputs, int outputs, bool neww)
{
	inputCount = inputs;
	outputCount = outputs;
	if (neww)
	{
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
}

Genome::~Genome()
{
	for (int i = 0; i < gates.size(); i++)
	{
		delete gates[i];
		gates[i] = NULL;
	}
	gates.clear();
}

bool Genome::GetOutput(bool inputs[],int index)
{
	if (!memorisedInputs)
	{
		for (int i = 0; i < inputCount; i++)
		{
			inputGates[i]->SetInitialValue(inputs[i]);
		}
		memorisedInputs = true;
	}
	return outputGates[index % outputCount]->GetOutput();
}

void Genome::ResetMemory()
{
	memorisedInputs = false;
	for (LogicGate* gate : gates)
	{
		gate->ResetMemory();
	}
}

Genome* Genome::Clone()
{
	Genome* clone = new Genome(inputCount, outputCount, false);
	std::vector<LogicGate*> cloneGates;
	for (LogicGate* gate : gates)
	{
		cloneGates.push_back(gate->GetClone());
	}
	std::vector<InputGate*> cloneInputs;
	for (InputGate* inp : inputGates)
	{
		cloneInputs.push_back(inp->GetInputGateClone());
	}
	std::vector<LogicGate*> cloneIntermediates;
	for (LogicGate* intermediate : intermediateGates)
	{
		cloneIntermediates.push_back(intermediate->GetClone());
	}
	std::vector<OutputGate*> cloneOutputs;
	for (OutputGate* out : outputGates)
	{
		cloneOutputs.push_back(out->GetOutputGateClone());
	}
	clone->SetGates(cloneGates);
	clone->SetInputGates(cloneInputs);
	clone->SetIntermediateGates(cloneIntermediates);
	clone->SetOutputGates(cloneOutputs);
	return clone;
}

void Genome::SetInputGates(std::vector<InputGate*> inputs)
{
	inputGates = inputs;
}

void Genome::SetOutputGates(std::vector<OutputGate*> outputs)
{
	outputGates = outputs;
}

void Genome::SetIntermediateGates(std::vector<LogicGate*> intermediates)
{
	intermediateGates = intermediates;
}

void Genome::SetGates(std::vector<LogicGate*> gatevec)
{
	gates = gatevec;
}

void Genome::CreateDSourceGate(DSOURCEGATE dsource, int source1, int source2, int out)
{
	DoubleSourceGate* newGate = new DoubleSourceGate(dsource);
	source1 = source1 % gates.size();
	source2 = source2 % gates.size();
	out = out % gates.size();
	LogicGate* s1 = gates[source1];
	LogicGate* s2 = gates[source2];
	LogicGate* outp = gates[out];
	newGate->CreateInput(s1, 0);
	newGate->CreateInput(s2, 1);
	outp->CreateInput(newGate, 0);
	gates.push_back(newGate);
	intermediateGates.push_back(newGate);
}

void Genome::CreateNOTGate(int source, int out)
{
	NOTGate* newGate = new NOTGate();
	source = source % gates.size();
	out = out % gates.size();
	LogicGate* s = gates[source];
	LogicGate* outp = gates[out];
	newGate->CreateInput(s);
	outp->CreateInput(newGate, 0);
	gates.push_back(newGate);
	intermediateGates.push_back(newGate);
}

void Genome::CreateLink(int source, int out)
{
	CreateLink(source, out, Operations::randd->Next(2));
}

void Genome::CreateLink(int source, int out, int inpIndex)
{
	if (gates.size() > 0)
	{
		source = source % gates.size();
		out = out % gates.size();
		if (source == out) return;
		LogicGate* inp = gates[source];
		LogicGate* outp = gates[out];
		outp->CreateInput(inp, inpIndex%outp->InputQuantity());
	}
}

void Genome::Mutate()
{
	if (intermediateGates.size() > 0)
	{
		int gate = Operations::randd->Next(intermediateGates.size());

		if (intermediateGates.size() > 1)
		{

		}
	}
	if (Operations::randd->NextBool())
	{

	}
}
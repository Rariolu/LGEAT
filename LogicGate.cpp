#include "LogicGate.h"

const double LogicGate::maxDistance = 10000;
const double LogicGate::maxElevation = 10000;

LogicGate::LogicGate(int inputs)
{
	inputQuantity = inputs;
	SetDistance(Operations::randd->Next(1, maxDistance - 1));
	SetElevation(Operations::randd->Next(1, maxElevation));
}

LogicGate::~LogicGate()
{
	for (int i = 0; i < inputQuantity; i++)
	{
		delete inputLinks[i];
		inputLinks[i] = NULL;
	}
}

bool LogicGate::SourceVal(int link)
{
	link = link % inputQuantity;
	return inputLinks[link] ? inputLinks[link]->GetSource()->GetOutput() : false;
}

bool LogicGate::Memorise(bool val)
{
	memorised = true;
	return memorisedValue = val;
}

void LogicGate::ResetMemory()
{
	memorised = false;
}

int LogicGate::InputQuantity()
{
	return inputQuantity;
}

void LogicGate::CloneOutputLinks()
{
	if (clone)
	{
		for (Link* outLink : outputLinks)
		{
			clone->CreateOutput(outLink->GetClone());
		}
	}
}

void LogicGate::CreateInput(LogicGate::Link* link, int index)
{
	index = index % inputQuantity;
	if (inputLinks[index])
	{
		delete inputLinks[index];
	}
	inputLinks[index] = link;
}

void LogicGate::CreateOutput(LogicGate::Link* link)
{
	outputLinks.push_back(link);
	//if (outputLink)
	//{
	//	delete outputLink;
	//}
	//outputLink = link;
}

void LogicGate::CreateInput(LogicGate* gate, int index)
{
	Link* link = new Link(gate, this);
	CreateInput(link, index);
	gate->CreateOutput(link);
}

double LogicGate::GetDistance()
{
	return distance;
}

void LogicGate::SetDistance(double d)
{
	distance = d;
}

double LogicGate::GetElevation()
{
	return elevation;
}

void LogicGate::SetElevation(double d)
{
	elevation = d;
}
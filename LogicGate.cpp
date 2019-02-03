#include "LogicGate.h"

LogicGate::LogicGate(int inputs)
{
	inputQuantity = inputs;
}

LogicGate::~LogicGate()
{

}

bool LogicGate::SourceVal(int link)
{
	link = link % inputQuantity;
	return inputLinks[link] ? inputLinks[link]->GetSource()->GetOutput() : false;
}

void LogicGate::Memorise(bool val)
{
	memorised = true;
	memorisedValue = val;
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
	if (outputLink)
	{
		delete outputLink;
	}
	outputLink = link;
}

void LogicGate::CreateInput(LogicGate* gate, int index)
{
	Link* link = new Link(gate, this);
	CreateInput(link, index);
	gate->CreateOutput(link);
}

//void LogicGate::CreateOutput(LogicGate* gate)
//{
//	Link* link = new Link(this, gate);
//	CreateOutput(link);
//	
//}
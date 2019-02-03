#ifndef _LOGICGATE_H
#define _LOGICGATE_H

#include "MISC.h"

class LogicGate
{
	public:
		class Link
		{
			public:
				Link(LogicGate* source, LogicGate* dest) : sourceGate(source), destGate(dest)
				{

				}
				~Link()
				{

				}
				LogicGate* GetSource()
				{
					return sourceGate;
				}
				LogicGate* GetDestination()
				{
					return destGate;
				}
				Link* GetClone()
				{
					if (!clone)
					{
						clone = new Link(sourceGate->GetClone(), destGate->GetClone());
					}
					return clone;
				}
			private:
				LogicGate* sourceGate;
				LogicGate* destGate;
				Link* clone;
		};
		LogicGate(int inputs);
		~LogicGate();
		virtual bool GetOutput()=0;
		virtual LogicGate* GetClone()=0;
		void CreateInput(Link* link, int index);
		void CreateOutput(Link* link);
		void CreateInput(LogicGate* gate, int index);
		//void CreateOutput(LogicGate* gate);
	protected:
		Link* inputLinks[2];
		Link* outputLink;
		bool SourceVal(int link);
		LogicGate* clone;
		bool memorised = false;
		bool memorisedValue;
		void Memorise(bool val);
	private:
		int inputQuantity;
		
};

#endif
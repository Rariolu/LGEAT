#ifndef _LOGICGATE_H
#define _LOGICGATE_H

#include "MISC.h"
#include "Operations.h"

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
		void CloneOutputLinks();
		void CreateInput(Link* link, int index);
		void CreateOutput(Link* link);
		void CreateInput(LogicGate* gate, int index);
		//void CreateOutput(LogicGate* gate);
		void ResetMemory();
		int InputQuantity();
		double GetDistance();
		void SetDistance(double d);
		double GetElevation();
		void SetElevation(double d);
	protected:
		Link* inputLinks[2];
		//Link* outputLink;
		std::vector<Link*> outputLinks;
		bool SourceVal(int link);
		LogicGate* clone;
		bool memorised = false;
		bool memorisedValue;
		bool Memorise(bool val);
		static const double maxDistance;
		static const double maxElevation;
	private:
		double distance;
		double elevation;
		int inputQuantity;
		
		
};

#endif
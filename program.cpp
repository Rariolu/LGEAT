#include "InputGate.h"
#include "DoubleSourceGate.h"
#include "OutputGate.h"
#include "NOTGate.h"

int main()
{
	InputGate* a = new InputGate();
	InputGate* b = new InputGate();
	DoubleSourceGate* gate = new DoubleSourceGate(NAND);
	OutputGate* c = new OutputGate();
	gate->CreateInput(a, 0);
	gate->CreateInput(b, 1);
	NOTGate * not = new NOTGate();
	not->CreateInput(gate, 0);
	c->CreateInput(not,0);
	bool vals[] = { false,true };
	
	for (bool av : vals)
	{
		for (bool bv : vals)
		{

			a->SetInitialValue(av);
			b->SetInitialValue(bv);
			std::cout << "A: " << av << "; B: " << bv << "; C: " << c->GetOutput() << ";" << std::endl;
		}
	}
	std::system("pause");
	return 0;
}
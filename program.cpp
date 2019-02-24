#include "Genome.h"

int main()
{
	Genome* g = new Genome(2, 1);
	g->CreateDSourceGate(AND, 0, 1, 2);
	g->CreateNOTGate(3, 2);
	bool vals[] = { false,true };
	for (bool av : vals)
	{
		for (bool bv : vals)
		{
			std::cout << "A: " << av << "; B: " << bv << "; C: " << g->GetOutput(new bool[2]{ av,bv },0) << ";" << std::endl;
			g->ResetMemory();
		}
	}
	/*std::vector<LogicGate*> gates;
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
	gates.push_back(a);
	gates.push_back(b);
	gates.push_back(gate);
	gates.push_back(not);
	gates.push_back(c);
	for (bool av : vals)
	{
		for (bool bv : vals)
		{

			a->SetInitialValue(av);
			b->SetInitialValue(bv);
			std::cout << "A: " << av << "; B: " << bv << "; C: " << c->GetOutput() << ";" << std::endl;
			for (LogicGate* g : gates)
			{
				g->ResetMemory();
			}
		}
	}*/
	std::system("pause");
	return 0;
}
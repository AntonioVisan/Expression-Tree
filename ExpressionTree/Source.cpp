#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include "Node.h"
enum Operatori
{
	Adunare = 1,
	Scadere = 1,
	Inmultire = 2,
	Impartire = 2
};
int Prioritate(char character)
{
	if (character == '+')
		return Operatori::Adunare;
	if (character == '-')
		return Operatori::Scadere;
	if (character == '*')
		return Operatori::Inmultire;
	if (character == '/')
		return Operatori::Impartire;
	else return 0;
}
std::string FormaPoloneza(std::string expresie)
{
	std::string polish;
	std::stack<char> operatori;
	for (char caracter : expresie)
	{
		if ((caracter >= '0' && caracter <= '9') || (caracter >= 'a' && caracter <= 'z'))
		{
			polish.push_back(caracter);
			//polish.push_back(' ');
		}
		else if (caracter == '(')
			operatori.push(caracter);
		else
		{
			if (caracter == ')')
			{
				while (!operatori.empty() && operatori.top() != '(')
				{
					polish.push_back(operatori.top());
					//polish.push_back(' ');
					operatori.pop();
				}
				if (!operatori.empty()) operatori.pop();
			}
			else //caracter = operator
			{
				while (!operatori.empty() && Prioritate(operatori.top()) >= Prioritate(caracter))
				{
					polish.push_back(operatori.top());
					//polish.push_back(' ');
					operatori.pop();
				}
				operatori.push(caracter);
			}
		}
	}
	while (!operatori.empty())
	{
		polish.push_back(operatori.top());
		//polish.push_back(' ');
		operatori.pop();
	}
	return polish;
}
Node* arboreSintactic(std::string polish)
{
	std::stack<Node*> noduri;
	for (char caracter : polish)
	{
		if ((caracter >= '0' && caracter <= '9') || (caracter >= 'a' && caracter <= 'z'))
		{
			Node* nod = new Node;
			nod->setValue(caracter);
			nod->setLeft(nullptr);
			nod->setRight(nullptr);
			noduri.push(nod);
		}
		else if (caracter == '-' || caracter == '+' || caracter == '*' || caracter == '/')
		{
			Node* nod1 = noduri.top();
			noduri.pop();
			Node* nod2 = noduri.top();
			noduri.pop();
			Node* nodnou = new Node;
			nodnou->setValue(caracter);
			nodnou->setLeft(nod2);
			nodnou->setRight(nod1);
			noduri.push(nodnou);
		}
	}
	if (noduri.size() == 1)
		return noduri.top();
	else
	{
		std::cerr << "Eroare";
		return nullptr;
	}
}
int main()
{
	std::ifstream fin("input.txt");
	std::string expresie;
	fin >> expresie;
	fin.close();
	std::string polish = FormaPoloneza(expresie);
	//std::cout << polish;
	Node* arbore=arboreSintactic(polish);
	arbore->printByLevels();
	int optiune;
	do
	{
		std::cout << "Doresti sa mai evaluezi expresia aritmetica dand alte valori pentru variabile?" << std::endl;
		std::cout << "1) Da." << std::endl;
		std::cout << "2) Nu." << std::endl;
		std::cin >> optiune;
		switch (optiune)
		{
		case 1:
			std::cout << "Evaluarea expresiei pentru arbore: " << arbore->evaluate() << std::endl;
			break;
		case 2: break;
		default: std::cout << "Optiune invalida. Alege optiunea 1 sau 2." << std::endl;
		}
	} while (optiune != 2);
	delete arbore;
	return 0;
}
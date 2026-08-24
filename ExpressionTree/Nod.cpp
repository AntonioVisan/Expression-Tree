#include "Nod.h"

Nod::Nod() : info( ), left(nullptr), right(nullptr)
{
}

Nod::Nod(char info, Nod* left, Nod* right)
{
	this->info = info;
	this->left = left;
	this->right = right;
}

Nod::~Nod()
{
	this->info = '\0';
	delete left;
	delete right;
	left = right = nullptr;
}

void Nod::setOp(const char caracter)
{
	this->info = caracter;
}

void Nod::setLeft(Nod* left)
{
	this->left = left;
}

void Nod::setRight(Nod* right)
{
	this->right = right;
}

char Nod::getInfo() const
{
	return this->info;
}

Nod* Nod::getLeft() const
{
	return this->left;
}

Nod* Nod::getRight() const
{
	return this->right;
}

void Nod::afisareNiveluri()
{
	int i = 0, nrElementePeNivel;
	std::queue<Nod*> coada;
	coada.push(this);
	while (!coada.empty())
	{
		nrElementePeNivel = coada.size();
		std::cout << "Pe nivelul " << i << " avem nodurile: " << std::endl;
		while (nrElementePeNivel > 0)
		{
			Nod* current = coada.front();
			coada.pop();
			std::cout << current->getInfo() << " ";
			Nod* left = current->getLeft();
			Nod* right = current->getRight();
			if (left)
				coada.push(left);
			if (right)
				coada.push(right);
			nrElementePeNivel--;
		}
		std::cout << std::endl;
		i++;
	}
}

double Nod::evaluare_expresie()
{
	if (this->getInfo() >= '0' && this->getInfo() <= '9')
		return this->getInfo() - 48.0;
	if (this->getInfo() >= 'a' && this->getInfo() <= 'z')
	{
		double valoare;
		std::cout << "Introduceti o valoare pentru variabila " << this->getInfo() << ":" << std::endl;
		std::cin >> valoare;
		return valoare;
	}
	double val1 = this->getLeft()->evaluare_expresie();
	double val2 = this->getRight()->evaluare_expresie();
	
	switch (this->getInfo())
	{
		case '+':
			return val1 + val2;
		case '-':
			return val1 - val2;
		case '*':
			return val1 * val2;
		case '/':
			return val1 / val2;
	}
}



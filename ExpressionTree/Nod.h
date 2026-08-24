#pragma once
#include <queue>
#include <iostream>
class Nod
{
public:
	Nod();
	Nod(char info, Nod* left, Nod* right);
	~Nod();
	void setOp(const char caracter);
	void setLeft(Nod* left);
	void setRight(Nod* right);
	char getInfo() const;
	Nod* getLeft() const;
	Nod* getRight() const;
	void afisareNiveluri();
	double evaluare_expresie();
private:
	char info;
	Nod* left;
	Nod* right;
};


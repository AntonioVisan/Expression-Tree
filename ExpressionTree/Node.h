#pragma once

class Node
{
public:
	Node();
	Node(char value, Node* left, Node* right);
	~Node();

	void setValue(char value);
	void setLeft(Node* left);
	void setRight(Node* right);

	char getValue() const;
	Node* getLeft() const;
	Node* getRight() const;

	void printByLevels();
	double evaluate();

private:
	char value;
	Node* left;
	Node* right;
};


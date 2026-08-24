#include "Node.h"

#include <iostream>
#include <queue>

Node::Node() : value('\0'), left(nullptr), right(nullptr)
{}

Node::Node(char value, Node* left, Node* right)
	: value(value), left(left), right(right)
{}

Node::~Node()
{
	delete left;
	delete right;
}

void Node::setValue(char value)
{
	this->value = value;
}

void Node::setLeft(Node* left)
{
	this->left = left;
}

void Node::setRight(Node* right)
{
	this->right = right;
}

char Node::getValue() const
{
	return this->value;
}

Node* Node::getLeft() const
{
	return this->left;
}

Node* Node::getRight() const
{
	return this->right;
}

void Node::printByLevels()
{
	int level = 0;
	std::queue<Node*> queue;

	queue.push(this);

	while (!queue.empty())
	{
		int nodesOnLevel = static_cast<int>(queue.size());

		std::cout << "Level " << level << ": ";

		while (nodesOnLevel > 0)
		{
			Node* current = queue.front();
			queue.pop();

			std::cout << current->getValue() << " ";

			if (current->getLeft() != nullptr)
				queue.push(current->getLeft());

			if (current->getRight() != nullptr)
				queue.push(current->getRight());

			nodesOnLevel--;
		}

		std::cout << std::endl;
		level++;
	}
}

double Node::evaluate(const std::map<char, double>& variables) const
{
	if (value >= '0' && value <= '9')
		return value - '0';

	if (value >= 'a' && value <= 'z')
		return variables.at(value);

	double leftValue = left->evaluate(variables);
	double rightValue = right->evaluate(variables);

	switch (value)
	{
	case '+':
		return leftValue + rightValue;

	case '-':
		return leftValue - rightValue;

	case '*':
		return leftValue * rightValue;

	case '/':
		return leftValue / rightValue;
	}

	return 0.0;
}
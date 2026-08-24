#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>

#include "Node.h"

int getPrecedence(char character)
{
	if (character == '+' || character == '-')
		return 1;

	if (character == '*' || character == '/')
		return 2;

	return 0;
}

bool isOperand(char character)
{
	return (character >= '0' && character <= '9') ||
		(character >= 'a' && character <= 'z');
}

bool isOperator(char character)
{
	return character == '+' || character == '-' ||
		character == '*' || character == '/';
}

std::string toPostfix(const std::string& expression)
{
	std::string postfix;
	std::stack<char> operators;

	for (char character : expression)
	{
		if (isOperand(character))
		{
			postfix.push_back(character);
		}
		else if (character == '(')
		{
			operators.push(character);
		}
		else if (character == ')')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				postfix.push_back(operators.top());
				operators.pop();
			}

			if (!operators.empty())
				operators.pop();
		}
		else if (isOperator(character))
		{
			while (!operators.empty() &&
				operators.top() != '(' &&
				getPrecedence(operators.top()) >= getPrecedence(character))
			{
				postfix.push_back(operators.top());
				operators.pop();
			}

			operators.push(character);
		}
	}

	while (!operators.empty())
	{
		postfix.push_back(operators.top());
		operators.pop();
	}

	return postfix;
}

Node* buildExpressionTree(const std::string& postfix)
{
	std::stack<Node*> nodes;

	for (char character : postfix)
	{
		if (isOperand(character))
		{
			Node* node = new Node(character, nullptr, nullptr);
			nodes.push(node);
		}
		else if (isOperator(character))
		{
			if (nodes.size() < 2)
			{
				std::cerr << "Invalid expression." << std::endl;
				return nullptr;
			}

			Node* right = nodes.top();
			nodes.pop();

			Node* left = nodes.top();
			nodes.pop();

			Node* node = new Node(character, left, right);
			nodes.push(node);
		}
	}

	if (nodes.size() != 1)
	{
		std::cerr << "Invalid expression." << std::endl;
		return nullptr;
	}

	return nodes.top();
}

std::set<char> getVariables(const std::string& expression)
{
	std::set<char> variables;

	for (char character : expression)
	{
		if (character >= 'a' && character <= 'z')
			variables.insert(character);
	}

	return variables;
}

std::map<char, double> readVariableValues(const std::set<char>& variables)
{
	std::map<char, double> values;

	for (char variable : variables)
	{
		std::cout << "Enter a value for variable " << variable << ": ";
		std::cin >> values[variable];
	}

	return values;
}

int main()
{
	std::ifstream inputFile("input.txt");

	if (!inputFile)
	{
		std::cerr << "Could not open input.txt." << std::endl;
		return 1;
	}

	std::string expression;
	inputFile >> expression;
	inputFile.close();

	std::string postfix = toPostfix(expression);

	Node* expressionTree = buildExpressionTree(postfix);

	if (expressionTree == nullptr)
		return 1;

	expressionTree->printByLevels();

	std::set<char> variables = getVariables(expression);

	int option;

	do
	{
		std::cout << "\nDo you want to evaluate the expression "
			"with different variable values?"
			<< std::endl;
		std::cout << "1) Yes" << std::endl;
		std::cout << "2) No" << std::endl;
		std::cout << "Choose an option: ";

		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			std::map<char, double> variableValues =
				readVariableValues(variables);

			std::cout << "Expression result: "
				<< expressionTree->evaluate(variableValues)
				<< std::endl;

			break;
		}

		case 2:
			break;

		default:
			std::cout << "Invalid option. Choose 1 or 2."
				<< std::endl;
		}

	} while (option != 2);

	delete expressionTree;

	return 0;
}
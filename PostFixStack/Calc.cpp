#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include"stack.h"

using namespace std;

bool IsDigit(char c)
{
	if (c == '1' || c == '2' || c == '3' || c == '4' || c== '5' || c == '6' || c == '7' || c == '8' || c == '9')
	{return true;}
	else
	{return false;}
}

bool primaryOps(char ops)
{
	if (ops == '*' || ops == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool secondaryOps(char ops)
{
	if (ops == '+' || ops == '-')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	myStack calculatorStack;
	ifstream myReadFile;
	myReadFile.open("tests.txt");
	if (myReadFile.fail())
	{
		cout << "Could not open the file." << endl;
	}
	string output;
	if (myReadFile.is_open())
	{
		while (!myReadFile.eof())
		{
			myReadFile >> output;
			cout << "\n" << output << endl;

			int i = 0;
			double num;
			while (output[i] != NULL)
			{
				if ((primaryOps(calculatorStack.top()) && secondaryOps(output[i])) || (primaryOps(calculatorStack.top()) && primaryOps(output[i])) || (secondaryOps(calculatorStack.top()) && secondaryOps(output[i])))
				{
					cout << calculatorStack.top();
					calculatorStack.pop();
					calculatorStack.push(output[i]);
				}

				if (secondaryOps(calculatorStack.top()) && primaryOps(output[i]))
				{
					cout << output[i] << calculatorStack.top();
					calculatorStack.pop();
				}

				if (output[i] == '(')
				{
					calculatorStack.push(output[i]);
				}

				else if (IsDigit(output[i]))
				{
					cout << output[i];
				}

				else if (primaryOps(output[i]) || secondaryOps(output[i]))
				{
					calculatorStack.push(output[i]);
				}

				else
				{
					if (output[i] == ')')
					{
						while (primaryOps(calculatorStack.top()) || secondaryOps(calculatorStack.top()))
						{
							cout << calculatorStack.top();
							calculatorStack.pop();
						}
						if (calculatorStack.top() == '(')
						{
							calculatorStack.pop();
						}

						else if ((primaryOps(calculatorStack.top()) && secondaryOps(output[i])) || (primaryOps(calculatorStack.top()) && primaryOps(output[i])) || (secondaryOps(calculatorStack.top()) && secondaryOps(output[i])))
						{
							cout << calculatorStack.top();
							calculatorStack.pop();
							calculatorStack.push(output[i]);
						}
					}

					while (primaryOps(calculatorStack.top()) || secondaryOps(calculatorStack.top()))
					{
						cout << calculatorStack.top();
						calculatorStack.pop();
					}
					calculatorStack.pop();
				}
				i++;
			}

			if (secondaryOps(calculatorStack.top()) || primaryOps(calculatorStack.top()))
			{
				cout << calculatorStack.top();
				calculatorStack.pop();
			}

			cout << "\n";
		}
	}
	system("PAUSE");
	return 0;
}
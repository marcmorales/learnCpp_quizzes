#include <iostream>
#include <limits>

void clearIOState()
{
	
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getVal()
{
	double val;
	bool foo{ std::cin.fail() }; // iostate check
	do // loop until we get a valid value;
	{
		if (std::cin.fail())
		{
			std::cout << "You entered an improper value\n";
			clearIOState();
			foo = std::cin.fail(); // iostate check
		}
		std::cout << "Enter a double value: ";
		std::cin >> val;
		foo = std::cin.fail(); // iostate check

	} while (std::cin.fail());

	return val;
}

char getOperator()
{
	char getVal;
	bool validator{ false };
	do
	{
		clearIOState();
		std::cout << "Enter an operator (+, -, *, /): ";
		std::cin >> getVal;
		switch (getVal)
		{
		case '+': case '-': case '*': case '/':
			validator = false;
			break;
		default:
			std::cout << "You did not enter a proper operator.\n";
			validator = true;
			break;
		}
	} while (validator);
	return getVal;
}

int main()
{
	double a{ getVal() };
	double b{ getVal() };
	char myOperator{ getOperator() };
	switch (myOperator)
	{
	case '+': 
		std::cout << a + b << '\n';
		break;
	case '-': 
		std::cout << a - b << '\n';
		break;
	case '*': 
		std::cout << a * b << '\n';
		break;
	case '/':
		std::cout << a / b << '\n';
		break;
	default:
		//this should not run
		break;
	}

	return 0;
}

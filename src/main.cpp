
#include <iostream>
#include "Rational.h"

using std::cout;


int main()
{
	Rational number(3,-4);

	Rational number1(4,7);

	Rational number2(3, 5);

	cout << number / number1;
}

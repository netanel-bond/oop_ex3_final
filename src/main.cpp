
#include <iostream>
#include "Poly.h"
#include "Rational.h"
#include <vector>

using std::endl;
using std::cout;

int main()
{
	Rational number(0,4);

	Rational number1(0);

	//Rational number2(3, 5);

	//cout << number;
	//cout << number1 << endl;
	//cout << (number == number1);


	auto rationals = std::vector<Rational> { Rational(14,1), 
		Rational(), Rational(), Rational(5,1), Rational(), Rational(17,2)};

	auto rationals2 = std::vector<Rational>{ Rational(),
		Rational(), Rational(3,2), Rational(5,1), Rational(6,3), Rational(3,3) };


	Poly p(rationals),p3(rationals2);

	//cout << p << endl;

	Poly p2 ;
    p2 = p*p3;

	cout << p2;
}
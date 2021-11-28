
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


	auto rationals = std::vector<Rational> {  Rational(2,1), Rational(), Rational(1,1)};

	auto rationals2 = std::vector<Rational>{ Rational(1,1),Rational(), Rational(6,1) };


	Poly p(rationals),p3(rationals2);

	//cout << p << endl;

	Poly p2,p1 ;
    

	cout << p1;
}
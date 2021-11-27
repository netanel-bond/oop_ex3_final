
#include "Rational.h"
#include <iostream>
#include <stdlib.h>

using std::cout;

Rational::Rational(int numer, int denom)
	:m_numer(numer), m_denom(denom)
{
	if (m_denom == 0 || m_numer == 0)
	{
		m_numer = 0;
		m_denom = 1;

		return;
	}

	if (m_denom < 0)
	{
		m_denom *= -1;
		m_numer *= -1;
	}

	reduction();
}

Rational& Rational::operator=(const Rational& rat)
{
	m_numer = rat.m_numer;
	m_denom = rat.m_denom;

	reduction();

	return *this;
}


Rational operator+(const Rational& rat1, const Rational& rat2)
{

	Rational new_rat = rat1;

	new_rat += rat2;

	return new_rat;
}

Rational& Rational::operator+=(const Rational& rat)
{

	if (m_denom == rat.m_denom)
		m_numer += rat.m_numer;
	else
	{
		m_numer = rat.m_denom * m_numer + m_denom * rat.m_numer;

		m_denom = lcmFinder(m_denom, rat.m_denom);
	}

	reduction();

	return *this;
}

Rational operator-(const Rational& rat1, const Rational& rat2)
{
	Rational temp = rat2;

	Rational new_rat = rat1 + -temp;

	return new_rat;
}

Rational& operator-=(Rational& rat1, const Rational& rat2)
{
	Rational temp = rat2;

	rat1 += -temp;

	return rat1;
}

Rational operator*(const Rational& rat1, const Rational& rat2)
{
	Rational new_rat = Rational(rat1.getNumer() * rat2.getNumer(), rat1.getDenom() * rat2.getDenom());

	return new_rat;
}

Rational& operator*=(Rational& rat1, const Rational& rat2)
{
	rat1 = rat1 * rat2;

	return rat1;
}


Rational operator/(const Rational& rat1, const Rational& rat2)
{
	Rational inverse_rat2 = Rational(rat2.getDenom(), rat2.getNumer());

	Rational new_rat = rat1 * inverse_rat2;

	return new_rat;
}

Rational& operator/=(Rational& rat1, const Rational& rat2)
{
	rat1 = rat1 / rat2;

	return rat1;
}

Rational& Rational::operator-()
{
	m_numer *= -1;

	return *this;
}

Rational& operator+(Rational& rat)
{
	if (rat.getNumer() < 0)
		-rat;

	return rat;
}

bool operator>(const Rational& rat1, const Rational& rat2)
{
	Rational new_rat = rat1 - rat2;

//		if result is above 0 return true
	if (new_rat.getNumer() > 0)
		return true;

	return false;
}

bool operator>=(const Rational& rat1, const Rational& rat2)
{
	return rat1 > rat2 || rat1 == rat2;
}

bool operator<(const Rational& rat1, const Rational& rat2)
{
	Rational new_rat = rat1 - rat2;

//		if result is above 0 return false
	if (new_rat.getNumer() < 0)
		return true;

	return false;
}

bool operator<=(const Rational& rat1, const Rational& rat2)
{
	return rat1 < rat2 || rat1 == rat2;
}

bool operator==(const Rational& rat1, const Rational& rat2)
{
	bool bigger = rat1 > rat2;
	bool smaller = rat1 < rat2;

	return !(bigger || smaller);
}

bool operator!=(const Rational& rat1, const Rational& rat2)
{
	return !(rat1 == rat2);
}

std::ostream& operator<<(std::ostream& output, const Rational& rat)
{
	cout << rat.getNumer() << '/' << rat.getDenom();

	return output;
}

void Rational::reduction()
{
	int gcd = gcdFinder(m_numer, m_denom);

	m_numer /= gcd;
	m_denom /= gcd;
}

int Rational::lcmFinder(const int num1, const int num2)
{
	return (abs(num1) * abs(num2)) / gcdFinder(num1, num2);
}

int Rational::gcdFinder(const int num1, const int num2)
{
	int num_1 = abs(num1),
		num_2 = abs(num2);

	int gcd = num_1 <= num_2 ? num_1 : num_2;

	for (; gcd > 0; gcd--)
	{
		if (num_1 % gcd == 0 && num_2 % gcd == 0)
			return gcd;
	}

	return 1;
}

int Rational::getNumer() const
{
	return m_numer;
}


int Rational::getDenom() const
{
	return m_denom;
}
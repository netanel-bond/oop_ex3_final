
#include "Rational.h"
#include "ostream.h"
Rational::Rational(int numer, int denom)
	:m_numer(numer), m_denom(denom)
{
	if (m_denom == 0)
	{
		m_numer = 0;
		m_denom = 1;

		return;
	}

	bool denom_neg = m_denom < 0, numer_neg = m_numer < 0;

	if (m_denom < 0)
	{
		m_denom *= -1;
		m_numer *= -1;
	}



}

Rational operator+(const Rational rat1, const Rational rat2)
{
	Rational new_rat = Rational(rat1.getNumer() + rat2.getNumer(), rat1.getDenom() + rat2.getDenom());

	return new_rat;
}

Rational operator-(const Rational rat1, const Rational rat2)
{
	Rational new_rat = Rational(rat1.getNumer() - rat2.getNumer(), rat1.getDenom() - rat2.getDenom());

	return new_rat;
}

int Rational::getNumer() const
{
	return m_numer;
}

int Rational::getDenom() const
{
	return m_denom;
}
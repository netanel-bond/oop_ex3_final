
#include "Poly.h"

//c-tor for array of rationals
Poly::Poly(const std::vector<Rational>& coeffes) : m_theData(coeffes) {}

// default c-tor, builds poly with 0 as rational
Poly::Poly() : m_theData(0) {}

//  c-tor for rational as scalar
Poly::Poly(const Rational rat)	: m_theData(rat) {}

//  c-tor for an int for the exponent and rational
Poly::Poly(const int coeffe, const Rational rat) : m_theData(coeffe, rat) {}
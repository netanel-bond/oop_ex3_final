

class Rational {

public:

	Rational(int numer = 0, int denom = 1);

	int getNumer() const;

	int getDenom() const;


private:

	int m_numer, m_denom;
};



Rational operator+(const Rational rat1, const Rational rat2);
Rational operator-(const Rational rat1, const Rational rat2);
class Rational
{
private:
	int _numerator;
	int _denominator;
public:
	explicit Rational(int numerator, int denominator)
		:_numerator(numerator),
		_denominator(denominator)
	{}
	inline int getNumerator() const {return _numerator;}
	inline int getDenominator() const {return _denominator;}
	//... //contains no operator*
};

const Rational operator*(const Rational& lhs, const Rational& rhs)//now a non-member function
{
	return Rational(lhs.getNumerator()*rhs.getNumerator(), lhs.getDenominator()*rhs.getDenominator());
}
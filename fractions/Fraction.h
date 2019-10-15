/* *******************************
AUTHOR: Dibe
FILE:	Fraction.h

ABOUT THIS CODE:
	This header contains the Fraction class 
	that holds the information for a single
	fraction and defines the set of admissible
	operations on a Fraction object.

******************************* */

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {

	class Fraction
	{
		int m_numerator;
		int m_denominator;

		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		Fraction() : m_numerator{0}, m_denominator{0} { }
		Fraction(int numerator, int denominator);
		bool isEmpty() const;
		void setEmpty();
		void display() const;
		
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);
		Fraction& operator=(const Fraction& rhs);
	};
}
#endif 
/* *******************************
AUTHOR: Dibe
FILE:	Fraction.cpp

ABOUT THIS CODE:
	This module implements the
	functions declared in the Fraction.h.
	In here you will find functions and
	overloaded operators that helps 
	to deal with objects of Fraction type.

******************************* */

#include <iostream>
#include "Fraction.h"

namespace sict {

	// Two-argument constructor that initialize the data members with
	// specific values, but set them to safe empty state if they are not valid
	Fraction::Fraction(int numerator, int denominator) 
	{
		if (numerator >= 0 && denominator > 0) {
			m_numerator = numerator;
			m_denominator = denominator;
		}
		else {
			setEmpty();
		}
		reduce();
	}

	// return the greatest value between numerator and denominator
	int Fraction::max() const 
	{
		return (m_numerator > m_denominator) ? m_numerator : m_denominator;
	}

	// return the lowest value between numerator and denominator
	int Fraction::min() const 
	{
		return (m_numerator < m_denominator) ? m_numerator : m_denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor is found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// reduce the modifiers
	void Fraction::reduce() 
	{
		int divison = gcd();
		m_numerator = m_numerator / divison;
		m_denominator = m_denominator / divison;
	}

	// query function to display the values of numerator and denominator
	void Fraction::display() const
	{
		if (m_numerator >= 0 && m_denominator > 1) {
			std::cout << m_numerator << "/" << m_denominator;
		}
		else if (m_numerator >= 0 && m_denominator == 1) {
			std::cout << m_numerator;
		}
		else {
			std::cout << "no fraction stored";
		}
	}

	// Check if the numerator and denominator are in a safe empty state
	bool Fraction::isEmpty() const 
	{
		return (m_numerator == 0 && m_denominator == 0) ? true : false;
	}

	// set data members to safe empty state
	void Fraction::setEmpty()
	{
		m_numerator = 0;
		m_denominator = 0;
	}

	// overloaded + operator to calculate the numerator and denominator portions
	// to do a fraction between numbers
	Fraction Fraction::operator+(const Fraction& rhs) const 
	{
		Fraction temp;

		if (!this->isEmpty() && !rhs.isEmpty()) 
		{
			temp.m_numerator = (this->m_numerator*rhs.m_denominator) + (this->m_denominator*rhs.m_numerator);
			temp.m_denominator = this->m_denominator*rhs.m_denominator;
		}
		temp.reduce();
		 
		return temp;
	}

	// overloaded * operator to calculate multiplication between two objects
	Fraction Fraction::operator*(const Fraction& rhs) const 
	{
		Fraction temp;

		if (!this->isEmpty() && !rhs.isEmpty())
		{
			temp.m_numerator = (this->m_numerator*rhs.m_numerator);
			temp.m_denominator = (this->m_denominator*rhs.m_denominator);
		}
		temp.reduce();

		return temp;
	}

	// overloaded == operator to check if two objects are equal
	bool Fraction::operator==(const Fraction& rhs) const 
	{
		return (!this->isEmpty() && !rhs.isEmpty() &&
				this->m_numerator == rhs.m_numerator &&
				this->m_denominator == rhs.m_denominator);
	}

	// overloaded != operator to check if two objects are not equal
	bool Fraction::operator!=(const Fraction& rhs) const
	{
		return !this->isEmpty() && !rhs.isEmpty() &&
			this->m_numerator != rhs.m_numerator &&
			this->m_denominator != rhs.m_denominator;
	}

	// overloaded != operator to increment the current instance with another one
	Fraction& Fraction::operator+=(const Fraction& rhs) 
	{
		if (!this->isEmpty() && !rhs.isEmpty()) {
			*this = *this + rhs;
		}
		else {
			setEmpty();
		}
		return *this;
	}
	
	// overloaded = operator to assign the values of another instance to
	// the current instance
	Fraction& Fraction::operator=(const Fraction& rhs) 
	{
		if (this != &rhs) {
			m_numerator = rhs.m_numerator;
			m_denominator = rhs.m_denominator;
		}
		return *this;
	}
}

#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Fraction
    {

    public:
        int numerator;
        int denominator;

        // Help functions
        int gcd(int num1, int num2);
        void reduce();

        // Getters and Setters
        int getNumerator()
        {
            return this->numerator;
        }
        void setNumerator(int numerator)
        {
            this->numerator = numerator;
        }
        void setDenominator(int denominator)
        {
            this->denominator = denominator;
        }
        int getDenominator()
        {
            return this->denominator;
        }

        // Constructors
        Fraction(int numerator, int denominator);
        Fraction(float num);
        // Fraction(const Fraction& other) noexcept;

        // Operators
        friend ostream &operator<<(ostream &ostr, const Fraction &frac);
        friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator+(const Fraction &frac1, float num);
        friend Fraction operator-(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator-(const Fraction &frac1, float num);
        friend Fraction operator/(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator/(const Fraction &frac1, float num);
        friend Fraction operator/(float num, const Fraction &frac1);
        friend Fraction operator*(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator*(const Fraction &frac1, float num);
        friend Fraction operator*(float num, const Fraction &frac1);
        friend Fraction operator++(Fraction &frac1, int num);
        friend Fraction operator++(int num);
        friend Fraction &operator--(Fraction &frac1);
        friend bool operator>(const Fraction &frac1, float num);
        friend bool operator>=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator>=(const Fraction &frac1, float num);
        friend bool operator>(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<(const Fraction &frac1, Fraction &frac2);
        friend bool operator<(const Fraction &frac1, const float num);
        friend bool operator<=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<=(const Fraction &frac1, float num);
        friend bool operator==(const Fraction &frac1, const Fraction &frac2);
        friend bool operator==(const Fraction &frac1, const float num);
        friend std::istream &operator>>(istream &num, Fraction &frac1);
    };

}

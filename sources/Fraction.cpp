#include "Fraction.hpp"
#include <cmath>

namespace ariel
{

    // Help function
    int Fraction::gcd(int num1, int num2)
    {
        if (num2 == 0)
            return num1;
        return Fraction::gcd(num2, num1 % num2);
    }

    void Fraction::reduce()
    {

        int gcdValue;
        gcdValue = this->gcd(this->numerator, this->denominator);

        this->numerator /= gcdValue;
        this->denominator /= gcdValue;
    }

    // Constructors
    Fraction::Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
        this->reduce();
    }

    Fraction::Fraction(float num)
    {
        // Check if the number is zero
        if (num == 0)
        {
            numerator = 0;
            denominator = 1;
            return;
        }

        this->numerator = num * 1000;
        this->denominator = 1000;
        this->reduce();
    }

    // Operators Part

    // Operator <<
    std::ostream &operator<<(std::ostream &ostr, const ariel::Fraction &f)
    {
        ostr << f.numerator << "/" << f.denominator;
        return ostr;
    }

    // Operator >>
    std::istream &operator>>(istream& num , Fraction& frac1)
    {
        
    }

    Fraction operator+(const Fraction &frac1, const Fraction &frac2)
    {
        int numerator = (frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator);
        int denominator = frac1.denominator * frac2.denominator;

        Fraction frac = Fraction(numerator, denominator);
        return frac;
    }

    Fraction operator+(const Fraction &frac1, const float num)
    {
        Fraction frac = Fraction(num);
        Fraction res = frac + frac1;
        // res.reduce();
        return res;
    }
    Fraction operator-(const Fraction &frac1, const Fraction &frac2)
    {
        int numerator = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
        int denominator = frac1.denominator * frac2.denominator;

        Fraction frac = Fraction(numerator, denominator);
        return frac;
    }

    Fraction operator-(const Fraction &frac1, float num)
    {
        Fraction frac = Fraction(num);
        return frac1 - frac;
    }

    Fraction operator-(float num, const Fraction &frac1)
    {
        Fraction frac = Fraction(num);
        return frac1 - frac;
    }

    Fraction operator/(const Fraction &frac1, const Fraction &frac2)
    {
        if (frac2.numerator == 0)
        {
            throw std::runtime_error("Division by zero is unposibble.");
        }

        int numerator = frac1.numerator * frac2.denominator;
        int denominator = frac1.denominator * frac2.numerator;

        Fraction frac = Fraction(numerator, denominator);
        return frac;
    }
    Fraction operator*(const Fraction &frac1, const Fraction &frac2)
    {
        int numerator = frac1.numerator * frac2.numerator;
        int denominator = frac1.denominator * frac2.denominator;
        Fraction frac = Fraction(numerator, denominator);
        return frac;
    }
    Fraction operator*(float num, const Fraction &frac1)
    {
        Fraction frac = Fraction(frac1.numerator * (int)(num * 1000), 1000 * frac1.denominator);
        // frac.reduce();
        return frac;
    }

    // Postfix ++
    Fraction operator++(Fraction &frac1, int num)
    {
        Fraction oldFraction = Fraction(frac1.numerator, frac1.denominator);
        frac1.numerator += frac1.denominator;
        return oldFraction;
    }

    // Postfix --
    Fraction operator--(Fraction &frac1, int num)
    {
        Fraction oldFraction = Fraction(frac1.numerator, frac1.denominator);
        frac1.numerator -= frac1.denominator;
        return oldFraction;
    }

    // Prefix ++
    Fraction operator++(Fraction &frac1)
    {
        Fraction &frac = const_cast<Fraction &>(frac1);
        frac.numerator += frac.denominator;
        frac.reduce();
        return frac;
    }

    // Prefix --
    Fraction &operator--(Fraction &frac1)
    {
        Fraction &frac = const_cast<Fraction &>(frac1);
        frac.numerator -= frac.denominator;
        frac.reduce();
        return frac;
    }

    bool operator>(const Fraction &frac1, Fraction &frac2)
    {
        int crossProduct1 = frac1.numerator * frac2.denominator;
        int crossProduct2 = frac2.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 > crossProduct2;
    }

    bool operator>(const Fraction &frac1, const float num)
    {
        Fraction frac = Fraction(num);
        int crossProduct1 = frac1.numerator * frac.denominator;
        int crossProduct2 = frac.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 > crossProduct2;
    }

    bool operator>=(const Fraction &frac1, const Fraction &frac2)
    {
        int crossProduct1 = frac1.numerator * frac2.denominator;
        int crossProduct2 = frac2.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 >= crossProduct2;
    }

    bool operator>=(const Fraction &frac1, float num)
    {
        Fraction frac = Fraction(num);
        int crossProduct1 = frac1.numerator * frac.denominator;
        int crossProduct2 = frac.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 >= crossProduct2;
    }

    bool operator<(const Fraction &frac1, Fraction &frac2)
    {
        int crossProduct1 = frac1.numerator * frac2.denominator;
        int crossProduct2 = frac2.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 < crossProduct2;
    }

    bool operator<(const Fraction &frac1, const float num)
    {
        Fraction frac = Fraction(num);
        int crossProduct1 = frac1.numerator * frac.denominator;
        int crossProduct2 = frac.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 < crossProduct2;
    }

    bool operator<=(const Fraction &frac1, const Fraction &frac2)
    {
        int crossProduct1 = frac1.numerator * frac2.denominator;
        int crossProduct2 = frac2.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 <= crossProduct2;
    }

    bool operator<=(const Fraction &frac1, float num)
    {
        Fraction frac = Fraction(num);
        int crossProduct1 = frac1.numerator * frac.denominator;
        int crossProduct2 = frac.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 <= crossProduct2;
    }

    bool operator==(const Fraction &frac1 , const Fraction &frac2)
    {
        int crossProduct1 = frac1.numerator * frac2.denominator;
        int crossProduct2 = frac2.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 == crossProduct2;
    }

    bool operator==(const Fraction &frac1 , const float num)
    {
        Fraction frac = Fraction(num);
        int crossProduct1 = frac1.numerator * frac.denominator;
        int crossProduct2 = frac.numerator * frac1.denominator;

        // Compare the cross products
        return crossProduct1 == crossProduct2;
    }



}

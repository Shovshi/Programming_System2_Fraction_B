#include "Fraction.hpp"
#include <cmath>

namespace ariel{

// Help function
    int Fraction::gcd(int num1, int num2)
    {
        if (num2 == 0) return num1;
        return Fraction::gcd(num2, num1 % num2);
    }

// Constructors
    Fraction::Fraction(int numerator, int denominator)
    {
        this->numerator= numerator;
        this->denominator = denominator;
    }

    Fraction::Fraction(float num) {
        // Check if the number is zero
        if (num == 0) {
            numerator = 0;
            denominator = 1;
            return;
        }
        
        // Calculate the initial approximation
        float approx = num;
        int sign = 1;
        if (num < 0) {
            approx = -approx;
            sign = -1;
        }
        
        int wholePart = floor(approx);
        float fractionalPart = approx - wholePart;
        
        // Limit the fractional part to 3 decimal places
        fractionalPart = std::floor(fractionalPart * 1000) / 1000;
        
        // Continued fraction expansion
        int a = wholePart;
        int h1 = 1, h2 = 0;
        int k1 = 0, k2 = 1;
        
        while (approx - static_cast<float>(a) > 0.000001) {
            approx = 1 / (approx - static_cast<float>(a));
            a = floor(approx);
            
            int h = a * h1 + h2;
            int k = a * k1 + k2;
            
            h2 = h1;
            h1 = h;
            k2 = k1;
            k1 = k;
        }
        
        numerator = sign * (wholePart * k1 + h1);
        denominator = k1;
    }

    void reduce(Fraction& fraction) 
    {
    int gcdValue;
    gcdValue = fraction.gcd(fraction.numerator, fraction.denominator);
    
    fraction.numerator /= gcdValue;
    fraction.denominator /= gcdValue;
    }

    
    //Fraction::Fraction(const Fraction& other) 
    //{
    //    this->numerator= other.numerator;
    //    this->denominator = other.numerator;
    //}

    // Operators 

    std::ostream& operator<<(std::ostream& ostr, const ariel::Fraction& f)
    {
        ostr << f.numerator<< "/" << f.denominator;
        return ostr;
    }

    Fraction operator+(const Fraction& frac1, const Fraction& frac2)
    {
        int numerator = (frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator);
        int denominator = frac1.denominator * frac2.denominator;
    
        Fraction frac = Fraction(numerator, denominator);
        reduce(frac);
        return frac;
    }

    Fraction operator+(const Fraction &frac1, const float num)
    {
        return 1;
    }
    Fraction operator-(const Fraction& frac1 , const Fraction& frac2)
    {
        return 1;
    }
    Fraction operator-(const Fraction& frac1 , const int num)
    {
        return 1;
    }
    Fraction operator/(const Fraction& frac1 , const Fraction& frac2)
    {
        return 1;
    }
    Fraction operator*(const Fraction& frac1 , const Fraction& frac2)
    {
        return 1;
    }
    Fraction operator*(const float num , const Fraction& frac1)
    {
        return 1;
    }
    Fraction operator++(const Fraction& frac1 , int num)
    {
        return 1;
    }
    Fraction& operator--(const Fraction& frac1)
    {
    Fraction& f = const_cast<Fraction&>(frac1);
    f.numerator-= f.denominator;
    //f.reduce();
    return f;
    }
    bool operator>(const Fraction& frac1, const float num)
    {
        return true;
    }
    bool operator>=(const Fraction& frac1,const Fraction& frac2)
    {
        return true;
    }

}



# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int					_value;
    static const int	fractional_bits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    int     getRawValue(void) const;
    float   toFloat(void) const;

    // Comparison operators
    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed   operator+(const Fixed &other) const;
    Fixed   operator-(const Fixed &other) const;
    Fixed   operator*(const Fixed &other) const;
    Fixed   operator/(const Fixed &other) const;

    // Increment and decrement operators
    Fixed   &operator++(void);
    Fixed   operator++(int);
    Fixed   &operator--(void);
    Fixed   operator--(int);

    // Static member functions
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

# endif
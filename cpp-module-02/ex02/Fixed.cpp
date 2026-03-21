#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	fixed_p = 0;
	if (!DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	if (!DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed()
{
	if (!DEBUG)
		std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	if (!DEBUG)
		std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_p);
}

void Fixed::setRawBits( int const raw )
{
	if (!DEBUG)
		std::cout << "setRawBits member function called" << std::endl;
	this->fixed_p = raw;
}


Fixed& Fixed::operator=(const Fixed& obj)
{
	if (!DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixed_p = obj.fixed_p;
	return *this;
}


/*				New functions ex01			*/

Fixed::Fixed(const int value)
{
	if (!DEBUG)
		std::cout << "Int constructor called" << std::endl;
	this->fixed_p = value << bits;
}

Fixed::Fixed(const float value)
{
	if (!DEBUG)
		std::cout << "Float constructor called" << std::endl;
	this->fixed_p = roundf(value * (1 << bits));
}

int Fixed::toInt( void ) const
{
	return (this->fixed_p >> bits);
}

float Fixed::toFloat( void ) const
{
	return ((float)(this->fixed_p ) / (1 << bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

/*				The 6 comparison 			*/

bool Fixed::operator>(const Fixed& obj) const
{
	return (this->fixed_p > obj.fixed_p);
}

bool Fixed::operator<(const Fixed& obj) const
{
	return (this->fixed_p < obj.fixed_p);
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return (this->fixed_p >= obj.fixed_p);
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return (this->fixed_p <= obj.fixed_p);
}

bool Fixed::operator==(const Fixed& obj) const
{
	return (this->fixed_p == obj.fixed_p);
}

bool Fixed::operator!=(const Fixed& obj) const
{
	return (this->fixed_p != obj.fixed_p);
}

/*			  The 4 arithmetic				*/

float Fixed::operator+(const Fixed& obj) const
{
	return (this->toFloat() + obj.toFloat());
}

float Fixed::operator-(const Fixed& obj) const
{
	return (this->toFloat() - obj.toFloat());
}

float Fixed::operator*(const Fixed& obj) const
{
	return (this->toFloat() * obj.toFloat());
}

float Fixed::operator/(const Fixed& obj) const
{
	return (this->toFloat() / obj.toFloat());
}

/*			  The 4 increment				*/

Fixed& Fixed::operator++()
{
	this->fixed_p++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp_obj = *this;
	this->fixed_p++;
	return tmp_obj;
}

Fixed& Fixed::operator--()
{
	this->fixed_p--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp_obj = *this;
	this->fixed_p--;
	return tmp_obj;
}

/*			  The 4 max/min				*/

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1.fixed_p > obj2.fixed_p)
		return obj1;
	else
		return obj2;
}
const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.fixed_p > obj2.fixed_p)
		return obj1;
	else
		return obj2;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1.fixed_p > obj2.fixed_p)
		return obj2;
	else
		return obj1;
}
const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.fixed_p > obj2.fixed_p)
		return obj2;
	else
		return obj1;
}
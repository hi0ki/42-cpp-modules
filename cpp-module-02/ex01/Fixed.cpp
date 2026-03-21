#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	fixed_p = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_p);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_p = raw;
}


Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixed_p = obj.fixed_p;
	return *this;
}


/*				New functions			*/

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_p = value << bits;
}

Fixed::Fixed(const float value)
{
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
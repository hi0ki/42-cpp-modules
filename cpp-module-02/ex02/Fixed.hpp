#ifndef FIXED_HPP
	#define FIXED_HPP

	#include <iostream>
	#include <cmath>
	#define DEBUG 0

	class Fixed
	{
		private:
			int fixed_p;
			static const int bits;
		public:
			Fixed();
			Fixed(const int value);
			Fixed(const float value);
			Fixed(const Fixed& obj);
			~Fixed();
			/* 								*/
			Fixed& operator=(const Fixed& obj);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			/* 								*/
			float toFloat( void ) const;
			int toInt( void ) const;
			/*		 The 6 comparison		*/
			bool operator>(const Fixed& obj) const;
			bool operator<(const Fixed& obj) const;
			bool operator>=(const Fixed& obj) const;
			bool operator<=(const Fixed& obj) const;
			bool operator==(const Fixed& obj) const;
			bool operator!=(const Fixed& obj) const;
			/*		 The 4 arithmetic 		*/
			float operator+(const Fixed& obj) const; 
			float operator-(const Fixed& obj) const;
			float operator*(const Fixed& obj) const;
			float operator/(const Fixed& obj) const;
			/*		 The 4 increment	*/
			Fixed& operator++();
			Fixed operator++(int);
			Fixed& operator--();
			Fixed operator--(int);
			/*		 The 4 max/min		*/
			static Fixed& max(Fixed& obj1, Fixed& obj2);
			static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
			static Fixed& min(Fixed& obj1, Fixed& obj2);
			static const Fixed& min(const Fixed& obj1, const Fixed& obj2);

	};
	std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif
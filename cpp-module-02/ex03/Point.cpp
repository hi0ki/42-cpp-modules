#include "Point.hpp"

Point::Point( void ) : x(0) , y(0) {}

Point::Point( float nx, float ny ) : x(nx), y(ny) {}

Point& Point::operator=(const Point& obj)
{
	(void)obj;
	return *this;
}

Point::Point(Point& obj) : x(obj.x) , y(obj.y) {}

Point::~Point() {}

Fixed Point::get_x() const
{
	return (x);
}
Fixed Point::get_y() const
{
	return (y);
}
#include "Point.hpp"

float cal_triangle(Point const& a, Point const& b, Point const& c)
{
	float f_res;
	float s_res;
	float res;

	f_res = (a.get_x().toFloat() * b.get_y().toFloat()) + (b.get_x().toFloat() * c.get_y().toFloat()) + (c.get_x().toFloat() * a.get_y().toFloat());
	s_res = (a.get_x().toFloat() * c.get_y().toFloat()) + (b.get_x().toFloat() * a.get_y().toFloat()) + (c.get_x().toFloat() * b.get_y().toFloat());

	res = (f_res - s_res) / 2;
	return std::abs(res);
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float abc;
	float pab;
	float pbc;
	float pac;

	abc = cal_triangle(a, b , c);
	pab = cal_triangle(a, b, point);
	pbc = cal_triangle(b, c, point);
	pac = cal_triangle(a, c, point);

	if (!pab || !pbc || !pac)
		return (false);
	if ((pab + pbc + pac) - abc == 0)
		return (true);
	return (false);
}
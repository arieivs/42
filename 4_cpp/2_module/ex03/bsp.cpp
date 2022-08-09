#include "Point.hpp"

/*
How to check if a point is inside a triangle:
https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
BSP = Binary Space Partitioning
*/

Fixed	areaTriangle(Point const a, Point const b, Point const c) {
	Fixed	area;

	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()))/2;
	if (area < 0)
		return (area * -1);
	return (area);
}

/* if any of the areas is 0, the point belongs to the line created by the other two points
thus, it it's inside it's on the edge and it should return false */
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area_abc;
	Fixed	area_abp;
	Fixed	area_acp;
	Fixed	area_bcp;

	area_abc = areaTriangle(a, b, c);
	area_abp = areaTriangle(a, b, point);
	area_acp = areaTriangle(a, c, point);
	area_bcp = areaTriangle(b, c, point);
	if (area_abp == 0 || area_acp == 0 || area_bcp == 0)
		return false;
	return (area_abc == area_abp + area_acp + area_bcp);
}
#include <stdlib.h>
#include <stdio.h>

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb >> 24);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 255);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 255);
}

int	get_b(int trgb)
{
	return (trgb & 255);
}

int	add_shade(int trgb, float shade)
{
	int	new_r;
	int	new_g;
	int	new_b;

	new_r = (1 - shade) * get_r(trgb);
	new_g = (1 - shade) * get_g(trgb);
	new_b = (1 - shade) * get_b(trgb);
	return (get_trgb(get_t(trgb), new_r, new_g, new_b));
}

int	get_opposite(int trgb)
{
	int	new_r;
	int	new_g;
	int	new_b;

	new_r = 255 - get_r(trgb);
	new_g = 255 - get_g(trgb);
	new_b = 255 - get_b(trgb);
	return (get_trgb(get_t(trgb), new_r, new_g, new_b));
}


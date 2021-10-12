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

int	main(void)
{
	int	t = 0;
	int	r = 115;
	int g = 186;
	int b = 155;
	int	trgb;
	int	shaded;
	int	black;
	int	opposite;

	trgb = get_trgb(t, r, g, b);
	printf("Int: %d\n", trgb);
	printf("TRGB: 0X%02X%X%X%X\n", get_t(trgb), get_r(trgb), get_g(trgb), get_b(trgb));
	shaded = add_shade(trgb, 0.5);
	black = add_shade(trgb, 1);
	printf("Shaded: 0X%02X%X%X%X | Black: 0X%02X%02X%02X%02X\n", get_t(shaded), get_r(shaded), get_g(shaded), get_b(shaded), get_t(black), get_r(black), get_g(black), get_b(black));
	opposite = get_opposite(trgb);
	printf("Opposite: 0X%02X%X%X%X\n", get_t(opposite), get_r(opposite), get_g(opposite), get_b(opposite));
	return (0);
}

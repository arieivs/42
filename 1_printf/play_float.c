#include "ft_printf.h"
#include <stdio.h>

static int	ft_tail_rec_power(int nb, int power, int acc)
{
	if (power == 0)
		return (acc);
	return (ft_tail_rec_power(nb, power - 1, nb * acc));
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_tail_rec_power(nb, power, 1));
}

static int	fnum_len(float f, int precision)
{
	int	len;
	int	bef;
	int	aft;
	int	next;

	len = 0;
	if (f == 0)
		len = 1;
	if (f < 0)
		len++;
	if (f > 0)
		f *= -1;
	bef = (int)f;
	aft = (f - bef) * ft_recursive_power(10, precision);
	next = (aft * 10) - (f - bef) * ft_recursive_power(10, precision + 1);
	while (bef != 0)
	{
		len++;
		bef = bef / 10;
	}
	if (!precision && next >= 5) //rounding demands an extra digit (99.5 -> 100)
		len++;
	if (precision) //counting with the .
		len++;
	return (len + precision);
}

void	ft_putfloat_nosign(float f, int precision)
{
	int	bef;
	int	aft;
	int	next;

	if (f > 0)
		f *= -1;
	bef = (int)f;
	aft = (f - bef) * ft_recursive_power(10, precision);
	next = (aft * 10) - (f - bef) * ft_recursive_power(10, precision + 1);
	if (!precision && next >= 5)
		bef--;
	else if (next >= 5)
		aft--;
	ft_putnbr_nosign(bef);
	if (precision)
	{
		write(1, ".", 1);
		ft_putnbr_nosign(aft);
	}
}

int	main(void)
{
	float	a = 99.7358;
	int	precision = 0;
	int	len;

	ft_putfloat_nosign(a, precision);
	printf(" orig: <%.*f>\n", precision, a);
	len = fnum_len(a, precision);
	printf("just len %d len %d\n", fnum_len(a, 0), len);
	return (0);
}

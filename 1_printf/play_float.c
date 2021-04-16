#include <stdio.h>

typedef union	u_float
{
	float		f;
	struct
	{
		unsigned int	fraction : 23;
		unsigned int	exponent : 8;
		unsigned int	signal : 1;
	};
}				t_float;

typedef union	u_double
{
	double		f;
	struct
	{
		unsigned long	fraction : 52;
		unsigned long	exponent : 11;
		unsigned long	signal : 1;
	};
}				t_double;

int	ft_tail_rec_power(int nb, int power, int acc)
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

int	main(void)
{
	float		f;
	t_float		bin_f;
	int			bias_f = 127;
	float		my_f;
	double		d;
	t_double	bin_d;
	int			bias_d = 1023;
	double		my_d;

	f = -9.6754;
	d = 9.6754;
	bin_f.f = f;
	bin_d.f = d;
	printf("signal: %u, exponent: %u, fraction: %u\n", bin_f.signal, bin_f.exponent, bin_f.fraction);
	printf("signal: %u, exponent: %u, fraction: %lu\n", bin_d.signal, bin_d.exponent, bin_d.fraction);
	my_f = ft_recursive_power(-1, bin_f.signal) * (1 + bin_f.fraction / 10000000.0) * ft_recursive_power(2, bin_f.exponent - bias_f);
	my_d = ft_recursive_power(-1, bin_d.signal) * (1 + bin_d.fraction / 1000000000000000.0) * ft_recursive_power(2, bin_d.exponent - bias_d);
	printf("recreating: %f and %lf\n", my_f, my_d);
	return (0);
}

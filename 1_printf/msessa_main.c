/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msessa_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:09:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 16:18:13 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>
#include "ft_printf.h"

void	c_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF C\n");
	printf("1, %c\n", '0');
	printf("2,  %c \n", '0');
	printf("3, 10%c\n", '0');
	printf("4, %10c\n", '0');
	printf("5, -10%c\n", '0');
	printf("6, %-10c\n", '0');
	printf("7, %-10c\n", '0');
	printf("8, %*c\n", 1, '0');
	printf("9, %*c\n", 0, '0');
	printf("10, %*c\n", 2, '0');
	printf("%i \n ", printf("11,  %*c = ", -2, '0'));
	printf("12,  %*c\n", 0, '0');
	printf("%i\n", printf("13,  %*c = ", 10, '0'));
	printf("%i\n", printf("14,  %*c = ", -10, '0'));
	printf("15,  %*c%*c\n", -10, '0', 10, '1');
	printf("16,  *%c%*c\n", '0', 10, '1');
	printf("17,  %*c%c*\n", -10, '0', '1');
	printf("18,  %-10c*\n",'0');
	printf("19,  %-10c%*c%c*\n",'0', 10, '1', '2');
	printf("20,  %c%c%c*\n",'0', '1', '2');
	printf("%i\n", printf("21,  %-c%-c%c* = ", 1, '0', 0));
	printf("22,  %c\n", '0' - 256);
	printf("23,  %c\n", '0' + 256);
	printf("%i\n", printf("24,  %c = ", 0));
	printf("%i\n", printf("25,  0%c = ", 0));
	printf("26,  %c\n", -129);
	printf("27,  %c\n", 128);
	printf("28,  %-*c\n", 10, '1');
	printf("%i\n", printf("29,   -%*c* -%-*c* = ", -2, 0, 2, 0));
	printf("%i\n", printf("30,   -%-*c* -%-*c* = ", 2, 0, -2, 0));
	printf("%i\n", printf("31,   -%*c* -%-*c* = ", -1, 0, 1, 0));
	printf("%i\n", printf("32,   -%-*c* -%-*c* = ", 2, 0, -2, 0));
	printf("%i\n", printf("33,   -%-2c* -%2c* = ", 0, 0));
}

void	c_tester_ft(void)
{
	ft_printf("\n\nMY PRINTF C\n");
	ft_printf("1, %c\n", '0');
	ft_printf("2,  %c \n", '0');
	ft_printf("3, 10%c\n", '0');
	ft_printf("4, %10c\n", '0');
	ft_printf("5, -10%c\n", '0');
	ft_printf("6, %-10c\n", '0');
	ft_printf("7, %-10c\n", '0');
	ft_printf("8, %*c\n", 1, '0');
	ft_printf("9, %*c\n", 0, '0');
	ft_printf("10, %*c\n", 2, '0');
	ft_printf("%i\n", ft_printf("11,  %*c = ", -2, '0'));
	ft_printf("12,  %*c\n", 0, '0');
	ft_printf("%i\n", ft_printf("13,  %*c = ", 10, '0'));
	ft_printf("%i\n", ft_printf("14,  %*c = ", -10, '0'));
	ft_printf("15,  %*c%*c\n", -10, '0', 10, '1');
	ft_printf("%i\n", ft_printf("16,  *%c%*c = \n", '0', 10, '1'));
	ft_printf("17,  %*c%c*\n", -10, '0', '1');
	ft_printf("18,  %-10c*\n",'0');
	ft_printf("19,  %-10c%*c%c*\n",'0', 10, '1', '2');
	ft_printf("20,  %c%c%c*\n",'0', '1', '2');
	ft_printf("%i\n", ft_printf("21,  %-c%-c%c* = ", 1, '0', 0));
	ft_printf("22,  %c\n", '0' - 256);
	ft_printf("23,  %c\n", '0' + 256);
	ft_printf("%i\n", ft_printf("24,  %c = ", 0));
	ft_printf("%i\n", ft_printf("25,  0%c = ", 0));
	ft_printf("26,  %c\n", -129);
	ft_printf("27,  %c\n", 128);
	ft_printf("28,  %-*c\n", 10, '1');
	ft_printf("%i\n", ft_printf("29,   -%*c* -%-*c* = ", -2, 0, 2, 0));
	ft_printf("%i\n", ft_printf("30,   -%-*c* -%-*c* = ", 2, 0, -2, 0));
	ft_printf("%i\n", ft_printf("31,   -%*c* -%-*c* = ", -1, 0, 1, 0));
	ft_printf("%i\n", ft_printf("32,   -%-*c* -%-*c* = ", 2, 0, -2, 0));
	ft_printf("%i\n", ft_printf("33,   -%-2c* -%2c* = ", 0, 0));
}

void	d_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF\n");
	printf(" 1, %d \n", 0);
	printf(" 2, %.d \n", 0);
	printf(" 3, %-.2d \n", 0);
	printf(" 4, %-2.2d \n", 0);
	printf(" 5, %-3.2d \n", 0);
	printf(" 6, %-3.2d %10.42d \n", 0, 0);
	printf(" 7, %-3.2d %10.42d \n", 1, -1);
	printf(" 8, %-3.2d %10.42d \n", 10, -10);
	printf(" 9, *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -10);
	printf("10, *%-*.*d* *%*.*d* \n", 6, 2, 102, 10, 21, -101);
	printf("11, *%*.*d* *%*.*d* \n", -6, 2, 102, 10, 21, 101);
	printf("12, 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	printf("13, 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	printf("14, 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	printf("14BIS, 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, 1011);
	printf("15, 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	printf("16, --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	printf("17, --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	printf("18, --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	printf("19, --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("20, --0*%-0*.2d*0 0*%-0*.2d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("21, --0*%-0*.3d*0 0*%-0*.3d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("22, --0*%-0*.4d*0 0*%-0*.4d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("23,%9.2d\n", UINT_MAX);
	printf("24,%9.10d\n", UINT_MAX);
	printf("25,%10.0d\n", UINT_MAX);
	printf("26,%10.1d\n", UINT_MAX);
	printf("27,%10.2d\n", UINT_MAX);
	printf("28,%10.10d\n", UINT_MAX);
	printf("29,%11.0d\n", UINT_MAX);
	printf("30,%11.1d\n", UINT_MAX);
	printf("31,%11.2d\n", UINT_MAX);
	printf("32,%11.10d\n", UINT_MAX);
	printf("33,%-9.0d\n", UINT_MAX);
	printf("34,%-9.1d\n", UINT_MAX);
	printf("35,%-9.2d\n", UINT_MAX);
	printf("36,%-9.10d\n", UINT_MAX);
	printf("37,%-10.0d\n", UINT_MAX);
	printf("38,%-10.1d\n", UINT_MAX);
	printf("39,%-10.2d\n", UINT_MAX);
	printf("40,%-10.10d\n", UINT_MAX);
	printf("41,%-11.0d\n", UINT_MAX);
	printf("42,%-11.1d\n", UINT_MAX);
	printf("43,%-11.2d\n", UINT_MAX);
	printf("44,%-11.10d\n", UINT_MAX);
	printf("45,%09.0d\n", UINT_MAX);
	printf("46,%09.1d\n", UINT_MAX);
	printf("47,%09.2d\n", UINT_MAX);
	printf("48,%09.10d\n", UINT_MAX);
	printf("49,%010.0d\n", UINT_MAX);
	printf("50,%010.1d\n", UINT_MAX);
	printf("51,%010.2d\n", UINT_MAX);
	printf("52,%010.10d\n", UINT_MAX);
	printf("53,%011.0d\n", UINT_MAX);
	printf("54,%011.1d\n", UINT_MAX);
	printf("55,%011.2d\n", UINT_MAX);
	printf("56,%011.10d\n", UINT_MAX);
	printf("57,%09.0d\n", UINT_MAX + 1);
	printf("58,%09.1d\n", UINT_MAX + 1);
	printf("59,%09.2d\n", UINT_MAX + 1);
	printf("60,%09.10d\n", UINT_MAX + 1);
	printf("61,%010.0d\n", UINT_MAX + 1);
	printf("62,%010.1d\n", UINT_MAX + 1);
	printf("63,%010.2d\n", UINT_MAX + 1);
	printf("64,%010.10d\n", UINT_MAX + 1);
	printf("65,%011.0d\n", UINT_MAX + 1);
	printf("66,%011.1d\n", UINT_MAX + 1);
	printf("67,%011.2d\n", UINT_MAX + 1);
	printf("68,%011.10d\n", UINT_MAX + 1);
	printf("69,%.0d\n", 0);
	printf("70,%.0d\n", 5);
	printf("71,%.0d\n", 10);

	printf("72,%1.d\n", 0);
	printf("73,%2.d\n", 0);
	printf("74,%3.d\n", 0);
	printf("75,%1.1d\n", 0);
	printf("76,%1.2d\n", 0);
	printf("77,%1.3d\n", 0);
	printf("78,%1.1d\n", 0);
	printf("79,%2.2d\n", 0);
	printf("80,%3.3d\n", 0);
}

void	d_tester_ft(void)
{
	ft_printf("\n\nMYPRINTF\n");
	ft_printf(" 1, %d \n", 0);
	ft_printf(" 2, %.d \n", 0);
	ft_printf(" 3, %-.2d \n", 0);
	ft_printf(" 4, %-2.2d \n", 0);
	ft_printf(" 5, %-3.2d \n", 0);
	ft_printf(" 6, %-3.2d %10.42d \n", 0, 0);
	ft_printf(" 7, %-3.2d %10.42d \n", 1, -1);
	ft_printf(" 8, %-3.2d %10.42d \n", 10, -10);
	ft_printf(" 9, *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -10);
	 ft_printf("10, *%-*.*d* *%*.*d* \n", 6, 2, 102, 10, 21, -101);
	 ft_printf("11, *%*.*d* *%*.*d* \n", -6, 2, 102, 10, 21, 101);
	 ft_printf("12, 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	 ft_printf("13, 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	 ft_printf("14, 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	 ft_printf("14BIS, 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, 1011);
	 ft_printf("15, 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	 ft_printf("16, --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	 ft_printf("17, --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	 ft_printf("18, --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	 ft_printf("19, --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	 ft_printf("20, --0*%-0*.2d*0 0*%-0*.2d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	 ft_printf("21, --0*%-0*.3d*0 0*%-0*.3d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	 ft_printf("22, --0*%-0*.4d*0 0*%-0*.4d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	 ft_printf("23,%9.2d\n", UINT_MAX);
	 ft_printf("24,%9.10d\n", UINT_MAX);
	 ft_printf("25,%10.0d\n", UINT_MAX);
	 ft_printf("26,%10.1d\n", UINT_MAX);
	 ft_printf("27,%10.2d\n", UINT_MAX);
	 ft_printf("28,%10.10d\n", UINT_MAX);
	 ft_printf("29,%11.0d\n", UINT_MAX);
	 ft_printf("30,%11.1d\n", UINT_MAX);
	 ft_printf("31,%11.2d\n", UINT_MAX);
	 ft_printf("32,%11.10d\n", UINT_MAX);
	 ft_printf("33,%-9.0d\n", UINT_MAX);
	 ft_printf("34,%-9.1d\n", UINT_MAX);
	 ft_printf("35,%-9.2d\n", UINT_MAX);
	 ft_printf("36,%-9.10d\n", UINT_MAX);
	 ft_printf("37,%-10.0d\n", UINT_MAX);
	 ft_printf("38,%-10.1d\n", UINT_MAX);
	 ft_printf("39,%-10.2d\n", UINT_MAX);
	 ft_printf("40,%-10.10d\n", UINT_MAX);
	 ft_printf("41,%-11.0d\n", UINT_MAX);
	 ft_printf("42,%-11.1d\n", UINT_MAX);
	 ft_printf("43,%-11.2d\n", UINT_MAX);
	 ft_printf("44,%-11.10d\n", UINT_MAX);
	 ft_printf("45,%09.0d\n", UINT_MAX);
	 ft_printf("46,%09.1d\n", UINT_MAX);
	 ft_printf("47,%09.2d\n", UINT_MAX);
	 ft_printf("48,%09.10d\n", UINT_MAX);
	 ft_printf("49,%010.0d\n", UINT_MAX);
	 ft_printf("50,%010.1d\n", UINT_MAX);
	 ft_printf("51,%010.2d\n", UINT_MAX);
	 ft_printf("52,%010.10d\n", UINT_MAX);
	 ft_printf("53,%011.0d\n", UINT_MAX);
	 ft_printf("54,%011.1d\n", UINT_MAX);
	 ft_printf("55,%011.2d\n", UINT_MAX);
	 ft_printf("56,%011.10d\n", UINT_MAX);
	 ft_printf("57,%09.0d\n", UINT_MAX + 1);
	 ft_printf("58,%09.1d\n", UINT_MAX + 1);
	 ft_printf("59,%09.2d\n", UINT_MAX + 1);
	 ft_printf("60,%09.10d\n", UINT_MAX + 1);
	 ft_printf("61,%010.0d\n", UINT_MAX + 1);
	 ft_printf("62,%010.1d\n", UINT_MAX + 1);
	 ft_printf("63,%010.2d\n", UINT_MAX + 1);
	 ft_printf("64,%010.10d\n", UINT_MAX + 1);
	 ft_printf("65,%011.0d\n", UINT_MAX + 1);
	 ft_printf("66,%011.1d\n", UINT_MAX + 1);
	 ft_printf("67,%011.2d\n", UINT_MAX + 1);
	 ft_printf("68,%011.10d\n", UINT_MAX + 1);
	 ft_printf("69,%.0d\n", 0);
	 ft_printf("70,%.0d\n", 5);
	 ft_printf("71,%.0d\n", 10);

	 ft_printf("72,%1.d\n", 0);
	 ft_printf("73,%2.d\n", 0);
	 ft_printf("74,%3.d\n", 0);
	 ft_printf("75,%1.1d\n", 0);
	 ft_printf("76,%1.2d\n", 0);
	 ft_printf("77,%1.3d\n", 0);
	 ft_printf("78,%1.1d\n", 0);
	 ft_printf("79,%2.2d\n", 0);
	 ft_printf("80,%3.3d\n", 0);
}

void	x_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF X\n");
	printf(" 1, %x \n", 0);
	printf(" 2, %.x \n", 0);
	printf(" 3, %-.2x \n", 0);
	printf(" 4, %-2.2x \n", 0);
	printf(" 5, %-3.2x \n", 0);
	printf(" 6, %-3.2x %10.42x \n", 0, 0);
	printf(" 7, %-3.2x %10.42x \n", 1, -1);
	printf(" 8, %-3.2x %10.42x \n", 10, -10);
	printf(" 9, *%-*.*x* *%*.*x* \n", 4, 5, 10, 10, 21, -10);
	printf("10, *%-*.*x* *%*.*x* \n", 6, 2, 102, 10, 21, -101);
	printf("11, *%*.*x* *%*.*x* \n", -6, 2, 102, 10, 21, 101);
	printf("12, 0*%0-*.*x*0 0*%0*.*x*0 \n", 6, 2, 102, 10, 21, -101);
	printf("13, 0*%0-*.*x*0 0*%0*.*x*0 \n", 2, 6, 102, 21, 10, -101);
	printf("14, 0*%0-*x*0 0*%0*x*0 \n", 21, 1021, 21, -1011);
	printf("15, 0*%-0*.10x*0 0*%-0*.0x*0 \n", 21, 1021, 21, -1011);
	printf("16, --0*%0*.0x*0 0*%0*.10x*0-- \n", -2, 0, 21, 1);
	printf("17, --0*%0*.0x*0 0*%0*.10x*0-- \n", -21, INT_MAX, 21, INT_MIN);
	printf("18, --0*%0*.0x*0 0*%0*.10x*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	printf("19, --0*%-0*.20x*0 0*%-0*.10x*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf("20, --0*%-0*.2x*0 0*%-0*.2x*0-- \n", -21, UINT_MAX, 21, UINT_MAX + 1);
	printf("21,%9.0x\n", UINT_MAX);
	printf("22,%9.1x\n", UINT_MAX);
	printf("23,%9.2x\n", UINT_MAX);
	printf("24,%9.10x\n", UINT_MAX);
	printf("25,%10.0x\n", UINT_MAX);
	printf("26,%10.1x\n", UINT_MAX);
	printf("27,%10.2x\n", UINT_MAX);
	printf("28,%10.10x\n", UINT_MAX);
	printf("29,%11.0x\n", UINT_MAX);
	printf("30,%11.1x\n", UINT_MAX);
	printf("31,%11.2x\n", UINT_MAX);
	printf("32,%11.10x\n", UINT_MAX);
	printf("33,%-9.0x\n", UINT_MAX);
	printf("34,%-9.1x\n", UINT_MAX);
	printf("35,%-9.2x\n", UINT_MAX);
	printf("36,%-9.10x\n", UINT_MAX);
	printf("37,%-10.0x\n", UINT_MAX);
	printf("38,%-10.1x\n", UINT_MAX);
	printf("39,%-10.2x\n", UINT_MAX);
	printf("40,%-10.10x\n", UINT_MAX);
	printf("41,%-11.0x\n", UINT_MAX);
	printf("42,%-11.1x\n", UINT_MAX);
	printf("43,%-11.2x\n", UINT_MAX);
	printf("44,%-11.10x\n", UINT_MAX);
	printf("45,%09.0x\n", UINT_MAX);
	printf("46,%09.1x\n", UINT_MAX);
	printf("47,%09.2x\n", UINT_MAX);
	printf("48,%09.10x\n", UINT_MAX);
	printf("49,%010.0x\n", UINT_MAX);
	printf("50,%010.1x\n", UINT_MAX);
	printf("51,%010.2x\n", UINT_MAX);
	printf("52,%010.10x\n", UINT_MAX);
	printf("53,%011.0x\n", UINT_MAX);
	printf("54,%011.1x\n", UINT_MAX);
	printf("55,%011.2x\n", UINT_MAX);
	printf("56,%011.10x\n", UINT_MAX);
	printf("57,%09.0x\n", UINT_MAX + 1);
	printf("58,%09.1x\n", UINT_MAX + 1);
	printf("59,%09.2x\n", UINT_MAX + 1);
	printf("60,%09.10x\n", UINT_MAX + 1);
	printf("61,%010.0x\n", UINT_MAX + 1);
	printf("62,%010.1x\n", UINT_MAX + 1);
	printf("63,%010.2x\n", UINT_MAX + 1);
	printf("64,%010.10x\n", UINT_MAX + 1);
	printf("65,%011.0x\n", UINT_MAX + 1);
	printf("66,%011.1x\n", UINT_MAX + 1);
	printf("67,%011.2x\n", UINT_MAX + 1);
	printf("68,%011.10x\n", UINT_MAX + 1);
	printf("69,%.0x\n", 0);
	printf("70,%.0x\n", 5);
	printf("71,%.0x\n", 10);

	printf("72,%1.x\n", 0);
	printf("73,%2.x\n", 0);
	printf("74,%3.x\n", 0);
	printf("75,%1.1x\n", 0);
	printf("76,%1.2x\n", 0);
	printf("77,%1.3x\n", 0);
	printf("78,%1.1x\n", 0);
	printf("79,%2.2x\n", 0);
	printf("80,%3.3x\n", 0);
}

void	x_tester_ft(void)
{
	ft_printf("\n\nMYPRINTF X\n");
	ft_printf(" 1, %x \n", 0);
	ft_printf(" 2, %.x \n", 0);
	ft_printf(" 3, %-.2x \n", 0);
	ft_printf(" 4, %-2.2x \n", 0);
	ft_printf(" 5, %-3.2x \n", 0);
	ft_printf(" 6, %-3.2x %10.42x \n", 0, 0);
	ft_printf(" 7, %-3.2x %10.42x \n", 1, -1);
	ft_printf(" 8, %-3.2x %10.42x \n", 10, -10);
	ft_printf(" 9, *%-*.*x* *%*.*x* \n", 4, 5, 10, 10, 21, -10);
	ft_printf("10, *%-*.*x* *%*.*x* \n", 6, 2, 102, 10, 21, -101);
	ft_printf("11, *%*.*x* *%*.*x* \n", -6, 2, 102, 10, 21, 101);
	ft_printf("12, 0*%0-*.*x*0 0*%0*.*x*0 \n", 6, 2, 102, 10, 21, -101);
	ft_printf("13, 0*%0-*.*x*0 0*%0*.*x*0 \n", 2, 6, 102, 21, 10, -101);
	ft_printf("14, 0*%0-*x*0 0*%0*x*0 \n", 21, 1021, 21, -1011);
	ft_printf("15, 0*%-0*.10x*0 0*%-0*.0x*0 \n", 21, 1021, 21, -1011);
	ft_printf("16, --0*%0*.0x*0 0*%0*.10x*0-- \n", -2, 0, 21, 1);
	ft_printf("17, --0*%0*.0x*0 0*%0*.10x*0-- \n", -21, INT_MAX, 21, INT_MIN);
	ft_printf("18, --0*%0*.0x*0 0*%0*.10x*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	ft_printf("19, --0*%-0*.20x*0 0*%-0*.10x*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	ft_printf("20, --0*%-0*.2x*0 0*%-0*.2x*0-- \n", -21, UINT_MAX, 21, UINT_MAX + 1);
	ft_printf("21,%9.0x\n", UINT_MAX);
	ft_printf("22,%9.1x\n", UINT_MAX);
	ft_printf("23,%9.2x\n", UINT_MAX);
	ft_printf("24,%9.10x\n", UINT_MAX);
	ft_printf("25,%10.0x\n", UINT_MAX);
	ft_printf("26,%10.1x\n", UINT_MAX);
	ft_printf("27,%10.2x\n", UINT_MAX);
	ft_printf("28,%10.10x\n", UINT_MAX);
	ft_printf("29,%11.0x\n", UINT_MAX);
	ft_printf("30,%11.1x\n", UINT_MAX);
	ft_printf("31,%11.2x\n", UINT_MAX);
	ft_printf("32,%11.10x\n", UINT_MAX);
	ft_printf("33,%-9.0x\n", UINT_MAX);
	ft_printf("34,%-9.1x\n", UINT_MAX);
	ft_printf("35,%-9.2x\n", UINT_MAX);
	ft_printf("36,%-9.10x\n", UINT_MAX);
	ft_printf("37,%-10.0x\n", UINT_MAX);
	ft_printf("38,%-10.1x\n", UINT_MAX);
	ft_printf("39,%-10.2x\n", UINT_MAX);
	ft_printf("40,%-10.10x\n", UINT_MAX);
	ft_printf("41,%-11.0x\n", UINT_MAX);
	ft_printf("42,%-11.1x\n", UINT_MAX);
	ft_printf("43,%-11.2x\n", UINT_MAX);
	ft_printf("44,%-11.10x\n", UINT_MAX);
	ft_printf("45,%09.0x\n", UINT_MAX);
	ft_printf("46,%09.1x\n", UINT_MAX);
	ft_printf("47,%09.2x\n", UINT_MAX);
	ft_printf("48,%09.10x\n", UINT_MAX);
	ft_printf("49,%010.0x\n", UINT_MAX);
	ft_printf("50,%010.1x\n", UINT_MAX);
	ft_printf("51,%010.2x\n", UINT_MAX);
	ft_printf("52,%010.10x\n", UINT_MAX);
	ft_printf("53,%011.0x\n", UINT_MAX);
	ft_printf("54,%011.1x\n", UINT_MAX);
	ft_printf("55,%011.2x\n", UINT_MAX);
	ft_printf("56,%011.10x\n", UINT_MAX);
	ft_printf("57,%09.0x\n", UINT_MAX + 1);
	ft_printf("58,%09.1x\n", UINT_MAX + 1);
	ft_printf("59,%09.2x\n", UINT_MAX + 1);
	ft_printf("60,%09.10x\n", UINT_MAX + 1);
	ft_printf("61,%010.0x\n", UINT_MAX + 1);
	ft_printf("62,%010.1x\n", UINT_MAX + 1);
	ft_printf("63,%010.2x\n", UINT_MAX + 1);
	ft_printf("64,%010.10x\n", UINT_MAX + 1);
	ft_printf("65,%011.0x\n", UINT_MAX + 1);
	ft_printf("66,%011.1x\n", UINT_MAX + 1);
	ft_printf("67,%011.2x\n", UINT_MAX + 1);
	ft_printf("68,%011.10x\n", UINT_MAX + 1);
	ft_printf("69,%.0x\n", 0);
	ft_printf("70,%.0x\n", 5);
	ft_printf("71,%.0x\n", 10);

	ft_printf("72,%1.x\n", 0);
	ft_printf("73,%2.x\n", 0);
	ft_printf("74,%3.x\n", 0);
	ft_printf("75,%1.1x\n", 0);
	ft_printf("76,%1.2x\n", 0);
	ft_printf("77,%1.3x\n", 0);
	ft_printf("78,%1.1x\n", 0);
	ft_printf("79,%2.2x\n", 0);
	ft_printf("80,%3.3x\n", 0);
}

void	p_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF P\n");
	printf(" 1, %p \n", -1);
	printf(" 2, %p \n", 1);
	printf(" 3, %p \n", 15);
	printf(" 4, %p \n", 16);
	printf(" 5, %p \n", 17);
	printf(" 6, %10p %10p \n", 1, -1);
	printf(" 7, %-10p %10p \n", 1, -1);
	printf(" 8, %10p %-10p \n", 1, -1);
	printf(" 9, %-10p %-10p \n", 1, -1);
	printf("10, %10p %-10p \n", 1, -1);
	printf("11, %p %p \n", 1, -1);
	printf("12, %10p %-10p \n", 0, 0);
	printf("13, %p %p \n", LONG_MIN, LONG_MAX);
	printf("14, %p %p \n", INT_MIN, INT_MAX);
	printf("15, %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("16, %*p %-*p \n", -10, 101, -10, 42);
	printf("17, .-0*%*p %-*p*0-. \n", 11, 101, 11, 42);
}

void	p_tester_ft(void)
{
	ft_printf("\n\nMYPRINTF P\n");
	ft_printf(" 1, %p \n", -1);
	ft_printf(" 2, %p \n", 1);
	ft_printf(" 3, %p \n", 15);
	ft_printf(" 4, %p \n", 16);
	ft_printf(" 5, %p \n", 17);
	ft_printf(" 6, %10p %10p \n", 1, -1);
	ft_printf(" 7, %-10p %10p \n", 1, -1);
	ft_printf(" 8, %10p %-10p \n", 1, -1);
	ft_printf(" 9, %-10p %-10p \n", 1, -1);
	ft_printf("10, %10p %-10p \n", 1, -1);
	ft_printf("11, %p %p \n", 1, -1);
	ft_printf("12, %10p %-10p \n", 0, 0);
	ft_printf("13, %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf("14, %p %p \n", INT_MIN, INT_MAX);
	ft_printf("15, %p %p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf("16, %*p %-*p \n", -10, 101, -10, 42);
	ft_printf("17, .-0*%*p %-*p*0-. \n", 11, 101, 11, 42);
}

void	l_tester(void)
{
	long int n;

	n = 42;
	ft_printf("\n\nSTANDARD PRINTF L\n");
	printf("subcategory: d\n");
	printf(" 1, %ld \n", INT_MAX + 1);
	printf(" 2, %ld \n", INT_MIN - 1);
	printf(" 3, %ld \n", LONG_MAX + 1);
	printf(" 4, %ld \n", LONG_MIN - 1);
	printf("subcategory: i\n");
	printf(" 5, %li \n", INT_MAX + 1);
	printf(" 6, %li \n", INT_MIN - 1);
	printf(" 7, %li \n", LONG_MAX + 1);
	printf(" 8, %li \n", LONG_MIN - 1);
	printf("subcategory: u\n");
	printf(" 9, %lu \n", ULONG_MAX);
	printf("10, %lu \n", ULONG_MAX + 1);
	printf("11, %lu \n", 0 - 1);
	printf("subcategory: x\n");
	printf("12, %lx \n", ULONG_MAX);
	printf("13, %lx \n", ULONG_MAX + 1);
	printf("14, %lx \n", 0 - 1);
	printf("subcategory: X\n");
	printf("15, %lX \n", ULONG_MAX);
	printf("16, %lX \n", ULONG_MAX + 1);
	printf("17, %lX \n", 0 - 1);
	printf("subcategory: n\n");
	printf("%ln\n", &n);
	printf(" %ln \n", &n);
	printf("subcategory: c\n");
	printf("20, %lc \n", u'ƀ');
	printf("21, %lc \n", u'ɏ');
	printf("22, %lc \n", u'ɐ');
	printf("23, %lc \n", u'ʯ');
	printf("24, %lc \n", u'ʰ');
	printf("25, %lc \n", u'˿');
	printf("26, %lc \n", u'ୟ');
	printf("27, %lc \n", u'௫');
	printf("28, %lc \n", u'࿚');
	printf("subcategory: s\n");
	wchar_t	 empty[] = {0};
	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	printf("29, %ls \n", empty);
	printf("30, %ls \n", s);
}

void	l_tester_ft(void)
{
	long int n;

	n = 42;
	ft_printf("\n\nMY PRINTF L\n");
	ft_printf("subcategory: d\n");
	ft_printf(" 1, %ld \n", INT_MAX + 1);
	ft_printf(" 2, %ld \n", INT_MIN - 1);
	ft_printf(" 3, %ld \n", LONG_MAX + 1);
	ft_printf(" 4, %ld \n", LONG_MIN - 1);
	ft_printf("subcategory: i\n");
	ft_printf(" 5, %li \n", INT_MAX + 1);
	ft_printf(" 6, %li \n", INT_MIN - 1);
	ft_printf(" 7, %li \n", LONG_MAX + 1);
	ft_printf(" 8, %li \n", LONG_MIN - 1);
	ft_printf("subcategory: u\n");
	ft_printf(" 9, %lu \n", ULONG_MAX);
	ft_printf("10, %lu \n", ULONG_MAX + 1);
	ft_printf("11, %lu \n", 0 - 1);
	ft_printf("subcategory: x\n");
	ft_printf("12, %lx \n", ULONG_MAX);
	ft_printf("13, %lx \n", ULONG_MAX + 1);
	ft_printf("14, %lx \n", 0 - 1);
	ft_printf("subcategory: X\n");
	ft_printf("15, %lX \n", ULONG_MAX);
	ft_printf("16, %lX \n", ULONG_MAX + 1);
	ft_printf("17, %lX \n", 0 - 1);
	ft_printf("subcategory: n\n");
	ft_printf("%ln\n", &n);
	ft_printf(" %ln \n", &n);
	ft_printf("subcategory: c\n");
	ft_printf("20, %lc \n", u'ƀ');
	ft_printf("21, %lc \n", u'ɏ');
	ft_printf("22, %lc \n", u'ɐ');
	ft_printf("23, %lc \n", u'ʯ');
	ft_printf("24, %lc \n", u'ʰ');
	ft_printf("25, %lc \n", u'˿');
	ft_printf("26, %lc \n", u'ୟ');
	ft_printf("27, %lc \n", u'௫');
	ft_printf("28, %lc \n", u'࿚');
	ft_printf("subcategory: s\n");
	wchar_t	 empty[] = {0};
	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	ft_printf("29, %ls \n", empty);
	ft_printf("30, %ls \n", s);
}

void	sharp_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF SHARP\n");
	printf("subcategory: x\n");
	printf(" 1, %#x \n", 0);
	printf(" 2, %#2x \n", 0);
	printf(" 3, %#02x \n", 0);
	printf(" 4, %#-03x \n", 0);
	printf(" 5, %#-03.x \n", 0);
	printf(" 6, %#-03.1x \n", 0);
	printf(" 7, %#-03.2x \n", 0);
	printf(" 8, %#-03.*x \n", 2, 0);
	printf(" 9, %#x \n", 1);
	printf("10, %#2x \n", 1);
	printf("11, %#02x \n", 1);
	printf("12, %#-03x \n", 1);
	printf("13, %#-03.x \n", 1);
	printf("14, %#-03.1x \n", 1);
	printf("15, %#-03.2x \n", 1);
	printf("16, %#-03.*x \n", 2, 1);
	printf("subcategory: X\n");
	printf("17, %#X \n", 0);
	printf("18, %#2X \n", 0);
	printf("19, %#02X \n", 0);
	printf("20, %#-03X \n", 0);
	printf("21, %#-03.X \n", 0);
	printf("22, %#-03.1X \n", 0);
	printf("23, %#-03.2X \n", 0);
	printf("24, %#-03.*X \n", 2, 0);
	printf("25, %#X \n", 1);
	printf("26, %#2X \n", 1);
	printf("27, %#02X \n", 1);
	printf("28, %#-03X \n", 1);
	printf("29, %#-03.X \n", 1);
	printf("30, %#-03.1X \n", 1);
	printf("31, %#-03.2X \n", 1);
	printf("32, %#-03.*X \n", 2, 1);
	printf("subcategory: e\n");
	printf("33, %#e \n", 0.1);
	printf("34, %#2e \n", 0.1);
	printf("35, %#02e \n", 0.1);
	printf("36, %#-03e \n", 0.1);
	printf("37, %#-03.e \n", 0.1);
	printf("38, %#-03.1e \n", 0.1);
	printf("39, %#-03.2e \n", 0.1);
	printf("40, %#-03.*e \n", 2, 0.1);
	printf("41, %#e \n", 1.0);
	printf("42, %#2e \n", 1.0);
	printf("43, %#02e \n", 1.0);
	printf("44, %#-03e \n", 1.0);
	printf("45, %#-03.e \n", 1.0);
	printf("46, %#-03.1e \n", 1.0);
	printf("47, %#-03.2e \n", 1.0);
	printf("48, %#-03.*e \n", 2, 1.0);
	printf("subcategory: f\n");
	printf("49, %#f \n", 0.1);
	printf("50, %#2f \n", 0.1);
	printf("51, %#02f \n", 0.1);
	printf("52, %#-03f \n", 0.1);
	printf("53, %#-03.f \n", 0.1);
	printf("54, %#-03.1f \n", 0.1);
	printf("55, %#-03.2f \n", 0.1);
	printf("56, %#-03.*f \n", 2, 0.1);
	printf("57, %#f \n", 1.0);
	printf("58, %#2f \n", 1.0);
	printf("59, %#02f \n", 1.0);
	printf("60, %#-03f \n", 1.0);
	printf("61, %#-03.f \n", 1.0);
	printf("62, %#-03.1f \n", 1.0);
	printf("63, %#-03.2f \n", 1.0);
	printf("64, %#-03.*f \n", 2, 1.0);
	printf("subcategory: g\n");
	printf("65, %#g \n", 0.1);
	printf("66, %#2g \n", 0.1);
	printf("67, %#02g \n", 0.1);
	printf("68, %#-03g \n", 0.1);
	printf("69, %#-03.g \n", 0.1);
	printf("70, %#-03.1g \n", 0.1);
	printf("71, %#-03.2g \n", 0.1);
	printf("72, %#-03.*g \n", 2, 0.1);
	printf("73, %#g \n", 1.0);
	printf("74, %#2g \n", 1.0);
	printf("75, %#02g \n", 1.0);
	printf("76, %#-03g \n", 1.0);
	printf("77, %#-03.g \n", 1.0);
	printf("78, %#-03.1g \n", 1.0);
	printf("79, %#-03.2g \n", 1.0);
	printf("80, %#-03.*g \n", 2, 1.0);
}

void	sharp_tester_ft(void)
{
	ft_printf("\n\nMY PRINTF SHARP\n");
	ft_printf("subcategory: x\n");
	ft_printf(" 1, %#x \n", 0);
	ft_printf(" 2, %#2x \n", 0);
	ft_printf(" 3, %#02x \n", 0);
	ft_printf(" 4, %#-03x \n", 0);
	ft_printf(" 5, %#-03.x \n", 0);
	ft_printf(" 6, %#-03.1x \n", 0);
	ft_printf(" 7, %#-03.2x \n", 0);
	ft_printf(" 8, %#-03.*x \n", 2, 0);
	ft_printf(" 9, %#x \n", 1);
	ft_printf("10, %#2x \n", 1);
	ft_printf("11, %#02x \n", 1);
	ft_printf("12, %#-03x \n", 1);
	ft_printf("13, %#-03.x \n", 1);
	ft_printf("14, %#-03.1x \n", 1);
	ft_printf("15, %#-03.2x \n", 1);
	ft_printf("16, %#-03.*x \n", 2, 1);
	ft_printf("subcategory: X\n");
	ft_printf("17, %#X \n", 0);
	ft_printf("18, %#2X \n", 0);
	ft_printf("19, %#02X \n", 0);
	ft_printf("20, %#-03X \n", 0);
	ft_printf("21, %#-03.X \n", 0);
	ft_printf("22, %#-03.1X \n", 0);
	ft_printf("23, %#-03.2X \n", 0);
	ft_printf("24, %#-03.*X \n", 2, 0);
	ft_printf("25, %#X \n", 1);
	ft_printf("26, %#2X \n", 1);
	ft_printf("27, %#02X \n", 1);
	ft_printf("28, %#-03X \n", 1);
	ft_printf("29, %#-03.X \n", 1);
	ft_printf("30, %#-03.1X \n", 1);
	ft_printf("31, %#-03.2X \n", 1);
	ft_printf("32, %#-03.*X \n", 2, 1);
	ft_printf("subcategory: e\n");
	ft_printf("33, %#e \n", 0.1);
	ft_printf("34, %#2e \n", 0.1);
	ft_printf("35, %#02e \n", 0.1);
	ft_printf("36, %#-03e \n", 0.1);
	ft_printf("37, %#-03.e \n", 0.1);
	ft_printf("38, %#-03.1e \n", 0.1);
	ft_printf("39, %#-03.2e \n", 0.1);
	ft_printf("40, %#-03.*e \n", 2, 0.1);
	ft_printf("41, %#e \n", 1.0);
	ft_printf("42, %#2e \n", 1.0);
	ft_printf("43, %#02e \n", 1.0);
	ft_printf("44, %#-03e \n", 1.0);
	ft_printf("45, %#-03.e \n", 1.0);
	ft_printf("46, %#-03.1e \n", 1.0);
	ft_printf("47, %#-03.2e \n", 1.0);
	ft_printf("48, %#-03.*e \n", 2, 1.0);
	ft_printf("subcategory: f\n");
	ft_printf("49, %#f \n", 0.1);
	ft_printf("50, %#2f \n", 0.1);
	ft_printf("51, %#02f \n", 0.1);
	ft_printf("52, %#-03f \n", 0.1);
	ft_printf("53, %#-03.f \n", 0.1);
	ft_printf("54, %#-03.1f \n", 0.1);
	ft_printf("55, %#-03.2f \n", 0.1);
	ft_printf("56, %#-03.*f \n", 2, 0.1);
	ft_printf("57, %#f \n", 1.0);
	ft_printf("58, %#2f \n", 1.0);
	ft_printf("59, %#02f \n", 1.0);
	ft_printf("60, %#-03f \n", 1.0);
	ft_printf("61, %#-03.f \n", 1.0);
	ft_printf("62, %#-03.1f \n", 1.0);
	ft_printf("63, %#-03.2f \n", 1.0);
	ft_printf("64, %#-03.*f \n", 2, 1.0);
	ft_printf("subcategory: g\n");
	ft_printf("65, %#g \n", 0.1);
	ft_printf("66, %#2g \n", 0.1);
	ft_printf("67, %#02g \n", 0.1);
	ft_printf("68, %#-03g \n", 0.1);
	ft_printf("69, %#-03.g \n", 0.1);
	ft_printf("70, %#-03.1g \n", 0.1);
	ft_printf("71, %#-03.2g \n", 0.1);
	ft_printf("72, %#-03.*g \n", 2, 0.1);
	ft_printf("73, %#g \n", 1.0);
	ft_printf("74, %#2g \n", 1.0);
	ft_printf("75, %#02g \n", 1.0);
	ft_printf("76, %#-03g \n", 1.0);
	ft_printf("77, %#-03.g \n", 1.0);
	ft_printf("78, %#-03.1g \n", 1.0);
	ft_printf("79, %#-03.2g \n", 1.0);
	ft_printf("80, %#-03.*g \n", 2, 1.0);
}

void	space_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF SPACE\n");
	printf("subcategory: d\n");
	printf(" 1, p% d \n", 0);
	printf(" 2, p% 2d \n", 0);
	printf(" 3, p% 02d \n", 0);
	printf(" 4, p% -03d \n", 0);
	printf(" 5, p% -03.d \n", 0);
	printf(" 6, p% -03.1d \n", 0);
	printf(" 7, p% -03.2d \n", 0);
	printf(" 8, p% d \n", -1);
	printf(" 9, p% 2d \n", -1);
	printf("10,  % 02d \n", -1);
	printf("11,  % 03d \n", -1);
	printf("12,  % -03d \n", -1);
	printf("13,  % -03.d \n", -1);
	printf("14,  % -03.1d \n", -1);
	printf("15,  % -03.2d \n", -1);
	printf("16,  % -03.3d \n", -1);
	printf("17,  % 03.3d \n", -1);
	printf("18,  % 010.3d \n", -1);
	printf("19,  % -010.3d \n", -1);
	printf("20,  % -010.*d \n", 42, -1);
	printf("21,  % .i \n", 0);
	printf("22,  % .1i \n", 0);
	printf("23,  % .2i \n", 0);
	printf( "subcategory: i\n");
	printf("24,  % i \n", 0);
	printf("25,  % 2i \n", 0);
	printf("26,  % 02i \n", 0);
	printf("27,  % -03i \n", 0);
	printf("28,  % -03.i \n", 0);
	printf("29,  % -03.1i \n", 0);
	printf("30,  % -03.2i \n", 0);
	printf("31,  % i \n", -1);
	printf("32,  % 2i \n", -1);
	printf("33,  % 02i \n", -1);
	printf("34,  % 03i \n", -1);
	printf("35,  % -03i \n", -1);
	printf("36,  % -03.i \n", -1);
	printf("37,  % -03.1i \n", -1);
	printf("38,  % -03.2i \n", -1);
	printf("39,  % -03.3i \n", -1);
	printf("40,  % 03.3i \n", -1);
	printf("41,  % 010.3i \n", -1);
	printf("42,  % -010.3i \n", -1);
	printf("43,  % -010.*i \n", 42, -1);
	printf("44,  % .i \n", 0);
	printf("45,  % .1i \n", 0);
	printf("46,  % .2i \n", 0);
	printf("subcategory: e\n");
	printf("47,  % e \n", 0.);
	printf("48,  % 2e \n", 0.);
	printf("49,  % 02e \n", 0.);
	printf("50,  % -03e \n", 0.);
	printf("51,  % -03.e \n", 0.);
	printf("52,  % -03.1e \n", 0.);
	printf("53,  % -03.2e \n", 0.);
	printf("54,  % e \n", -1.);
	printf("55,  % 2e \n", -1.);
	printf("56,  % 02e \n", -1.);
	printf("57,  % 03e \n", -1.);
	printf("58,  % -03e \n", -1.);
	printf("59,  % -03.e \n", -1.);
	printf("60,  % -03.1e \n", -1.);
	printf("61,  % -03.2e \n", -1.);
	printf("62,  % -03.3e \n", -1.);
	printf("63,  % 03.3e \n", -1.);
	printf("64,  % 010.3e \n", -1.);
	printf("65,  % -010.3e \n", -1.);
	printf("66,  % -010.*e \n", 42, -1.);
	printf("67,  % .e \n", 0.);
	printf("68,  % .1e \n", 0.);
	printf("69,  % .2e \n", 0.);
	printf("70,  % .*e \n", 0, 0.1234567890);
	printf("71,  % .*e \n", 1, 0.1234567890);
	printf("72,  % .*e \n", 2, 0.1234567890);
	printf("73,  % .*e \n", 3, 0.1234567890);
	printf("74,  % .*e \n", 4, 0.1234567890);
	printf("75,  % .*e \n", 5, 0.1234567890);
	printf("76,  % .*e \n", 6, 0.1234567890);
	printf("subcategory: f\n");
	printf("77,  % f \n", 0.);
	printf("78,  % 2f \n", 0.);
	printf("79,  % 02f \n", 0.);
	printf("80,  % -03f \n", 0.);
	printf("81,  % -03.f \n", 0.);
	printf("82,  % -03.1f \n", 0.);
	printf("83,  % -03.2f \n", 0.);
	printf("84,  % f \n", -1.);
	printf("85,  % 2f \n", -1.);
	printf("86,  % 02f \n", -1.);
	printf("87,  % 03f \n", -1.);
	printf("88,  % -03f \n", -1.);
	printf("89,  % -03.f \n", -1.);
	printf("90,  % -03.1f \n", -1.);
	printf("91,  % -03.2f \n", -1.);
	printf("92,  % -03.3f \n", -1.);
	printf("93,  % 03.3f \n", -1.);
	printf("94,  % 010.3f \n", -1.);
	printf("95,  % -010.3f \n", -1.);
	printf("96,  % -010.*f \n", 42, -1.);
	printf("97,  % .f \n", 0.);
	printf("98,  % .1f \n", 0.);
	printf("99,  % .2f \n", 0.);
	printf("100 % .*f \n", 0, 0.1234567890);
	printf("101 % .*f \n", 1, 0.1234567890);
	printf("102 % .*f \n", 2, 0.1234567890);
	printf("103 % .*f \n", 3, 0.1234567890);
	printf("104 % .*f \n", 4, 0.1234567890);
	printf("105 % .*f \n", 5, 0.1234567890);
	printf("106 % .*f \n", 6, 0.1234567890);
	printf("subcategory: g\n");
	printf("107 % g \n", 0.);
	printf("108 % 2g \n", 0.);
	printf("109 % 02g \n", 0.);
	printf("110 % -03g \n", 0.);
	printf("111 % -03.g \n", 0.);
	printf("112 % -03.1g \n", 0.);
	printf("113 % -03.2g \n", 0.);
	printf("114 % g \n", -1.);
	printf("115 % 2g \n", -1.);
	printf("116 % 02g \n", -1.);
	printf("117 % 03g \n", -1.);
	printf("118 % -03g \n", -1.);
	printf("119 % -03.g \n", -1.);
	printf("120 % -03.1g \n", -1.);
	printf("121 % -03.2g \n", -1.);
	printf("122 % -03.3g \n", -1.);
	printf("123 % 03.3g \n", -1.);
	printf("124 % 010.3g \n", -1.);
	printf("125 % -010.3g \n", -1.);
	printf("126 % -010.*g \n", 42, -1.);
	printf("127 % .g \n", 0.);
	printf("128 % .1g \n", 0.);
	printf("129 % .2g \n", 0.);
	printf("130 % .*g \n", 0, 0.1234567890);
	printf("131 % .*g \n", 1, 0.1234567890);
	printf("132 % .*g \n", 2, 0.1234567890);
	printf("133 % .*g \n", 3, 0.1234567890);
	printf("134 % .*g \n", 4, 0.1234567890);
	printf("135 % .*g \n", 5, 0.1234567890);
	printf("136 % .*g \n", 6, 0.1234567890);
	printf("137 % .*g \n", 0, 1234567890.);
	printf("138 % .*g \n", 1, 1234567890.);
	printf("139 % .*g \n", 2, 1234567890.);
	printf("140 % .*g \n", 3, 1234567890.);
	printf("141 % .*g \n", 4, 1234567890.);
	printf("142 % .*g \n", 5, 1234567890.);
	printf("143 % .*g \n", 6, 1234567890.);
}

void	null_tester(void)
{
	int res0, res1;
	ft_printf("\n\nNULL PRINTF pointer and string\n");
	res0 = printf("null is: %10p\n", NULL);
	res1 = ft_printf("null is: %10p\n", NULL);
	printf("res0: %d, res1: %d\n", res0, res1);

	res0 = printf("null is: %10s\n", NULL);
	res1 = ft_printf("null is: %10s\n", NULL);
	printf("res0: %d, res1: %d\n", res0, res1);
}

void	space_tester_ft(void)
{
	ft_printf("\n\nMY PRINTF SPACE\n");
	ft_printf("subcategory: d\n");
	ft_printf(" 1, p% d \n", 0);
	ft_printf(" 2, p% 2d \n", 0);
	ft_printf(" 3, p% 02d \n", 0);
	ft_printf(" 4, p% -03d \n", 0);
	ft_printf(" 5, p% -03.d \n", 0);
	ft_printf(" 6, p% -03.1d \n", 0);
	ft_printf(" 7, p% -03.2d \n", 0);
	ft_printf(" 8, p% d \n", -1);
	ft_printf(" 9, p% 2d \n", -1);
	ft_printf("10,  % 02d \n", -1);
	ft_printf("11,  % 03d \n", -1);
	ft_printf("12,  % -03d \n", -1);
	ft_printf("13,  % -03.d \n", -1);
	ft_printf("14,  % -03.1d \n", -1);
	ft_printf("15,  % -03.2d \n", -1);
	ft_printf("16,  % -03.3d \n", -1);
	ft_printf("17,  % 03.3d \n", -1);
	ft_printf("18,  % 010.3d \n", -1);
	ft_printf("19,  % -010.3d \n", -1);
	ft_printf("20,  % -010.*d \n", 42, -1);
	ft_printf("21,  % .i \n", 0);
	ft_printf("22,  % .1i \n", 0);
	ft_printf("23,  % .2i \n", 0);
	ft_printf( "subcategory: i\n");
	ft_printf("24,  % i \n", 0);
	ft_printf("25,  % 2i \n", 0);
	ft_printf("26,  % 02i \n", 0);
	ft_printf("27,  % -03i \n", 0);
	ft_printf("28,  % -03.i \n", 0);
	ft_printf("29,  % -03.1i \n", 0);
	ft_printf("30,  % -03.2i \n", 0);
	ft_printf("31,  % i \n", -1);
	ft_printf("32,  % 2i \n", -1);
	ft_printf("33,  % 02i \n", -1);
	ft_printf("34,  % 03i \n", -1);
	ft_printf("35,  % -03i \n", -1);
	ft_printf("36,  % -03.i \n", -1);
	ft_printf("37,  % -03.1i \n", -1);
	ft_printf("38,  % -03.2i \n", -1);
	ft_printf("39,  % -03.3i \n", -1);
	ft_printf("40,  % 03.3i \n", -1);
	ft_printf("41,  % 010.3i \n", -1);
	ft_printf("42,  % -010.3i \n", -1);
	ft_printf("43,  % -010.*i \n", 42, -1);
	ft_printf("44,  % .i \n", 0);
	ft_printf("45,  % .1i \n", 0);
	ft_printf("46,  % .2i \n", 0);
	ft_printf("subcategory: e\n");
	ft_printf("47,  % e \n", 0.);
	ft_printf("48,  % 2e \n", 0.);
	ft_printf("49,  % 02e \n", 0.);
	ft_printf("50,  % -03e \n", 0.);
	ft_printf("51,  % -03.e \n", 0.);
	ft_printf("52,  % -03.1e \n", 0.);
	ft_printf("53,  % -03.2e \n", 0.);
	ft_printf("54,  % e \n", -1.);
	ft_printf("55,  % 2e \n", -1.);
	ft_printf("56,  % 02e \n", -1.);
	ft_printf("57,  % 03e \n", -1.);
	ft_printf("58,  % -03e \n", -1.);
	ft_printf("59,  % -03.e \n", -1.);
	ft_printf("60,  % -03.1e \n", -1.);
	ft_printf("61,  % -03.2e \n", -1.);
	ft_printf("62,  % -03.3e \n", -1.);
	ft_printf("63,  % 03.3e \n", -1.);
	ft_printf("64,  % 010.3e \n", -1.);
	ft_printf("65,  % -010.3e \n", -1.);
	ft_printf("66,  % -010.*e \n", 42, -1.);
	ft_printf("67,  % .e \n", 0.);
	ft_printf("68,  % .1e \n", 0.);
	ft_printf("69,  % .2e \n", 0.);
	ft_printf("70,  % .*e \n", 0, 0.1234567890);
	ft_printf("71,  % .*e \n", 1, 0.1234567890);
	ft_printf("72,  % .*e \n", 2, 0.1234567890);
	ft_printf("73,  % .*e \n", 3, 0.1234567890);
	ft_printf("74,  % .*e \n", 4, 0.1234567890);
	ft_printf("75,  % .*e \n", 5, 0.1234567890);
	ft_printf("76,  % .*e \n", 6, 0.1234567890);
	ft_printf("subcategory: f\n");
	ft_printf("77,  % f \n", 0.);
	ft_printf("78,  % 2f \n", 0.);
	ft_printf("79,  % 02f \n", 0.);
	ft_printf("80,  % -03f \n", 0.);
	ft_printf("81,  % -03.f \n", 0.);
	ft_printf("82,  % -03.1f \n", 0.);
	ft_printf("83,  % -03.2f \n", 0.);
	ft_printf("84,  % f \n", -1.);
	ft_printf("85,  % 2f \n", -1.);
	ft_printf("86,  % 02f \n", -1.);
	ft_printf("87,  % 03f \n", -1.);
	ft_printf("88,  % -03f \n", -1.);
	ft_printf("89,  % -03.f \n", -1.);
	ft_printf("90,  % -03.1f \n", -1.);
	ft_printf("91,  % -03.2f \n", -1.);
	ft_printf("92,  % -03.3f \n", -1.);
	ft_printf("93,  % 03.3f \n", -1.);
	ft_printf("94,  % 010.3f \n", -1.);
	ft_printf("95,  % -010.3f \n", -1.);
	ft_printf("96,  % -010.*f \n", 42, -1.);
	ft_printf("97,  % .f \n", 0.);
	ft_printf("98,  % .1f \n", 0.);
	ft_printf("99,  % .2f \n", 0.);
	ft_printf("100 % .*f \n", 0, 0.1234567890);
	ft_printf("101 % .*f \n", 1, 0.1234567890);
	ft_printf("102 % .*f \n", 2, 0.1234567890);
	ft_printf("103 % .*f \n", 3, 0.1234567890);
	ft_printf("104 % .*f \n", 4, 0.1234567890);
	ft_printf("105 % .*f \n", 5, 0.1234567890);
	ft_printf("106 % .*f \n", 6, 0.1234567890);
	ft_printf("subcategory: g\n");
	ft_printf("107 % g \n", 0.);
	ft_printf("108 % 2g \n", 0.);
	ft_printf("109 % 02g \n", 0.);
	ft_printf("110 % -03g \n", 0.);
	ft_printf("111 % -03.g \n", 0.);
	ft_printf("112 % -03.1g \n", 0.);
	ft_printf("113 % -03.2g \n", 0.);
	ft_printf("114 % g \n", -1.);
	ft_printf("115 % 2g \n", -1.);
	ft_printf("116 % 02g \n", -1.);
	ft_printf("117 % 03g \n", -1.);
	ft_printf("118 % -03g \n", -1.);
	ft_printf("119 % -03.g \n", -1.);
	ft_printf("120 % -03.1g \n", -1.);
	ft_printf("121 % -03.2g \n", -1.);
	ft_printf("122 % -03.3g \n", -1.);
	ft_printf("123 % 03.3g \n", -1.);
	ft_printf("124 % 010.3g \n", -1.);
	ft_printf("125 % -010.3g \n", -1.);
	ft_printf("126 % -010.*g \n", 42, -1.);
	ft_printf("127 % .g \n", 0.);
	ft_printf("128 % .1g \n", 0.);
	ft_printf("129 % .2g \n", 0.);
	ft_printf("130 % .*g \n", 0, 0.1234567890);
	ft_printf("131 % .*g \n", 1, 0.1234567890);
	ft_printf("132 % .*g \n", 2, 0.1234567890);
	ft_printf("133 % .*g \n", 3, 0.1234567890);
	ft_printf("134 % .*g \n", 4, 0.1234567890);
	ft_printf("135 % .*g \n", 5, 0.1234567890);
	ft_printf("136 % .*g \n", 6, 0.1234567890);
	ft_printf("137 % .*g \n", 0, 1234567890.);
	ft_printf("138 % .*g \n", 1, 1234567890.);
	ft_printf("139 % .*g \n", 2, 1234567890.);
	ft_printf("140 % .*g \n", 3, 1234567890.);
	ft_printf("141 % .*g \n", 4, 1234567890.);
	ft_printf("142 % .*g \n", 5, 1234567890.);
	ft_printf("143 % .*g \n", 6, 1234567890.);
}

void	n_tester(void)
{
	int n;

	
	printf("\n\nSTANDARD P RINTF N\n");
	printf("1, %n\n", &n);
	printf("n: %d\n", n);
	printf("1, %10n\n", &n);
	printf("n: %d\n", n);
	printf("1, %-10n\n", &n);
	printf("n: %d\n", n);
	printf("1, %.n\n", &n);
	printf("n: %d\n", n);
	printf("1, %.10n\n", &n);
	printf("n: %d\n", n);
	printf("2, %s%n\n", "tripouille", &n);
	printf("n: %d\n", n);
	printf("3, %s%n42\n", "tripouille", &n);
	printf("n: %d\n", n);
	printf("4, %s%i%n42\n", "tripouille", INT_MAX, &n);
	printf("n: %d\n", n);
	printf("5, %s%i%n42\n", "tripouille", INT_MIN, &n);
	printf("n: %d\n", n);
	printf("6, %s%x%n42\n", "tripouille", LONG_MAX, &n);
	printf("n: %d\n", n);
	printf("7, %s%x%n42\n", "tripouille", LONG_MIN, &n);
	printf("n: %d\n", n);
	printf("8, %s%x%n42\n", "", 0, &n);
	printf("n: %d\n", n);
	printf("9, n%.s%x%n \n", "42", -1, &n);
	printf("n: %d\n", n);
	printf("10,%%n%.s%x%n \n", "42", -1, &n);
	printf("n: %d\n", n);
	printf("11,%%n%.s%p%n \n", "42", (void*)1, &n);
	printf("n: %d\n", n);
	printf("12,%.s%n\n", "12345", &n);
	printf("n: %d\n", n);
	printf("13,%s%c42%n\n", "12345", 0, &n);
	printf("n: %d\n", n);
	printf("14,%s%c%i42%n\n", "12345", 0, 42, &n);
	printf("n: %d\n", n);
	printf("15,%s%c42%n\n", "12345", 'A', &n);
	printf("n: %d\n", n);
	printf("16,%s%d42%n\n", "12345", -42, &n);
	printf("n: %d\n", n);
	printf("17,%s%X42%n\n", "12345", 42, &n);
	printf("n: %d\n", n);
}

void	n_tester_ft(void)
{
	int n;

	n = 0;
	ft_printf("\n\nMY ft_PRINTF N\n");
	ft_printf("1, %n\n", &n);
	printf("n: %d\n", n);
	ft_printf("1, %10n\n", &n);
	printf("n: %d\n", n);
	ft_printf("1, %-10n\n", &n);
	printf("n: %d\n", n);
	ft_printf("1, %.n\n", &n);
	printf("n: %d\n", n);
	ft_printf("1, %.10n\n", &n);
	printf("n: %d\n", n);
	ft_printf("2, %s%n\n", "tripouille", &n);
	printf("n: %d\n", n);
	ft_printf("3, %s%n42\n", "tripouille", &n);
	printf("n: %d\n", n);
	ft_printf("4, %s%i%n42\n", "tripouille", INT_MAX, &n);
	printf("n: %d\n", n);
	ft_printf("5, %s%i%n42\n", "tripouille", INT_MIN, &n);
	printf("n: %d\n", n);
	ft_printf("6, %s%x%n42\n", "tripouille", LONG_MAX, &n);
	printf("n: %d\n", n);
	ft_printf("7, %s%x%n42\n", "tripouille", LONG_MIN, &n);
	printf("n: %d\n", n);
	ft_printf("8, %s%x%n42\n", "", 0, &n);
	printf("n: %d\n", n);
	ft_printf("9, n%.s%x%n \n", "42", -1, &n);
	printf("n: %d\n", n);
	ft_printf("10,%%n%.s%x%n \n", "42", -1, &n);
	printf("n: %d\n", n);
	ft_printf("11,%%n%.s%p%n \n", "42", (void*)1, &n);
	printf("n: %d\n", n);
	ft_printf("12,%.s%n\n", "12345", &n);
	printf("n: %d\n", n);
	ft_printf("13,%s%c42%n\n", "12345", 0, &n);
	printf("n: %d\n", n);
	ft_printf("14,%s%c%i42%n\n", "12345", 0, 42, &n);
	printf("n: %d\n", n);
	ft_printf("15,%s%c42%n\n", "12345", 'A', &n);
	printf("n: %d\n", n);
	ft_printf("16,%s%d42%n\n", "12345", -42, &n);
	printf("n: %d\n", n);
	ft_printf("17,%s%X42%n\n", "12345", 42, &n);
	printf("n: %d\n", n);
}

void	s_tester(void)
{
	ft_printf("\n\nSTANDARD PRINTF S\n");
	
	printf("1, %s", "");
	printf("\n");
	printf("2, %s", "0");
	printf("\n");
	printf("3, %s %s", "", "");
	printf("\n");
	printf("4, %s %s", "0", "1");
	printf("\n");
	printf("5,  %s %s ", "0", "1");
	printf("\n");
	printf("6,  %s %s ", "", "");
	printf("\n");
	printf("7,  %1s %1s ", "123", "4567");
	printf("\n");
	printf("8,  %4s %4s ", "123", "4567");
	printf("\n");
	printf("9,  %-4s %4s ", "123", "4567");
	printf("\n");
	printf("10, %4s %-4s ", "123", "4567");
	printf("\n");
	printf("11, %-4s %-4s ", "123", "4567");
	printf("\n");
	printf("12, %-4s %-4s ", "123", "4567");
	printf("\n");
	printf("13, %*s %*s ", 1, "123", 10, "4567");
	printf("\n");
	printf("14, *%s %*s ", "123", 10, "4567");
	printf("\n");
	printf("15, %*s %s ", 10, "123", "4567");
	printf("\n");
	printf(" = %i", printf("16, %*.s %.1s ", 10, "123", "4567"));
	printf("\n");
	printf(" = %i", printf("17, %*.0s %.2s ", 10, "123", "4567"));
	printf("\n");
	printf(" = %i", printf("18, %*.3s %.3s ", 10, "123", "4567"));
	printf("\n");
	printf("19, %*.4s %.4s ", 10, "123", "4567");
	printf("\n");
	printf("20, %*.5s %.5s ", 10, "123", "4567");
	printf("\n");
	printf("21, %*.5s %*.5s ", 10, "123", 10, "4567");
	printf("\n");
	printf("22, %*.5s %*.5s ", -10, "123", 10, "4567");
	printf("\n");
	printf("23, %*.5s %*.5s ", 10, "123", -10, "4567");
	printf("\n");
	printf("24, %*.5s %*.5s ", -10, "123", -10, "4567");
	printf("\n");
	printf("25, %10.s %1.s ", "123", "4567");
	printf("\n");
	printf("26, %0.s %0.s ", "123", "4567");
	printf("\n");
	printf("27, %.s %.s ", "123", "4567");
	printf("\n");
	printf("28, %3.3s %3.3s ", "123", "4567");
	printf("\n");
	printf("29, %4.3s %-4.3s ", "123", "4567");
	printf("\n");
	printf("30,%.s", "");
	printf("\n");
	printf("31,%.0s", "");
	printf("\n");
	printf("32,%.1s", "");
	printf("\n");
	printf("33, %4.2s %-4.2s ", "123", "4567");
	printf("\n");
	printf("34, %-3.s ", NULL);
	printf("\n");
	printf("35, %-9.1s ", NULL);
	printf("\n");
	printf("36, %.*s ", -2, NULL);
	printf("\n");
}

void	s_tester_ft(void)
{
	ft_printf("\n\nMY PRINTF S\n");
	
	ft_printf("1, %s", "");
	printf("\n");
	ft_printf("2, %s", "0");
	printf("\n");
	ft_printf("3, %s %s", "", "");
	printf("\n");
	ft_printf("4, %s %s", "0", "1");
	printf("\n");
	ft_printf("5,  %s %s ", "0", "1");
	printf("\n");
	ft_printf("6,  %s %s ", "", "");
	printf("\n");
	ft_printf("7,  %1s %1s ", "123", "4567");
	printf("\n");
	ft_printf("8,  %4s %4s ", "123", "4567");
	printf("\n");
	ft_printf("9,  %-4s %4s ", "123", "4567");
	printf("\n");
	ft_printf("10, %4s %-4s ", "123", "4567");
	printf("\n");
	ft_printf("11, %-4s %-4s ", "123", "4567");
	printf("\n");
	ft_printf("12, %-4s %-4s ", "123", "4567");
	printf("\n");
	ft_printf("13, %*s %*s ", 1, "123", 10, "4567");
	printf("\n");
	ft_printf("14, *%s %*s ", "123", 10, "4567");
	printf("\n");
	ft_printf("15, %*s %s ", 10, "123", "4567");
	printf("\n");
	ft_printf(" = %i", ft_printf("16, %*.s %.1s ", 10, "123", "4567"));
	printf("\n");
	ft_printf(" = %i", ft_printf("17, %*.0s %.2s ", 10, "123", "4567"));
	printf("\n");
	ft_printf(" = %i", ft_printf("18, %*.3s %.3s ", 10, "123", "4567"));
	printf("\n");
	ft_printf("19, %*.4s %.4s ", 10, "123", "4567");
	printf("\n");
	ft_printf("20, %*.5s %.5s ", 10, "123", "4567");
	printf("\n");
	ft_printf("21, %*.5s %*.5s ", 10, "123", 10, "4567");
	printf("\n");
	ft_printf("22, %*.5s %*.5s ", -10, "123", 10, "4567");
	printf("\n");
	ft_printf("23, %*.5s %*.5s ", 10, "123", -10, "4567");
	printf("\n");
	ft_printf("24, %*.5s %*.5s ", -10, "123", -10, "4567");
	printf("\n");
	ft_printf("25, %10.s %1.s ", "123", "4567");
	printf("\n");
	ft_printf("26, %0.s %0.s ", "123", "4567");
	printf("\n");
	ft_printf("27, %.s %.s ", "123", "4567");
	printf("\n");
	ft_printf("28, %3.3s %3.3s ", "123", "4567");
	printf("\n");
	ft_printf("29, %4.3s %-4.3s ", "123", "4567");
	printf("\n");
	ft_printf("30,%.s", "");
	printf("\n");
	ft_printf("31,%.0s", "");
	printf("\n");
	ft_printf("32,%.1s", "");
	printf("\n");
	ft_printf("33, %4.2s %-4.2s ", "123", "4567");
	printf("\n");
	ft_printf("34, %-3.s ", NULL);
	printf("\n");
	ft_printf("35, %-9.1s ", NULL);
	printf("\n");
	ft_printf("36, %.*s ", -2, NULL);
	printf("\n");
}

int		main(int argc, char **argv)
{
	if (argc == 1 || argv[1][0] == 'd')
	{
		if (argc < 3)
			d_tester();
		d_tester_ft();
	}
	if (argc == 1 || argv[1][0] == 's')
	{
		if (argc < 3)
			s_tester();
		s_tester_ft();
	}

	if (argc == 1 || argv[1][0] == 'x')
	{
		if (argc < 3)
			x_tester();
		x_tester_ft();
	}

	if (argc == 1 || argv[1][0] == 'p')
	{
		if (argc < 3)
			p_tester();
		p_tester_ft();
	}

	if (argc == 1 || argv[1][0] == 'l')
	{
		if (argc < 3)
			l_tester();
		l_tester_ft();
	}

	if (argc == 1 || argv[1][0] == 'S')
	{
		if (argc < 3)
			sharp_tester();
		sharp_tester_ft();
	}

	if (argc == 1 || argv[1][0] == ' ')
	{
		if (argc < 3)
			space_tester();
		space_tester_ft();
	}

	if (argc == 1 || argv[1][0] == 'c')
	{
		if (argc < 3)
			c_tester();
		c_tester_ft();
	}

	if (argc == 1 || argv[1][0] == 'n')
	{
		if (argc < 3)
			n_tester();
		n_tester_ft();
	}

	if (argc == 1 || !strcmp(argv[1], "null"))
	{
		null_tester();
	}

	if (argc == 1 || !strcmp(argv[1], "eval"))
	{
		printf("printf: %--00-4-i\n", 42);
		ft_printf("ft_printf: %--00-4-i\n", 42);

		printf("printf: %--00i\n", 42);
		ft_printf("ft_printf: %--00i\n", 42);
	}
	return (0);
}

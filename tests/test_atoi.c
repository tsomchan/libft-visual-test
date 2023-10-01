/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:19:10 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:19:11 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "~/include/myft.h"

void	test_atoi(const char*str)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\"\n", str);
	o = ft_atoi(str);
	l = atoi(str);
	print_result_text("output\t");
	printf("%d\t", o);
	print_result_text("libc\t");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
}

char	*increase_nbr(char *str, int inc)
{
	long int	nbr;
	// size_t	nbr;

	nbr = atoi(str);
	if (nbr > 0)
		nbr += inc;
	return (ft_itoa(nbr));
}

void	test_atoi_select(const char*str)
{
	int	o;
	int	l;

	o = ft_atoi(str);
	l = atoi(str);
	if (o != l)
	{
		print_result_text("input\t\t");
		printf("\"%s\"\n", str);
		print_result_text("output\t");
		printf("%d\t", o);
		print_result_text("libc\t");
		printf("%d ", l);
		compare_int(o, l);
	}	
}
#include <limits.h>
void	run_atoi(char **argv)
{
	char start[99]	= "-2147483648";
	char *overflow = "9999998653054364530953435954803";
	if (find_test(argv, "1", "atoi") == 1)
	{
		banner("ft_atoi", "");
		// printf("%zu\n", (size_t)-1);
		printf("INT_MIN = %d\n", (INT_MIN));
		// while (atoi(start) > 0)
			// memmove(start, increase_nbr(start, 1), 99);
		if (atoi(start) < 0)
			test_atoi(start);
		test_atoi("-2147483649");
		test_atoi("-21474836500");
		// test_atoi("test");
		test_atoi("   1844674407370955161");
		test_atoi("   -1844674407370955161");
		test_atoi("   18446744073709551614");
		test_atoi("   18446744073709551615");
		test_atoi("   18446744073709551616");
		test_atoi("   -18446744073709551614");
		test_atoi("   -18446744073709551615");
		test_atoi("   -18446744073709551616");
		test_atoi(overflow);
		test_atoi("–2147483648");
		test_atoi("–9223372036854775808");
		// test_atoi(size);
		test_atoi("123");
		test_atoi("-123");
		test_atoi("+123");
		test_atoi("--123");
		// test_atoi(" \t\r123");
		// test_atoi("- \t\r123");
		// test_atoi(" \t\r+123");
		// test_atoi(" \t\r-123");
	}
}

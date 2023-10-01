/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:29:51 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:29:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_memcmp(const void *s, const void *s2, size_t n)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | \"%s\" | %zu\n", s, s2, n);
	if ((s && s2) || n == 0)
	{
		o = ft_memcmp(s, s2, n);
		l = memcmp(s, s2, n);
		print_result_text("output\t");
		printf("%d\t", o);
		print_result_text("libc\t");
		printf("%d ", l);
		compare_int(o, l);
	}
	else 
		print_error_text("");
	divider_end();
}

void	run_memcmp(char **argv)
{
	if (find_test(argv, "1", "memcmp") == 1)
	{
		banner("ft_memcmp", "");
		test_memcmp("12345", "1234a", 5);
		test_memcmp("", "1234a", 5);
		test_memcmp("12345", "1234a", 0);
		test_memcmp("", "1234a", 0);
		test_memcmp(0, 0, 0);
		test_memcmp(0, "12345", 5);
		test_memcmp(0, 0, 5);
	}
}

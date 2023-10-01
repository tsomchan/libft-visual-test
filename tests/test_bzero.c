/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:05:41 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:05:42 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_bzero(void *s, void *s2, size_t n)
{
	size_t	ini_s;
	size_t	ini_s2;

	ini_s = strlen(s);
	ini_s2 = strlen(s2);
	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | %zu\n", s, n);
	ft_bzero(s, n);
	bzero(s2, n);
	print_result_text("output\t");
	print_null(s, ini_s);
	print_result_text("libc\t\t");
	print_null(s2, ini_s2);
	if (ini_s > ini_s2)
		compare_null(s, s2, ini_s);
	else
		compare_null(s, s2, ini_s2);
	divider_end();
}

void	run_bzero(char **argv)
{
	if (find_test(argv, "1", "bzero") == 1)
	{
		banner("ft_bzero", "add \"n\" characters of \"0\" byte");
		test_bzero((char [99]){"bbbbb"}, (char [99]){"bbbbb"}, 0);
		test_bzero((char [99]){"bbbbb"}, (char [99]){"bbbbb"}, 5);
		test_bzero((char [99]){"bbbbb"}, (char [99]){"bbbbb"}, 2);
	}
}

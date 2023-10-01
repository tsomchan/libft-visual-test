/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:22:15 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:22:16 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_isalnum(int c)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("%d (\'%c\')\n", c, c);
	o = ft_isalnum(c);
	l = isalnum(c);
	print_result_text("output\t");
	printf("%d\t", o);
	print_result_text("libc\t");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
}

void	run_isalnum(char **argv)
{
	if (find_test(argv, "1", "isalnum") == 1)
	{
		banner("ft_isalnum", "");
		test_isalnum('0');
		test_isalnum('1');
		test_isalnum('A');
		test_isalnum('a');
	}
}

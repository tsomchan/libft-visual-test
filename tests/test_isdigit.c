/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:19:05 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:19:06 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_isdigit(int c)
{
	testft_char(c, ft_isdigit(c), isdigit(c));
}

void	run_isdigit(char **argv)
{
	if (find_test(argv, "1", "isdigit") == 1)
	{
		banner("ft_isdigit", "");
		test_isdigit('0');
		test_isdigit(':');
		test_isdigit('a');
	}
}

/*
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("%d (\'%c\')\n", c, c);
	o = ft_isdigit(c);
	l = isdigit(c);
	print_result_text("output\t");
	printf("%d\t", o);
	print_result_text("libc\t");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
*/
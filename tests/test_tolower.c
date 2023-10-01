/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:19:01 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:19:02 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_tolower(int c)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("%d ('%c')\n", c, c);
	o = ft_tolower(c);
	l = tolower(c);
	print_result_text("output\t");
	printf("%d ('%c')\t", o, o);
	print_result_text("libc\t");
	printf("%d ('%c')\n", l, l);
	compare_int(o, l);
	divider_end();
}

void	run_tolower(char **argv)
{
	if (find_test(argv, "1", "tolower") == 1)
	{
		banner("ft_tolower", "");
		test_tolower('A');
		test_tolower('L');
		test_tolower('Z');
		test_tolower('1');
		test_tolower(' ');
	}
}

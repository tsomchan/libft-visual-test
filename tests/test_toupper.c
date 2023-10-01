/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:18:51 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:18:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_toupper(int c)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("%d ('%c')\n", c, c);
	o = ft_toupper(c);
	l = toupper(c);
	print_result_text("output\t");
	printf("%d ('%c')\t", o, o);
	print_result_text("libc\t");
	printf("%d ('%c')\n", l, l);
	compare_int(o, l);
	divider_end();
}

void	run_toupper(char **argv)
{
	if (find_test(argv, "1", "toupper") == 1)
	{
		banner("ft_toupper", "");
		test_toupper('a');
		test_toupper('l');
		test_toupper('z');
		test_toupper('1');
		test_toupper(' ');
	}
}

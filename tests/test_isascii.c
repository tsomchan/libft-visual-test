/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:27:22 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/05 22:39:41 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_isascii(int c)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("(\'%c\')\tdec = %d\toct = %o\n", c, c, c);
	o = ft_isascii(c);
	l = isascii(c);
	print_result_text("output\t");
	printf("%o\t", o);
	print_result_text("libc\t");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
}

void	run_isascii(char **argv)
{
	if (find_test(argv, "1", "isascii") == 1)
	{
		banner("ft_isascii", "");
		test_isascii('\0');
		test_isascii('\177');
		test_isascii(0);
		test_isascii(126);
		test_isascii(127);
		test_isascii(128);
		test_isascii(-1);
		test_isascii(3896);
	}
}

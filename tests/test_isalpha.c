/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:14:10 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:14:12 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_isalpha(int c)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("%d (\'%c\')\n", c, c);
	o = ft_isalpha(c);
	l = isalpha(c);
	print_result_text("output\t");
	printf("%d\t", o);
	print_result_text("libc\t");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
}

void	run_isalpha(char **argv)
{
	if (find_test(argv, "1", "isalpha") == 1)
	{
		banner("ft_isalpha", "");
		test_isalpha('A');
		test_isalpha('a');
		test_isalpha('0');
	}
}

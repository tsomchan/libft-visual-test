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

#include "testft.h"

void	test_isalpha(int c)
{
	testft_char(c, ft_isalpha(c), isalpha(c));
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

/*
	int	o;
	int	l;

	o = ft_isalpha(c);
	l = isalpha(c);
	divider_start();
	print_result_text("input ");
	printf("%d (\'%c\')\t", c, c);
	print_result_text("output ");
	printf("%d\t", o);
	print_result_text("libc ");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
*/
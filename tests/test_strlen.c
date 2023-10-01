/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:39:07 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:39:09 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_strlen(const char *s)
{
	size_t	o;
	size_t	l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" \n", s);
	o = ft_strlen(s);
	l = strlen(s);
	print_result_text("output\t");
	printf("%zu\t", o);
	print_result_text("libc\t");
	printf("%zu ", l);
	compare_int(o, l);
	divider_end();
}

void	run_strlen(char **argv)
{
	if (find_test(argv, "1", "strlen") == 1)
	{
		banner("ft_strlen", "");
		test_strlen("abc");
		test_strlen("1234567890");
		test_strlen("");
		test_strlen("a b c");
	}
}

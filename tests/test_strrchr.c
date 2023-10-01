/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:50:47 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/04 22:34:39 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strrchr(const char *s, int c)
{
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\"\t'%c'\n", s, c);
	o = ft_strrchr(s, c);
	l = strrchr(s, c);
	print_result_text("output\t");
	printf("\"%s\"\t", o);
	print_result_text("libc\t");
	printf("\"%s\"\n", l);
	compare_str(o, l);
	divider_end();
}

void	run_strrchr(char **argv)
{
	if (find_test(argv, "1", "strrchr") == 1)
	{
		banner("ft_strrchr", "");
		test_strrchr("teste", 1024);
		test_strrchr("abc", '\0');
		test_strrchr("1234567890", '5');
		test_strrchr("1234567890", 'A');
		test_strrchr("1234567890", 0);
		test_strrchr("A12345A", 'A');
		test_strrchr("2--2--3", '2');
		test_strrchr("2--2--3", '2' + 256);
	}
}

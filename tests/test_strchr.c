/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:50:39 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/04 22:08:41 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_strchr(const char *s, int c)
{
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\"\t'%c'\n", s, c);
	o = ft_strchr(s, c);
	l = strchr(s, c);
	print_result_text("output\t");
	printf("\"%s\"\t", o);
	print_result_text("libc\t");
	printf("\"%s\"\n", l);
	compare_str(o, l);
	divider_end();
}

void	run_strchr(char **argv)
{
	if (find_test(argv, "1", "strchr") == 1)
	{
		banner("ft_strchr", "");
		test_strchr("teste", 'e');
		test_strchr("teste", '\0');
		test_strchr("abc", 'b');
		test_strchr("1234567890", '5');
		test_strchr("1234567890", 'A');
		test_strchr("1234567890", 0);
		test_strchr("A12345A", 'A');
		test_strchr("2--2--3", '2');
		test_strchr("2--2--3", '2' + 256);
		printf("%c\n", '2' + 256);
	}
}

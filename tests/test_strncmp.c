/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:51:00 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/05 13:47:17 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strncmp(const char *s1, const char *s2, size_t n)
{
	testft_cmp(s1, s2, n, ft_strncmp(s1, s2, n), strncmp(s1, s2, n), STRNCMP);
}

void	run_strncmp(char **argv)
{
	if (find_test(argv, "1", "strncmp") == 1)
	{
		banner("ft_strncmp", "");
		test_strncmp("", "", 2);
		test_strncmp("abcd", "", 4);
		test_strncmp("", "abcd", 4);
		test_strncmp("abcd", "abed", 4);
		test_strncmp("abcd", "abed", 3);
		test_strncmp("abcd", "abed", 2);
		test_strncmp("abcd", "abed", 0);
		test_strncmp("zbcd", "abcd", 0);
		test_strncmp("abc\200", "abc\0", 6);
	}
}

/*
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\"\t\"%s\"\t%zu\n", s1, s2, n);
	o = ft_strncmp(s1, s2, n);
	l = strncmp(s1, s2, n);
	print_result_text("output\t");
	printf("%d\t", o);
	print_result_text("libc\t");
	printf("%d ", strncmp(s1, s2, n));
	compare_int(o, l);
	divider_end();
*/
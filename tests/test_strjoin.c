/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:50:18 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:50:18 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strjoin(char const *s1, char const *s2, char *p)
{
	char	*o;

	divider_start();
	print_result_text("input\t\t");
	printf("s1 = \"%s\"\t| s2 = \"%s\"\n", s1, s2);
	o = ft_strjoin(s1, s2);
	print_result_text("output\t");
	print_null(o, strlen(o) + 1);
	print_result_text("predict\t");
	print_null(p, strlen(p) + 1);
	compare_str(o, p);
	printf("\n");
	free(o);
}

void	run_strjoin(char **argv)
{
	if (find_test(argv, "2", "strjoin") == 1)
	{
		banner("ft_strjoin", "join two strings together using malloc()");
		test_strjoin("123", "abc", "123abc");
		test_strjoin((char [4]){0, '2', '3', 0}, (char [4]){'a', 'b', 'c', 0},
			"abc");
		test_strjoin((char [4]){'1', '2', '3', 0}, (char [4]){0, 'b', 'c', 0},
			"123");
	}
}

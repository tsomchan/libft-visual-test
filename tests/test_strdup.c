/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:43:52 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/03 18:33:50 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strdup(const char *s1)
{
	char	*o;
	char	*l;

	print_result_text("input\t\t");
	printf("\"%s\"\n", s1);
	if (s1)
	{
		o = ft_strdup(s1);
		l = strdup(s1);
		divider_start();
		print_result_text("output\t");
		printf("\"%s\"\t", o);
		print_result_text("libc\t");
		printf("\"%s\" ", l);
		compare_str(o, l);
		free(l);
	}
	else
		print_error_text("");
	divider_end();
}

void	run_strdup(char **argv)
{
	if (find_test(argv, "1", "strdup") == 1)
	{
		banner("ft_strdup",
			"copy a string, put it in a pointer created from malloc()");
		test_strdup("test");
		test_strdup(NULL);
	}
}

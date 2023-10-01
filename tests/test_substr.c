/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:50:10 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/06 22:50:02 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_substr(char const *s, unsigned int start, size_t len, char *p)
{
	char	*o;

	divider_start();
	print_result_text("input\t\t");
	printf("s = \"%s\"\t| start = %d\t| len = %zu\n", s, start, len);
	o = ft_substr(s, start, len);
	if (!*o)
		len = 0;
	else if (strlen(s + start) < len)
		len = strlen(s + start);
	print_result_text("output\t");
	print_null(o, len + 1);
	print_result_text("predict\t");
	print_null(p, len + 1);
	compare_str(o, p);
	divider_end();
	free(o);
}

void	run_substr(char **argv)
{
	if (find_test(argv, "2", "substr") == 1)
	{
		banner("ft_substr", "");
		test_substr("12345", 0, -1, "12345");
		test_substr("12345", 0, 42000, "12345");
		test_substr("12345", 2, 3, "345");
		test_substr("lorem ipsum dolor", 0, 10, "lorem ipsu");
		test_substr("lorem ipsum dolor", 7, 10, "psum dolor");
		test_substr("lorem ipsum dolor", 7, 0, "");
		test_substr("lorem ipsum dolor", 0, 0, "");
		test_substr("lorem ipsum dolor", 400, 20, "");
	}
}

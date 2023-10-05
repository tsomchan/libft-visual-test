/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:51:15 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:51:16 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strnstr(const char *haystack, const char *needle, size_t len)
{
	testft_strnstr(haystack, needle, len,
					ft_strnstr(haystack, needle, len),
					strnstr(haystack, needle, len));
}

void	run_strnstr(char **argv)
{
	if (find_test(argv, "1", "strnstr") == 1)
	{
		banner("ft_strnstr", "");
		test_strnstr("haystack", "sta", -1);
		test_strnstr("haystack", "hay", 6);
		test_strnstr("haystack", "sta", 6);
		test_strnstr("haystack", "", 8);
		test_strnstr("haystack", "sta", 0);
		test_strnstr("lorem ipsum dolor sit amet", "ipsum0", 30);
		test_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	}
}

/*
	char	*o;
	char	*l;

	print_result_text("input\t\t");
	printf("\"%s\"\t\"%s\"\t%zu\n", haystack, needle, len);
	o = ft_strnstr(haystack, needle, len);
	l = strnstr(haystack, needle, len);
	print_result_text("output\t");
	printf("%s\t", o);
	print_result_text("libc\t");
	printf("%s ", l);
	compare_str(o, l);
*/
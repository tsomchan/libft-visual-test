/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:39:38 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:39:39 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

char	*str_start_null(char *s)
{
	*s = 0;
	return (s);
}

void	test_strlcat(char *dst, char *dst2, const char *src, size_t dstsize)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	if (dst)
	{
		printf("dst = ");
		print_null(dst, dstsize + 1);
	}
	else
		printf("dst is NULL\n");
	printf("\t\t  src = %s | size = %zu\n", src, dstsize);
	// if (src)
	// {
		o = ft_strlcat(dst, src, dstsize);
		l = strlcat(dst2, src, dstsize);
		print_result_text("output\t");
		printf("%d ", o);
		if (dst)
			print_null(dst, dstsize + 1);
		print_result_text("libc\t\t");
		printf("%d ", l);
		if (dst2)
			print_null(dst2, dstsize + 1);
		print_compare_text("Compare int ");
		compare_int(o, l);
		print_compare_text("Compare str ");
		if (dst && dst2)
			compare_null(dst, dst2, dstsize + 1);
	// }
	// else
		// print_error_text("");
	divider_end();
}

void	run_strlcat(char **argv)
{
	if (find_test(argv, "1", "strlcat") == 1)
	{
		banner("ft_strlcat", "");
		test_strlcat(((char [15]){"A23451234512345"}),
			((char [15]){"A23451234512345"}),
			((char [99]){"lorem ipsum dolor sit amet"}), 15);
		test_strlcat(((char [15]){"A23451234512345"}),
			((char [15]){"A23451234512345"}),
			((char [99]){"lorem ipsum dolor sit amet"}), 18);
		// test_strlcat(((char [5]){"A2345"}),
		// 	((char [5]){"A2345"}),
		// 	((char [99]){"123"}), 18);
		// test_strlcat(((char [15]){"A23451234512345"}),
		// 	((char [15]){"A23451234512345"}),
		// 	((char [99]){"lorem ipsum dolor sit amet"}), 35);
		// test_strlcat(NULL, NULL, ((char [0xF]){"nyan !"}), 0);
		// test_strlcat(NULL, NULL, ((char [0xF]){"nyan !"}), 0);
		// test_strlcat(((char [0xF]){"nyan !"}), ((char [0xF]){"nyan !"}),
			// NULL, 2);
		test_strlcat(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abc", 9);
		test_strlcat(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abc", 8);
		test_strlcat(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abc", 4);
		test_strlcat(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abc", 10);
		// test_strlcat(str_start_null(((char [99]){"12345"})),
		// 	str_start_null(((char [99]){"12345"})), "abc", 10);
	}
}

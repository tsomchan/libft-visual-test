/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:39:22 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/06 15:39:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_strlcpy(char *dst, char *dst2, const char *src, size_t dstsize)
{
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("dst = \"%s\" | src = \"%s\" | size = %zu\n", dst, src, dstsize);
	if (dst && dst2 && src)
	{
		o = ft_strlcpy(dst, src, dstsize);
		l = strlcpy(dst2, src, dstsize);
		print_result_text("output\t");
		printf("%d ", o);
		print_null(dst, dstsize + 1);
		print_result_text("libc\t\t");
		printf("%d ", l);
		print_null((char *)dst2, dstsize + 1);
		print_compare_text("Compare int ");
		compare_int(o, l);
		print_compare_text("Compare str ");
		compare_null(dst, (char *)dst2, dstsize + 1);
	}
	else
		print_error_text("");
	divider_end();
}

void	test_strlcpy_segfault(char *dst, const char *src, size_t dstsize)
{
	int	o;

	divider_start();
	print_result_text("input\t\t");
	printf("dst = \"%s\" | src = \"%s\" | size = %zu\n", dst, src, dstsize);
	o = ft_strlcpy(dst, src, dstsize);
	print_result_text("output\t");
	printcolor("why no segfault?\n", "red");
	divider_end();
}

void	run_strlcpy(char **argv)
{
	if (find_test(argv, "1", "strlcpy") == 1)
	{
		banner("ft_strlcpy", "");
		test_strlcpy(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abcdefghij", 11);
		test_strlcpy(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abcde", 6);
		test_strlcpy(((char [99]){"12345"}), ((char [99]){"12345"}),
			"", 6);
		test_strlcpy(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abcde", 5);
		test_strlcpy(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abcdefghij", 3);
		test_strlcpy(((char [99]){"12345"}), ((char [99]){"12345"}),
			"abcdefghij", 0);
		// test_strlcpy_segfault(NULL, NULL, 3);
	}
}

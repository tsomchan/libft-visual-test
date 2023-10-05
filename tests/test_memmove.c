/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:06:00 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/06 22:35:16 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_memmove(void *dst, void *dst2,
			const void *src, const void *src2, size_t n)
{
	testft_mem_arr(dst, dst2, src, src2, n, MEMMOVE);
}

void	test_memmove_lib(void *dst, const void *src, size_t n)
{
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | \"%s\" | %zu\n", dst, src, n);
	l = memmove(dst, src, n);
	print_result_text("libc\t");
	printf("%s\n", l);
	divider_end();
}

void	run_memmove(char **argv)
{
	char	*mem_s1;
	char	*mem_s2;

	if (find_test(argv, "1", "memmove") == 1)
	{
		mem_s1 = "12345";
		mem_s2 = "12345";
		banner("ft_memmove", "");
		test_memmove((char [12]){"lorem ipsum"}, (char [12]){"lorem ipsum"},
			"M", "M", 1);
		test_memmove(mem_s1, mem_s1, mem_s2, mem_s2, 10);
		// test_memmove((char [99]){"12345"}, (char [99]){"12345"},
		// 	"M", "M", 128 * 1024 * 1024);
		test_memmove(NULL, NULL, NULL, NULL, 3);
		test_memmove(NULL, NULL, NULL, NULL, 0);
		test_memmove((char [99]){"12345"}, (char [99]){"12345"},
			"M", "M", 1);
		test_memmove((char [99]){"12345"}, (char [99]){"12345"},
			"AEIOU", "AEIOU", 5);
		test_memmove((char [99]){"12345"}, (char [99]){"12345"},
			"AEIOU", "AEIOU", 0);
		test_memmove((char [99]){"12345"}, (char [99]){"12345"},
			"AEIOUAEIOU", "AEIOUAEIOU", 10);
		// test_memmove_lib(mem_s1 + 1, mem_s1, 4);
	}
}

/*
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | \"%s\" | %zu\n", dst, src, n);
	if ((dst && dst2) || (src && src2))
	{
		// if (!check_overlap(dst, (void *)src) && !check_overlap(dst, (void *)dst2))
		// {
		o = ft_memmove(dst, src, n);
		l = memmove(dst2, src2, n);
		print_result_text("output\t");
		printf("%s + '%c'\t", o, o[strlen(o)]);
		print_result_text("libc\t");
		printf("%s + '%c'\n", l, l[strlen(l)]);
		compare_str(o, l);
		// }
		// else
		// {
		// 	printcolor("| ", "blue");
		// 	printcolor("ERROR!\n", "yellow");
		// }
	}
	else
	{
		o = ft_memmove(dst, src, n);
		l = memmove(dst2, src2, n);
		print_result_text("output\t");
		printf("%s\t", o);
		print_result_text("libc\t");
		printf("%s\n", l);
		// compare_mem(o, l, 1);
	}
	divider_end();
*/
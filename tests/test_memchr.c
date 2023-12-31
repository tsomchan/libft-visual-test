/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:29:30 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:29:32 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_memchr(const void *s, const void *s2, int c, size_t n)
{
	testft_mem_chr((void *)s, c, n, ft_memchr(s, c, n), memchr(s2, c, n));
}

void	test_memchr_arr(const void *s, const void *s2, int c, size_t n)
{
	int	*o;
	int	*l;

	print_result_text("input ");
	printf("\"%s\" | '%c' | %zu\n", s, c, n);
	if (n > 0 && s && s2)
	{
		o = (int *)ft_memchr(s, c, n);
		l = (int *)memchr(s2, c, n);
		print_result_text("o ");
		if (o)
			print_arr(o, n);
		printf("\n");
		print_result_text("l ");
		if (l)
			print_arr(l, n);
		// printf("\n");
		// if ((!o && l) || (o && !l))
		if (o && l)
			compare_arr(o, l, n);
		else
		{
			printcolor("| ", BLUE);
			printcolor("XX-FALSE-XX\n", "red");
		}
	}
	else 
		print_error_text("");
	printf("\n");
}

//     int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
//     printf("%s", (char *)ft_memchr(tab, -1, 7));
void	run_memchr(char **argv)
{
	if (find_test(argv, "1", "memchr") == 1)
	{
		banner("ft_memchr", "");
		test_memchr((char [99]){"12345"}, (char [99]){"12345"}, '3', 3);
		test_memchr((char [99]){"12345"}, (char [99]){"12345"}, '3', 3);
		test_memchr((char [99]){"12345"}, (char [99]){"12345"}, '3', 3);
		test_memchr_arr((int [7]){-49, 49, 1, -1, 0, -2, 0}, (int [7]){-49, 49, 1, -1, 0, -2, 0}, -1, 6);
	}
}

/*
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | '%c' | %zu\n", s, c, n);
	if (n > 0 && s && s2)
	{
		o = ft_memchr(s, c, n);
		l = memchr(s2, c, n);
		print_result_text("output\t");
		printf("\"%s\"\t", o);
		print_result_text("libc\t");
		printf("\"%s\" ", l);
		compare_str(o, l);
	}
	else 
		print_error_text("");
	divider_end();
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:05:51 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/06 14:34:27 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_memcpy(void *dst, void *dst2, const void *src, const void *src2,
			size_t n)
{
	testft_mem_arr(dst, dst2, src, src2, n, MEMCPY);
}

void	run_memcpy(char **argv)
{
	char	*mem_s1;
	char	*mem_s2;

	if (find_test(argv, "1", "memcpy") == 1)
	{
		banner("ft_memcpy", "");
		test_memcpy(NULL, NULL, NULL, NULL, 1);
		test_memcpy((char [99]){"12345"}, (char [99]){"12345"},
					"M", "M", 1);
		test_memcpy((char [99]){"12345"}, (char [99]){"12345"},
					"AEIOU", "AEIOU", 5);
		test_memcpy((char [99]){"12345"}, (char [99]){"12345"},
			"AEIOUAEIOU", "AEIOUAEIOU", 10);
		
		mem_s1 = strdup("12345");
		mem_s2 = strdup("12345");
		test_memcpy(mem_s1, mem_s2,
					mem_s1 + 1, mem_s2 + 1, 5);
		
		free(mem_s1); mem_s1 = strdup("12345");
		free(mem_s2); mem_s2 = strdup("12345");
		test_memcpy(mem_s1, mem_s2,
					mem_s1, mem_s2, 5);
		
		free(mem_s1); mem_s1 = strdup("12345");
		free(mem_s2); mem_s2 = strdup("12345");
		test_memcpy(mem_s1 + 1, mem_s2 + 1,
					mem_s1, mem_s2, 5);
		free(mem_s1);	free(mem_s2);
	}
}

/*
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | \"%s\" | %zu\n", dst, src, n);
	if ((dst && dst2) || src)
	{
		if (!check_overlap(dst, (void *)src) && !check_overlap(dst, (void *)dst2))
		{
			o = ft_memcpy(dst, src, n);
			l = memcpy(dst2, src, n);
			print_result_text("output\t");
			printf("%s + '%c'\t", o, o[strlen(o)]);
			print_result_text("libc\t");
			printf("%s + '%c'\n", l, l[strlen(l)]);
			compare_str(o, l);
		}
		else
		{
			printcolor("| ", "blue");
			printcolor("ERROR!\n", "yellow");
		}
	}
	else
	{
		o = ft_memcpy(dst, src, n);
		l = memcpy(dst2, src, n);
		print_result_text("output\t");
		printf("%s\t", o);
		print_result_text("libc\t");
		printf("%s\n", l);
		// compare_mem(o, l, n);
	}
	divider_end();
*/
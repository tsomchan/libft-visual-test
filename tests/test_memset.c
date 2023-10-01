/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:05:24 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 21:05:26 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_memset_str(void *b, void *b2, int c, size_t len)
{
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("\"%s\" | '%c' | %zu\n", b, c, len);
	o = ft_memset(b, c, len);
	l = memset(b2, c, len);
	print_result_text("output\t");
	printf("%s + '%c'\t", o, o[strlen(o)]);
	print_result_text("libc\t");
	printf("%s + '%c' ", l, l[strlen(l)]);
	compare_str(o, l);
	divider_end();
}

void	run_memset(char **argv)
{
	if (find_test(argv, "1", "memset") == 1)
	{
		banner("ft_memset", "");
		test_memset_str((char [99]){"12345"}, (char [99]){"12345"}, 'M', 2);
		test_memset_str((char [99]){"12345"}, (char [99]){"12345"}, 'M', 10);
	}
}

// void	test_memset_arr(void *b, void *b2, int c, size_t len)
// {
// 	divider_start();
// 	printf("input		: ");
// 	print_arr(b, len);
// 	print_arr(b2, len);
// 	printf(" | c = %d | len = %zu\n", c, len);
// 	memset(b2, c, len);
// 	ft_memset(b, c, len);
// 	printf("libc		: ");
// 	print_arr(b2, len);
// 	printf("\n");
// 	printf("output	: ");
// 	print_arr(b, len);
// 	printf("\n");
// 	divider_end();
// }
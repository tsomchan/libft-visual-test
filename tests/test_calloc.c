/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:43:43 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/05 17:00:42 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_calloc(size_t count, size_t size, void *str)
{
	void	*o;
	void	*l;

	o = ft_calloc(count, size);
	l = calloc(count, size);
	testft_calloc(count, size, str, o, l);
	free(o);
	free(l);
}

void	print_intl_arr(int long *arr, int size)
{
	printf("{");
	while (size > 0)
	{
		printf("%ld", *arr);
		if (size != 1)
			printf(", ");
		arr++;
		size--;
	}
	printf("} ");
}

void	put_intl(int long *dst, int long *src, int size)
{
	while (size-- > 0)
		*(dst++) = *(src++);
}

void	test_calloc_intl(size_t count, size_t size, int long *intl)
{
	int long	*o;
	int long	*l;

	print_result_text("input ");
	printf("count = %zu | size = %zu | intl = ", count, size);
	print_intl_arr(intl, count); printf("\n");
	o = ft_calloc(count, size);
	l = calloc(count, size);
	if (intl != 0)
	{
		put_intl(o, intl, count);
		put_intl(l, intl, count);
	}
	else
	{
		o = 0;
		l = 0;
	}
	print_result_text("o ");
	print_intl_arr(o, count);
	print_result_text("l ");
	print_intl_arr(l, count);
	compare_mem(o, l, count);
	printf("\n");
	divider_end();
	free(o);
	free(l);
}

void	run_calloc(char **argv)
{
	if (find_test(argv, "1", "calloc") == 1)
	{
		banner("ft_calloc", "");
		
		test_calloc(6, sizeof(char), "12345");
		test_calloc(1, sizeof(char), "");
		test_calloc(10, 0, 0);
		test_calloc(10, 0, "");
		test_calloc(1, 1, 0);
		test_calloc(6, sizeof(char), "12345");
		test_calloc(1, sizeof(char), "");
		test_calloc(10, 0, 0);
		test_calloc(10, 0, "");
		test_calloc(1, 1, 0);
		test_calloc_intl(10, sizeof(int long),
		 	(int long[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
		test_calloc_intl(10, sizeof(int long),
		 	(int long[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
		test_calloc_intl(10, sizeof(int long),
		 	(int long[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
		test_calloc_intl(10, sizeof(int long),
		 	(int long[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
		// test_calloc(10, 8, "1234567812345678123456781234567812345678123456781234567812345678123456781234567");
	}
}

/* void	*o;
	void	*l;

	print_result_text("input\t\t");
	printf("count = %zu | size = %zu | str = \"%s\"\n", count, size, str);
	o = ft_calloc(count, size);
	l = calloc(count, size);
	if (str != 0 && count > 0 && size > 0)
	{
		memcpy(o, str, count);
		memcpy(l, str, count);
	}
	print_result_text("o ");
	if (str != 0 && count > 0 && size > 0)
		printf("\"%s\"\n", o);
	else
		printf("\"not used\"\n");
	print_result_text("l ");
	if (str != 0 && count > 0 && size > 0)
		printf("\"%s\"\n", l);
	else
		printf("\"not used\"\n");
	compare_mem(o, l, count);
	printf("\n");
	free(o);
	free(l);
*/
/*
	void *a;	
	a = malloc(0);
	printf("%p\n", a);
	*(unsigned char *)a = 'x';
	printf("'%c'\n", (unsigned char)a);
	
*/
/*
	i = 0;
	while (i <= size)
	{
		o[i] = str[i];
		i++;
	}
	i = 0;
	while (i <= size)
	{
		l[i] = str[i];
		i++;
	}
*/
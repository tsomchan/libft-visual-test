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

#include "myft.h"

void	test_calloc(size_t count, size_t size, void *str)
{
	void	*o;
	void	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("count = %zu | size = %zu | str = \"%s\"\n", count, size, str);
	o = ft_calloc(count, size);
	l = calloc(count, size);
	if (str != 0 && count > 0 && size > 0)
	{
		memcpy(o, str, count);
		memcpy(l, str, count);
	}
	print_result_text("output\t");
	if (str != 0 && count > 0 && size > 0)
		printf("\"%s\"\n", o);
	else
		printf("\"not used\"\n");
	print_result_text("libc\t\t");
	if (str != 0 && count > 0 && size > 0)
		printf("\"%s\"\n", l);
	else
		printf("\"not used\"\n");
	compare_mem(o, l, count);
	divider_end();
	free(o);
	free(l);
}

void	test_calloc_str(size_t count, size_t size, char *str)
{
	char	*o;
	char	*l;

	divider_start();
	print_result_text("input\t\t");
	printf("count = %zu | size = %zu | str = \"%s\"\n", count, size, str);
	o = ft_calloc(count, size);
	l = calloc(count, size);
	if (str != 0 && count > 0 && size > 0)
	{
		memcpy(o, str, count);
		memcpy(l, str, count);
	}
	print_result_text("output\t");
	if (str != 0 && count > 0 && size > 0)
		printf("\"%s\"\n", o);
	else
		printf("\"not used\"\n");
	print_result_text("libc\t\t");
	if (str != 0 && count > 0 && size > 0)
		printf("\"%s\"\n", l);
	else
		printf("\"not used\"\n");
	if (str != 0 && count > 0 && size > 0)
		// compare_str(o, l);
	compare_mem(o, l, count);
	// if (memcmp(o, l, count * size) == 0)
	// 	printf("EQUAL\n");
	// else
	// 	printf("NOT EQUAL\n");
	divider_end();
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
	printf("}");
	printf("\n");
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

	divider_start();
	print_result_text("input\t\t");
	printf("count = %zu | size = %zu | \n\t\t  intl = ", count, size);
	print_intl_arr(intl, count);
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
	print_result_text("output\t");
	// printf("\"%s\"\n", o);
	print_intl_arr(o, count);
	print_result_text("libc\t\t");
	// printf("\"%s\"\n", l);
	print_intl_arr(l, count);
	compare_mem(o, l, count);
	divider_end();
	free(o);
	free(l);

}

void	run_calloc(char **argv)
{
	if (find_test(argv, "1", "calloc") == 1)
	{
		banner("ft_calloc", "");
		
		test_calloc_str(6, sizeof(char), "12345");
		test_calloc_str(1, sizeof(char), "");
		test_calloc_str(10, 0, 0);
		test_calloc_str(10, 0, "");
		test_calloc_str(1, 1, 0);
		test_calloc_intl(10, sizeof(int long),
		 	(int long[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
		test_calloc_intl(10, sizeof(int long),
		 	(int long[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
		// test_calloc_str(6, sizeof(char), "12345");
		// test_calloc_str(1, sizeof(char), "");
		// test_calloc_str(10, 0, 0);
		// test_calloc_str(10, 0, "");
		// test_calloc_str(1, 1, 0);
		// test_calloc_intl(10, sizeof(int long),
		//  	(int long[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
		// test_calloc_intl(10, sizeof(int long),
		//  	(int long[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
		// test_calloc_str(10, 8, "1234567812345678123456781234567812345678123456781234567812345678123456781234567");
	}
}

/*
	void *a;	
	a = malloc(0);
	printf("%p\n", a);
	*(unsigned char *)a = 'x';
	printf("'%c'\n", (unsigned char)a);
	divider_end();
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
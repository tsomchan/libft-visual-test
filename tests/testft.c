/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:24:13 by tsomchan          #+#    #+#             */
/*   Updated: 2023/10/04 14:24:14 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	printspace(char *s, int n)
{
	int size;

	size = 0;
	if (!s)
		size += 6;
	if (s)
		while (*(s++))
			size += 1;
	while (size++ < n)
		printf(" ");
}

void	printspace_null(char *s, unsigned int n, int space)
{
	int size;

	size = 0;
	while (n--)
	{
		if  (*s == '\0' && *(s + 1) != '\0')
			size += 4;
		else if (*s == '\0')
			size += 3;
		else
			size += 1;
		s++;
	}
	while (space-- > size)
		printf(" ");
}

void	testft_char(int c, int o, int l)
{
	print_result_text("input ");	printf("%d\t(\'%c\')\t", c, c);
	print_result_text("output ");	printf("%d\t", o);
	print_result_text("libc ");		printf("%d ", l);
	compare_int(o, l);
	printf("\n");
}

void	testft_len(const char *s)
{
	size_t	o;
	size_t	l;
	char	*o_str;
	char	*l_str;

	print_result_text("input ");	printf("\"%s\" \t", s);
	printspace((char *)s, 8);		printf("\t");
	o = ft_strlen(s);
	l = strlen(s);
	o_str = ft_itoa(o);
	l_str = ft_itoa(l);
	print_result_text("o ");	printf("%zu", o);
	printspace(o_str, 3);	printf("\t");
	print_result_text("l ");	printf("%zu", l);
	printspace(l_str, 3);	printf("\t");
	compare_int(o, l);
	printf("\n");
	free(o_str);
	free(l_str);
}

void	testft_atoi(const char *str)
{
	int	o;
	int	l;
	char	*o_str;
	char	*l_str;

	print_result_text("input\t");
	printf("\"%s\"", str);
	printspace((char *)str, 30);
	printf("\t");
	o = ft_atoi(str);
	l = atoi(str);
	o_str = ft_itoa(o);
	l_str = ft_itoa(l);
	print_result_text("o "); printspace(o_str, 12); printf("%d ", o);
	print_result_text("l "); printspace(l_str, 12); printf("%d ", l);
	compare_int(o, l);
	printf("\n");
	free(o_str);
	free(l_str);
}

void testft_strl(char *dst, char *dst2, const char *src, size_t dstsize,
		size_t (f1)(char *, const char*, size_t), size_t (f2)(char *, const char*, size_t))
{
	int	o;
	int	l;
	char	*o_str;
	char	*l_str;

	o_str = NULL;
	l_str = NULL;
	print_result_text("input\t");
	printf("dst = \"%s\" | src = \"%s\" | size = %zu\n", dst, src, dstsize);
	if (dst && dst2 && src)
	{
		o = f1(dst, src, dstsize);
		l = f2(dst2, src, dstsize);
		o_str = ft_itoa(o);
		l_str = ft_itoa(l);
		print_result_text("o "); printf("%d ", o);	printspace(o_str, 3);
		print_null(dst, dstsize + 1);				printspace_null((char *)dst, dstsize + 1, 20);	//printf("\t");
		print_result_text("l "); printf("%d ", l);	printspace(l_str, 3);
		print_null((char *)dst2, dstsize + 1);		printspace_null((char *)dst2, dstsize + 1, 20);	//printf("\t");
		// printf("\n");
		print_compare_text("Int "); compare_int(o, l);
		print_compare_text("Str "); compare_null(dst, (char *)dst2, dstsize + 1);
	}
	else
		print_error_text("");
	printf("\n");
	divider_end();
	free(o_str);
	free(l_str);
}

void testft_bzero(void *s, void *s2, size_t n)
{
	size_t	ini_s;
	size_t	ini_s2;
	char	*n_str;

	n_str = ft_itoa(n);
	ini_s = strlen(s);
	ini_s2 = strlen(s2);
	print_result_text("input ");
	printf("\"%s\" ", s);	printspace(s, 10);
	printf("| %zu ", n);	printspace(n_str, 2);
	ft_bzero(s, n);
	bzero(s2, n);
	print_result_text("o "); print_null(s, ini_s);
						printspace_null(s, ini_s, 16);
	print_result_text("l "); print_null(s2, ini_s2);
						printspace_null(s2, ini_s2, 16);
	if (ini_s > ini_s2)
		compare_null(s, s2, ini_s);
	else
		compare_null(s, s2, ini_s2);
	printf("\n");
	free(n_str);
}

void testft_mem_chr(void *b, int c, size_t len, void *o, void *l)
{
	char *len_str;

	len_str = ft_itoa(len);
	divider_start();
	print_result_text("input ");
	printf("\"%s\" ", b);							printspace(b, 10);
	printf("| '%c' | %zu ", c, len);				printspace(len_str, 3);
	print_result_text("o ");	printf("%s", o);	printspace(o, 15);
	print_result_text("l ");	printf("%s", l);	printspace(o, 15);
	compare_str(o, l);
	printf("\n");
	free(len_str);
}

/*
	print_result_text("o ");	printf("%s + '%c'", o, o[strlen(o)]);
								printspace(o, 15);
	print_result_text("l ");	printf("%s + '%c'", l, l[strlen(l)]);
								printspace(o, 15);
*/

void testft_mem_arr(void *dst, void *dst2, const void *src, const void *src2,
		size_t len, char *ftname)
{
	char	*o;
	char	*l;
	char *len_str;

	len_str = ft_itoa(len);
	print_result_text("input ");
	printf("\"%s\" ", dst);		printspace(dst, 12);
	printf("| \"%s\" ", src);	printspace((char *)src, 12);
	printf("| %zu", len);		printspace(len_str, 3);
	o = NULL;	l = NULL;
	if (!strcmp(ftname, MEMCPY) && check_overlap(dst, (void *)src) && dst > src)
		{ printcolor("| ", BLUE); printcolor("OVERLAP", YELLOW); }
	else
	{
		if (!strcmp(ftname, MEMCPY))
			{o = ft_memcpy(dst, src, len); l = memcpy(dst2, src2, len); }
		else if (!strcmp(ftname, MEMMOVE))
			{o = ft_memmove(dst, src, len);	l = memmove(dst2, src2, len);}
		print_result_text("o ");
		printf("%s", o);	printspace(o, 12);
		print_result_text("l ");
		printf("%s", l);	printspace(l, 12);
		compare_str(o, l);
	}
	printf("\n");
	free(len_str);
}

void testft_strchr(const char*s, int c, char *o, char *l)
{
	print_result_text("input ");
	printf("\"%s\"", s);	printspace((char *)s, 15);
	if ((!isprint(c) && c <= CHAR_MAX)) printf(" ");
	if ((!isprint(c) && c > 500)) printf(" ");
	printf("'%c' ", c);
	print_result_text("o "); printf("\"%s\"", o);	printspace(o, 12);
	print_result_text("l "); printf("\"%s\"", l);	printspace(l, 12);
	compare_str(o, l);
	printf("\n");
}

void testft_strnstr(const char *haystack, const char *needle, size_t len,
						char *o, char *l)
{
	char *len_str;

	len_str = ft_itoa(len);
	print_result_text("input ");
	printf("\"%s\"", haystack);	printspace((char *)haystack, 30);
	printf("\"%s\"", needle);	printspace((char *)needle, 10);
	if (len + 1 == 0)
		{printf("-1");					printspace("-1", 4);}
	else
		{printf("%zu", len);			printspace(len_str, 4);}
	print_result_text("o "); printf("%s", o); printspace(o, 10);
	print_result_text("l "); printf("%s", l); printspace(l, 10);
	compare_str(o, l);
	printf("\n");
	free(len_str);
}

void testft_cmp(const char *s1, const char *s2, size_t n, int o, int l,
				char *ftname)
{
	char	*n_str;
	char	*o_str;
	char	*l_str;

	n_str = ft_itoa(n);
	o_str = ft_itoa(o);
	l_str = ft_itoa(l);
	print_result_text("input ");
	printf("\"%s\"", s1);		printspace((char *)s1, 10);
	printf("\"%s\"", s2);		printspace((char *)s2, 10);
	printf("%zu", n);			printspace(n_str, 3);
	if (!strcmp(ftname, MEMCMP) && (((!s1 || !s2)) && n != 0))
		print_error_text("");
	else
	{
		print_result_text("o ");	printspace(o_str, 5); printf("%d ", o);
		print_result_text("l ");	printspace(l_str, 5); printf("%d ", l);
		compare_int(o, l);
	}
	printf("\n");
	free(n_str);
	free(o_str);
	free(l_str);
}

void testft_calloc(size_t count, size_t size, void *str, void *o, void *l)
{
	char	*count_str;
	char	*size_str;

	count_str = ft_itoa(count);
	size_str = ft_itoa(size);
	print_result_text("input ");
	printf("count = %zu", count);		printspace(count_str, 5);
	printf("| size = %zu", size);		printspace(size_str, 5);
	printf("| str = \"%s\"", str);	printspace(str, 15); printf("\n");
	if (str != 0 && count > 0 && size > 0)
		{ memcpy(o, str, count); memcpy(l, str, count); }
	else if (str == 0 || count == 0 || size == 0)
		{ o = "not used"; l = "not used"; }
	print_result_text("o "); printf("\"%s\"", o);	printspace(o, 15);
	print_result_text("l "); printf("\"%s\"", l);	printspace(l, 15);
	compare_mem(o, l, count);
	printf("\n");
	divider_end();
	free(count_str);
	free(size_str);
}

void testft_strdup(const char *s1, char *o, char *l)
{
	print_result_text("input "); printf("\"%s\" ", s1); printspace((char *)s1, 10);
	if (s1)
	{
		divider_start();
		print_result_text("o "); printf("\"%s\"", o);	printspace(o, 10);
		print_result_text("l "); printf("\"%s\" ", l);	printspace(l, 10);
		compare_str(o, l);
	}
	else
		print_error_text("");
	printf("\n");
}
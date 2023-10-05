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

void	printspace_n(int space)
{
	while (space--)
		printf(" ");
}

int	count_space(char *s, int space)
{
	int size;
	int count;

	size = 0;
	if (!s)
		size += 6;
	if (s)
		while (*(s++))
			size += 1;
	count = 0;
	while (size++ < space)
		count++;
	return (count);
}

int	count_space_null(char *s, unsigned int len, int space)
{
	int size;
	int count;

	size = 0;
	while (len--)
	{
		if  (*s == '\0' && *(s + 1) != '\0')
			size += 4;
		else if (*s == '\0')
			size += 3;
		else
			size += 1;
		s++;
	}
	count = 0;
	while (space-- > size)
		count++;
	return (count);
}

void	print_result(char *data_type, void *input, int space)
{
	unsigned char	*data;
	int				*number;

	data = NULL;
	number = NULL;
	if (!strcmp(data_type, STR) || !strcmp(data_type, CHAR))
	{
		data = (unsigned char *)input;
		if (!strcmp(data_type, STR))
			printf("\"%s\" ", data);
		else if (!strcmp(data_type, CHAR))
			printf("'%c' ", *data);
		printspace_n(count_space(input, space));
	}
	else if (!strcmp(data_type, SIZE_T) || !strcmp(data_type, INT))
	{
		char	*n_str;

		number = (int *)input;
		n_str = ft_itoa(*number);
		printspace_n(count_space(n_str, space));
		if (!strcmp(data_type, SIZE_T))
			printf("%zu ", (size_t)*number);
		else if (!strcmp(data_type, INT))
			printf("%d ", (int)*number);
		free(n_str);
	}
}

void	print_result_null(char *data_type, void *input, size_t len, int space)
{
	int				*number;

	number = NULL;
	if (!strcmp(data_type, STR))
	{
		print_null(input, len);
		printspace_n(count_space_null(input, len, space));
	}
}

void	testft_char(int c, int o, int l)
{
	print_result_text("input ");
	print_result(INT, &c, 4);
	print_result(CHAR, &c, 1);
	print_result_text("output ");
	print_result(INT, &o, 4);
	print_result_text("libc ");
	print_result(INT, &l, 4);
	compare_int(o, l);
	printf("\n");
}

void	testft_len(const char *s, size_t o, size_t l)
{
	print_result_text("input ");
	print_result(STR, (char *)s, 12);
	print_result_text("o "); print_result(SIZE_T, &o, 3);
	print_result_text("l "); print_result(SIZE_T, &l, 3);
	compare_int(o, l);
	printf("\n");
}

void	testft_atoi(const char *str, int o, int l)
{
	print_result_text("input\t"); print_result(STR, (char *)str, 30);
	printf("\t");
	print_result_text("o "); print_result(INT, &o, 12);
	print_result_text("l "); print_result(INT, &l, 12);
	compare_int(o, l);
	printf("\n");
}

void testft_strl(char *dst, char *dst2, const char *src, size_t dstsize,
		size_t (f1)(char *, const char*, size_t), size_t (f2)(char *, const char*, size_t))
{
	int	o;
	int	l;

	print_result_text("input\t");
	printf("dst = \"%s\" | src = \"%s\" | size = %zu\n", dst, src, dstsize);
	if (dst && dst2 && src)
	{
		o = f1(dst, src, dstsize);
		l = f2(dst2, src, dstsize);
		print_result_text("o ");
		print_result(INT, &o, 3); print_result_null(STR, dst, dstsize + 1, 20);
		print_result_text("l ");
		print_result(INT, &l, 3); print_result_null(STR, dst2, dstsize + 1, 20);
		print_compare_text("Int "); compare_int(o, l);
		print_compare_text("Str "); compare_null(dst, (char *)dst2, dstsize + 1);
	}
	else
		print_error_text("");
	printf("\n");
	divider_end();
}

void testft_bzero(void *s, void *s2, size_t n)
{
	size_t	ini_s;
	size_t	ini_s2;

	ini_s = strlen(s);
	ini_s2 = strlen(s2);
	print_result_text("input ");
	print_result("str", s, 10);
	print_result("size_t", &n, 2);
	ft_bzero(s, n);
	bzero(s2, n);
	print_result_text("o "); print_result_null(STR, s, ini_s, 16);
	print_result_text("l "); print_result_null(STR, s2, ini_s2, 16);
	if (ini_s > ini_s2)
		compare_null(s, s2, ini_s);
	else
		compare_null(s, s2, ini_s2);
	printf("\n");
}

void testft_mem_chr(void *b, int c, size_t len, void *o, void *l)
{
	char *len_str;

	len_str = ft_itoa(len);
	divider_start();
	print_result_text("input ");
	print_result(STR, b, 10);
	printf("c = ");		print_result(CHAR, &c, 2);
	printf("len =");	print_result(SIZE_T, &len, 3);
	print_result_text("o "); print_result(STR, o, 15);
	print_result_text("l "); print_result(STR, l, 15);
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

	print_result_text("input ");
	printf("dst = "); print_result(STR, dst, 12);
	printf("src = "); print_result(STR, (char *)src, 12);
	printf("len = "); print_result(SIZE_T, &len, 3);
	o = NULL;	l = NULL;
	if (!strcmp(ftname, MEMCPY) && check_overlap(dst, (void *)src) && dst > src)
		{ printcolor("| ", BLUE); printcolor("OVERLAP", YELLOW); }
	else
	{
		if (!strcmp(ftname, MEMCPY))
			{o = ft_memcpy(dst, src, len); l = memcpy(dst2, src2, len); }
		else if (!strcmp(ftname, MEMMOVE))
			{o = ft_memmove(dst, src, len);	l = memmove(dst2, src2, len);}
		print_result_text("o "); print_result(STR, o, 12);
		print_result_text("l "); print_result(STR, l, 12);
		compare_str(o, l);
	}
	printf("\n");
}

void testft_strchr(const char*s, int c, char *o, char *l)
{
	print_result_text("input ");
	print_result(STR, (char *)s, 15);
	if ((!isprint(c) && c <= CHAR_MAX)) printf(" ");
	if ((!isprint(c) && c > 500)) printf(" ");
	printf("'%c' ", c);
	print_result_text("o "); print_result(STR, o, 12);
	print_result_text("l "); print_result(STR, l, 12);
	compare_str(o, l);
	printf("\n");
}

void testft_strnstr(const char *haystack, const char *needle, size_t len,
						char *o, char *l)
{
	int negative[1];

	negative[0] = -1;
	print_result_text("input ");
	print_result(STR, (char *)haystack, 30);
	print_result(STR, (char *)needle, 10);
	if (len + 1 == 0)
		print_result(INT, &negative, 4);
	else
		print_result(SIZE_T, &len, 4);
	print_result_text("o "); print_result(STR, o, 10);
	print_result_text("l "); print_result(STR, l, 10);
	compare_str(o, l);
	printf("\n");
}

void testft_cmp(const char *s1, const char *s2, size_t n, int o, int l,
				char *ftname)
{
	print_result_text("input ");
	print_result(STR, (char *)s1, 10);
	print_result(STR, (char *)s2, 10);
	print_result(SIZE_T, &n, 3);
	if (!strcmp(ftname, MEMCMP) && (((!s1 || !s2)) && n != 0))
		print_error_text("");
	else
	{
		print_result_text("o "); print_result(INT, &o, 5);
		print_result_text("l "); print_result(INT, &l, 5);
		compare_int(o, l);
	}
	printf("\n");
}

void testft_calloc(size_t count, size_t size, void *str, void *o, void *l)
{
	print_result_text("input ");
	printf("count =");	print_result(SIZE_T, &count, 5);
	printf("    size =");	print_result(SIZE_T, &size, 5);
	printf("    str = ");	print_result(STR, str, 15);
	printf("\n");
	if (str != 0 && count > 0 && size > 0)
		{ memcpy(o, str, count); memcpy(l, str, count); }
	else if (str == 0 || count == 0 || size == 0)
		{ o = "not used"; l = "not used"; }
	print_result_text("o "); print_result(STR, o, 15);
	print_result_text("l "); print_result(STR, l, 15);
	compare_mem(o, l, count);
	printf("\n");
	divider_end();
}

void testft_strdup(const char *s1, char *o, char *l)
{
	print_result_text("input ");
	print_result(STR, (char *)s1, 10);
	if (s1)
	{
		divider_start();
		print_result_text("o "); print_result(STR, (char *)o, 10);
		print_result_text("l "); print_result(STR, (char *)l, 10);
		compare_str(o, l);
	}
	else
		print_error_text("");
	printf("\n");
}

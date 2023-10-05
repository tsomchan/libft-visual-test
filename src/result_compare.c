/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:41:49 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/07 15:11:03 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

int	check_overlap(void *dst, void *src)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (0);
	d = dst;
	s = src;
	while (*d != 0)
	{
		if (d == s)
			return (1);
		d++;
	}
	d = dst;
	s = src;
	while (*s != 0)
	{
		if (d == s)
			return (1);
		s++;
	}
	return (0);
}

void	compare_mem(void *s1, void *s2, size_t n)
{
	printcolor("| ", BLUE);
	printf("");
	if (memcmp(s1, s2, n) == 0)
		printcolor("✓", GREEN);
	else
		printcolor("x", RED);
}

void	compare_str_arr(char **s1, char **s2, size_t n)
{
	int	istrue;

	istrue = 1;
	while (n--)
	{
		if (memcmp(*(s1++), *(s2++), n))
			istrue = 0;
	}
	if (istrue)
		printcolor("✓", GREEN);
	else
		printcolor("x", RED);
}

void	compare_int(int i, int o)
{
	printcolor("| ", BLUE);
	printf("");
	if (i == o)
		printcolor("✓", GREEN);
	else
		printcolor("x", RED);
}

void	compare_str(char *s, char *o)
{
	int	i;

	i = 0;
	printcolor("| ", BLUE);
	printf("");
	if (s == 0 && o == 0)
		printcolor("✓", GREEN);
	else if (s != 0 && o != 0)
	{
		while (s[i] == o[i] && s[i] != 0)
			i++;
		if (s[i] == o[i])
			printcolor("✓", GREEN);
		else
			printcolor("x", RED);
	}
	else
		printcolor("x", RED);
}

void	compare_null(char *s, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	printcolor("| ", BLUE);
	printf("");
	while (s[i] == s2[i] && i <= n)
		i++;
	if (s[i] == s2[i])
		printcolor("✓", GREEN);
	else
		printcolor("x", RED);
}

void	compare_arr(int *o, int *l, unsigned int n)
{
	unsigned int	i;

	i = 0;
	printcolor("| ", BLUE);
	while (i < n && o[i] == l[i])
		i++;
	if (i == n)
		i--;
	if (o[i] == l[i])
		printcolor("✓", GREEN);
	else
		printcolor("x", RED);
}

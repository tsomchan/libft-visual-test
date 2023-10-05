/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:39:07 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:39:09 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strlen(const char *s)
{
	testft_len(s, ft_strlen(s), strlen(s));
}

void	run_strlen(char **argv)
{
	if (find_test(argv, "1", "strlen") == 1)
	{
		banner("ft_strlen", "");
		test_strlen("abc");
		test_strlen("1234567890");
		test_strlen("");
		test_strlen("a b c");
	}
}

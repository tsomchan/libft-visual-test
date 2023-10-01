/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:02:47 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:02:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*o;

	divider_start();
	printf("input		: s = \"%s\"\n", s);
	o = ft_strmapi(s, f);
	printf("output	: \"%s\"", o);
	printf("\n");
	divider_end();
	free(o);
}

void	run_strmapi(char **argv)
{
	if (find_test(argv, "2", "strmapi") == 1)
	{
		banner("ft_strmapi", "");
		test_strmapi("test", &chr_rpc);
	}
}

// print_str_arr(p, 3);
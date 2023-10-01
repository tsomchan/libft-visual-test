/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:02:20 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 22:02:22 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_putchar_fd(char s, int fd)
{
	printcolor("---- --- --", "black");
	printcolor(" \n", "reset");
	ft_putchar_fd(s, fd);
	printcolor(" \n", "reset");
}

void	run_putchar_fd(char **argv)
{
	if (find_test(argv, "2", "putchar_fd") == 1)
	{
		banner("ft_putchar_fd", "");
		test_putchar_fd('t', 1);
		test_putchar_fd('1', 1);
		test_putchar_fd('*', 1);
	}
}

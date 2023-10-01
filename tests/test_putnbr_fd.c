/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:02:57 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/06 21:13:55 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_putnbr_fd(int n, int fd)
{
	printcolor("---- --- --", "black");
	printcolor(" \n", "reset");
	ft_putnbr_fd(n, fd);
	printcolor(" \n", "reset");
}

void	run_putnbr_fd(char **argv)
{
	if (find_test(argv, "2", "putnbr_fd") == 1)
	{
		banner("ft_putnbr_fd", "");
		test_putnbr_fd(42, 1);
		test_putnbr_fd(-42, 1);
		test_putnbr_fd(0, 1);
	}
}

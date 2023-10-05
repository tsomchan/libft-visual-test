/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:02:37 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 22:02:38 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_putstr_fd(char *s, int fd)
{
	printcolor("---- --- --", BLACK);
	printcolor(" \n", RESET_C);
	ft_putstr_fd(s, fd);
	printcolor(" \n", RESET_C);
}

void	run_putstr_fd(char **argv)
{
	if (find_test(argv, "2", "putstr_fd") == 1)
	{
		banner("ft_putstr_fd", "write() a string");
		test_putstr_fd("test", 1);
		test_putstr_fd("ทดสอบ", 1);
		test_putstr_fd("😀 😃 😄 😁 😆 😅 😂 🤣", 1);
	}
}

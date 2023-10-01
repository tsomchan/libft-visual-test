/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:02:47 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 22:02:47 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_putendl_fd(char *s, int fd)
{
	printcolor("---- --- --", "black");
	printcolor(" \n", "reset");
	ft_putendl_fd(s, fd);
	printcolor(" \n", "reset");
}

void	run_putendl_fd(char **argv)
{
	if (find_test(argv, "2", "putendl_fd") == 1)
	{
		banner("ft_putendl_fd", "write() a string with a new line");
		test_putendl_fd("test", 1);
		test_putendl_fd("ทดสอบ", 1);
		test_putendl_fd("😀 😃 😄 😁 😆 😅 😂 🤣", 1);
	}
}


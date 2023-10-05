/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:27:30 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:27:32 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_isprint(int c)
{
	testft_char(c, ft_isprint(c), isprint(c));
}

void	run_isprint(char **argv)
{
	if (find_test(argv, "1", "isprint") == 1)
	{
		banner("ft_isprint", "");
		test_isprint('\40');
		test_isprint('\41');
		test_isprint('\176');
		test_isprint('\177');
		test_isprint(32);
		test_isprint(126);
		test_isprint(127);
		test_isprint(128);
		test_isprint(-1);
		test_isprint(3896);
	}
}

/*
	int	o;
	int	l;

	divider_start();
	print_result_text("input\t\t");
	printf("(\'%c\')\tdec = %d\toct = %o\n", c, c, c);
	o = ft_isprint(c);
	l = isprint(c);
	print_result_text("output\t");
	printf("%o\t", o);
	print_result_text("libc\t");
	printf("%d ", l);
	compare_int(o, l);
	divider_end();
*/
	//	it seems I can't put in '\48' and '\49' 
	//	because number "8" and "9" don't exist in octal
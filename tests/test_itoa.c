/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:43:44 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/04 22:00:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_itoa(int n, char *p)
{
	char	*o;

	divider_start();
	print_result_text("input\t\t");
	printf("n = %d\n", n);
	o = ft_itoa(n);
	print_result_text("output\t");
	printf("\"%s\"\t", o);
	print_result_text("prediction\t");
	printf("\"%s\" ", p);
	compare_str(o, p);
	printf("\n");
	free(o);
}

void	run_itoa(char **argv)
{
	if (find_test(argv, "2", "itoa") == 1)
	{
		banner("ft_itoa", "");
		test_itoa(0, "0");
		test_itoa(-2147483648LL, "-2147483648");
		test_itoa(5, "5");
		test_itoa(42, "42");
		test_itoa(123456, "123456");
		test_itoa(-42, "-42");
		test_itoa(-615286913, "-615286913");
	}
}

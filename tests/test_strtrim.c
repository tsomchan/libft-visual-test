/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:50:26 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/06 20:23:33 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_strtrim(char const *s1, char const *set, char *p)
{
	char	*o;

	divider_start();
	print_result_text("input\t\t");
	printf("s1 = \"%s\"\t| set = \"%s\"\n", s1, set);
	o = ft_strtrim(s1, set);
	print_result_text("output\t");
	printf("\"%s\"\n", o);
	print_result_text("predict\t");
	printf("\"%s\" ", p);
	compare_str(o, p);
	divider_end();
	free(o);
}

void	run_strtrim(char **argv)
{
	if (find_test(argv, "2", "strtrim") == 1)
	{
		banner("ft_strtrim", "");
		test_strtrim("abcd", "", "abcd");
		test_strtrim(" . abcd", " ", ". abcd");
		test_strtrim("", "", "");
		test_strtrim("123Hello World321", "123", "Hello World");
		test_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " ",
			"lorem \n ipsum \t dolor \n sit \t amet");
		test_strtrim("lorem ipsum dolor sit amet", "te",
			"lorem ipsum dolor sit am");
		test_strtrim("lorem ipsum dolor sit amet", "l ",
			"orem ipsum dolor sit amet");
		test_strtrim("lorem ipsum dolor sit amet", "tel",
			"orem ipsum dolor sit am");
		test_strtrim("   ", " ", "");
	}
}

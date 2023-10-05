/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:34:35 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/07 17:05:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_split(char const *s, char c, char **p, int test_size)
{
	char	**o;
	int		i;

	divider_start();
	print_result_text("input\t\t");
	printf("c = '%c' | s = \"%s\"\n", c, s);
	o = ft_split(s, c);
	print_result_text("output\t");
	print_str_arr(o, test_size);
	printf("\t");
	print_result_text("predict\t");
	print_str_arr(p, test_size);
	compare_str_arr(o, p, test_size);
	printf("\n");
	i = 0;
	while (o[i] != 0)
		free(o[i++]);
	free(o);
	divider_end();
}

void	run_split(char **argv)
{
	if (find_test(argv, "2", "split") == 1)
	{
		banner("ft_split", "");
		test_split((char [5]){'1', '2', 0, '4', 0},  '_',
			(char *[2]){"12", 0}, 2);
		test_split("123456789", '_',
			(char *[2]){"123456789", 0}, 2);
		test_split("123_456_789", '_',
			(char *[4]){"123", "456", "789", 0}, 4);
		test_split("______123____456_789_______", '_',
			(char *[4]){"123", "456", "789", 0}, 4);
		test_split("123____456_789_______", '_',
			(char *[4]){"123", "456", "789", 0}, 4);
		test_split("______123____456_789", '_',
			(char *[4]){"123", "456", "789", 0}, 4);
		// test_split("___", '_', 0, 1);
		// test_split("", '_', 0, 1);
		//test_split("aabbcc_____", '_', 0, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:07:51 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/11 20:07:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_lstsize(char *test, t_list *lst)
{
	if (lst)
	{
		print_list(test, lst);
	}
	else
	{
		printcolor("| ", "blue");
		printf("the list is NULL\n");
	}
	printcolor("| ", "blue");
	printf("lstsize\t= %d\n", ft_lstsize(lst));
	divider_end();
}

void	run_lstsize(char **argv)
{
	if (find_test(argv, "bonus", "lstsize") == 1)
	{
		banner("ft_lstsize", "");
		test_lstsize("str", (t_list*){
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}});
	}
}
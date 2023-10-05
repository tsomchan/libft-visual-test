/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:13:48 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/11 21:13:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_lstadd_back(char *test, t_list **lst, t_list *new)
{
	if (lst)
		print_list(test, *lst);
	else
		print_test_line("the list is NULL\n");
	printcolor("| ", BLUE);
	if (!new)	
		printf("new\t\t= %s\n", (char *)new);
	else if (!strcmp(test, "str"))
		printf("new->content\t= \"%s\"\n", new->content);
	ft_lstadd_back(lst, new);
	print_list(test, *lst);
	divider_end();
}

void	run_lstadd_back(char **argv)
{
	if (find_test(argv, "bonus", "lstadd_back") == 1)
	{
		banner("ft_lstadd_back", "");
		test_lstadd_back("str", &(t_list*){
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}},
			&(t_list){"add", NULL});
		test_lstadd_back("str", &(t_list*){
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}},
			NULL);
		test_lstadd_back("str", &(t_list*){NULL},
			&(t_list){"add", NULL});
	}
}
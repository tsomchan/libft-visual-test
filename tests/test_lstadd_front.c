/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:59:31 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/11 15:59:32 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	test_lstadd_front(char *test, t_list **lst, t_list *new)
{
	if (lst)
		print_list(test, *lst);
	else
		print_test_line("the list is NULL\n");
	printcolor("| ", "blue");
	if (!new)	
		printf("new\t\t= %s\n", (char *)new);
	else if (!strcmp(test, "str"))
		printf("new->content\t= %s\n", new->content);
	ft_lstadd_front(lst, new);
	if (*lst)
		print_list(test, *lst);
	divider_end();
}

void	run_lstadd_front(char **argv)
{
	if (find_test(argv, "bonus", "lstadd_front") == 1)
	{
		banner("ft_lstadd_front", "");

		test_lstadd_front("str", &(t_list*){
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}},
			&(t_list){"add", NULL});
		test_lstadd_front("str", &(t_list*){
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}},
			NULL);
		test_lstadd_front("str", &(t_list*){NULL},
			&(t_list){"add", NULL});
	}
}

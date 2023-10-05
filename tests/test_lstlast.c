/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:46:02 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/11 20:46:03 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	print_lstlast(char *test, t_list *lst)
{
	printcolor("| ", BLUE);
	if (!lst)
	{
		printf("lstlast\t\t= %s\n", (char *)lst);
	}
	else
	{
		if (!strcmp(test, "str"))
		{
			printf("lstlast->content\t= \"%s\"\n", lst->content);
			printcolor("| ", BLUE);
			if (lst->next)
				printf("lstlast->next\t\t= \"%s\"\n", (lst->next)->content);
			else
				printf("lstlast->next\t\t= (null)\n");
		}
		if (!strcmp(test, "int"))
		{
			printf("lstlast->content\t= %d\n", *(int *)lst->content);
			printcolor("| ", BLUE);	
			if (lst->next)
				printf("lstlast->next\t\t= %d\n", *(int *)(lst->next)->content);
			else
				printf("lstlast->next\t\t= (null)\n");
		}
	}
}

void	test_lstlast(char *test, t_list *lst)
{
	t_list	*node;

	node = 0;
	if (lst)
	{
		print_list(test, lst);
	}
	else
	{
		printcolor("| ", BLUE);
		printf("the list is NULL\n");
	}
	node = ft_lstlast(lst);
	print_lstlast(test, node);
	divider_end();
}

void	run_lstlast(char **argv)
{
	if (find_test(argv, "bonus", "lstlast") == 1)
	{
		banner("ft_lstlast", "");
		test_lstlast("str", (t_list*){
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}});
		test_lstlast("str", (t_list*){
			&(t_list){"original", NULL}});
		test_lstlast("str", (t_list*){
			&(t_list){NULL, NULL}});
		test_lstlast("str", (t_list*){ NULL});
		test_lstlast("str", NULL);
	}
}
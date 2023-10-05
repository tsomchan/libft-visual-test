/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:11:31 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/11 22:11:33 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_lstdelone(char *test, t_list *lst, void (*del)(void *))
{
	print_list(test, lst);
	if (!del)
	{
		printcolor("| ", BLUE);
		printf("del\t\t= %s\n", (char *)del);
	}
	if (lst)
	{
		ft_lstdelone(lst, del);
		if (!lst)
		{
			printcolor("| ", BLUE);
			printf("lstdelone\t= %s\n", (char *)lst);
		}
		else if(lst)
			print_test_line("hopefully the node is properly cleared\n");
	}
	else if (!lst)
		ft_lstdelone(lst, del);
		if (!lst)
		{
			printcolor("| ", BLUE);
			printf("lstdelone\t= %s\n", (char *)lst);
		}
	// if (lst)	
	// {
	// 	printf("%d \n", *(int *)lst->content);
	// 	printf("lst\t\t= %d \n", *(int *)lst);
	// }
	// lst = 0;
	// print_list(test, lst);
	divider_end();
}

void	run_lstdelone(char **argv)
{
	if (find_test(argv, "bonus", "lstdelone") == 1)
	{
		banner("ft_lstdelone", "");
		// test_lstdelone("str", (t_list*){NULL}, &free);
		test_lstdelone("str", (t_list*){NULL}, NULL);
		test_lstdelone("str", ft_lstnew((strdup("content"))), &free);
	}
}

	// if (lst)	
	// {
	// 	printf("%d \n", *(int *)lst->content);
	// 	printf("lst\t\t= %d \n", *(int *)lst);
	// }
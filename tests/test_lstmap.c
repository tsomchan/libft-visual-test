/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:54:36 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/12 16:54:38 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myft.h"


void	*test_lstmap_strlen(void *content)
{
	// printf("ft_strlen(%s)\t= %zu\n", content, ft_strlen(content));
	// printf("ft_strlen(%s)\t= %zu\n", content, ft_strlen(content));
	return (ft_itoa(ft_strlen(content)));
}
// 
// void	test_lstmap_intchange(void *content)
// {
// 	*(int *)content = 0;
// }

void	test_lstmap(char *test, t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*test_lst;

	test_lst = 0;
	print_list(test, lst);
	if (!f)
	{
		printcolor("| ", "blue");
		printf("f\t\t= %s\n", (char *)f);
	}
	if (!del)
	{
		printcolor("| ", "blue");
		printf("del\t\t= %s\n", (char *)del);
	}
	test_lst = ft_lstmap(lst, f, del);
	if (test_lst)
	{
		if (!lst)
		{
			printcolor("| ", "blue");
			printf("lstmap\t= %s\n", (char *)test_lst);
		}
		else if(lst)
			print_list(test, test_lst);
	}
	else
	{
		printcolor("| ", "blue");
		printf("lstmap\t= %s\n", (char *)lst);
	}
	ft_lstclear(&test_lst, del);
	divider_end();
}

void	run_lstmap(char **argv)
{
	if (find_test(argv, "bonus", "lstmap") == 1)
	{
		banner("ft_lstmap", "");
		//test_lstmap("str", (t_list*){NULL}, NULL, NULL);
		test_lstmap("str", (t_list*){NULL}, &test_lstmap_strlen, &free);
		test_lstmap("str", 
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}
			, &test_lstmap_strlen, &free);
		// test_lstmap("int", 
		// 	&(t_list){(int [1]){42},
		// 	&(t_list){(int [1]){24},
		// 	&(t_list){(int [1]){4}, NULL}}}
		// 	, &test_lstmap_intchange);
		// test_lstmap("str", ft_lstnew((strdup("content"))), &free);
	}
}

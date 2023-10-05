/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:22:02 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/10 17:22:03 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_lstnew(char *test, void *content)
{
	t_list *node;

	node = 0;
	printcolor("| ", BLUE);
	if (!node)
		printf("initialized with empty node\n");
	node = ft_lstnew(content);
	printcolor("| ", BLUE);
	if (node)
	{
		if (!strcmp(test, "str"))
			printf("created a node, node->content = \"%s\"\n", node->content);
		else if (!strcmp(test, "int"))
			printf("created a node, node->content = ( %d )\n", *(int *)node->content);
	}
	else
		printf("node isn't created, bruh\n");
	divider_end();
}

void	run_lstnew(char **argv)
{
	if (find_test(argv, "bonus", "lstnew") == 1)
	{
		banner("ft_lstnew", "create a new list with new content");
		test_lstnew("str", "new");
		test_lstnew("int", (int [1]){42});
		// test_lstnew_str("new");
		// test_lstnew_int(42);
	}
}

// void	test_lstnew_str(char *str)
// {
// 	t_list *node;
// 
// 	node = 0;
// 	if (!node)
// 		printf("initialized with empty node\n");
// 	node = ft_lstnew(str);
// 	if (node)
// 		printf("created a node, node->content is \"%s\"\n", node->content);
// 	else
// 		printf("node isn't created, bruh\n");
// 	divider_end();
// }
// 
// void	test_lstnew_int(int n)
// {
// 	t_list *node;
// 
// 	node = 0;
// 	if (!node)
// 		printf("initialized with empty node\n");
// 	node = ft_lstnew(&n);
// 	if (node)
// 		printf("created a node, node->content is ( %d )\n", *(int *)node->content);
// 		// printf("created a node, content is ( %d )\n", *(int *)node->content);
// 	else
// 		printf("node isn't created, bruh\n");
// 	divider_end();
// }
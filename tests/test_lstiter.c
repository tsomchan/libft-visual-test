/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:14:53 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/12 16:14:54 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	test_lstiter_strlen(void *content)
{
	printf("ft_strlen(%s)\t= %zu\n", content, ft_strlen(content));
}

void	test_lstiter_intchange(void *content)
{
	*(int *)content = 0;
}

void	test_lstiter(char *test, t_list *lst, void (*f)(void *))
{
	print_list(test, lst);
	if (!f)
	{
		printcolor("| ", BLUE);
		printf("f\t\t= %s\n", (char *)f);
	}
	if (lst)
	{
		ft_lstiter(lst, f);
		if (!lst)
		{
			printcolor("| ", BLUE);
			printf("lstiter\t= %s\n", (char *)lst);
		}
		else if(lst)
			print_list(test, lst);
	}
	else if (!lst)
		ft_lstiter(lst, f);
		if (!lst)
		{
			printcolor("| ", BLUE);
			printf("lstiter\t= %s\n", (char *)lst);
		}
	divider_end();
}

void	run_lstiter(char **argv)
{
	if (find_test(argv, "bonus", "lstiter") == 1)
	{
		banner("ft_lstiter", "");
		// test_lstiter("str", (t_list*){NULL}, &free);
		test_lstiter("str", (t_list*){NULL}, NULL);
		test_lstiter("str", 
			&(t_list){"original1",
			&(t_list){"original2",
			&(t_list){"original3", NULL}}}
			, &test_lstiter_strlen);
		test_lstiter("int", 
			&(t_list){(int [1]){42},
			&(t_list){(int [1]){24},
			&(t_list){(int [1]){4}, NULL}}}
			, &test_lstiter_intchange);
		// test_lstiter("str", ft_lstnew((strdup("content"))), &free);
	}
}
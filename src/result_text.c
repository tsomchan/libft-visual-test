/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:39:32 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 15:39:34 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	result_divider(int answer)
{
	char *color;

	if (answer == 0)
		color = RED;
	else if (answer == 1)
		color = GREEN;
	else if (answer == -1)
		color = YELLOW;
	else
		color = BLUE;
	printcolor("| ", color);
}

void	print_error_text(char *s)
{
	printcolor("| ", BLUE);
	printcolor("ERROR!", YELLOW);
	if (s && *s != 0)
	{
		printf(" ");
		printcolor(s, BLACK);
	}
}

void	print_result_text(char *s)
{
	printcolor("| ", BLUE);
	printcolor(s, BLACK);
	printcolor(": ", BLACK);
}

void	print_compare_text(char *s)
{
	printcolor("| ", BLUE);
	printcolor(s, BLACK);
}

void	print_test_line(char *s)
{
	printcolor("| ", BLUE);
	printf("%s", s);
}

char	chr_rpc(unsigned int n, char c)
{
	set_color(BLACK);
	printf("Function %s is called\n", __func__);
	set_color(RESET_C);
	n = c;
	return (n);
}

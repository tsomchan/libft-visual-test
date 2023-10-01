/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosmetic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:57:55 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 14:57:57 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>
#include "myft.h"

void	banner_border(int len)
{
	int	i;

	set_color(BLUE);
	printf("o");
	i = len + 2;
	while (--i >= 0)
		printf("-");
	printf("o\n");
	set_color(RESET_C);
}

void	banner(char *str, char *desc)
{
	int	len;
	int	i;

	i = -1;
	if (*desc == 0)
		len = strlen(str);
	else
		len = strlen(str) + strlen(desc) + 3;
	banner_border(len);
	printcolor("|", BLUE);
	set_color(WHITE);
	printf(" %s ", str);
	printcolor("| ", BLUE);
	if (*desc != 0)
	{
		printcolor(desc, BLACK);
		printcolor(" |", BLUE);
	}
	printf("\n");
	banner_border(len);
}

void	divider_start(void)
{
	printf("");
}

void	divider_end(void)
{
	set_color(BLUE);
	printf("o-------------------------------------- --- -- -\n");
	set_color(RESET_C);
}

void	program_header(void)
{
	set_color(PURPLE);
	printf("o-------------------------------------- --- -- -\n");
	printf("o------------------------------- -- --- -\n");
	printf("o------------------------ --- -- -\n");
	printf("o----------------- -- -- -- -\n");
	set_color(RESET_C);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:38:49 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 14:40:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myft.h"

void	set_color(char *colorstr)
{
	printf("%s", colorstr);
}

char	*strtocolor(char *str)
{
	char	*set;
	char	*color;
	int	i;

	color = strdup(str);
	i = -1;
	while (color[++i])
		color[i] = tolower(color[i]);
	if (strcmp(color, "black") == 0)
		set = BLACK;
	else if (strcmp(color, "red") == 0)
		set = RED;
	else if (strcmp(color, "green") == 0)
		set = GREEN;
	else if (strcmp(color, "yellow") == 0)
		set = YELLOW;
	else if (strcmp(color, "blue") == 0)
		set = BLUE;
	else if (strcmp(color, "purple") == 0)
		set = PURPLE;
	else if (strcmp(color, "cyan") == 0)
		set = CYAN;
	else if (strcmp(color, "white") == 0)
		set = WHITE;
	else if (strcmp(color, "reset") == 0)
		set = RESET_C;
	else
		set = NULL;
	return (free(color), set);
}

void	printcolor(char *s, char *color)
{
	set_color(color);
	// printf("%s", color);
	printf("%s", s);
	// printf("%s", RESET_C);
	set_color(RESET_C);
}

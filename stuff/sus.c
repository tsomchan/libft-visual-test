/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sus.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:44:50 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 18:47:12 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/myft.h"

void	printsus(char *color)
{
	set_color(color);
	printf("    ##############    \n");
	printf("  ##             ###  \n");
	printcolor(" #########", RESET_C);
	printcolor("       #  #\n", color);
	printcolor("#         #", RESET_C);
	printcolor("      #   #\n", color);
	printcolor("#         #", RESET_C);
	printcolor("      #   #\n", color);
	printf(" #########");
	set_color(color);
	printf("       #   #\n");
	printf("   #             #   #\n");
	printf("   #             #   #\n");
	printf("   #             #   #\n");
	printf("   #              ### \n");
	printf("   #    ######    #   \n");
	printf("   #    #    #    #   \n");
	printf("   ######    ######   \n");
	set_color(RESET_C);
}

// int	main(void)
int	main(int argc, char **argv)
{
	char	*color;

	if (argc < 1)
		return (0);
	color = RED;
	if (argv[1])
		color = strtocolor(argv[1]);
	if (!color || !strcmp(color, RESET_C))
		color = RED;
	banner("sus", "");
	printsus(color);
}

// printf("color = \"%s\"\n", color);
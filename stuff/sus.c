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
	ft_color(color);
	printf("    ##############    \n");
	printf("  ##             ###  \n");
	printcolor(" #########", "reset");
	printcolor("       #  #\n", color);
	printcolor("#         #", "reset");
	printcolor("      #   #\n", color);
	printcolor("#         #", "reset");
	printcolor("      #   #\n", color);
	printf(" #########");
	ft_color(color);
	printf("       #   #\n");
	printf("   #             #   #\n");
	printf("   #             #   #\n");
	printf("   #             #   #\n");
	printf("   #              ### \n");
	printf("   #    ######    #   \n");
	printf("   #    #    #    #   \n");
	printf("   ######    ######   \n");
	ft_color("reset");
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);

	char	*color;

	color = "red";
	if (argv[1] && (
		!strcmp(argv[1], "black") ||
		!strcmp(argv[1], "red") ||
		!strcmp(argv[1], "green") ||
		!strcmp(argv[1], "yellow") ||
		!strcmp(argv[1], "blue") ||
		!strcmp(argv[1], "purple") ||
		!strcmp(argv[1], "cyan") ||
		!strcmp(argv[1], "white")))
		color = argv[1];
	banner("sus", "");
	printsus(color);
}

// printf("color = \"%s\"\n", color);
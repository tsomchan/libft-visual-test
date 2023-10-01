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

#include "myft.h"

int	main(void)
{
	char	*color;

	color = "red";
	banner("sus", "");
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

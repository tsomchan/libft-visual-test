/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc_07.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:21:54 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/13 18:21:55 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "../myft.h"

int main()
{
	banner("/07/ ft_calloc", "count = -1, size = 0");
	void *ptr = ft_calloc(-1 , 0);
}

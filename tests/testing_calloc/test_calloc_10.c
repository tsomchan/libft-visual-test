/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc_10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:34:30 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/13 14:34:33 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "../myft.h"

int main()
{
	banner("/10/ calloc", "count = (INT_MAX) + 1, size = 1");
	void *ptr = calloc((INT_MAX) + 1, 1);
}

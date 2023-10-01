/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:11:22 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 20:11:23 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	typing base numbers

	/001	- Octal 1
	1		- Dec 1
	/x01	- Hex 1

	---------------

	int c = 79;

	//	you can't assign integer to a char value directly. 
	//	you need to use "unsigned char"

	s[3] = "ab";
	s[1] --> b

	if (s[1] == (unsigned char)c)

	---------------
	//	declare a variable of unsigned char and then use the value of desired integer
	//	doing this will reduce the need of typing "unsigned char" multiple times

	unsigned char	new_c;
	new_c	=	(unsigned  char)c;
*/
/*
	I still want to find out why the value of pointer dst and src can be
		compared 

	"your memmove crash because it read too many bytes
			or attempt to read on dst !"

	what is 128o data?
*/
/*
	memset test
	tried to test with array but no success
	int		memset_o3[3] = {1, 2, 3};
	int		memset_l3[3] = {1, 2, 3};
	test_memset_arr(memset_o3,
					memset_l3, 42, 3);
	test_memset_str((void *)"12345"[99], 'M', 10);
	
	int		*memset_o3 = malloc(sizeof(int) * 3);
	int		*memset_l3 = malloc(sizeof(int) * 3);
	memset_o3[0] = 1; 
	memset_o3[1] = 2;
	memset_o3[2] = 3;
	
	memset_l3[0] = 1; 
	memset_l3[1] = 2;
	memset_l3[2] = 3;
	divider_start();
	printcolor("| ", "blue"); 	printf("input		: ");
		for (int i=0; i<3; i++)
			printf("%d ", memset_o3[i]);
	// print_arr(memset_o3, 3);
	// print_arr(memset_l3, 3);
	printf(" | c = %d | len = %d\n", 42, 3);
	memset(memset_l3, 42, 3);
	ft_memset(memset_o3, 42, 3);
	printcolor("| ", "blue"); 	printf("libc		: ");
	// print_arr(memset_l3, 3);
		for (int i=0; i<3; i++)
			printf("%d ", memset_l3[i]);
	printf("\n");
	printcolor("| ", "blue"); 	printf("output	: ");
	// print_arr(memset_o3, 3);
		for (int i=0; i<3; i++)
			printf("%d ", memset_o3[i]);
	printf("\n");
	divider_end();
*/

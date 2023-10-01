/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:00:33 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/24 21:00:34 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../tests/testft.h"

//	Part 1 - Libc functions - basics
void	run_part1(char **argv)
{
	run_isalpha(argv);
	run_isdigit(argv);
	run_isalnum(argv);
	run_isascii(argv);
	run_isprint(argv);
	run_strlen(argv);
	run_memset(argv);
	run_bzero(argv);
	run_memcpy(argv);
	run_memmove(argv);
	run_strlcpy(argv);
	run_strlcat(argv);
	run_toupper(argv);
	run_tolower(argv);
	run_strchr(argv);
	run_strrchr(argv);
	run_strncmp(argv);
	run_memchr(argv);
	run_memcmp(argv);
	run_strnstr(argv);
	run_atoi(argv);
	run_calloc(argv);
	run_strdup(argv);
}

void	run_part2(char **argv)
{
	run_substr(argv);
	run_strjoin(argv);
	run_strtrim(argv);
	run_split(argv);
	run_itoa(argv);
	run_strmapi(argv);
	run_striteri(argv);
	run_putchar_fd(argv);
	run_putstr_fd(argv);
	run_putendl_fd(argv);
	run_putnbr_fd(argv);
}

void	run_bonus(char **argv)
{
	run_lstnew(argv);
	run_lstadd_front(argv);
	run_lstsize(argv);
	run_lstlast(argv);
	run_lstadd_back(argv);
	run_lstdelone(argv);
	run_lstiter(argv);
	run_lstmap(argv);
}

int	main(int argc, char **argv)
{
	program_header();
	if (argc == 1)
		printf("showing ALL functions\n");
	run_part1(argv);
	run_part2(argv);
	run_bonus(argv);
}

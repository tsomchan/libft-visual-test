/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:06:23 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/03 14:06:25 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTFT_H
# define TESTFT_H

//	Part 1 test
void	run_isalpha(char **argv);
void	run_isdigit(char **argv);
void	run_isalnum(char **argv);
void	run_isascii(char **argv);
void	run_isprint(char **argv);
void	run_strlen(char **argv);
void	run_strlcpy(char **argv);
void	run_strlcat(char **argv);
void	run_strchr(char **argv);
void	run_strrchr(char **argv);
void	run_strncmp(char **argv);
void	run_strnstr(char **argv);
void	run_memset(char **argv);
void	run_bzero(char **argv);
void	run_memcpy(char **argv);
void	run_memmove(char **argv);
void	run_toupper(char **argv);
void	run_tolower(char **argv);
void	run_atoi(char **argv);
void	run_memchr(char **argv);
void	run_memcmp(char **argv);
void	run_calloc(char **argv);
void	run_strdup(char **argv);

//	Part 2 test
void	run_substr(char **argv);
void	run_strjoin(char **argv);
void	run_strtrim(char **argv);
void	run_split(char **argv);
void	run_itoa(char **argv);
void	run_strmapi(char **argv);
void	run_striteri(char **argv);
void	run_putchar_fd(char **argv);
void	run_putstr_fd(char **argv);
void	run_putendl_fd(char **argv);
void	run_putnbr_fd(char **argv);

//	bonust test
void	run_lstnew(char **argv);
void	run_lstadd_front(char **argv);
void	run_lstsize(char **argv);
void	run_lstlast(char **argv);
void	run_lstadd_back(char **argv);
void	run_lstdelone(char **argv);
void	run_lstiter(char **argv);
void	run_lstmap(char **argv);
#endif
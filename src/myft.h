/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:47:53 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/07 15:09:56 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFT_H
# define MYFT_H
# include "../../libft/libft.h"
# include <stdio.h>
# include <libc.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET_C "\033[0m"

//	MY TEST FUNCTIONS
//	coloring.c
void	set_color(char *color);
char	*strtocolor(char *str);
void	printcolor(char *s, char *color);
//	cosmetic.c
void	banner_border(int len);
void	banner(char *str, char *desc);
void	divider_start(void);
void	divider_end(void);
void	program_header(void);
//	result_compare.c
int		check_overlap(void *dst, void *src);
void	compare_mem(void *s1, void *s2, size_t n);
void	compare_str_arr(char **s1, char **s2, size_t n);
void	compare_int(int i, int o);
void	compare_str(char *s, char *o);
void	compare_null(char *s, char *s2, unsigned int n);
void	compare_arr(int *o, int *l, unsigned int n);
//	result_output.c
int		find_test(char **argv, char *part, char *test);
void	print_null(char *s, unsigned int n);
void	print_arr(int *arr, int size);
void	print_str_arr(char **arr, int size);
void	print_list(char *test, t_list *lst);
//	result_text.c
void	result_divider(int answer);
void	print_result_text(char *s);
void	print_error_text(char *s);
void	print_compare_text(char *s);
void	print_test_line(char *s);
char	chr_rpc(unsigned int n, char c);

#endif

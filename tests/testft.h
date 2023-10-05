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
# include "../src/myft.h"
//	define function names
# define MEMCPY "memcpy"
# define MEMMOVE "memmove"
# define STRNCMP "strncmp"
# define MEMCMP "memcmp"

//	Part 1 test functions
void	testft_char(int c, int o, int l);
void	testft_len(const char *s);
void	testft_strl(char *dst, char *dst2, const char *src, size_t dstsize
			,size_t (f1)(char *, const char*, size_t)
			,size_t (f2)(char *, const char*, size_t));
void	testft_bzero(void *s, void *s2, size_t n);
void	testft_mem_chr(void *b, int c, size_t len, void *o, void *l);
void	testft_mem_arr(void *dst, void *dst2, const void *src, const void *src2,
		size_t len, char *ftname);
void	testft_strchr(const char*s, int c, char *o, char *l);
void	testft_strnstr(const char *haystack, const char *needle, size_t len,
						char *o, char *l);
void	testft_cmp(const char *s1, const char *s2, size_t n, int o, int l,
				char *ftname);
void	testft_atoi(const char *str);
void	testft_calloc(size_t count, size_t size, void *str, void *o, void *l);
void	testft_strdup(const char *s1, char *o, char *l);

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
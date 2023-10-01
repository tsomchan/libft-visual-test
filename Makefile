# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 20:14:55 by tsomchan          #+#    #+#              #
#    Updated: 2023/09/05 14:02:36 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

PRJ_PTH	=	../libft/

NAME	=	libft.a
INC		=	libft.h
SRC 	=	$(addprefix $(PRJ_PTH), ft_bzero.c ft_atoi.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)
SRC_B	=	$(addprefix $(PRJ_PTH), ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c)
OBJ_PTH	=	obj/
OBJ		=	$(SRC:.c=.o)
OBJ_B	=	$(SRC_B:.c=.o)
AR		=	ar rc
CC		=	cc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(INC)
	$(CC) $(CFLAG) -c $< -o $(OBJ_PTH)$@

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_B)
	$(AR) $(NAME) $^

.PHONY = all clean fclean re bonus

#	my additional rules
clear:
	clear

norm:
ifdef v
	norminette $(PRJ_PTH)ft_$(v).c
else
	norminette $(SRC) $(SRC_B)
endif
	norminette --version

log: clear
	git log --name-status -2

clean_more:
	rm -f $(NAME)
	rm -f .DS_Store
	rm -f main.a

.PHONY += clear norm log clean_more

#	git
push:
	git push
	clear && git log --name-status -1

git_add:
	git add .
ifdef m
	git commit -m "$(m)"
endif

git: git_add push

.PHONY += push git_add git

#	my testing rules
T_PTH		=	testing/
T_SRC_PTH	=	src/
T_TEST_PTH	=	tests/
MYFT		=	$(addprefix $(T_SRC_PTH), coloring.c cosmetic.c result_compare.c \
			result_output.c result_text.c)
T_HEADER	=	$(SRC) $(SRC_B) $(MYFT)
T_SRC		=	src/main.c $(T_HEADER)
T_SRC		+=	$(addprefix $(T_TEST_PTH)test_, atoi.c bzero.c calloc.c isalnum.c \
			isalpha.c isascii.c isdigit.c isprint.c itoa.c memchr.c memcmp.c \
			memcpy.c memmove.c memset.c putchar_fd.c putendl_fd.c putnbr_fd.c \
			putstr_fd.c split.c strchr.c strdup.c striteri.c strjoin.c \
			strlcat.c strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c \
			strrchr.c strtrim.c substr.c tolower.c toupper.c)
T_SRC		+=	$(addprefix $(T_TEST_PTH)test_, lstnew.c lstadd_front.c lstsize.c \
			lstlast.c lstadd_back.c lstdelone.c lstiter.c lstmap.c)
T_NAME		=	main.a

test:
	$(CC) $(CFLAG) -g $(T_SRC) -o $(T_NAME)
	clear
ifdef v
	./$(T_NAME) $(v)
#	norminette $(PRJ_PTH)ft_$(v).c
else
	./$(T_NAME)
endif
	make norm

val: norm
	$(CC) $(CFLAG) $(T_SRC) -o $(T_NAME)
	clear
ifdef v
	valgrind ./$(T_NAME) $(v)
#	norminette $(PRJ_PTH)ft_$(v).c
else
	valgrind ./$(T_NAME)
endif

.PHONY += test val 

#	test multiple main files
T_CALLOC		=	 $(addprefix $(T_PTH)testing_calloc/, *.c)

define run_tests
	clear
	for i in $1 ; do \
		$(CC) -g $(T_HEADER) $$i -o $(T_NAME) ; \
		./$(T_NAME) ; \
	done
endef

define run_vals
	clear
	for i in $1 ; do \
		$(CC) -g $(T_HEADER) $$i -o $(T_NAME) ; \
		valgrind ./$(T_NAME) ; \
	done
endef
#		valgrind ./$(T_NAME) > log.txt > 2>&1 ; \
#		valgrind ./$(T_NAME) --log-file="log.txt" ; \
#		valgrind --log-file="$(T_NAME)" ; \
#		valgrind ./$(T_NAME) ; \

tests:
ifdef v
	$(call run_tests, $(addprefix $(T_PTH)testing_$(v)/, *.c))
else
	$(call run_tests, $(T_CALLOC))
endif

vals:
ifdef v
	$(call run_vals, $(addprefix $(T_PTH)testing_$(v)/, *.c))
else
	$(call run_vals, $(T_CALLOC))
endif

.PHONY += tests vals

# my other rules
STUFF_PTH	=	stuff/
STUFF	:=	$(MYFT)
STUFF	+=	$(STUFF_PTH)sus.c

sus:
	cc -Wall -Wextra -Werror $(STUFF) -o $(T_NAME)
ifdef v
	./$(T_NAME) $(v)
else
	./$(T_NAME)
endif

.PHONY += sus
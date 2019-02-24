# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 09:34:18 by cdelahay          #+#    #+#              #
#    Updated: 2019/02/22 13:45:41 by cdelahay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME_PUSH = push_swap

NAME_CHECKER = checker

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES_PUSH   =  dlist_funct.c \
		          fill_d_list.c \
		          instructions.c \
		          main_push_swap.c \
		          median_and_path.c \
		          quick_sort.c \
		          sort.c \
		          spliter_tab.c \
		          utils_functions.c \

SOURCES_CHECKER = checker.c \
		          dlist_funct.c \
		          fill_d_list.c \
		          instructions.c \
		          main_checker.c \
		          spliter_tab.c \
		          utils_functions.c \

SRCS_PUSH = $(addprefix $(DIR_S)/,$(SOURCES_PUSH))

OBJS_PUSH = $(addprefix $(DIR_O)/,$(SOURCES_PUSH:.c=.o))

SRCS_CHECKER = $(addprefix $(DIR_S)/,$(SOURCES_CHECKER))

OBJS_CHECKER = $(addprefix $(DIR_O)/,$(SOURCES_CHECKER:.c=.o))

all: $(NAME_PUSH) $(NAME_CHECKER)

$(NAME_PUSH): $(OBJS_PUSH)
	make -C $(LIBFT)
	$(C) -L libft -lft $^ -o $@

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/push_swap.h
	mkdir -p obj
	$(C) $(FLAGS) -c $< -I includes -I libft/libft.h -o $@

$(NAME_CHECKER): $(OBJS_CHECKER)
	make -C $(LIBFT)
	$(C) -L libft -lft $^ -o $@

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/push_swap.h
	mkdir -p obj
	$(C) $(FLAGS) -c $< -I includes -I libft/libft.h -o $@

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME_PUSH) $(NAME_CHECKER)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean

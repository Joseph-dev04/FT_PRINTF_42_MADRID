# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02 13:26:23 by jopajuel          #+#    #+#              #
#    Updated: 2026/03/02 13:27:24 by jopajuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
FLAGS       = -Wall -Werror -Wextra
AR          = ar rcs

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
DIR_BONUS   = bonus

SRC         = ft_convert_plus.c ft_detec_arguments.c ft_printf.c \
              ft_utils.c ft_basic.c
SRC_BONUS   = $(DIR_BONUS)/ft_convert_plus_bonus.c \
              $(DIR_BONUS)/ft_convert_bonus.c \
              $(DIR_BONUS)/ft_detec_arguments_bonus.c \
              $(DIR_BONUS)/ft_detec_flags_bonus.c \
              $(DIR_BONUS)/ft_printf_bonus.c \
              $(DIR_BONUS)/ft_flag_hexa_bonus.c \
              $(DIR_BONUS)/ft_flag_integer_bonus.c \
              $(DIR_BONUS)/ft_flag_unsigned_bonus.c \
              $(DIR_BONUS)/ft_utils_bonus.c \
              $(DIR_BONUS)/ft_flag_pointer_bonus.c

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

STATUS_ALL   = .status_all
STATUS_BONUS = .status_bonus

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@rm -f $(STATUS_BONUS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@touch $(STATUS_ALL)
	@echo "ft_printf: Mandatory compiled."

bonus: $(OBJ_BONUS) $(LIBFT)
	@rm -f $(STATUS_ALL)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ_BONUS)
	@touch $(STATUS_BONUS)
	@echo "ft_printf: Bonus compiled."

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(STATUS_ALL) $(STATUS_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
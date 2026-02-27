# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 14:49:06 by jopajuel          #+#    #+#              #
#    Updated: 2026/02/04 16:07:38 by jopajuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar rcs

LIBFT_DIR = ./libft

LIBFT = ${LIBFT_DIR}/libft.a

SRC = ft_convert_plus.c ft_convert.c ft_detec_arguments.c ft_detec_flags.c ft_printf.c\
		ft_flag_hexa.c ft_flag_integer.c ft_flag_unsigned.c ft_utils_bonus.c\
		ft_flag_pointer.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

all		: ${NAME}

${NAME}	: ${LIBFT} ${OBJ}
		@cp ${LIBFT} ${NAME}
		@${AR} ${NAME} ${OBJ}

${LIBFT}: 
		 @make -C ${LIBFT_DIR}

%.o		: %.c
		@${CC} ${FLAGS} -c $< -o $@
			
clean	: 
		 @rm -f ${OBJ}
		 @make -C ${LIBFT_DIR} clean

fclean	: clean
		 @rm -f ${NAME}

bonus: all
re		: fclean all
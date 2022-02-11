# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 20:37:12 by acesar-l          #+#    #+#              #
#    Updated: 2021/12/28 21:34:16 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIB_PATH 	= ./library
LIBFT 		= ./libft/libft.a
LIBFTPRINTF 	= ${LIB_PATH}/ft_printf.h
LIBS 		= -lftprintf

CC 		= clang

FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f
INCLUDE 	= -I ${LIB_PATH}

SRCS_PATH	= ./ft_printf
SRCS 		= ${SRCS_PATH}/ft_printf.c		\
			${SRCS_PATH}/ft_argument_c.c		\
			${SRCS_PATH}/ft_arguments_d_i.c		\
			${SRCS_PATH}/ft_argument_p.c		\
			${SRCS_PATH}/ft_argument_percent.c	\
			${SRCS_PATH}/ft_argument_s.c		\
			${SRCS_PATH}/ft_argument_u.c		\
			${SRCS_PATH}/ft_arguments_x.c		\
			${SRCS_PATH}/ft_is_argument.c		\
			${SRCS_PATH}/ft_nbrlen.c		\
			${SRCS_PATH}/ft_free_ptr.c		\
			${SRCS_PATH}/ft_putchar_bw.c		\
			${SRCS_PATH}/ft_revstr.c		\
			${SRCS_PATH}/ft_hexa_converter.c
			
OBJS 		= $(SRCS:.c=.o)

all:		${NAME}

${NAME}: 	${OBJS} ${LIBFT}
		ar rcs ${NAME} ${OBJS}

${LIBFT}:
		make -C libft
		cp ${LIBFT} ${NAME}

.c.o:
		${CC} -c ${FLAGS} $< -o ${<:.c=.o} ${INCLUDE} 


clean:
		make clean -C libft
		${REMOVE} ${OBJS}
		echo "Objects deleted"

fclean:		clean
		make fclean -C libft
		${REMOVE} ${NAME}
		echo "$(NAME) deleted"

re :		fclean all

.PHONY:		all clean fclean re

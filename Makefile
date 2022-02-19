# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 20:37:12 by acesar-l          #+#    #+#              #
#    Updated: 2022/02/19 16:23:44 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

GREEN		 = \033[0;32m
RED			 = \033[0;31m
RESET		 = \033[0m

LIB_PATH 	= ./library
LIBFT 		= ./libft/libft.a
LIBFTPRINTF = ${LIB_PATH}/ft_printf.h
LIBS 		= -lftprintf

CC 			= clang

FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f
INCLUDE 	= -I ${LIB_PATH}

SRCS_PATH	= ./ft_printf
SRCS 		= ${SRCS_PATH}/ft_printf.c					\
				${SRCS_PATH}/ft_argument_c.c			\
				${SRCS_PATH}/ft_arguments_d_i.c			\
				${SRCS_PATH}/ft_argument_p.c			\
				${SRCS_PATH}/ft_argument_percent.c		\
				${SRCS_PATH}/ft_argument_s.c			\
				${SRCS_PATH}/ft_argument_u.c			\
				${SRCS_PATH}/ft_arguments_x.c			\
				${SRCS_PATH}/ft_is_argument.c			\
				${SRCS_PATH}/ft_revert_str.c			\
				${SRCS_PATH}/ft_free_ptr.c				\
				${SRCS_PATH}/ft_hex_length.c			\
				${SRCS_PATH}/ft_decimal_length.c		\
				${SRCS_PATH}/ft_decimal_converter_to_hex.c
			
OBJS 		= $(SRCS:.c=.o)

all:		${NAME}

${NAME}: 	${OBJS} ${LIBFT}
			ar rcs ${NAME} ${OBJS}
			@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

${LIBFT}:
			make bonus -C libft
			cp ${LIBFT} ${NAME}

.c.o:
			${CC} -c ${FLAGS} $< -o ${<:.c=.o} ${INCLUDE}
			@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"

clean:
			make clean -C libft
			${REMOVE} ${OBJS}
			@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:		clean
			make fclean -C libft
			${REMOVE} ${NAME}
			@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re :		fclean all

norm:		
			norminette

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 20:37:12 by acesar-l          #+#    #+#              #
#    Updated: 2022/02/28 13:23:44 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

LIB_PATH 	= ./library
LIBFT 		= ./libft/libft.a
LIBFTPRINTF	= ${LIB_PATH}/ft_printf.h
LIBS 		= -lftprintf

CC 		= clang

FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f
INCLUDE 	= -I ${LIB_PATH}

SRCS_PATH	= ./printf

SRCS 		= ${SRCS_PATH}/ft_printf.c			\
		${SRCS_PATH}/ft_argument_c.c			\
		${SRCS_PATH}/ft_arguments_d_i.c			\
		${SRCS_PATH}/ft_argument_p.c			\
		${SRCS_PATH}/ft_argument_percent.c		\
		${SRCS_PATH}/ft_argument_s.c			\
		${SRCS_PATH}/ft_argument_u.c			\
		${SRCS_PATH}/ft_arguments_x.c			\
		${SRCS_PATH}/ft_print_reversed_str.c		\
		${SRCS_PATH}/ft_free_ptr.c			\
		${SRCS_PATH}/ft_hex_length.c			\
		${SRCS_PATH}/ft_decimal_length.c		\
		${SRCS_PATH}/ft_decimal_converter_to_hex.c
			
OBJS 		= $(SRCS:.c=.o)

all:		${NAME}

${NAME}: 	${OBJS} ${LIBFT}
		@echo "\n$(NAME): $(GREEN)$(NAME) was created$(RESET)"
		ar -rcs ${NAME} ${OBJS}
		@echo

${LIBFT}:
		@echo
		make bonus -C libft
		cp ${LIBFT} ${NAME}

.c.o:
		@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
		${CC} -c ${FLAGS} $< -o ${<:.c=.o} ${INCLUDE}

clean:
		make clean -C libft
		@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
		${REMOVE} ${OBJS}
		@echo

fclean:
		make fclean -C libft
		@echo "\n$(NAME): $(RED)object files were deleted$(RESET)"
		${REMOVE} ${OBJS}
		@echo "\n$(NAME): $(RED)$(NAME) was deleted$(RESET)"
		${REMOVE} ${NAME}
		@echo

re :		fclean all

norm:		
		norminette

.PHONY:		all clean fclean re norm

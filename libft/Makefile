# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 17:02:42 by acesar-l          #+#    #+#              #
#    Updated: 2022/02/19 16:17:16 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

LIB_PATH 	= ../library
INCLUDE		= -I${LIB_PATH}
LIB 		= -lft

CC 		= clang

FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f

SRCS 		= ft_atoi.c 		\
		ft_bzero.c 		\
		ft_calloc.c 		\
		ft_isalnum.c 		\
		ft_isalpha.c 		\
		ft_isascii.c 		\
		ft_isdigit.c 		\
		ft_isprint.c 		\
		ft_itoa.c 		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c 		\
		ft_memmove.c 		\
		ft_memset.c 		\
		ft_putchar_fd.c 	\
		ft_putendl_fd.c 	\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c 		\
		ft_split.c 		\
		ft_strchr.c 		\
		ft_strdup.c 		\
		ft_striteri.c 		\
		ft_strjoin.c 		\
		ft_strlcat.c 		\
		ft_strlcpy.c 		\
		ft_strlen.c 		\
		ft_strmapi.c 		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strrchr.c 		\
		ft_strtrim.c		\
		ft_substr.c 		\
		ft_tolower.c 		\
		ft_toupper.c

BONUS_SRCS  =	ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstlast.c		\
		ft_lstmap.c		\
		ft_lstnew.c		\
		ft_lstsize.c

OBJS 		= $(SRCS:.c=.o)

BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

all:		${NAME}

${NAME}: 	${OBJS}
		ar -rcs ${NAME} ${OBJS}
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

bonus:		${NAME} ${BONUS_OBJS}
		ar -rcs ${NAME} ${BONUS_OBJS}
		@echo "$(NAME): $(GREEN)$(NAME) was created with Bonus$(RESET)"

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}
		@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"

clean:
		${REMOVE} ${OBJS} ${BONUS_OBJS}
		@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:		clean
		${REMOVE} ${NAME}
		@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re :		fclean all

norm:		
		norminette

.PHONY:		all clean fclean re bonus norm

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 12:45:38 by vvu               #+#    #+#              #
#    Updated: 2022/12/10 13:00:54 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC = ./srcs/

DIRINC = ./includes/

DIROBJ = ./objs/

DIRLIB = ./libft/

SRC = ft_put_ptr.c ft_put_hex.c ft_put_unsigned.c ft_printf.c ft_utils.c

SRCS = $(addprefix ${DIRSRC}, ${SRC})

HEAD = ./includes/

OBJS = ${SRCS:.c=.o}

NAME = libft.printf.a

NAMELFT = libft.a

CC = gcc
RM = -rm -f
AR = ar rc
RN = ranlib

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$

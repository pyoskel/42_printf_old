# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 00:58:05 by pbartoch          #+#    #+#              #
#    Updated: 2025/01/26 21:40:19 by pbartoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
CC = cc

SOURCE =	ft_printf.c \
			

OBJECTS = $(SOURCE:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Rule for compiling .c \ files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default rule
all: $(NAME)

# Clean object files
clean:
	@rm -f $(OBJECTS)

# Clean everything (object files and library)
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
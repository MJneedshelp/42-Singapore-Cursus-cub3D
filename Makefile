# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mintan <mintan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 22:10:59 by mintan            #+#    #+#              #
#    Updated: 2025/02/04 11:33:48 by mintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler + compile flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
LIBFLAGS = -Lminilibx-linux -lmlx -lXext -L/usr/lib/X11 -lX11 -lm -lz
INC = -Iminilibx-linux

# Definitions
NAME = cub3D
SRCDIR = src
LIBDIR = $(SRCDIR)/libft
LIBFT_LIB = $(LIBDIR)/libft.a


MLXDIR = minilibx-linux/
MLXREPO = https://github.com/42Paris/minilibx-linux.git
MLX_LIB = $(MLXDIR)/libmlx_Linux.a


# MJ TO POPULATE LATER
CUB3D_SRCS = $(SRCDIR)/main.c $(SRCDIR)/init_cub.c $(SRCDIR)/init_events.c
CUB3D_OBJ = $(CUB3D_SRCS:.c=.o)

# Target to make using Make all
all: $(NAME) print_art

# Generate the mandatory programme by compiling the objects with libft.a
# and libmlx_Linux.a
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(CUB3D_OBJ)
	$(CC) $(CFLAGS) $(CUB3D_OBJ) $(LIBFT_LIB) $(LIBFLAGS) -o $@

# Build the libft.a library
$(LIBFT_LIB):
	cd $(LIBDIR) && make all

# Git clone and build MLX
$(MLX_LIB):
	if [ ! -d $(MLXDIR) ] || [ ! -f $(MLX_LIB) ]; then \
		echo "mlx directory or mlx lib not found"; \
		echo "Clear directory, git clone, then remake mlx library"; \
		rm -rf $(MLXDIR); \
		git clone $(MLXREPO) $(MLXDIR); \
		cd $(MLXDIR) && make; \
	else \
		echo "mlx library present already"; \
	fi

# Generate all the .o files from the .c files for fractol
%.o: %.c
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

# Clear the build files
clean:
	rm -f $(CUB3D_OBJ)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean
	rm -rf $(MLXDIR)

# Rule to rebuild the target
re:	fclean all

print_art:
	@echo "      /\\"
	@echo " __   \\/   __"
	@echo " \\_\\_\\/\\/_/_/"
	@echo "   _\\_\\/_/_"
	@echo "  __/_/\\_\\__"
	@echo " /_/ /\\/\\ \\_\\"
	@echo "      /\\"
	@echo "      \\/"


# Phony targets
.PHONY: all clean re fclean print_art

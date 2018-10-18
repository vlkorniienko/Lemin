# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 15:32:54 by vkorniie          #+#    #+#              #
#    Updated: 2018/09/20 15:32:56 by vkorniie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

LIB_DIR := ./libft/
SRC_DIR := ./src/
OBJ_DIR := ./objects/
INC_DIR := ./inc/

SRCS := lem_in_first.c read_data.c write_links.c finish_validation.c number_five.c number_six.c seven.c last_file.c last_after_last.c
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC := gcc
FLAGS := -g -Wall -Wextra -Werror

LIBFT = $(LIB_DIR)libft.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)inc

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT)
	@	# -fsanitize=address

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	@ make -C $(LIB_DIR)

clean:
	@ make clean -C $(LIB_DIR)
	@ rm -f $(OBJ)
	

fclean:
	@ make fclean -C $(LIB_DIR)
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_DIR)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lezhang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 15:13:19 by lezhang           #+#    #+#              #
#    Updated: 2018/10/18 17:29:38 by lezhang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   Executable   #
##################

NAME = lem_in

#########################
#   Compilation flags   #
#########################

CC = gcc

FLAGS = -Wall -Wextra -Werror

#################
#   Directory   #
#################

SRCDIR = srcs

INCDIR = includes

OBJDIR = objs

LIBFTDIR = libft

###################
#   Source name   #
###################

FILLER = lem_in				\
		stock_file			\
		handle_info			\
		verif_tool			\
		verif_tool2			\
		check_tool			\
		print_error			\
		choose_path			\
		choose_path_tool	\
		algorithme			\
		find_path			\
		find_path_tool		\
		find_less			\
		print_fourmie		\
		print_fourmie_tool

##############
#   Source   #
##############

SRC = $(addprefix $(SRCDIR)/, $(addsuffix .c, $(FILLER)))

###############
#   Objects   #
###############

OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILLER)))

###############
#   Headers   #
###############

INCFILLER = -I $(INCDIR)

INCLIBFT = -I $(addprefix $(LIBFTDIR)/, $(INCDIR))

INC = $(INCLIBFT) $(INCFILLER)

###############
#   Library   #
###############

LIB = -L$(LIBFTDIR) -lft

###############
#   Targets   #
###############

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C $(LIBFTDIR)
	@ $(CC) $(FLAGS) $(OBJ) $(LIB) -o $@
	@ echo "$@			\033[1;32mCreate\033[0m"

clean:
	@ rm -rf $(OBJDIR)
	@ make clean -C $(LIBFTDIR)
	@ echo "$@ lem_in		\033[1;32mOK\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIBFTDIR)
	@ echo "Delete $(NAME)		\033[1;32mOK\033[0m"

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(FLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re

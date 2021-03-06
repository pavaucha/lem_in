# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lezhang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 09:41:15 by lezhang           #+#    #+#              #
#    Updated: 2018/10/02 17:34:30 by lezhang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################
#   File name to create   #
###########################

NAME = libft.a

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

PRINTFDIR = srcs/ft_printf

###################
#   Source name   #
###################

LIBFT = ft_memset		\
		ft_bzero		\
		ft_memcpy		\
		ft_memccpy		\
	  	ft_memmove		\
	  	ft_memchr		\
	  	ft_memcmp		\
	  	ft_strlen		\
	  	ft_strdup		\
	  	ft_strcpy		\
	  	ft_strncpy		\
	  	ft_strcat		\
	  	ft_strncat		\
	  	ft_strlcat		\
	  	ft_strchr		\
	  	ft_strrchr		\
	  	ft_strstr		\
	  	ft_strnstr		\
	  	ft_strcmp		\
	  	ft_strncmp		\
	  	ft_atoi			\
	  	ft_isalpha		\
	  	ft_isdigit		\
	  	ft_isalnum		\
	  	ft_isascii		\
	  	ft_isprint		\
	  	ft_toupper		\
	  	ft_tolower		\
	  	ft_memalloc		\
	  	ft_memdel		\
	  	ft_strnew		\
	  	ft_strdel		\
	  	ft_strdel_tab	\
	  	ft_strclr		\
	  	ft_striter		\
	  	ft_striteri		\
	  	ft_strmap		\
	  	ft_strmapi		\
	  	ft_strequ		\
	  	ft_strnequ		\
	  	ft_strsub		\
	  	ft_strjoin		\
	  	ft_strtrim		\
	  	ft_strsplit		\
	  	ft_itoa			\
	  	ft_putchar		\
	  	ft_putstr		\
	  	ft_putnstr		\
	  	ft_putendl		\
	  	ft_putnbr		\
	  	ft_putchar_fd	\
	  	ft_putstr_fd	\
	  	ft_putendl_fd	\
	  	ft_putnbr_fd	\
	  	ft_lstnew		\
	  	ft_lstdelone	\
	  	ft_lstdel		\
	  	ft_lstadd		\
	  	ft_lstiter		\
	  	ft_lstmap		\
	  	ft_power		\
	  	ft_itoa_base	\
	  	ft_atoi_base	\
	  	ft_num_len		\
		ft_putcolor		\
		ft_strswap		\
		ft_abs			\
		ft_swap			\
		ft_strnum		\
		get_next_line

PRINTF = ft_printf			\
		 ft_check_flags		\
		 ft_check_type		\
		 ft_get_val			\
		 ft_wchar			\
		 ft_wchar_len		\
		 ft_wstr			\
		 ft_wstr_len		\
		 ft_percent			\
		 ft_other			\
		 ft_di				\
		 ft_di2				\
		 ft_u				\
		 ft_o				\
		 ft_o2				\
		 ft_x				\
		 ft_x2				\
		 ft_p				\
		 ft_p2				\
		 ft_c				\
		 ft_s				\
		 ft_bigs

##############
#   Source   #
##############

SRCLIBFT = $(addprefix $(SRCDIR)/, $(addsuffix .c, $(LIBFT)))

SRCPRINTF = $(addprefix $(PRINTFDIR)/$(SRCDIR)/, $(addsuffix .c, $(PRINTF)))

SRC = $(SRCLIBFT) $(SRCPRINTF)

###############
#   Objects   #
###############

OBJLIBFT = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(LIBFT)))

OBJPRINTF = $(addprefix $(PRINTFDIR)/$(OBJDIR)/, $(addsuffix .o, $(PRINTF)))

OBJ = $(OBJLIBFT) $(OBJPRINTF)

###############
#   Headers   #
###############

INCLIBFT = -I $(INCDIR)

INC = $(INCLIBFT) $(INCPRINTF)

INCFILE = $(INCDIR)/libft.h			\
		  $(INCDIR)/ft_printf.h		\
		  $(INCDIR)/get_next_line.h	\
		  $(INCDIR)/color.h

###############
#   Targets   #
###############

all: $(NAME)

$(NAME): $(OBJ) $(INCFILE)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "La librairie $@	\033[1;32mCreate\033[0m"

clean:
	@ rm -rf $(OBJDIR)
	@ rm -rf $(PRINTFDIR)/$(OBJDIR)
	@ echo "$@ libft		\033[1;32mOK\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$@ libft		\033[1;32mOK\033[0m"

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(FLAGS) $(INC) -c $< -o $@

$(PRINTFDIR)/$(OBJDIR)/%.o: $(PRINTFDIR)/$(SRCDIR)/%.c
	@ mkdir -p $(PRINTFDIR)/$(OBJDIR)
	@ $(CC) $(FLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re

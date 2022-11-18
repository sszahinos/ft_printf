# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 09:56:12 by sersanch          #+#    #+#              #
#    Updated: 2022/11/18 11:30:57 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME	= libftprintf.a

HEADER	= libftprintf.h
INCLUDE	= -I 
SRC_DIR	= src/
OBJ_DIR	= obj/
INC_DIR = include/

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
AR		= ar -rcs
MKDIR	= mkdir -p
MV		= mv -f

#### FORMAT #####
RESET		:= \033[0m
BOLD		:= \033[1m
GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
LMAGENTA	:= \033[95m


##### FILES #####
SRC_FILES =	ft_isalpha.c \
			ft_isdigit.c 

##### OBJECTS #####
SRC_OBJS = $(SRC_FILES:.c=.o)

##### DEPENDENCIES #####
SRC_DEPS = $(SRC_FILES:.c=.d)

##### RULES #####
all: $(NAME)

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(NAME): $(SRC_OBJS)
	@$(AR) $(NAME) $(SRC_OBJS)
	@echo "$(BOLD)$(LMAGENTA)SRC $(GREEN)compilated succesfully!$(RESET)"

clean:
	@$(RM) $(SRC_OBJS) $(SRC_DEPS) 
	@echo "$(YELLOW)Objects and dependencies deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) $(YELLOW)deleted.$(RESET)"

re: fclean all

norm:
	$(NORM)
push:
	git add *.c Makefile *.h && git commit -m "Functions updated" && git push

folders:
	@$(MKDIR) ./$(OBJ_DIR)
	@$(MV) *.o ./$(SRC_DIR)/$(OBJ_DIR)

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm folders

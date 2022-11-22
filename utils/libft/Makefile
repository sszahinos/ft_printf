# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:30:33 by sersanch          #+#    #+#              #
#    Updated: 2022/11/21 17:46:45 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME	= libft.a

HEADER	= libft.h
INCLUDE	= -I 
PATH	= utils/libft
SRC_DIR	= src
OBJ_DIR	= obj
DEP_DIR = dep
INC_DIR	= include

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
RMALL	= rm -rf
AR		= ar -rcs
MKDIR	= mkdir -p
#MV		= mv -f

#### FORMAT #####
RESET		:= \033[0m
BOLD		:= \033[1m
GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
LMAGENTA	:= \033[95m


##### FILES #####
SRC_FILES =	./$(SRC_DIR)/ft_putchar.c \
			./$(SRC_DIR)/ft_putstr.c \
			./$(SRC_DIR)/ft_putnbr.c

##### OBJECTS #####
SRC_OBJS = $(SRC_FILES:.c=.o)

##### DEPENDENCIES #####
SRC_DEPS = $(SRC_FILES:.c=.d)

##### RULES #####
all: folders $(NAME)
#	@make folders

./$(SRC_DIR)/%.o: ./$(SRC_DIR)/%.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) ./$(INC_DIR)/$(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(NAME): $(SRC_OBJS)
	@$(AR) $(NAME) $(SRC_OBJS)
#	@make folders
	@make movefiles
	@touch $(NAME) 
	@echo "$(BOLD)$(LMAGENTA)$(NAME) $(GREEN)compilated succesfully!$(RESET)"

clean:
	#$(RM) $(SRC_DIR)/$(SRC_OBJS) $(SRC_DIR)/$(SRC_DEPS) 
	$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(NAME) $(YELLOW)objects and dependencies deleted.$(RESET)"

fclean: #clean --> Clean executed on main Makefile
	@$(RM) $(NAME)
	@$(RMALL) ./$(PATH)/$(SRC_DIR)/$(OBJ_DIR) ./$(PATH)/$(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(NAME) $(YELLOW)$(YELLOW)deleted.$(RESET)"

re: fclean all

norm:
	$(NORM)

push:
	git add ft_*.c && git commit -m "Functions updated" && git push

folders:
	$(MKDIR) $(SRC_DIR)/$(OBJ_DIR)
	@$(MKDIR) $(SRC_DIR)/$(DEP_DIR)

movefiles:
	mv $(SRC_DIR)/*.o $(SRC_DIR)/$(OBJ_DIR)/*.o
#	@mv ./$(SRC_DIR)/*.d ./$(SRC_DIR)/$(DEP_DIR)/

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm folders movefiles

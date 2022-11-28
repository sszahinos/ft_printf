# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 09:56:12 by sersanch          #+#    #+#              #
#    Updated: 2022/11/28 10:37:57 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME		= libftprintf.a
LBF_NAME	= libft.a 

HEADER	= libftprintf.h
INCLUDE	= -I 
SRC_DIR	= src
OBJ_DIR	= obj
DEP_DIR = dep
INC_DIR = include
LBF_DIR = utils/libft
TST_DIR = test

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
RMALL	= rm -rf
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
SRC_FILES =	ft_printf
TST_FILES = test_main.c

SRC	= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ	= $(addprefix $(SRC_DIR)/$(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
DEP	= $(addprefix $(SRC_DIR)/$(DEP_DIR)/, $(addsuffix .d, $(SRC_FILES)))

##### RULES #####
all: make_libft folders $(NAME)

$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) $(LBF_DIR)/$(LBF_NAME) Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) $(INC_DIR)/$(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(NAME): $(OBJ)
	@make import_utils
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BOLD)$(LMAGENTA)$(NAME) $(GREEN)compilated succesfully!$(RESET)"

make_libft:
	@make -C $(LBF_DIR)

clean:
	@make clean -C $(LBF_DIR)
	@$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(NAME) $(YELLOW)objects and dependencies deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LBF_DIR)
	@echo "$(CYAN)$(NAME)$(YELLOW) deleted.$(RESET)"

re: fclean all

norm:
	$(NORM)

push:
	git add *.c Makefile *.h && git commit -m "Functions updated" && git push

folders:
	@$(MKDIR) $(SRC_DIR)/$(OBJ_DIR)
	@$(MKDIR) $(SRC_DIR)/$(DEP_DIR)

import_utils:
	@cp $(LBF_DIR)/$(LBF_NAME) ./$(NAME)
	@echo "$(GREEN)Imported $(CYAN)$(LBF_NAME)$(RESET)"

test:
	@make re
	@$(CC) $(CFLAGS) $(NAME) $(TST_DIR)/$(TST_FILES)
	@echo "$(GREEN)Test compiled$(RESET)"
	@./a.out

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm folders make_libft folders import_utils test

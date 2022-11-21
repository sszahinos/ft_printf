# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:30:33 by sersanch          #+#    #+#              #
#    Updated: 2022/11/21 09:31:07 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### VARIABLES #####
NAME	= libft.a

HEADER	= libft.h
INCLUDE	= -I 
SRC_DIR	= src
OBJ_DIR	= obj
DEP_DIR = dep
INC_DIR	= include

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
SRC_FILES =	./$(SRC_DIR)/ft_putchar.c \
			./$(SRC_DIR)/ft_putstr.c \
			./$(SRC_DIR)/ft_putnbr.c

##### OBJECTS #####
SRC_OBJS = $(SRC_FILES:.c=.o)

##### DEPENDENCIES #####
SRC_DEPS = $(SRC_FILES:.c=.d)

##### RULES #####
all: folders $(NAME)

./$(SRC_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	$(CC) $(CFLAGS) -MMD $(INCLUDE) ./$(INC_DIR)/$(HEADER) -c $< -o $@
	@echo "$(CYAN)$< $(GREEN)✓$(RESET)"

$(NAME): $(SRC_OBJS)
	@$(AR) $(NAME) $(SRC_OBJS)
	@make folders
	@move_files
	@echo "$(BOLD)$(LMAGENTA)SRC $(GREEN)compilated succesfully!$(RESET)"

clean:
	@$(RM) $(SRC_OBJS) $(SRC_DEPS) 
	@echo "$(YELLOW)Objects and dependencies deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME) 
	@echo "$(CYAN)$(NAME) $(YELLOW)and $(CYAN)$(BNUS) $(YELLOW)deleted.$(RESET)"

re: fclean all

norm:
	$(NORM)
push:
	git add ft_*.c && git commit -m "Functions updated" && git push

folders:
	@$(MKDIR) ./$(SRC_DIR)/$(OBJ_DIR)
	@$(MKDIR) ./$(SRC_DIR)/$(DEP_DIR)

move_files:
	$(MV) ./$(SRC_DIR)/*.o ./$(SRC_DIR)/$(OBJ_DIR)/
	$(MV) ./$(SRC_DIR)/*.d ./$(SRC_DIR)/$(DEP_DIR)/

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm folders move_files

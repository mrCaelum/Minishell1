##
## EPITECH CPE_solostumper_2_2018, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc
ECHO	=	echo -e

LIGHT   =   \e[0m
BOLD    =   \e[1m
BLACK   =   \e[30m
RED     =   \e[31m
GREEN   =   \e[32m
YELLOW  =   \e[33m
BLUE    =   \e[34m
PURPLE  =   \e[35m
CYAN    =   \e[36m
WHITE   =   \e[37m
DEFAULT =   \e[0;37m

INFO    =   $(BOLD)$(GREEN)[INFO]\t$(WHITE)
WARNING =   $(BOLD)$(YELLOW)[WARNING]\t$(WHITE)
ERROR   =   $(BOLD)$(RED)[ERROR]\t$(WHITE)

BIN_DIR	=	./bin/
SRC_DIR	=	./src/
OBJ_DIR	=	./obj/
INC_DIR	=	./include/

SRC	=	$(wildcard $(SRC_DIR)*.c)	\
		$(wildcard $(SRC_DIR)str/*.c)
OBJ	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CFLAGS	=	-I$(INC_DIR)

NAME	=	mysh

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -g -o $(BIN_DIR)$(NAME)
	@cp $(BIN_DIR)$(NAME) .
	@$(ECHO) "$(INFO)Build complete !$(DEFAULT)"

$(OBJ): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -g -c $< -o $@

all:	$(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(BIN_DIR)$(NAME)
	@$(ECHO) "$(INFO)Files removed !$(DEFAULT)"

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

setup:
	@$(ECHO) "\n$(BOLD)$(WHITE)Project setup : $(CYAN)$(NAME)$(DEFAULT)\n"
	@mkdir -p $(BIN_DIR) && $(ECHO) "$(INFO)$(BIN_DIR)\t\t$(GREEN)[OK]$(DEFAULT)" || $(ECHO) "$(ERROR)$(BIN_DIR)\t\t$(RED)[x]$(DEFAULT)"
	@touch $(BIN_DIR).gitignore
	@mkdir -p $(SRC_DIR) && $(ECHO) "$(INFO)$(SRC_DIR)\t\t$(GREEN)[OK]$(DEFAULT)" || $(ECHO) "$(ERROR)$(SRC_DIR)\t\t$(RED)[x]$(DEFAULT)"
	@touch $(SRC_DIR).gitignore
	@mkdir -p $(OBJ_DIR) && $(ECHO) "$(INFO)$(OBJ_DIR)\t\t$(GREEN)[OK]$(DEFAULT)" || $(ECHO) "$(ERROR)$(OBJ_DIR)\t\t$(RED)[x]$(DEFAULT)"
	@touch $(OBJ_DIR).gitignore
	@mkdir -p $(INC_DIR) && $(ECHO) "$(INFO)$(INC_DIR)\t$(GREEN)[OK]$(DEFAULT)" || $(ECHO) "$(ERROR)$(INC_DIR)\t$(RED)[x]$(DEFAULT)"
	@touch $(INC_DIR).gitignore
	@$(ECHO) "\n"

.PHONY: all clean fclean setup re

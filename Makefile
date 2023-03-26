CC		= cc
FLAGS	= -Wall -Wextra -Werror -IINC  -pthread

NAME	= philosophers

INC	= inc
SRC_PATH	= src
OBJ_PATH	= obj

SRCS = philo.c

		
SRC		= $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling Philosophers...$(NOC)"
	@$(CC) -IINC  -o $@ $^ 
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INC) -c -o $@ $<
	
clean:
	@echo "$(RED)Deleting Philo OBJS ✔️ $(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJB_PATH)

fclean: clean
	@echo "$(RED)Deleting Philo Binary ✔️$(NOC)"
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re 
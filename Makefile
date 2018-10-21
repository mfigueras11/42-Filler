NAME = mfiguera.filler
FILES = filler solving cleaning
SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = includes
OBJECTS = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))
SOURCES = $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))
HEADER = $(addsuffix .h, $(addprefix $(INC_DIR)/, filler))
FLAGS = -Wall -Werror -Wextra
LIBRARY = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS) $(LIBRARY)
	@gcc $(FLAGS) $(OBJECTS) -o $(NAME) $(LIBRARY) -I $(INC_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBRARY):
	@make -C libft

clean:
	@make -C libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean $(NAME)

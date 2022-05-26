NAME = badminton

CC   = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM   = rm -f
INC  = -Iinclude -Ilibft
LIB  = -Llibft -lft

MAIN = main.c
ERROR_DIR = src/error/
MATCH_DIR = src/match/
PLAYER_DIR = src/player/
UTILS_DIR = src/utils
SRC  = $(addprefix $(ERROR_DIR), error_handler.c) \
       $(addprefix $(MATCH_DIR), match_add.c match_del.c) \
	   $(addprefix $(PLAYER_DIR), player_del.c player_get.c player_reset.c \
	   player_set.c player_sort.c) \
	   #$(addprefix $(UTILS_DIR), )
OBJ  = $(SRC:.c=.o)

LIBFT_PATH = ./libft

all: $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $@ $(MAIN) $(OBJ) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: clean 
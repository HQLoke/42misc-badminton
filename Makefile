NAME = badminton

CC   = gcc
CFLAGS = -g3 -fsanitize=address
RM   = rm -f
INC  = -Iinclude -Ilibft
LIB  = -Llibft -lft

MAIN = src/main.c
INIT_DIR   = src/init/
MATCH_DIR  = src/match/
PLAYER_DIR = src/player/
OUTPUT_DIR = src/output/
UTILS_DIR  = src/utils/
SRC  = $(addprefix $(INIT_DIR), init.c) \
       $(addprefix $(MATCH_DIR), match_add.c mmr_calc.c) \
	   $(addprefix $(PLAYER_DIR), player_add.c player_del.c player_get.c \
	   player_reset.c player_set.c player_sort.c) \
	   $(addprefix $(OUTPUT_DIR), beautiful_output.c update_player_data.c) \
	   $(addprefix $(UTILS_DIR), ft_close.c ft_memdel.c ft_open.c)
OBJ  = $(SRC:.c=.o)

LIBFT_PATH = ./libft

all: $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJ) $(MAIN)
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

norm:
	norminette include/* src/*

.PHONY: clean 
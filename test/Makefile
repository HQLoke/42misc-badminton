# Implicit variables
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I../include -I../libft -g -fsanitize=address
LDFLAGS	=	-L.. -L../libft
LDLIBS	=	-lft -lm
SRCS	=	$(wildcard */test*.c)
FILES	=	$(notdir $(SRCS))
MAINS	=	$(FILES:test_%.c=%)

# Something extra to try
ORIDIR  =   ../src/

all: $(MAINS)

echo:
	echo $(MAINS)

%: */test_%.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS) $(ORIDIR)*/$@.c
	@echo Testing $<:
	@./$@
	@$(RM) $@

clean:
	@echo "Removing test executables..."
	$(RM) $(MAINS)

fclean: clean
	@$(MAKE) --no-print-directory -C .. fclean

re: fclean all

norm:
	norminette */*.c

.PHONY: clean librt norm
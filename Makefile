NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c check_input.c free_all.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)  $(LIBFT)
	$(CC) $(OBJ)  $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

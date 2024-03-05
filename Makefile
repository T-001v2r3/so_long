NAME			=   so_long
SRCS			=   ./src/main.c ./src/map_reader.c ./src/graphics/graphics.c \
					./src/graphics/graphicshelper.c ./src/moves/moves.c ./src/moves/moveshandler.c \
					./src/utils/get_next_line.c ./src/utils/get_next_line_utils.c \
					./src/utils/ft_printf_utils.c ./src/utils/ft_printf.c ./src/utils/functions.c \
					./src/utils/fillin.c ./src/graphics/anims.c ./src/graphics/anims2.c
OBJS			=   $(SRCS:.c=.o)
CC              =   cc
RM              =   rm -f
CFLAGS          =   -Wall -Wextra -Werror# -fsanitize=address -g
IFLAGS          =   -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBMLX          =   minilibx-linux/libmlx.a

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBMLX) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

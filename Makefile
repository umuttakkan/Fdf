CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f
NAME = fdf
LIBS = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
SRCS =  ft_printf/*.c libft/*.c get_next_line/*.c sources/color.c sources/controls_utils.c sources/controls.c sources/convert.c sources/draw.c sources/init.c sources/keyboard_controls.c sources/main.c sources/menu.c sources/mouse_controls.c sources/project.c sources/read_map.c sources/read_stack.c sources/utils.c sources/utils2.c
${NAME}:
	${CC} ${CFLAGS} ${SRCS} ${LIBS} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
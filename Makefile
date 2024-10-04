CC = cc
NAME = so_long

MINILIBX_DIR = ./mlx_linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

SRCS =  get_next_line.c\
        get_next_line_utils.c\
        copy_map_add_lines.c\
        ft_split.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(MINILIBX_DIR)
LDFLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

# .c 파일을 .o 파일로 컴파일하는 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 최종 실행 파일을 만드는 규칙
$(NAME): $(MINILIBX_LIB) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

# MinilibX 라이브러리 빌드
$(MINILIBX_LIB):
	make -C $(MINILIBX_DIR)

clean:
	make -C $(MINILIBX_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

NAME		:= FdF
BONUS_NAME	:= FdF_bonus
CFLAGS		:= -Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBMLX		:= ./MLX42
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

HEADERS		:= -I ./include -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -L$(LIBFT_DIR) -lft
SRCS		:= main.c get_data.c draw_map.c coloring.c calculations.c calculations_two.c
BONUS_SRCS	:= bonus/main_bonus.c bonus/key_commands_bonus.c bonus/get_data_bonus.c bonus/draw_map_bonus.c bonus/coloring_bonus.c bonus/calculations_bonus.c bonus/calculations_two_bonus.c
OBJS		:= $(SRCS:.c=.o)
BONUS_OBJS	:= $(BONUS_SRCS:.c=.o)

all: $(LIBFT) libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

bonus: $(LIBFT) libmlx $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_NAME)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx bonus main

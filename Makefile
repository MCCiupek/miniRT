CC =			clang

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

DIR_OBJS =		./

MLX_DIR = 		./
				# /usr/local/lib/

MLX_HEADER = 	./includes/
				# /usr/local/include/

FLAGS		=	-g

MLX_FLAGS	=	-lmlx

MACOS_FLAGS =	-framework OpenGL -framework AppKit

LINUX_FLAGS =	-lX11 -lXext -lm

LIBMLX =		libmlx.a

LIBFT =			libft.a

FSAN =			-fsanitize=address

SRC =			gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				\
				parser/parse_scene.c \
				parser/parse_shapes.c \
				parser/parser.c \
				\
				vectors/init.c \
				vectors/operations.c \
				vectors/products.c \
				vectors/rotation.c \
				vectors/utils.c \
				\
				intersect/intersect.c \
				intersect/intersect_cy.c \
				intersect/intersect_pl.c \
				intersect/intersect_sp.c \
				intersect/intersect_sq.c \
				intersect/intersect_tr.c \
				intersect/ray.c \
				\
				light/light.c \
				light/shadows.c \
				light/colors.c \
				\
				display/display.c \
				display/save.c \
				\
				error.c \
				\
				main.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(FLAGS) $(FSAN)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

UNAME := 		$(shell uname)

ifeq ($(UNAME),Darwin)
	MLX_FLAGS += $(MACOS_FLAGS)
	MLX_DIR = ./mlx
endif

ifeq ($(UNAME),Linux)
	MLX_FLAGS += $(LINUX_FLAGS)
	MLX_DIR = ./mlx_linux
endif

all:			$(NAME)

$(NAME) :		$(OBJS)
				@$(MAKE) bonus -C ./libft
				@cp ./libft/libft.a libft.a && cp ./libft/libft.h $(DIR_HEADERS)/libft.h
				@$(MAKE) CFLAGS="-w" -C $(MLX_DIR)
				@cp $(MLX_DIR)/$(LIBMLX) ./$(LIBMLX) && cp $(MLX_DIR)/mlx.h $(MLX_HEADER)mlx.h
				@$(CC) $(COMPIL) -I $(DIR_HEADERS) -I $(MLX_HEADER) $(LIBFT) $(OBJS) -o $(NAME) -L $(MLX_DIR) $(MLX_FLAGS)

%.o: %.c
				@$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"
		
bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(MAKE) clean -C ./libft
				$(MAKE) clean -C $(MLX_DIR)
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(LIBMLX)
				$(RM) $(MLX_HEADER)mlx.h
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus, norme
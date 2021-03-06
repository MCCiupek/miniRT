SHELL :=		/bin/bash

CC =			clang

FLAGS =			-Wall -Wextra -Werror -g

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

MLX_DIR = 		./

MLX_HEADER = 	/usr/local/include/

MLX_LIB = 		/usr/local/lib/

MLX_FLAGS	=	-lmlx

MACOS_FLAGS =	-framework OpenGL -framework AppKit

LINUX_FLAGS =	-lXext -lX11 -lm

LIBMLX =		libmlx.a

LIBFT =			libft.a

FSAN =			-fsanitize=address

SRC =			gnl/get_next_line_utils.c \
				gnl/get_next_line_utils2.c \
				gnl/get_next_line.c \
				\
				parser/parse_scene.c \
				parser/parse_shapes.c \
				parser/parse_utils.c \
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
				display/mlx_utils.c \
				\
				error.c \
				\
				utils.c \
				\
				main.c

SRC_BONUS =		gnl/get_next_line_utils.c \
				gnl/get_next_line_utils2.c \
				gnl/get_next_line.c \
				\
				parser/parse_scene.c \
				parser/parse_shapes.c \
				parser/parse_utils.c \
				parser/parser.c \
				\
				vectors/init.c \
				vectors/operations.c \
				vectors/products.c \
				vectors/rotation.c \
				vectors/utils.c \
				\
				intersect/intersect.c \
				intersect/intersect_cy_bonus.c \
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
				display/mlx_utils.c \
				\
				error.c \
				\
				utils.c \
				\
				main.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

SRCS_BONUS =	$(addprefix $(DIR_SRCS), $(SRC_BONUS))

COMPIL =		$(FLAGS)# $(FSAN)

OBJS =			$(SRCS:.c=.o)

OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

NAME =			miniRT

UNAME := 		$(shell uname)

CP_MLX_H =		@cp $(MLX_DIR)/*.h $(MLX_HEADER)

CP_MLX_LIB =	@cp $(MLX_DIR)/$(LIBMLX) $(MLX_LIB)

ifeq ($(UNAME),Darwin)
	Y_MAX := $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$4}')
	X_MAX := $(shell system_profiler SPDisplaysDataType | grep Resolution | awk '{print $$2}')
	RES = -D RES_X_MAX=$(X_MAX) -D RES_Y_MAX=$(Y_MAX)
	CP_MLX_H = @echo "Using local mlx headers"
	CP_MLX_LIB = @echo "Using local mlx library"
	MLX_DIR = ./mlx
	MLX_FLAGS += $(MACOS_FLAGS)
	COMPIL += -Lmlx -lmlx $(MACOS_FLAGS)
	FLAGS += -I$(DIR_HEADERS) -Imlx
	OS = -D MACOS
endif

ifeq ($(UNAME),Linux)
	CP_MLX_H += && echo "Copying mlx headers"
	CP_MLX_LIB += && echo "Copying mlx library"
	MLX_DIR = ./mlx_linux
	MLX_FLAGS = -Lmlx -lmlx -L$(MLX_LIB) -Imlx_linux $(LINUX_FLAGS)
	FLAGS += -I$(DIR_HEADERS) -I$(MLX_HEADER) -Imlx_linux
	OS = -D LINUX
	X_MAX = 0
	Y_MAX = 0
	RES = -D RES_X_MAX=$(X_MAX) -D RES_Y_MAX=$(Y_MAX)
endif

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(MAKE) -C ./libft bonus
				@cp ./libft/$(LIBFT) $(LIBFT) && cp ./libft/libft.h $(DIR_HEADERS)/libft.h
				$(CP_MLX_H)
				@$(MAKE) CFLAGS="-w" -C $(MLX_DIR)
				$(CP_MLX_LIB)
				@$(CC) $(COMPIL) $(OS) $(RES) $(OBJS) $(MLX_FLAGS) -L $(LIB)libft -lft -o $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) $(OS) $(RES) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus:			$(OBJS_BONUS)
				@$(MAKE) -C ./libft bonus
				@cp ./libft/$(LIBFT) $(LIBFT) && cp ./libft/libft.h $(DIR_HEADERS)/libft.h
				$(CP_MLX_H)
				@$(MAKE) CFLAGS="-w" -C $(MLX_DIR)
				$(CP_MLX_LIB)
				@$(CC) $(COMPIL) $(OS) $(RES) $(OBJS_BONUS) $(MLX_FLAGS) -L $(LIB)libft -lft -o $(NAME)

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)
				norminette ./libft/

clean:
				$(MAKE) -C ./libft clean
				$(MAKE) -C $(MLX_DIR) clean
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(MAKE) -C ./libft fclean
				$(RM) $(LIBFT)
				$(RM) $(LIBMLX)
				$(RM) $(NAME)

git:			fclean
				git add .
				git commit -m "$(shell date)"
				git push

re:				fclean all

.PHONY:			all, clean, fclean, re, norme, git, bonus

SRCS	= so_long.c \
		  actions.c \
		  events.c \
		  map_array.c \
		  make_nice_window.c \
		  map_renderization.c \
		  map_validation.c \
		  put_assets.c \
		  path_validation.c \
		  utils_path_validation.c \

NAME	= so_long

CC		= cc -Wall -Wextra -Werror

LIBPATH	= ./libft

MLXPATH	= ./minilibx_mms_20200219

LIBLIB	= ./libft.a

MLXLIB	= ./libmlx.dylib

RM		= rm -rf

AR		= ar -rcs

DEBUG	= debugging

$(NAME): $(SRCS)  
		@cd $(LIBPATH) && make && cp libft.a ../ 
		@cd $(MLXPATH) && make && cp libmlx.dylib ../
		@$(CC) $(SRCS) $(LIBLIB) $(MLXLIB) -o $(NAME)

$(DEBUG): $(SRCS)  
		@cd $(LIBPATH) && make && cp libft.a ../ 
		@cd $(MLXPATH) && make && cp libmlx.dylib ../
		@$(CC) -g $(SRCS) $(LIBLIB) $(MLXLIB) -o $(NAME)

all: $(NAME)

clean:
		@$(RM) $(LIBLIB) $(MLXLIB) so_long.dSYM libmlx.dylib.dSYM 

fclean:
		@$(RM) $(NAME) $(LIBLIB) $(MLXLIB) so_long.dSYM libmlx.dylib.dSYM
		@cd $(LIBPATH) && make fclean
		@cd $(MLXPATH) && make clean

re: fclean all

debug: $(DEBUG)
		
.PHONY:	all clean fclean re debug

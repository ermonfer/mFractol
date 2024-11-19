NAME 	:= fractol
MLX := lib/minilibx-linux/libmlx_Linux.a
LIBFT := lib/libft/libft.a

#Compilador y Flags
CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -Ofast -march=native -funroll-loops
HEADERS	:= -I/usr/local/include -I./minilibx-linux

#Archivos fuente y directorios
DIR_MANDATORY	:= mandatory
SRC_MAN	:= $(wildcard $(DIR_MANDATORY)/*.c) #Esto recuerdo que luego habrá que incluirlos explicitamente por norma
OBJ_MAN:= ${SRC_MAN:.c=.o}
DIR_BONUS	:= bonus
SRC_BONUS	:= $(wildcard $(DIR_BONUS)/*.c) #Esto recuerdo que luego habrá que incluirlos explicitamente por norma
OBJ_BONUS:= ${SRC_BONUS:.c=.o}

#Librerias 
LIBS := -L/usr/local/lib -L./lib/minilibx-linux -L./lib/libft
LIBS := $(LIBS) -lmlx_Linux -lft -lXext -lX11 -lm -lbsd

#Archivo final
OUTDIR := .
OUT := $(OUTDIR)/$(NAME)

#Reglas de compilación

all: $(OUT)

$(OUT): $(MLX) $(LIBFT) $(OBJ_MAN)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ $(OBJ_MAN) $(LIBS) $(LDFLAGS)

bonus: $(OUTDIR)/.cache_bonus
	@touch $(OUTDIR)/.cache_bonus

$(OUTDIR)/.cache_bonus: $(MLX) $(LIBFT) $(OBJ_BONUS) 
	$(CC) $(CFLAGS) $(HEADERS) -o $(OUT) $(OBJ_BONUS) $(LIBS) $(LDFLAGS)
	
$(MLX):
	make -C ./lib/minilibx-linux

$(LIBFT):
	make -C ./lib/libft

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Limpiar los archivos y el ejecutable
clean:
	make -C ./lib/libft clean
	rm -f $(OBJ_MAN) $(OBJ_BONUS)

fclean: clean
	make -C ./lib/libft fclean
	make -C ./lib/minilibx-linux clean
	rm -f $(OUT)
	rm -f $(OUTDIR)/.cache_bonus

re: fclean $(OUT)

.PHONY: all bonus clean fclean re
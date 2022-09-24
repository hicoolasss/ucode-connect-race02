NAME = way_home
SRC_D = src
INC_D = inc
SRC_F = src/*.c
CFLAGS = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
RM = rm -rf
all: clean $(NAME)

$(NAME):
	@$(CFLAGS) $(SRC_F) -o $@ -I $(INC_D)

clean:
	@$(RM) $(NAME)

uninstall: clean
	@$(RM) $(NAME)

reinstall: uninstall all

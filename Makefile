# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # ! TODO -Werror
LIB_CC			=	ar -crT
COMPILE			=	$(CC) $(FLAGS)
LIB_NAME		=	libftprintf.a

# Binaries variables
TOOLS_SRC		=	tools/ft_hasany.c \
					tools/ft_get_argc.c

ROOT_SRC		=	ft_printf.c

CONVERTER_SRC	=	#converter/atoi.c

MANDATORY_SRC	=	$(TOOLS_SRC) $(ROOT_SRC) $(CONVERTER_SRC)
MANDATORY		=	${MANDATORY_SRC:%.c=bin/%.o}

# Triggers
all: $(LIB_NAME)

$(LIB_NAME): libft.a $(MANDATORY) 
	$(info Compiling mandatory into $(LIB_NAME))
	@$(LIB_CC) $(LIB_NAME) $^

bin/%.o: %.c
	@echo "- Compiling $< -> $@"
	@mkdir -p $(dir $@)
	@if [ ! "$(dir $^)" = "./" ]; then cp -u libft.h $(dir $^); cp -u ft_printf.h $(dir $^); fi
	@$(COMPILE) -c $< -o $@

# Libft
libft:
	$(info Obtaining latest version of Libft)
	@if [ ! -d libft ]; then git clone https://github.com/Jkutkut/42Madrid-Libft.git libft; fi

libft.a: libft
	$(info Compiling library and moving libft.a, libft.h to the root directory)
	make bonus -C ./libft
	@cp ./libft/libft.a .
	@cp ./libft/libft.h .

# Tests
setup_run: $(LIB_NAME) libft.h
	@cp -f libft.h tests/
	@cp -f ft_printf.h tests/

run_%: setup_run tests/%_test.c
	@echo "Compiling test using main form $(word 2, $^)"
	$(COMPILE) $(word 2, $^) $(LIB_NAME) -o run

# Clean logic
.PHONY: re fclean

re: fclean all

fclean:
	$(info Removing $(LIB_NAME))
	@rm -f $(LIB_NAME)
	$(info Removing binary directory)
	@rm -rf ./bin
	$(info Removing libft library)
	@rm -rf ./libft ./libft.a ./libft.h
	$(info Removing .h files from directories)
	@rm -f ./tests/libft.h ./tests/ft_printf.h
	@rm -f ./tools/libft.h ./tools/ft_printf.h
	$(info Removing executables from root directory)
	@rm -f ./run
	$(info Project now clean.)

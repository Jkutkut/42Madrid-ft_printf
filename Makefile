# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # ! TODO -Werror
LIB_CC			=	ar -crT
COMPILE			=	@$(CC) $(FLAGS)
LIB_NAME		=	libftprintf.a

# Binaries variables
ROOT_SRC		=	ft_printf.c
ROOT_BIN		=	${ROOT_SRC:%.c=bin/%.o}

CONVERTER_SRC	=	converter/atoi.c
CONVERTER_BIN	=	${CONVERTER:%.c=bin/%.o}

MANDATORY		=	$(ROOT_BIN) # $(CONVERTER_BIN)

# Triggers
all: $(LIB_NAME)

$(LIB_NAME): libft.a $(MANDATORY) 
	$(info Compiling mandatory into $(LIB_NAME))
	@$(LIB_CC) $(LIB_NAME) $^

bin/%.o: %.c
	@echo "- Compiling $< -> $@"
	@mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@

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
MAIN			=	tests/basic_test.c
run_test: $(LIB_NAME) libft.h
	@cp -f libft.h tests/
	@cp -f ft_printf.h tests/
	$(COMPILE) $(MAIN) $(LIB_NAME) -o run

run: run_test
	./run

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
	$(info Removing .h files from test directory)
	@rm -f ./tests/libft.h ./tests/ft_printf.h
	$(info Project now clean.)

# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # ! TODO -Werror
LIB_CC			=	ar -crs
COMPILE			=	@$(CC) $(FLAGS)
LIB_NAME		=	libftprintf.a


# Binaries variables
CONVERTER_SRC	=	converter/atoi.c

CONVERTER_BIN	=	${CONVERTER:%.c=bin/%.o}

MANDATORY		=	$(CONVERTER_BIN)

# Triggers
all: $(LIB_NAME)

$(LIB_NAME): $(MANDATORY)
	$(info Compiling mandatory into $(LIB_NAME))
	@$(LIB_CC) $(LIB_NAME) $^

bin/%.o: %.c
	@echo "- Compiling $< -> $@"
	@mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@

# Clean logic
.PHONY: re fclean

re: fclean all

fclean:
	$(info Removing $(LIB_NAME))
	@rm -f $(LIB_NAME)
	$(info Removing binary directory)
	@rm -rf ./bin
	$(info Project now clean.)

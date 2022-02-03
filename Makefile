# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
# FLAGS			=	-Wall -Wextra # ! TODO -Werror
LIB_CC			=	ar cr
COMPILE			=	$(CC) $(FLAGS)
LIB_NAME		=	libftprintf.a

# Colors:
NC				=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
LRED			=	\033[1;31m
LGREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
LBLUE			=	\033[1;34m
TITLE			=	\033[38;5;33m

# Binaries variables
TOOLS_SRC		=	tools/ft_get_argc.c \
					tools/ft_hasany.c \
					tools/ft_putnstr.c \
					tools/ft_super_itoa.c

ROOT_SRC		=	ft_printf.c

CONVERTER_SRC	=	#converter/atoi.c

MANDATORY_SRC	=	$(TOOLS_SRC) $(ROOT_SRC) $(CONVERTER_SRC)
MANDATORY		=	${MANDATORY_SRC:%.c=bin/%.o}

# Triggers
all: $(LIB_NAME)

$(LIB_NAME): libft.a $(MANDATORY) 
	@echo "Compiling ${YELLOW}mandatory${NC} into ${TITLE}$(LIB_NAME)${NC}"
	@$(LIB_CC) $(LIB_NAME) $^

bin/%.o: %.c
	@echo "- ${LBLUE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@if [ ! "$(dir $^)" = "./" ]; then cp -f libft.h $(dir $^); cp -f ft_printf.h $(dir $^); fi
	@$(COMPILE) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

# Libft
libft:
	@echo "Obtaining latest version of ${GREEN}Libft${NC} from ${LBLUE}GitHub${NC}..."
	@if [ ! -d libft ]; then git clone https://github.com/Jkutkut/42Madrid-Libft.git libft; fi

libft.a: libft
	@echo "\n${TITLE}Compiling library${NC} and ${YELLOW}moving libft.a, libft.h to the root directory${NC}"
	make bonus -C ./libft
	@cp ./libft/libft.a .
	@cp ./libft/libft.h .

# Tests
setup_run: $(LIB_NAME) libft.h
	@cp -f libft.h tests/
	@cp -f ft_printf.h tests/

run_%: setup_run tests/%_test.c libft.a $(LIB_NAME)
	@echo "${TITLE}Compiling test${NC} using main form ${YELLOW}$(word 2, $^)${NC}\c"
	@$(COMPILE) $(word 2, $^) $(LIB_NAME) -o run -fsanitize=address
	@echo " ${GREEN}[OK]${NC}"

# Clean logic
.PHONY: re fclean

re: fclean all

fclean: clean

clean:
	@echo "${TITLE}Cleaning${NC} ${YELLOW}Project${NC}"
	@echo "- ${RED}Removing${NC} $(LIB_NAME)"
	@rm -f $(LIB_NAME)
	@echo "- ${RED}Removing binary directory${NC}"
	@rm -rf ./bin
	@echo "- ${RED}Removing libft${NC} library"
	@rm -rf ./libft ./libft.a ./libft.h
	@echo "- ${RED}Removing .h${NC} files from ${RED}directories${NC}"
	@rm -f ./tests/libft.h ./tests/ft_printf.h
	@rm -f ./tools/libft.h ./tools/ft_printf.h
	@echo "- ${RED}Removing executables${NC} from root directory"
	@rm -f ./run
	@echo "Project now ${GREEN}clean.${NC}\n"

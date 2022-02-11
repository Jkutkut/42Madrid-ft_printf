# Colors:
NC			=	\033[0m
LRED			=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compile variables
LIB_CC		=	ar rcT
CC			=	gcc -Wall -Wextra -Werror


# Code variables
NAME		=	libftprintf.a

SRCS		=	ft_printf.c

# OBJS		=	${SRCS:.c=.o}
OBJS		=	${SRCS:%.c=bin/%.o}


# Makefile logic
all: $(NAME)
re: fclean all

$(NAME):	$(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC} \c"
	@$(LIB_CC) $(NAME) $(OBJS)
	@echo "${LGREEN}[OK]${NC}"

bin/%.o: %.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@if [ ! "$(dir $^)" = "./" ]; then cp -f libft.h $(dir $^); cp -f ft_printf.h $(dir $^); fi
	@$(CC) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) \c"
	@rm -f $(NAME)
	@echo "${LGREEN}[OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@# rm -rf $(OBJS)
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean

# TODO Debug
libft:
	@echo "Obtaining latest version of ${GREEN}Libft${NC} from ${LBLUE}GitHub${NC}..."
	@if [ ! -d libft ]; then git clone https://github.com/Jkutkut/42Madrid-Libft.git libft; fi

# Colors:
NC			=	\033[0m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compile variables
CC			=	ar
FLAGS		=	rcT
LIB_CC		=	$(CC) $(FLAGS)

CC_T		=	gcc
FLAGS_T		=	-Wall -Wextra -Werror
COMPILE_T	=	$(CC_T) $(FLAGS_T)


# Code variables
NAME		=	libftprintf.a

SRCS		=	ft_printf.c

OBJS		=	${SRCS:%.c=bin/%.o}


# Makefile logic
all: $(NAME)
re: fclean all

$(NAME):	$(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC} \c"
	@$(LIB_CC) $(NAME) $(OBJS)
	@echo "${LGREEN}[OK]${NC}"

bin/%.o: %.c
	@echo "- ${LBLUE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@if [ ! "$(dir $^)" = "./" ]; then cp -f libft.h $(dir $^); cp -f ft_printf.h $(dir $^); fi
	@$(CC_T) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

fclean: clean
	@echo "${RED}Cleaning ${NC}$(NAME) \c"
	@rm -f $(NAME)
	@echo "${LGREEN}[OK]${NC}"

clean:
	@echo "${RED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"
# Colors:
NC			=	\033[0m
LRED		=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

OS			=	$(shell uname -s)


# Compile variables
FLAGS		=	-Wall -Wextra -Werror
INCLUDE 	=	-I ./include
ifeq ($(OS), Linux)
	INCLUDE 	=	-I ./include -D LINUX
endif

LIB_CC		=	ar rcT
CC			=	gcc $(FLAGS) $(INCLUDE)


# Code variables
NAME		=	libftprintf.a

PRINT		=	ft_put_pointer_fd.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c

STR			=	ft_strdup.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strtoupper.c

TOOLS		=	ft_hasany.c \
				ft_itoa_base.c \
				ft_nbrlen.c

SRCS		=	${PRINT:%=print/%} \
				${STR:%=str/%} \
				${TOOLS:%=tools/%} \
				ft_printf.c

OBJS		=	${SRCS:%.c=bin/%.o}


# Makefile logic
all: $(NAME)
re: fclean all

$(NAME):	$(OBJS)
	@echo "${TITLE}Compiling ${YELLOW}$(NAME)${NC} \c"
	@$(LIB_CC) $(NAME) $(OBJS)
	@echo "${LGREEN}[OK]${NC}"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}$(NAME) \c"
	@rm -f $(NAME)
	@echo "${LGREEN}[OK]${NC}"

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf bin
	@echo "${LGREEN} [OK]${NC}"

.PHONY: all re fclean clean

# TODO Debug
libft:
	@echo "Obtaining latest version of ${GREEN}Libft${NC} from ${LBLUE}GitHub${NC}..."
	@if [ ! -d libft ]; then git clone https://github.com/Jkutkut/42Madrid-Libft.git libft; fi

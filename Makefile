NAME	=	push_swap

NAME_B	=	checker

NAME_A	=	push_swap.a

NAME_A_B	=	checker.a

SRCS	=	basic_functions.c				for_linked_list_functions.c		for_main_logic_1_functions.c \
			for_main_logic_2_functions.c	for_main_logic_3_functions.c	for_operations_1_functions.c \
			for_operations_2_functions.c 	for_operations_3_functions.c	for_parser_functions.c \
			for_split_functions.c 			push_swap.c	\

SRCS_B	=	basic_bonus_functions.c			for_checker_1_functions.c		for_checker_2_functions.c \
			for_gnl_functions.c				for_operations_2_functions.c	for_operations_3_functions.c \
			for_linked_list_functions.c		for_parser_functions.c			for_split_functions.c \
			basic_functions.c				checker.c

HEADER 	= 	push_swap.h

OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

FLAGS	=	-W -W -W

all			:	${NAME}

bonus		:	${NAME_B}

%.o			:	%.c ${HEADER}
				gcc ${FLAGS} -c $< -o $@

${NAME}		:	${NAME_A}
				gcc ${FLAGS} $< -o $@

${NAME_B}	:	${NAME_A_B}
				gcc ${FLAGS} $< -o $@

${NAME_A}	:	${OBJS} ${HEADER}
				ar rcs $@ $?

${NAME_A_B}	:	${OBJS_B} ${HEADER}
				ar rcs $@ $?

clean		:
				rm -f ${OBJS} ${OBJS_B}

fclean		:	clean
				rm -f ${NAME_A} ${NAME} ${NAME_B} ${NAME_A_B}

re			:	fclean all

.PHONY		:   all clean fclean re bonus
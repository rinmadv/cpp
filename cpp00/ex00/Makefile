SRCS	= 	megaphone.cpp

OBJS = $(SRCS:.c=.o)

CC    = c++

CFLAGS  = -Wall -Wextra -Werror -std=c++98 #-g3 

NAME    = megaphone

DEPS	=	${SRCS:.c=.d}

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined
endif

all: ${NAME}

${NAME}: ${OBJS}
	echo -n "${BOLD_WHITE}⏳ COMPILING MEGAPHONE ${NC}"
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	echo "${GREEN}Done 💅${NC}"

.c.o:
	${CC} ${CFLAGS} ${CDCFLAGS} -c $< -o ${<:.c=.o}


clean:
	echo -n "${BOLD_WHITE}🧹 CLEANING OBJECTS\t${NC}"
	${RM} ${OBJS}
	${RM} ${DEPS}
	echo "${GREEN}Done 💅${NC}"


fclean: clean
	echo -n "${BOLD_WHITE}🧹 CLEANING EXEC\t${NC}"
	${RM} ${NAME}
	echo "${GREEN}Done 💅${NC}"

re : fclean
	${MAKE}

.PHONY: re fclean all
.SILENT:
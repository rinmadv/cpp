SRCS	= 	main.cpp

OBJS = $(SRCS:.c=.o)

CC    = c++

CFLAGS  = -Wall -Wextra -Werror -std=c++98 #-g3 

NAME    = exec

DEPS	=	${SRCS:.c=.d}

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined
endif

#################
#### DISPLAY ####
#################

RED=\033[0;31m
BOLD_WHITE=\033[1m
GREEN=\033[1;32m
ORANGE=\033[0;33m
YELLOW=\033[1;33m
BLUE=\033[1;36m
NC=\033[0m # No Color


#################
##### RULES #####
#################

all: ${NAME}

${NAME}: ${OBJS}
	echo -n "${BOLD_WHITE}⏳ COMPILING EXEC${NC}"
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

.PHONY: re fclean all seed
.SILENT:
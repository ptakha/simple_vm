SRC_FILES = main.c
CC_FLAGS = -Wall -Wextra -std=c11
CC = clang

all:
	${CC} ${CC_FLAGS} ${SRC_FILES} -o tiny

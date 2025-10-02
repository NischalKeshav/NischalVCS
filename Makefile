CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
OUT = src/mygit

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(OUT)

# Rule for building .o files from .c files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

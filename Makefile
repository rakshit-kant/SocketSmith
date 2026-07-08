CC      = clang
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude

SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)

TARGET  = build/linux/socketsmith

.PHONY: all clean run

all: $(TARGET)

build/linux:
	mkdir -p build/linux

$(TARGET): build/linux $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ)
	rm -rf build

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -MMD -MP

TARGET = app
SRC = src/main.c src/task.c
OBJ = $(SRC:.c=.o)
DEPS = $(OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(OBJ) -o $@

src/%.o: src/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(TARGET) $(OBJ) $(DEPS)

-include $(DEPS)

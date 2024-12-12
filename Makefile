#Grup:28
#Habibe Bayram 
#Fatma Selma Akp�nar
#Eren Sancar
#�mer Elmas
#�ule Y�lmaz
# Makefile
# Build file for the custom shell project.

CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = shell
INCREMENT = increment
OBJS = main.o command_parser.o executor.o

all: $(TARGET) $(INCREMENT)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(INCREMENT): increment.o
	$(CC) $(CFLAGS) -o $(INCREMENT) increment.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(INCREMENT) $(OBJS) increment.o

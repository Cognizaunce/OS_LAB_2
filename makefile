# OS - LAB 2
# CRN: 74025
# GROUP 17
# Iqra Zahid - 100824901
# Rhea Mathias - 100825543
# Rivka Sagi - 100780926
# Julian Olano Medina - 100855732

# Makefile

CC = gcc
CFLAGS = -Wall
TARGET = myshell
OBJS = myshell.o utility.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)  

myshell.o: myshell.c myshell.h
	$(CC) $(CFLAGS) -c myshell.c  

utility.o: utility.c myshell.h
	$(CC) $(CFLAGS) -c utility.c  

clean:
	rm -f $(TARGET) $(OBJS)

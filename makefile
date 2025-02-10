# Makefile

CC = gcc
CFLGS = -Wall
TARGET = myshell
OBJS = myshell.o utility.o

all: $(TARGET)

$(TARGET): $(OBJS)
  $(CC) $(CFLAGS) $(OBJS) -O $(TARGET) 

myshell.o: myshell.c myshell.h
  $(CC) $(CFLAGS) -c myshell.c

utility.o: utility.c myshell.h
  $(CC) $(CFLAGS) -c utility.c

clean:
  rm -f $(TARGET) $(OBJS)

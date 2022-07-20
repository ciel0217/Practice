CC = gcc
CFLAGS = -fno-asynchronous-unwind-tables
TARGET = main
.PHONY: all clean
all: $(TARGET)

main:prog.o test.o zzz.o
	$(CC) $^ -o $@
clean:
	rm -f $(TARGET) *.o

%.o:%.c
%.o:%.s
	$(CC) -c $<
%.s:%.c
	$(CC) $(CFLAGS) -S -masm=intel $<

.SECONDARY:
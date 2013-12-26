# ciso.exe makefile
CC = gcc
LD = gcc

ciso.exe: src/ciso.o
	$(LD) $^ $(LIBS) -lz -o $@

%.o: %.c
	$(CC) -c $< -o $@

OUTPUT = daxcr
OBJS= main.o iso9660search.o
CFLAGS = -Wall -DGCC_COMPILER
LDFLAGS = 
LIBS = -lz

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(LINK.c) $(LDFLAGS) -o $@ $^ $(LIBS)



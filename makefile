#Le 16 août 2014

CC=clang
CFLAGS=-Wall -O2
LDFLAGS=
EXEC=libBenjamin.a
SRC=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJ=$(SRC:.c=.o)
PREFIX=/usr/local

all: $(EXEC)

$(EXEC): $(OBJ)
	ar -r $(EXEC) $(OBJ)

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean install

clean: 
	@rm -f $(OBJ) $(EXEC)

install: all
	@test -d $(PREFIX) || mkdir $(PREFIX)
	@test -d $(PREFIX)/lib || mkdir $(PREFIX)/lib	
	install -m 0644 $(EXEC) $(PREFIX)/lib
	@test -d $(PREFIX)/include || mkdir $(PREFIX)/include	
	install -m 0644 $(HEADERS) $(PREFIX)/include

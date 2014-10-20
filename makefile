#Le 16 août 2014

CC=clang
CFLAGS=-Wall -O2
LDFLAGS=
EXEC=libBenjamin.a
SRC=$(wildcard *.c)
HEADERS=$(wildcard *.h)
OBJ=$(SRC:.c=.o)
PREFIX=/usr/local
VERSION=1.0
IDENTIFIER=self.Benjamin
INSTALLER_NAME=output.pkg


all: $(EXEC)

$(EXEC): $(OBJ)
	@ar -r $(EXEC) $(OBJ)

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean install pkg
clean: 
	@rm -f $(OBJ) $(EXEC) $(INSTALLER_NAME)

install: all
	@test -d $(PREFIX) || mkdir -p $(PREFIX)
	@test -d $(PREFIX)/lib || mkdir $(PREFIX)/lib	
	install -m 0644 $(EXEC) $(PREFIX)/lib
	@test -d $(PREFIX)/include || mkdir $(PREFIX)/include	
	install -m 0644 $(HEADERS) $(PREFIX)/include

pkg: all
	export PREFIX=./pkg$(PREFIX) && make -e install
	pkgbuild --ownership recommended --version $(VERSION) --identifier $(IDENTIFIER) --root pkg/ $(INSTALLER_NAME)
	rm -r pkg


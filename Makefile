# Kecerahan - Kontrol kecerahan layar dengan CLI
# customize below to fit your system

SRC = main.c
BIN = kecerahan
DIR = /usr/bin
MANPREFIX = /usr/local/share/man/man1
MANFILES = kecerahan.1
CC = cc

build:
	${CC} ${SRC} -o ${BIN}

test:
	rm -f main
	${CC} -Wall ${SRC} -o main -v

uninstall:
	rm -f ${DIR}/${BIN} \
		${MANPREFIX}/${MANFILES}

install: build
	cp -f ${BIN} ${DIR}/${BIN}
	chmod 755 ${DIR}/${BIN}
	cp -f ${MANFILES} ${MANPREFIX}/${MANFILES}
	chmod 644 ${MANPREFIX}/${MANFILES}

.PHONY: build

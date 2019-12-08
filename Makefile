# xbc - Brightness Controller for X
# customize below to fit your system

SRC = kecerahan.c
BIN = kecerahan
DIR = /usr/bin

build:
	gcc ${SRC} -o ${BIN}

clean:
	rm ${BIN}

uninstall:
	rm ${DIR}/${BIN}

install: build
	cp ${BIN} ${DIR}/${BIN}
	chmod 4767 ${DIR}/${BIN}

.PHONY: build

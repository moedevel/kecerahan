build:
	gcc kecerahan.c -o build/kecerahan

clean:
	rm build/kecerahan

install: build
	cp build/kecerahan /usr/bin/kecerahan
	chown root:root /usr/bin/kecerahan
	chmod 4767 /usr/bin/kecerahan

.PHONY: build

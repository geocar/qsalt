arch=32
nacl=read_README.md
pv=$(shell echo "$(nacl)" | openssl sha1 | sed -e 's/^.*= *//' | cut -c1-5)

qsalt.so: qsalt.so.$(shell uname -s | tr A-Z a-z).$(pv)

qsalt.so.darwin.$(pv) $(HOME)/q/m$(arch)/qsalt.so: qsalt.c makefile
	gcc-6 -Wl,-undefined,dynamic_lookup -fPIC -shared -O3 -m$(arch) -DKXVER=3 -I$(HOME)/q/c -o $@ $(nacl) $<
	-ln -s -f $(shell pwd)/qsalt.so.darwin.$(pv) $(HOME)/q/m$(arch)/qsalt.so

qsalt.so.linux.$(pv) $(HOME)/q/l$(arch)/qsalt.so: qsalt.c makefile
	gcc -fPIC -shared -O3 -m$(arch) -DKXVER=3 -I$(HOME)/q/c -o $@ $(nacl) $< 
	-ln -s -f $(shell pwd)/qsalt.so.linux.$(pv) $(HOME)/q/l$(arch)/qsalt.so



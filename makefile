arch=32
nacl=read_README.md
pv=$(shell echo "$(nacl)" | openssl sha256 | sed -e 's/^.*= *//' | cut -c1-5)

qsalt.so: qsalt.so.$(shell uname -s | tr A-Z a-z).$(pv)

qsalt.so.darwin.$(pv) $(HOME)/q/m$(arch)/qsalt.so: qsalt.c makefile
	-ln -s -f $(shell pwd)/qsalt.so.darwin.$(pv) $(HOME)/q/m$(arch)/qsalt.so
	gcc-5 -Wl,-undefined,dynamic_lookup -fPIC -shared -O3 -m$(arch) -DKXVER=3 -I$(HOME)/q/c -o $@ $(HOME)/q/c/m$(arch)/c.o $(nacl) $<

qsalt.so.linux.$(pv) $(HOME)/q/l$(arch)/qsalt.so: qsalt.c makefile
	-ln -s -f $(shell pwd)/qsalt.so.linux.$(pv) $(HOME)/q/l$(arch)/qsalt.so
	gcc -fPIC -shared -O3 -m$(arch) -DKXVER=3 -I$(HOME)/q/c -o $@ $(HOME)/q/c/l$(arch)/c.o $(nacl) $< 



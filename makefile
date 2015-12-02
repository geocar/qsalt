arch=32
nacl=read_README.md

qsalt.so: qsalt.so.$(shell uname -s | tr A-Z a-z)


qsalt.so.darwin $(HOME)/q/m$(arch)/u.so: qsalt.c $(nacl)
	-ln -s $(shell pwd)/qsalt.so.darwin $(HOME)/q/m$(arch)/qsalt.so
	gcc-5 -Wl,-undefined,dynamic_lookup -fPIC -shared -O3 -m$(arch) -DKXVER=3 -I$(HOME)/q/c -o $@ $(HOME)/q/c/m$(arch)/c.o $(nacl) $<

qsalt.so.linux $(HOME)/q/l$(arch)/qsalt.so: qsalt.c $(nacl)
	-ln -s $(shell pwd)/qsalt.so.linux $(HOME)/q/l$(arch)/qsalt.so
	gcc -fPIC -shared -O3 -m$(arch) -DKXVER=3 -I$(HOME)/q/c -o $@ $(HOME)/q/c/l$(arch)/c.o $(nacl) $< 



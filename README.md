[NaCL](http://nacl.cr.yp.to/) bindings for q/kdb.

# Building
The makefile assumes kdb/q is installed in `$HOME/q` and that you have
the [C bindings](http://kx.com/q/d/c.htm) installed in `$HOME/q/c`:

    q/c/k.h
    q/c/l64/c.o
    q/c/m64/c.o

qsalt requires NaCL. On Debian systems you can install:

    sudo apt-get install libsodium-dev

Note if you're building for the 32-bit version of KDB you will need:

    sudo apt-get install libsodium-dev:i386

On other systems you install it from [The NaCL homepage](http://nacl.cr.yp.to/install.html); You can unpack it directly into this tree:

    wget http://hyperelliptic.org/nacl/nacl-20110221.tar.bz2
    bunzip2 < nacl-20110221.tar.bz2 | tar -xf -
    (cd nacl-20110221 && ./do)

Then to build:

    make nacl=nacl-20110221/build/*/lib/amd64/libnacl.a

As a convenience, [tweetnacl](tweetnacl.c) is included, and can be used with:

    make nacl=tweetnacl.c






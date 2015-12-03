[NaCL](http://nacl.cr.yp.to/) bindings for q/kdb.

##### Table of Contents  
* [Loading](#loading)
* Public Key
 * [Authenticated Encryption](#public-key-authenticated-encryption)
 * [Signatures](#public-key-signatures)
* Secret Key
 * [Authenticated Encryption](#secret-key-authenticated-encryption)
* Utilities
 * [Hashing](#hashing)
 * [Comparing Strings](#comparing-strings)
* [Building](#building)

##Loading

You can load qsalt with:

    .qsalt:@[`qsalt 2:(`qsalt;1);0]

##Public Key Authenticated Encryption

Generate (public;private) keypair:

    alice:.qsalt.pkey`
    bob:.qsalt.pkey`

Alice creates a ciphertext message for Bob:

    message:.qsalt.pencrypt[(.qsalt.nonce`;"this is secret");bob 0;alice 1]

Bob decodes the ciphertext message:

    "c"$.qsalt.pdecrypt[message;alice 0;bob 1]

If the ciphertext has been corrupted or was not created by Alice, then null will be returned.

##Public Key Signatures

Generate (public;private) keypair:

    alice:.qsalt.newkey`
    bob:.qsalt.newkey`

Alice signs a message for Bob. Note that the message is not encrypted.

    message:.qsalt.sign["this is verified";alice 1]

Bob then verifies the signature:

    "c"$.qsalt.verify[message;alice 0]

If the signature is invalid, then null will be returned.

##Secret Key Authenticated Encryption

There are several ways to generate a secret key; it can be any 32 random bytes:

    secret:.qsalt.random32`

Encrypting a message requires a nonce; this nonce must not be reused:

    message:.qsalt.sencrypt[(.qsalt.nonce`;"this is also secret");secret]

Decrypting the message also verifies it:

    "c"$.qsalt.sdecrypt[message;secret]

If the message was altered, then null will be returned.

##Hashing

Calculates the SHA512 hash of a string/bytearray:

    .qsalt.hash "whatever"

##Comparing Strings

`.qsalt.cmp16` and `.qsalt.cmp32` are constant-time comparison functions and should be used for comparing byte-strings.

    .qsalt.cmp16["this is sixteen!";"this is sixteen!"]
    .qsalt.cmp16["this is sixteen!";"somethinginvalid"]

# Building
The makefile assumes kdb/q is installed in `$HOME/q` and that you have [k.h](http://kx.com/q/c/c/k.h) installed in `$HOME/q/c`:

    q/c/k.h

qsalt requires NaCL. On Debian systems you can install:

    sudo apt-get install libsodium-dev

then build with:

    make nacl=-lsodium arch=64

Note if you're building for the 32-bit version of KDB you will need:

    sudo apt-get install libsodium-dev:i386

then build with:

    make nacl=-lsodium arch=32

on other systems you install it from [The NaCL homepage](http://nacl.cr.yp.to/install.html); You can unpack it directly into this tree:

    wget http://hyperelliptic.org/nacl/nacl-20110221.tar.bz2
    bunzip2 < nacl-20110221.tar.bz2 | tar -xf -
    (cd nacl-20110221 && ./do)

Then to build:

    make nacl=nacl-20110221/build/*/lib/amd64/libnacl.a

As a convenience, [tweetnacl](tweetnacl.c) is included, and can be used with:

    make nacl=tweetnacl.c arch=32
    make nacl=tweetnacl.c arch=64




.qsalt:@[`qsalt 2:(`qsalt;1);0]
k)A:{$[x;`ok;'`oops]};T:{x@&~~x:"c"$x}

alice:.qsalt.pkey`
bob:.qsalt.pkey`
message:.qsalt.pencrypt[(.qsalt.nonce`;text:"this is secret");bob 0;alice 1]
A text~T .qsalt.pdecrypt[message;alice 0;bob 1]

alice:.qsalt.newkey`
bob:.qsalt.newkey`

message:.qsalt.sign[text:"this is verified";alice 1]
A text~T .qsalt.verify[message;alice 0]
A not text~T .qsalt.verify[0x69,message;alice 0]

secret:.qsalt.random32`
message:.qsalt.sencrypt[(.qsalt.nonce`;text:"this is also secret");secret]
A text~T .qsalt.sdecrypt[message;secret]
A not text~T .qsalt.sdecrypt[0x69,message;secret]

/ printf "%s" whatever | openssl sha512 | sed -e 's/.*=[ ]*/0x/'
A 0xae3d347982977b422948b64011ac14ac76c9ab15898fb562a66a136733aa645fb3a9ccd9bee00cc578c2f44f486af47eb254af7c174244086d174cc52341e63a~.qsalt.hash"whatever"

A .qsalt.cmp16["this is sixteen!";"this is sixteen!"]
A not .qsalt.cmp16["this is sixteen!";"somethinginvalid"]

\\

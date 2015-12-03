#include "k.h"

#include <unistd.h>
#include <fcntl.h>

typedef unsigned long long j;
void randombytes(unsigned char *b,j n){I f,r;while(n>0){r=read(f=open("/dev/urandom",O_RDONLY),b,n);close(f);if(r>0)b+=r,n-=r;}}

ZK gz(I n){K x=ktn(KG,n);if(n)memset(xG,0,n);R x;}ZK gg(S s,I n){K x=ktn(KG,n);memcpy(xG,s,n);R x;}ZK gp(K x,I n){K z=gz(n);jv(&z,x);R z;}ZK up(K x){memmove(xG,xG+32,xn-32);xn-=32;R x;}ZI kn(K x){R xt>=0?xn:-1;}
#define L(x,n)P(kn(x)!=n,krr("length"))

ZK nonce(K _){G n[32];randombytes(n,32);R gg(n,32);}//->nonce

ZK pkey(K x){G p[32],s[32];crypto_box_curve25519xsalsa20poly1305_ref_keypair(p,s);R knk(2,gg(p,32),gg(s,32),0);}//->(public;secret)
ZK pencrypt(K x,K y,K z){K m,r;L(y,32);L(z,32);m=gp(xy,32),r=gz(m->n);crypto_box_curve25519xsalsa20poly1305_ref(kG(r),kG(m),m->n,kG(xx),kG(y),kG(z));r0(m);jv(&r,xx);R r;}//(nonce;text);receiverpublic;sendersecret->message
ZK pdecrypt(K x,K y,K z){K r;L(y,32);L(z,32);P(xn<64,gz(0)); r=gz(xn);if(-1==crypto_box_curve25519xsalsa20poly1305_ref_open(kG(r),xG,xn-32,xG+(xn-32),kG(y),kG(z)))r0(r),r=gz(0);else r=up(r);R r;} //message;senderpublic;receiversecret->text

ZK newkey(K x){G p[32],s[64];crypto_sign_edwards25519sha512batch_ref_keypair(p,s);R knk(2,gg(p,32),gg(s,64),0);}//->(public;secret)
ZK sign(K x,K y){K r;j n;L(y,64);r=gz(xn+64);n=r->n;crypto_sign_edwards25519sha512batch_ref(kG(r),&n,xG,xn,kG(y));r->n=n;R r;}//text;secretkey->message
ZK verify(K x,K y){K r;j n;L(y,32);P(xn<64,gz(0)); r=gz(xn-64);n=r->n;if(-1==crypto_sign_edwards25519sha512batch_ref_open(kG(r),&n,xG,xn,kG(y))){r0(r);R gz(0);}r->n=n;R r;}//message;publickey->text|null

ZK sencrypt(K x,K y){K m=gp(xy,32),r=gz(m->n);crypto_secretbox_xsalsa20poly1305_ref(kG(r),kG(m),m->n,kG(xx),kG(y));jv(&r,xx);R r;}//(nonce;text);secret->message
ZK sdecrypt(K x,K y){K r;P(xn<32,gz(0)); r=gz(xn);if(-1==crypto_secretbox_xsalsa20poly1305_ref_open(kG(r),xG,xn-32,xG+(xn-32),kG(y)))r0(r),r=gz(0);else r=up(r);R r;}//message;secret->text

//no point is using the unauthenticated encryption

ZK hash(K x){K r=gz(64);crypto_hash_sha512_ref(kG(r),xG,xn);R r;}
ZK cmp16(K x,K y){L(x,16);L(y,16);R kb(!crypto_verify_16_ref(xG,kG(y)));}
ZK cmp32(K x,K y){L(x,32);L(y,32);R kb(!crypto_verify_32_ref(xG,kG(y)));}

K qsalt(K x){
  ZS a[]={"random32","nonce","pkey","pencrypt","pdecrypt","newkey","sign","verify","sencrypt","sdecrypt","hash","cmp16","cmp32"};
  ZV*b[]={ nonce    , nonce , pkey , pencrypt , pdecrypt , newkey , sign , verify , sencrypt , sdecrypt , hash , cmp16 , cmp32 };
  ZI c[]={ 1        , 1     , 1    , 3        , 3        , 1      , 2    , 2      , 2        , 2        , 1    , 2     , 2     }; ZI n=sizeof(a)/sizeof(S);
  if(xt==-KS){DO(n,if(!strcmp(a[i],x->s))R dl(b[i],c[i]));R ktn(0,0);}
  K y;x=ktn(KS,n),y=ktn(0,n);DO(n,xS[i]=ss(a[i]);kK(y)[i]=r1(dl(b[i],c[i])));R xD(x,y);
}

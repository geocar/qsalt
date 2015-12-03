/*
.qsalt:@[`qsalt 2:(`qsalt;1);0]
*/
#include "k.h"

#include <unistd.h>
#include <fcntl.h>

typedef unsigned long long j;

void randombytes(unsigned char *b,j n){I f,r;while(n>0){r=read(f=open("/dev/urandom",O_RDONLY),b,n);close(f);if(r>0)b+=r,n-=r;}}

ZK gg(K x){xt=KG;R x;}ZK gz(I n){K x=ktn(KG,n);DO(n,xG[i]=0);R x;}ZK gp(K x,I n){K z=gz(n);jv(&z,x);R z;}ZK gc(K x){K y=kpn(KG,xn);memcpy(kG(y),xG,xn);R y;}
ZK up(K x){memmove(xG,xG+32,xn-32);xn-=32;while(xn&&!xG[xn-1])xn--;R x;}
ZK nonce(K _){G n[32];randombytes(n,32);R gg(kpn(n,32));}//->nonce

ZK pkey(K x){G p[32],s[32];crypto_box_curve25519xsalsa20poly1305_ref_keypair(p,s);R knk(2,gg(kpn(p,32)),gg(kpn(s,32)),0);}//->(public;secret)
ZK pencrypt(K x,K y,K z){K m=gp(xy,32),r=ktn(KG,m->n);crypto_box_curve25519xsalsa20poly1305_ref(kG(r),kG(m),m->n,kG(xx),kG(y),kG(z));r0(m);jv(&r,xx);R r;}//(nonce;text);receiverpublic;sendersecret->message
ZK pdecrypt(K x,K y,K z){K r=ktn(KG,xn);if(-1==crypto_box_curve25519xsalsa20poly1305_ref_open(kG(r),xG,xn-32,xG+(xn-32),kG(y),kG(z)))r0(r),r=ss("");else r=up(r);R r;} //message;senderpublic;receiversecret->text

ZK newkey(K x){G p[32],s[64];crypto_sign_edwards25519sha512batch_ref_keypair(p,s);R knk(2,gg(kpn(p,32)),gg(kpn(s,64)),0);}//->(public;secret)
ZK sign(K x,K y){K r=ktn(KG,xn+64);j n=r->n;crypto_sign_edwards25519sha512batch_ref(kG(r),&n,xG,xn,kG(y));r->n=n;R r;}//text;secretkey->message
ZK verify(K x,K y){K r=ktn(KG,xn-64);j n=r->n;if(-1==crypto_sign_edwards25519sha512batch_ref_open(kG(r),&n,xG,xn,kG(y))){r0(r);R ks("");}r->n=n;R r;}//message;publickey->text|null

ZK sencrypt(K x,K y){K m=gp(xy,32),r=ktn(KG,m->n);crypto_secretbox_xsalsa20poly1305_ref(kG(r),kG(m),m->n,kG(xx),kG(y));jv(&r,xx);R r;}//(nonce;text);secret->message
ZK sdecrypt(K x,K y){K r=ktn(KG,xn);if(-1==crypto_secretbox_xsalsa20poly1305_ref_open(kG(r),xG,xn-32,xG+(xn-32),kG(y)))r0(r),r=ss("");else r=up(r);R r;}//message;secret->text

//no point is using the unauthenticated encryption

ZK hash(K x){K r=ktn(KG,64);crypto_hash_sha512_ref(kG(r),xG,xn);R r;}
ZK cmp16(K x,K y){R kb(!crypto_verify_16_ref(xG,kG(y)));}
ZK cmp32(K x,K y){R kb(!crypto_verify_32_ref(xG,kG(y)));}

K qsalt(K x){
  ZS a[]={"random32","nonce","pkey","pencrypt","pdecrypt","newkey","sign","verify","sencrypt","sdecrypt","hash","cmp16","cmp32"};
  ZV*b[]={ nonce    , nonce , pkey , pencrypt , pdecrypt , newkey , sign , verify , sencrypt , sdecrypt , hash , cmp16 , cmp32 };
  ZI c[]={ 1        , 1     , 1    , 3        , 3        , 1      , 2    , 2      , 2        , 2        , 1    , 2     , 2     };
  ZI n=sizeof(a)/sizeof(S);
  if(xt==-KS){DO(n,if(!strcmp(a[i],x->s))R dl(b[i],c[i]));R ktn(0,0);}
  K y;x=ktn(KS,n),y=ktn(0,n);DO(n,xS[i]=ss(a[i]);kK(y)[i]=r1(dl(b[i],c[i])));R xD(x,y);
}

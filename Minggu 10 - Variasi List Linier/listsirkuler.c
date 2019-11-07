
/* File : listsirkuler.c */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */
#include "listsirkuler.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
     //kamus
    address p= (address) malloc (sizeof(ElmtList));
    //algoritma
    if(p!=Nil){
        Info(p)=X;
        Next(p)=Nil;
        return p;
    } else{
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    //kamus
    address p;
    //algoritma
    if(IsEmpty(L)){
        return Nil;
    }else{
        p=First(L);
        while (Next(p)!=First(L) && Info(p)!=X){
            p=Next(p);
        }
        if(Info(p)==X){
            return p;
        } else{
            return Nil;
        }
    }
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    //kamus
    address p=Alokasi(X);
    //algoritma
    if(p!=Nil){
        InsertFirst(L,p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    //kamus
    address p=Alokasi(X);
    //algoritma
    if(p!=Nil){
        InsertLast(L,p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
    //kamus
    address p;
    ///algoritma
    DelFirst(L,&p);
    (*X)=Info(p);
    Dealokasi(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){
    //kamus
    address q;
    //algoritma
    DelLast(L,&q);
    (*X)=Info(q);
    Dealokasi(q);    
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    //Kamus
    address q;
    //algoritma
    if(!IsEmpty(*L)){
        q=First(*L);
        while(Next(q)!=First(*L)){
            q=Next(q);
        }
        Next(P)=First(*L);
        First(*L)=P;
        Next(q)=P;
    }else{
        First(*L)=P;
        Next(P)=P;    
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    //kamus
    address q;
    //algoritma
    if(!IsEmpty(*L)){
        q=First(*L);
        while(Next(q)!=First(*L)){
            q=Next(q);
        }
        Next(P)=First(*L);
        Next(q)=P;
    }else{
        InsertFirst(L,P);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    //algoritma
    Next(P)=Next(Prec);
    Next(Prec)=P;   
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    //kamus
    address q;
    //algoritma
    (*P)=First(*L);
    if(First(*L)==Next(First(*L))){
        First(*L)=Nil;
    }else{
        q=First(*L);
        while(Next(q)!=*P){
            q=Next(q);
        }
        First(*L)=Next(First(*L));
        Next(q)=First(*L);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    //kamus
    address prec=Nil,current=First(*L);
    //algoritma
    while(Next(current)!=First(*L)){
        prec=current;
        current=Next(current);
    }
    *P=current;
    if(prec==Nil){
        First(*L)=Nil;
    }else{
        Next(prec)=First(*L);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    //algoritma
    *Pdel=Next(Prec);
    if(Next(Prec)==Prec){
        First(*L)=Nil;
    }else{
        if(Next(Prec)==First(*L)){
            First(*L)=Next(Next(Prec));
        }
        Next(Prec)=Next(Next(Prec));
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){
    //kamus
    address prec=Nil,p;
    //algoritma
    p=Search(*L,X);
    if(p!=Nil){
        if(p==First(*L)){
            DelFirst(L,&p);
        }else{
            prec=First(*L);
            while(Next(prec)!=p){
                prec=Next(prec);
            }
            DelAfter(L,&p,prec);
        }
        Dealokasi(p);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    //kamus
    address p;
    //algoritma
    printf("[");
    if(!IsEmpty(L)){
        p=First(L);
        while(Next(p)!=First(L)){
            printf("%d,",Info(p));
            p=Next(p);
        }
        printf("%d",Info(p));
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 29 Oktober 2019
// Topik/Deskripsi  : Variasi List Linier/ADT List DP Linier nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)

#define Second(L) (Next(First(L)))
#define IsOneElmt(L) (Second(L) == First(L))

List* NextList(List *L){
	List* T = (List*) malloc(sizeof(List));
	CreateEmpty(T);
	if(!IsOneElmt(*L)) First(*T) = Second(*L);
	return T;
}


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P = (address) malloc(sizeof(address)+1);
	if(P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if(IsEmpty(L)) return Nil;
	if(Info(First(L)) == X) return First(L);
	if(!IsOneElmt(L)) return Search(*NextList(&L), X);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = Alokasi(X);
	Next(P) = First(*L);
	First(*L) = P;
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if(IsEmpty(*L)) InsVFirst(L, X);
	else if (!IsOneElmt(*L)){
		List* tmp = NextList(L);
		InsVLast(tmp, X);
		Next(First(*L)) = First(*tmp);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	*X = Info(First(*L));
	First(*L) = Second(*L);
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	if(IsOneElmt(*L)) DelVFirst(L, X);
	else if (!IsOneElmt(*L)){
		List* tmp = NextList(L);
		DelVLast(tmp, X);
		Next(First(*L)) = First(*tmp);
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if(!IsEmpty(*L)){
        address cari = First(*L);
        while(Next(cari) != First(*L)){
            cari = Next(cari);
        }
        Next(P) = First(*L);
        First(*L) = P;
        Next(cari) = P;
    } else {
        First(*L)=P;
        Next(P)=P;    
    }
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(IsEmpty(*L)) InsertFirst(L, P);
	else if (!IsOneElmt(*L)){
		List* tmp = NextList(L);
		InsertLast(tmp, P);
		Next(First(*L)) = First(*tmp);
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
    Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
{
	*P = First(*L);
    if(First(*L) == Second(*L)){
        First(*L) = Nil;
    } else {
        address cari =First(*L);
        while(Next(cari) != *P) cari = Next(cari);
        First(*L) = Next(First(*L));
        Next(cari) = First(*L);
    }
}

/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	if(IsOneElmt(*L)) DelFirst(L, P);
	else if (!IsOneElmt(*L)){
		List* tmp = NextList(L);
		DelLast(tmp, P);
		Next(First(*L)) = First(*tmp);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
    if(Next(Prec) == Prec) First(*L)=Nil;
    else {
        if(Next(Prec) == First(*L))
            First(*L) = Next(Next(Prec));
        Next(Prec) = Next(Next(Prec));
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if(Info(First(*L)) == X) {
		address P;
		DelFirst(L, &P);
	} else {
		List* tmp = NextList(L);
		if(!IsEmpty(*tmp)){
			DelP(tmp, X);
			Next(First(*L)) = First(*tmp);
		}
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoUtil(List L){
	if(!IsEmpty(L)){
		print(Info(First(L)));
		if(!IsOneElmt(L)){
			List* tmp = NextList(&L);
			if(!IsEmpty(*tmp)) printf(",");
			PrintInfoUtil(*tmp);
		}
	}
}

void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	PrintInfoUtil(L);
	printf("]");
}
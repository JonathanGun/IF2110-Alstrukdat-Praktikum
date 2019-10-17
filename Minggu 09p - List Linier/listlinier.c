// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 17 Oktober 2019
// Topik/Deskripsi  : List Linier/ADT List Linier nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define print(a)      printf("%c", a)
#define prints(a)     printf("%c ", a)
#define println(a)    printf("%c\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
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
	address P;
	Info(P) = X;
	Next(P) = Nil;
	return P;
}

void Dealokasi (address *P)
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
	while(!IsEmpty(L)){
		if (Info(First(L)) == X) return First(L);
		First(L) = Next(First(L));
	}
	return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	InsertFirst(L, Alokasi(X));
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	InsertLast(L, Alokasi(X));
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	*X = Info(First(*L));
	First(*L) = Next(First(*L));
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	List* tmp = L;
	while(Next(First(*L)) != Nil){
		First(*L) = Next(First(*L));
	}
	*X = Info(First(*L));
	First(*L) = Nil;
	L = tmp;
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	List* tmp = L;
	if (P != Nil){
		Next(First(*L)) = First(*L);
		First(*L) = P;
	}
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	while(First(*L) != Prec){
		Next(First(*L)) = First(*L);
	}
	address tmp = Next(First(*L));
	Next(First(*L)) = P;
	Next(Next(First(*L))) = tmp;

}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (P != Nil){
		while(!IsEmpty(*L)) First(*L) = Next(First(*L));
		First(*L) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	while(!IsEmpty(*L)){
		if (Info(First(*L)) == X){
			First(*L) = Next(First(*L));
			return;
		}
		First(*L) = Next(First(*L));
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	while(Next(First(*L)) != Nil){
		First(*L) = Next(First(*L));
	}
	*P = First(*L);
	First(*L) = Nil;

}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	while(First(*L) != Prec){
		First(*L) = Next(First(*L));
	}
	*Pdel = First(*L);
	Next(First(*L)) = First(*L);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	while(!IsEmpty(L)){
		print(Info(First(L)));
		First(L) = Next(First(L));
		if (!IsEmpty(L)) printf(",");
	}
	printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	int cnt = 0;
	while(!IsEmpty(L)){
		cnt++;
		First(L) = Next(First(L));
	}
	return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	int mx = 0;
	while(!IsEmpty(L)){
		mx = max(mx, Info(First(L)));
		First(L) = Next(First(L));
	}
	return mx;	
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	L3 = L1;
	while(!IsEmpty(*L1)){
		First(*L1) = Next(First(*L1));
	}
	First(*L1) = First(*L2);
}
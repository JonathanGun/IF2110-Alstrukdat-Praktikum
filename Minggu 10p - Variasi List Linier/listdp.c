// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 29 Oktober 2019
// Topik/Deskripsi  : Variasi List Linier/ADT List DP Linier nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

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

#define Second(L) Next(First(L))
#define SecondBack(L) Prev(Last(L))
#define IsOneElmt(L) Second(L) == Nil

List* NextList(List *L){
	List* T = (List*) malloc(sizeof(List));
	CreateEmpty(T);
	if(Second(*L) != Nil){
		First(*T) = Second(*L);
		Last(*T) = Last(*L);
	}
	return T;
}

List* PrevList(List *L){
	List* T = (List*) malloc(sizeof(List));
	CreateEmpty(T);
	if(SecondBack(*L) != Nil){
		Last(*T) = SecondBack(*L);
		First(*T) = First(*L);
	}
	return T;
}

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L) == Nil) && (Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L) = Nil;
	Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P = (address) malloc(sizeof(address));
	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if(IsEmpty(L)) return Nil;
	if(Info(First(L)) == X) return First(L);
	return Search(*NextList(&L), X);
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
	Prev(P) = Nil;
	if(!IsEmpty(*L)) Prev(First(*L)) = P;
	else Last(*L) = P;
	First(*L) = P;
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = Alokasi(X);
	Prev(P) = Last(*L);
	Next(P) = Nil;
	if(!IsEmpty(*L)) Next(Last(*L)) = P;
	else First(*L) = P;
	Last(*L) = P;
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	*X = Info(First(*L));
	First(*L) = Second(*L);
	Prev(First(*L)) = Nil;
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	*X = Info(Last(*L));
	Last(*L) = SecondBack(*L);
	Next(Last(*L)) = Nil;
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	if(IsEmpty(*L)) Last(*L) = P;
	else Prev(First(*L)) = P;
	First(*L) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	Prev(P) = Last(*L);
	if(IsEmpty(*L)) First(*L) = P;
	else Next(Last(*L)) = P;
	Last(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if(First(*L) == Next(Prec)) InsertFirst(L, P);
	else {
		List* tmp = NextList(L);
		InsertAfter(tmp, P, Prec);
		Second(*L) = First(*tmp);
		Prev(First(*tmp)) = First(*L);
	}
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	if (Prev(Succ) != Nil) InsertAfter(L, P, Prev(Succ));
	else InsertFirst(L, P);
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Second(*L);
	if(First(*L) == Nil) Last(*L) = Nil;
	else Prev(First(*L)) = Nil;
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = Last(*L);
	Last(*L) = SecondBack(*L);
	if(Last(*L) == Nil) First(*L) = Nil;
	else Next(Last(*L)) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if(IsEmpty(*L)) return;
	if(Info(First(*L)) == X) {
		address P;
		DelFirst(L, &P);
	} else {
		List* tmp = NextList(L);
		DelP(tmp, X);
		Next(First(*L)) = First(*tmp);
		Prev(First(*tmp)) = First(*L);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
    if((*Pdel) != Last(*L)) Prev(Next(*Pdel)) = Prec;
    else Last(*L) = Prec;
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	DelAfter(L, Pdel, Prev(Prev(Succ)));
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardUtil(List L){
	if(!IsEmpty(L)){
		print(Info(First(L)));
		List* tmp = NextList(&L);
		if(!IsEmpty(*tmp)) printf(",");
		PrintForwardUtil(*tmp);
	}
}

void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	PrintForwardUtil(L);
	printf("]");
}

void PrintBackwardUtil(List L){
	if(!IsEmpty(L)){
		print(Info(Last(L)));
		List* tmp = PrevList(&L);
		if(!IsEmpty(*tmp)) printf(",");
		PrintBackwardUtil(*tmp);
	}
}

void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	PrintBackwardUtil(L);
	printf("]");
}
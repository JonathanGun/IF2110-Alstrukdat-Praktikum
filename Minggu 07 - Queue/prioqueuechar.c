// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 2 Oktober 2019
// Topik/Deskripsi  : Queue/Prioqueuenya tuan yon

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%c", a)
#define prints(a)     printf("%c ", a)
#define println(a)    printf("%c\n", a)
#define ENDL          printf("\n")

#define fori(Q, i) for(int i = Head(Q); i != Tail(Q); i++)

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	return !(Head(Q) - (Tail(Q)%MaxEl(Q)) - 1);
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if(IsEmpty(Q)) return 0;
	if(IsFull(Q)) return MaxEl(Q);
	return ((Tail(Q) - Head(Q) + 1) % MaxEl(Q));
}

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
	MaxEl(*Q) = Max;
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	MaxEl(*Q) = 0;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
	if (IsEmpty(*Q)){
		Head(*Q)=1;
		Tail(*Q)=1;
	} else {
		if(Tail(*Q) == MaxEl(*Q)) Tail(*Q) = 1;
		else Tail(*Q)++;
	}
	int i = Head(*Q);
	boolean sudah = false;
	while(i != Tail(*Q)){
		if(!sudah && (Elmt(*Q, i).prio > X.prio)){
			sudah = true;
		}
		if (sudah){
			swap(Elmt(*Q, i), X);
		}
		if(i == MaxEl(*Q)) i = 1;
		else(i++);
	}
	InfoTail(*Q)=X;
}

void Del (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	*X = InfoHead(*Q);
	if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	} else {
		if (Head(*Q) == MaxEl(*Q)) Head(*Q) = 1;
		else Head(*Q)++;
	}
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	fori(Q, i){
		printf("%d %c\n", Elmt(Q, i).prio, Elmt(Q, i).info);
	}
	if(!IsEmpty(Q)){
		int i = Tail(Q);
		printf("%d %c\n", Elmt(Q, i).prio, Elmt(Q, i).info);	
	}
	print('#');
	ENDL;
}

// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 17 Oktober 2019
// Topik/Deskripsi  : List Linier/ADT List Linier nya Tuan Yon

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

#define Second(L) Next(First(L))
#define IsOneElmt(L) Second(L) == Nil
List* NextList(List *L);
List* PrevList(List *L);
void PrintForwardUtil(List L);
void PrintBackwardUtil(List L);

int main(){
	List L, S, T;
	CreateEmpty(&L);
	CreateEmpty(&S);
	CreateEmpty(&T);
	int tmp;
	address P;

	InsVLast(&L, 20);
	InsVFirst(&L, 30);
	fori(i, 4){
		InsVLast(&L, i*22);
	}

	fori(i, 3){
		int tmp;
		DelVFirst(&L, &tmp);
	}
	print(Search(L, 12));

	address newP = Alokasi(10);
	InsertFirst(&L, newP);
	// address newPP = Alokasi(15);
	// InsertBefore(&L, newPP, Last(L));
	address x;
	DelP(&L, 12);

	P = Alokasi(12);
	InsertLast(&L, P);


	// PrintForward(L); ENDL;
	// PrintBackward(L); ENDL;
	PrintInfo(L); ENDL;

	return 0;
}

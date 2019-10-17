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
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)

#define Second(L) Next(First(L))
#define IsOneElmt(L) Second(L) == Nil
List* NextList(List *L);

int main(){
	List L, S, T;
	CreateEmpty(&L);
	CreateEmpty(&S);
	CreateEmpty(&T);
	int tmp;
	address P;

	// InsVLast(&L, 20);
	// InsVLast(&L, 30);
	// fori(i, 3){
	// 	InsVLast(&L, i*22);
	// }

	fori(i, 3){
		InsVLast(&S, i*7);
	}

	// P = Alokasi(12);
	// InsertLast(&L, P);

	PrintInfo(L);
	ENDL;

	PrintInfo(S);
	ENDL;

	Konkat1(&L, &S, &T);
	PrintInfo(T);

	return 0;
}

// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 24 Oktober 2019
// Topik/Deskripsi  : List Linier/Cache nya Tuan Yon


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

int main(){
	int n; intput(n);
	List L;
	CreateEmpty(&L);
	fori(i, n) InsVLast(&L, i+1);

	int q; intput(q);
	fori(i, q){
		int tmp; intput(tmp);
		address cari = Search(L, tmp);
		if(cari == Nil){
			address p;
			DelLast(&L, &p);
			printf("miss ");
		} else {
			DelP(&L, tmp);
			printf("hit ");
		}
		InsVFirst(&L, tmp);
		PrintInfo(L);
		ENDL;

	}
	return 0;
}
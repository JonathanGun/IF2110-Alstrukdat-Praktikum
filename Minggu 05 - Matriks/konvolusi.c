// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Sabtu, 14 September 2019
// Topik/Deskripsi 	: Matriks/Konvolusinya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define ENDL          printf("\n")

#define forrow(T, i)  for(indeks i = 1; i <= NBrsEff(T); ++i)
#define forkol(T, i)  for(indeks i = 1;	i <= NKolEff(T); ++i)
#define formax(T, i)  for(indeks i = 1; i <= T.BrsMax;   ++i)
#define forn(i, n)    for(indeks i = 1; i <= n;   		 ++i)
#define forall(M,i,j) forn(i, NBrsEff(M)) forn(j, NKolEff(M))

int main(){
	MATRIKS A, B, C;
	int nb, nk; intput2(nb, nk);
	BacaMATRIKS(&A, nb, nk);

	int k; intput(k);
	BacaMATRIKS(&B, k, k);

	MakeMATRIKS(nb, nk, &C);

	int rp = k/2+1, cp = k/2+1;
	forall(A, i, j) forall(A, ii, jj){
		int r = rp-i+ii, c = cp-j+jj;
		if(IsIdxValid(r, c)) Elmt(C, i, j) += Elmt(B, r, c)*Elmt(A, ii, jj);
	}
	TulisMATRIKS(C);

	return 0;
}

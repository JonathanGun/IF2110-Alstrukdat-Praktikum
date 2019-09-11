// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 5 September 2019
// Topik/Deskripsi 	: Array Statis/arraynya tuan yon

#include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <assert.h>
// #include "boolean.h"
#define fori(T, i) for(IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); ++i)
#define forii(T, i) for(IdxType i = GetLastIdx(T); i >= GetFirstIdx(T); --i)
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}
#define ENDL printf("\n")
#define intput(a) scanf("%d", &a)
#define intput2(a,b) scanf("%d %d", &a, &b)
#define charput(a) scanf("%c", &a)
#define floatput(a) scanf("%f", &a)
#define print(a) printf("%d\n", a)

#include "array.h"

int NbOccX(TabInt T, ElType X){
	int ans = 0;
	fori(T, i) if (Elmt(T,i) == X) ans++;
	return ans;
}

int ceildiv(int x){
	if (x%2 == 0) return x/2;
	return (x/2)+1;
}

void descArray(TabInt T, int X){
	TulisIsiTab(T); ENDL;
	print(NbOccX(T, X));
	int idx = Search1(T, X);
	if (idx != IdxUndef) print(idx);
	else printf("%d tidak ada\n", X);

	if (X == ValMax(T)) printf("maksimum\n");
	if (X == ValMin(T)) printf("minimum\n");
	InsSortAsc(&T);
	if (X == Elmt(T, ceildiv(NbElmt(T)))) printf("median\n");
}

// DRIVER
int main(){
	TabInt T1;
	MakeEmpty(&T1);
	BacaIsi(&T1);

	int x; intput(x);
	descArray(T1, x);

	return 0;
}
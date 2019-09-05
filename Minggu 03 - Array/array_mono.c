// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 5 September 2019
// Topik/Deskripsi 	: Array Statis/array mono nya tuan yon

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

int main(){
	TabInt T1;
	MakeEmpty(&T1);
	BacaIsi(&T1);

	boolean turun = false, naik = false;
	fori(T1, i){
		if (i != 1){
			if (Elmt(T1, i) > Elmt(T1, i-1)){
				naik = true;
			} else if (Elmt(T1, i) < Elmt(T1, i-1)){
				turun = true;
			}
		}
	}
	if (naik && !turun){
		printf("Array monotonik tidak mengecil");
	} else if (turun && !naik){
		printf("Array monotonik tidak membesar");
	} else if (naik && turun){
		printf("Array tidak monotonik");
	} else {
		printf("Array monotonik statik");
	} ENDL;

	return 0;
}
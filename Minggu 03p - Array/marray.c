#include <stdio.h>
#include "array.h"
#define fori(T, i) for(IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); ++i)
#define forii(T, i) for(IdxType i = GetLastIdx(T); i >= GetFirstIdx(T); --i)
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}
#define ENDL printf("\n")
#define intput(a) scanf("%d", &a)
#define intput2(a,b) scanf("%d %d", &a, &b)
#define charput(a) scanf("%d", &a)
#define floatput(a) scanf("%f", &a)
#define print(a) printf("%d\n", a)
#define swapTab(a, b) {TabInt tmp; CopyTab(b, *tmp);CopyTab(a, *b);CopyTab(a, *tmp);}

void inputArray(TabInt *T){
	printf("Pilihan:\n");
	printf("1. isi array sejumlah N\n");
	printf("2. isi array hingga -9999 atau full (100 elmt)\n");
	printf(">>> ");

	int choose;
	intput(choose);
	if (choose == 1){
		BacaIsi(T);
	} else if (choose == 2){
		BacaIsiTab(T);
	}
}
	
void printArray(TabInt T){
	TulisIsiTab(T); ENDL;
}

void descArray(TabInt T){
	printf("Jumlah elemen: "); 	print(NbElmt(T));
	printf("Index Pertama: "); 	print(GetFirstIdx(T));
	printf("Index Terakhir: "); print(GetLastIdx(T));
	printf("Arraynya: "); 		printArray(T);
	printf("Elemen2nya: \n"); 	TulisIsi(T); ENDL;

	int mx = ValMax(T), mn = ValMin(T);
	printf("Nilai maks: "); print(mx);
	printf("Nilai min: "); print(mn);
	ENDL;
}

void compareArray(TabInt T1, TabInt T2){
	printf("array 1:"); printArray(T1);
	printf("array 2:"); printArray(T2);
	if (IsEQ(T1, T2)){
		printf("Array sama persis!\n");
	} else if (IsLess(T1, T2)){
		printf("Array pertama lebih kecil!\n");
	} else {
		printf("Array pertama lebih besar!\n");
	}
	ENDL;
}

int main(){
	TabInt T1, T2;
	MakeEmpty(&T1);
	MakeEmpty(&T2);

	printf("Array pertama:\n");
	inputArray(&T1);
	descArray(T1);
	printf("Array kedua:\n");
	inputArray(&T2);
	descArray(T2);
	
	int edit = -1;
	do{
		printf("What do you want to do?\n");
		printf("Edit(1)\nDelElmt(2)\nAddElmt(3)\nFind(4)\n");
		printf("SortAsc(5)\nSortDesc(6)\nDesc(7)\nCompare(8)\n");
		printf("CheckSymmetry(9)\nQuit(0)?\n>>> ");

		intput(edit);
		int choose; 
		if (edit != 8 && edit != 0){
			printf("Array yang mana? (1/2)\n>>> "); intput(choose);
		}

		if (edit == 1){
			printf("format: index{spasi}angka_baru\n");
			int i, x; intput2(i, x);
			if (choose == 1){
				DelEli(&T1, i, &x);
				AddEli(&T1, x, i);
			} else {
				DelEli(&T2, i, &x);
				AddEli(&T2, x, i);
			}
		} else if (edit == 2){
			printf("format: index\n");
			int i, x; intput(i); x = 0;
			if (choose == 1){
				DelEli(&T1, i, &x);
			} else {
				DelEli(&T2, i, &x);
			}
		} else if (edit == 3){
			printf("format: index{spasi}angka_baru\n");
			int i, x; intput2(i, x);
			if (choose == 1){
				AddEli(&T1, x, i);
			} else {
				AddEli(&T2, x, i);
			}
		} else if (edit == 4){
			printf("format: angka_yang_dicari\n");
			int x; intput(x);
			if (choose == 1){
				printf("Dengan Metode search1: "); print(Search1(T1, x));
				printf("Dengan Metode search2: "); print(Search2(T1, x));
				printf("Dengan Metode searchB: "); print(SearchB(T1, x));
				printf("Dengan Metode searchS: "); print(SearchSentinel(T1, x));
				printf("Dengan Metode searchU: "); print(SearchUrut(T1, x));
			} else {
				printf("Dengan Metode search1: "); print(Search1(T2, x));
				printf("Dengan Metode search2: "); print(Search2(T2, x));
				printf("Dengan Metode searchB: "); print(SearchB(T2, x));
				printf("Dengan Metode searchS: "); print(SearchSentinel(T2, x));
				printf("Dengan Metode searchU: "); print(SearchUrut(T2, x));
			}
		} else if (edit == 5){
			if (choose == 1){
				InsSortAsc(&T1);
			} else {
				InsSortAsc(&T2);
			}
		} else if (edit == 6){
			if (choose == 1){
				MaxSortDesc(&T1);
			} else {
				MaxSortDesc(&T2);
			}
		} else if (edit == 7){
			if (choose == 1){
				descArray(T1);
			} else {
				descArray(T2);
			}
		} else if (edit == 8){
			compareArray(T1, T2);
		} else if (edit == 9){
			if (choose == 1){
				printf("Apakah simetris? "); print(IsSimetris(T1));
			} else {
				printf("Apakah simetris? "); print(IsSimetris(T2));
			}
		}
		ENDL;
	} while(edit != 0);

	printf("Array terakhir:\n");
	descArray(T1);
	descArray(T2);

	return 0;
}
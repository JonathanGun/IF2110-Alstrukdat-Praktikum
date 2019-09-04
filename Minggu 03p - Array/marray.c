#include <stdio.h>
#include <conio.h>

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
		printf("CheckSymmetry(9)\nOperasiArrayTerurut(10)\n");
		printf("Flip(11)\nAppend(12)\nPop(13)\nQuit(0)?\n>>> ");

		intput(edit);
		int choose; 
		if (edit != 8 && edit != 0 && edit != 7){
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
			descArray(T1);
			descArray(T2);
		} else if (edit == 8){
			compareArray(T1, T2);
		} else if (edit == 9){
			if (choose == 1){
				printf("Apakah simetris? "); print(IsSimetris(T1));
			} else {
				printf("Apakah simetris? "); print(IsSimetris(T2));
			}
		} else if (edit == 10){
			printf("Add(1)\nDel(2)\nMaxMin(3)\nSearch(4)\n>>> ");
			int c; intput(c);
			if (c == 1){
				printf("format: angka_baru\n");
				int x; intput(x);
				if (choose == 1){
					Add1Urut(&T1,x);
				} else {
					Add1Urut(&T2,x);
				}
			} else if (c == 2){
				printf("format: angka_yang_didelete\n");
				int x; intput(x);
				if (choose == 1){
					Del1Urut(&T1,x);
				} else {
					Del1Urut(&T2,x);
				}
			} else if (c == 3){
				int mx, mn;
				if (choose == 1){
					printArray(T1);
					MaxMinUrut(T1,&mx,&mn);
				} else {
					printArray(T2);
					MaxMinUrut(T2,&mx,&mn);
				}
				printf("Nilai maks: "); print(mx);
				printf("Nilai min: "); print(mn);
			} else if (c == 4){
				printf("format: angka_yang_dicari\n");
				int x; intput(x);
				if (choose == 1){
					print(SearchUrut(T1,x));
				} else {
					print(SearchUrut(T2,x));
				}
			}
		} else if (edit == 11){
			if (choose == 1){
				T1 = InverseTab(T1);
			} else {
				T2 = InverseTab(T2);
			}
		} else if (edit == 12){
			printf("format: angka_baru\n");
			int x; intput(x);
			if (choose == 1){
				AddAsLastEl(&T1, x);
			} else {
				AddAsLastEl(&T2, x);
			}
		} else if (edit == 13){
			int x = 0;
			if (choose == 1){
				DelLastEl(&T1, &x);
			} else {
				DelLastEl(&T2, &x);
			}
		}
		ENDL;
		printf("array 1:"); printArray(T1);
		printf("array 2:"); printArray(T2);
		printf("Press Any Key to Continue");
		getch(); ENDL;
	} while(edit != 0);

	printf("Array terakhir:\n");
	descArray(T1);
	descArray(T2);

	return 0;
}
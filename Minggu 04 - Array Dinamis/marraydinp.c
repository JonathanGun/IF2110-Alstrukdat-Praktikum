#include <stdio.h>

#include "arraydin.h"
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

int main(){
	TabInt T; MakeEmpty(&T, 10);
	BacaIsi(&T);
	TulisIsiTab(T);
	int tmp; intput(tmp);
	printf("Search1 (idx): "); print(Search1(T, tmp));
	printf("SearchB (bool): "); print(SearchB(T, tmp));
	printf("CountX : "); print(CountX(T, tmp));
	printf("IsAllGenap: "); print(IsAllGenap(T));
	Sort(&T, false); TulisIsiTab(T);

	return 0;
}

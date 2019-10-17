// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 17 Oktober 2019
// Topik/Deskripsi  : Stack/Soal 1 Stacknya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

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

int main(){
	Stack s, t;
	CreateEmpty(&s);
	CreateEmpty(&t);
	int n,m; intput2(n,m);
	while(n--){
		int tmp; intput(tmp);
		if(tmp) Push(&s, tmp);
		else if (!IsEmpty(s)) Pop(&s, &tmp);
	}
	while(m--){
		int tmp; intput(tmp);
		if(tmp) Push(&t, tmp);
		else if (!IsEmpty(t)) Pop(&t, &tmp);
	}
	boolean same = true;
	int t1, t2;
	while(!(IsEmpty(s)|| IsEmpty(t))){
		Pop(&s, &t1); Pop(&t, &t2);
		if (t1 != t2){
			same = false;
			break;
		}

	}
	if (same) printf("Sama\n");
	else printf("Tidak sama\n");

	return 0;
}
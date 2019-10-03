// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 2 Oktober 2019
// Topik/Deskripsi  : Queue/Model TCPnya tuan yon

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define print(a)      printf("%c", a)
#define prints(a)     printf("%c ", a)
#define println(a)    printf("%c\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)
#define forq(Q, i) for(int i = Head(Q); i != Tail(Q); i++)

int main(){
	int p; intput(p);
	PrioQueueChar pq;
	CreateEmpty(&pq, p);
	int received = 0;
	fori(i, p){
		while(!IsEmpty(pq) && (InfoHead(pq).prio == received+1)){
			infotype x;
			Del(&pq, &x);
			printf("%d %c\n", i, x.info);
			received++;
		}
		int prio; char info;
		infotype pc;
		scanf("%d %c", &prio, &info);
		pc.prio = prio;
		pc.info = info;
		Add(&pq, pc);
	}
	while(!IsEmpty(pq) && InfoHead(pq).prio == received+1){
		infotype x;
		Del(&pq, &x);
		printf("%d %c", p, x.info);
		received++;
		ENDL;
	}
}
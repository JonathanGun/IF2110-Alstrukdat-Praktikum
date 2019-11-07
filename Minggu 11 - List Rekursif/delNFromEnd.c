// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 7 Nov 2019
// Topik/Deskripsi  : Variasi List Rekursif/Tuan Yon minta delNFromEnd tapi kukasih delNFromFront gapapa ya

#include<stdio.h>
#include "listrek.h"
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf(" %c", &a)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)

int total = 0;
List simpan = Nil;
// List delNFromFront(List L, int n){
// 	if(n == 2){
// 		List Next = Tail(L);
// 		SetNext(L, Tail(Next));
// 		Dealokasi(Next);
// 		return L;
// 	}
// 	if(n == 1){
// 		List ans = Tail(L);
// 		Dealokasi(L);
// 		return ans;
// 	}
// 	SetNext(L,  delNFromFront(Tail(L), n-1));
// }

boolean Apa(List L, int nbelmt, int delidx){
	if(IsEmpty(L)) return true;
	total++;
	Apa(Tail(L), nbelmt+1, delidx);
	// if (simpan != Nil) println(Info(simpan));
	if(delidx+nbelmt == total) simpan = L;
	if(delidx+nbelmt+1 == total) {
		Dealokasi(L);
		if(nbelmt == 0){
			return false;
		}
	}
	if(delidx+nbelmt+2 == total) {
		SetNext(L, simpan);
	}
	return true;
}

List delNFromEnd(List L, int n) {
	if(IsEmpty(L)) return L;
	if (!Apa(L, 0, n)) return Tail(L);
	return L;
}

// int main() {
// 	List L = Alokasi(-1);
// 	fori(i, 4){
// 		L = Konso(i, L);
// 	}
// 	PrintList(L); ENDL;

// 	L = delNFromEnd(L, 4);
// 	ENDL;
// 	PrintList(L);

// 	return 0;
// }
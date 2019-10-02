// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 26 September 2019
// Topik/Deskripsi  : Mesin Kata/Kemunculan Katanya Tuan Yon

#include "mesinkata.h"
#include <stdio.h>

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
#define printc(a)     printf("%c", a)
#define printcs(a)    printf("%c ", a)
#define printcln(a)   printf("%c\n", a)
#define ENDL          printf("\n")

#define forall(CKata, i) for(int i = 1; i <= CKata.Length; i++)
#define printkata(CKata) forall(CKata, i) printc(CKata.TabKata[i])

Kata Search;
Kata Cur;

void Salin(Kata* dest, Kata src, int start, int end)
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */
{
	(*dest).Length = end-start+1;
	forall((*dest), i) (*dest).TabKata[i] = src.TabKata[start+i-1];
}

boolean Equal(Kata kata1, Kata kata2){
	if(kata1.Length != kata2.Length) return false;
	forall(kata1, i){
		if(kata1.TabKata[i] != kata2.TabKata[i]){
			return false;
		}
	}
	return true;
}

int main(){
	STARTKATA();
	Salin(&Search, CKata, 1, CKata.Length);
	int cnt = 0;
	ADVKATA();
	while(!EndKata){
		for(int start = 1; start <= CKata.Length-Search.Length+1; start++){
			Salin(&Cur, CKata, start, start+Search.Length-1);
			if(Equal(Cur, Search)) {
				cnt = cnt+1;
			}
		}
		ADVKATA();
	}
	println(cnt);

	return 0;
}
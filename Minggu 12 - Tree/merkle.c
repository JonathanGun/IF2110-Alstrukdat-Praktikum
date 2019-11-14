// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 14 November 2019
// Topik/Deskripsi  : Tree/merkelelelelelelelle nya tuan yon

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

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
#define printc(a)     printf("%c", a)
#define printcs(a)    printf("%c ", a)
#define printcln(a)   printf("%c\n", a)
#define ENDL          printf("\n")

#define fori(i,n)     for(int i = 0; i < n; i++)
#define forii(i,s,e)  for(int i = s; i < e; i++)

BinTree BuildMerkleTree(int h){
	if(h == 0){
		int tmp; intput(tmp);
		return AlokNode(tmp);
	}
	BinTree cur = AlokNode(0);
	Left(cur) = BuildMerkleTree(h-1);
	Right(cur) = BuildMerkleTree(h-1);
	Akar(cur) = Akar(Left(cur)) + Akar(Right(cur));
	return cur;
}

int main(){
	int h; intput(h);\

	long long cek = 1; int i = 0;
	while(cek < h){
		cek *= 2;
		i++;
	}
	if (cek != h){
		printf("Jumlah masukan tidak sesuai\n");
		return 0;
	}
	BinTree T = BuildMerkleTree(i);
	PrintTree(T, 2);
	return 0;
}
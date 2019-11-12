// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 12 November 2019
// Topik/Deskripsi  : Tree/ADT Binary Tree nya Tuan Yon

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

int main(){
	BinTree T = AlokNode(10);
	Left(T) = AlokNode(11);
	Left(Left(T)) = AlokNode(12);
	Right(Left(T)) = AlokNode(13);
	Right(T) = AlokNode(14);
	PrintTree(T, 2);
	println(Tinggi(T));
	int X;
	DelDaunTerkiri(&T, &X);
	println(X);
	PrintTree(T, 2);
}
// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 14 November 2019
// Topik/Deskripsi  : Tree/Invert B Tree nya tuan yon

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

void InvertBtree(BinTree *P)
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
{
	if(IsTreeEmpty(*P)) return;
	InvertBtree(&Right(*P));
	InvertBtree(&Left(*P));
	*P = Tree(Akar(*P), Right(*P), Left(*P));
	return;
}
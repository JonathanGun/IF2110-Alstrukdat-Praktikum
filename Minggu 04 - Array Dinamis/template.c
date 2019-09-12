// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 12 September 2019
// Topik/Deskripsi 	: Array Dinamis/INSERT_YOUR_MEME_HERE

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
// #include <fcntl.h>
// #include <assert.h>
// #include "boolean.h"
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf("%c", &a)
#define floatput(a)   scanf("%f", &a)
#define print(a)      printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(T, i)    for(IdxType i = GetFirstIdx(T);   i <= GetLastIdx(T);    ++i)
#define fori1(T, i)   for(IdxType i = GetFirstIdx(T)+1; i <= GetLastIdx(T);    ++i)
#define forii(T, i)   for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T);   --i)
#define forii1(T, i)  for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T)+1; --i)

TabInt InverseTab (TabInt T){
  TabInt T2; MakeEmpty(&T2, MaxElement(T)); CopyTab(T, &T2);
  fori(T2, i) Elmt(T2, GetFirstIdx(T2)+NbElmt(T2)-i) = Elmt(T,i);
  return T2;
}

void DelEli (TabInt * T, IdxType i, ElType * X){
  *X = Elmt(*T,Neff(*T)--);
  for(int ii = i; ii <= GetLastIdx(*T); ++ii) Elmt(*T,ii) = Elmt(*T,ii+1);
}

ElType Head(TabInt T)   {return Elmt(T, GetFirstIdx(T));}
TabInt Tail(TabInt T){
  int tmp = 0;
  TabInt newT; MakeEmpty(&newT, NbElmt(T));
  CopyTab(T, &newT);
  DelEli(&newT, 1, &tmp);
  return newT;
}

ElType ValMax(TabInt T) {return (NbElmt(T) == 1)?Head(T): max(Head(T), ValMax(Tail(T)));}
ElType ValMin(TabInt T) {return (NbElmt(T) == 1)?Head(T): min(Head(T), ValMin(Tail(T)));}

// DRIVER
int main(){
	TabInt T; MakeEmpty(&T, 10);
	BacaIsi(&T);
	
	TulisIsiTab(T);
	return 0;
}
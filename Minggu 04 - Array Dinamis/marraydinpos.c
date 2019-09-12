// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 12 September 2019
// Topik/Deskripsi 	: Array Dinamis/INSERT_YOUR_MEME_HERE

#include <stdio.h>
#include <stdlib.h>
#include "arraydinpos.h"
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
#define print(a)      printf("%d", a)
#define ENDL          printf("\n")

#define fori(T, i)    for(IdxType i = GetFirstIdx(T);   i <= GetLastIdx(T);    ++i)
#define fori1(T, i)   for(IdxType i = GetFirstIdx(T)+1; i <= GetLastIdx(T);    ++i)
#define forii(T, i)   for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T);   --i)
#define forii1(T, i)  for(IdxType i = GetLastIdx(T);    i >= GetFirstIdx(T)+1; --i)
#define formax(T, i)  for(IdxType i = GetFirstIdx(T);   i <= MaxElement(T);    ++i)


void printTab(TabInt T){
  print(MaxElement(T)); printf(" "); TulisIsiTab(T); ENDL;
}

// DRIVER
int main(){
	TabInt T; 
  int maxel; intput(maxel);
  MakeEmpty(&T, maxel);
	BacaIsi(&T);
  printTab(T);
  int q; intput(q);
  for(int i = 0; i<q; i++){
    int op, num; intput(op);
    if (op < 4) intput(num);
    if (op == 1){
      if(IsFull(T)) {printf("array sudah penuh\n"); continue;}
      else AddAsLastEl(&T, num);
    } else if (op == 2){
      GrowTab(&T, num);
    } else if (op == 3){
      if (NbElmt(T) < num) {printf("array terlalu kecil\n"); continue;}
      else ShrinkTab(&T, num);
    } else {
      CompactTab(&T);
    }
    printTab(T);
  }
	
	return 0;
}
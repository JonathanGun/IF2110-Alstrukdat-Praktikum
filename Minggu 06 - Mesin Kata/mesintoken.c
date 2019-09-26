// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 26 September 2019
// Topik/Deskripsi  : Mesin Kata/Mesin Tokennya Tuan Yon

#include "mesintoken.h"
#include <stdio.h>

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%c", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define printc(a)     printf("%c", a)
#define printcs(a)    printf("%c ", a)
#define printcln(a)   printf("%c\n", a)
#define ENDL          printf("\n")

#define printtoken(CToken) printf("<'%c', %d>", CToken.tkn, CToken.val)

boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  while(!(CC != BLANK || CC == MARK)) ADV();  
}

void STARTTOKEN()
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
  START();
  if(CC == MARK) EndToken = true;
  else{
    IgnoreBlank();
    ADVTOKEN();
  }
}

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  SalinToken();
  IgnoreBlank();
  if(CC == MARK) EndToken = true;
}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  if('0' <= CC && CC <= '9'){
    CToken.tkn = 'b';
    CToken.val = 0;
    while('0' <= CC && CC <= '9'){
      CToken.val *= 10;
      CToken.val += (CC - '0');
      ADV();
    }
  } else if(!(CC == BLANK || CC == MARK)){
    CToken.tkn = CC;
    CToken.val = -1;
    ADV();
  }
}

// int main(){
//   STARTTOKEN();
//   printtoken(CToken); ENDL;
//   while(!EndToken){
//     ADVTOKEN();
//     printtoken(CToken); ENDL;
//   }
// }
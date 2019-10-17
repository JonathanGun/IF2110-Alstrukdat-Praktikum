// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 17 Oktober 2019
// Topik/Deskripsi  : Stack/Mesin Token x Stack nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"
#include "mesintoken.h"
#include "math.h"

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

int hitung(int b1, char op, int b2){
	printf("%d %c %d\n", b2, CToken.tkn, b1);

	int hasil;
	if (CToken.tkn == '*') hasil = b2 * b1;
	else if (CToken.tkn == '+') hasil = b2 + b1;
	else if (CToken.tkn == '-') hasil = b2 - b1;
	else if (CToken.tkn == '/') hasil = b2 / b1;
	else if (CToken.tkn == '^') hasil = pow(b2, b1);
	println(hasil);
	
	return hasil;
}

int main(){
	STARTTOKEN();
	Stack s;
	CreateEmpty(&s);
	while(!EndToken){
		if (CToken.tkn == 'b'){
			println(CToken.val);
			Push(&s, CToken.val);
		} else {
			int b1, b2;
			Pop(&s, &b1);
			Pop(&s, &b2);
			Push(&s, hitung(b1, CToken.tkn, b2););
		}
		ADVTOKEN();
	}

	if(!IsEmpty(s)){
		int hasil_akhir;
		Pop(&s, &hasil_akhir);
		printf("Hasil=");
		println(hasil_akhir);
	} else {
		printf("Ekspresi kosong\n");
	}

	return 0;
}
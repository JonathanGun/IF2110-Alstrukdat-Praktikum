// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 29 Oktober 2019
// Topik/Deskripsi  : Variasi List Linier/ADT List DP Linier nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

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

#define Second(L) (Next(First(L)))
#define IsOneElmt(L) (Second(L) == First(L))

void DeleteRR (List *L, infotype TQ)
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
{
	if(!IsEmpty(*L)){
		address last = First(*L);
		while (Next(last) != First(*L)){
			last = Next(last);
		}
		if (Info(last) > TQ){
			First(*L) = last;
			Info(First(*L)) -= TQ;
			print(TQ); ENDL;
		} else {
			int X;
			DelVLast(L, &X);
			print(X); ENDL;
		}
	} else {
		printf("List kosong\n");
	}
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	if(IsEmpty(L)) return 0.0;
	float ans = 0.0;
	float cnt = 1;
	address cur = Next(First(L));
	ans = Info(First(L));
	while (cur != First(L)){
		ans += Info(cur);
		cnt += 1;
		cur = Next(cur);
	}
	float avg = ans/cnt;
	return avg;
}

int main(){
	List L;
	CreateEmpty(&L);
	int TQ;
	do{
		intput(TQ);
	} while(TQ <= 0);
	char proses;
	do{
		charput(proses);
		if (proses == 'D'){
			DeleteRR(&L, TQ);
		} else if (proses == 'A'){
			int tmp; intput(tmp);
			if(tmp > 0) InsVFirst(&L, tmp);
		} else if (proses != 'F'){
			printf("Kode salah\n");
		}
	} while(proses != 'F');

	if (IsEmpty(L)){
		printf("Proses selesai\n");
	} else {
		printf("%.2f\n", Average(L));
	}

	return 0;
}
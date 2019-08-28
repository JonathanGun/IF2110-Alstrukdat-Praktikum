#include "jam.c"

int main(){
	printf("========= Program Penjabaran Informasi Beberapa Jam ========\n");
	printf("\t\tOleh Jonathan Yudi Gunawan\n");
	printf("\t\t\t13518084\n");
	printf("============================================================\n");

	int n;
	printf("Jumlah jam yang ingin diinput: ");
	scanf("%d", &n);

	JAM J, LAST;
	for (int i = 0; i < n; ++i){
		printf("Masukkan %d jam lagi dengan format HH<spasi>MM<spasi>SS<enter>:\n", n-i);
		printf(">>> "); BacaJAM(&J);

		if (i){
			printf("Jam sekarang selisih "); TulisJAM(DetikToJAM(Durasi(LAST, J)));
			printf(" dari jam sebelumnya\n");
			if (JEQ(J, LAST)){
				printf("Jam sekarang ("); TulisJAM(J);
				printf(") sama dengan yang sebelumnya ("); TulisJAM(LAST);
				printf(")\n");
			} else {
				if (JGT(J, LAST)){
					printf("Jam sekarang ("); TulisJAM(J);
					printf(") lebih besar daripada yang sebelumnya ("); TulisJAM(LAST);
					printf(")\n");
				} else {
					printf("Jam sekarang ("); TulisJAM(J);
					printf(") lebih kecil daripada yang sebelumnya ("); TulisJAM(LAST);
					printf(")\n");
				}
			}
		}

		int edit;
		printf("\nMau edit jam tadi? (YES = 1/ NO = 0)\n");
		printf(">>> "); scanf("%d", &edit);
		if (edit){
			int d;
			printf("Mau ditambah berapa detik? (bisa negatif)\n");
			printf(">>> "); scanf("%d", &d);

			J = NextNDetik(J, d);
			printf("Sekarang jadi jam "); TulisJAM(J); printf("\n");
		}

		LAST = J;
		printf("\n");
	}

	return 0;
}
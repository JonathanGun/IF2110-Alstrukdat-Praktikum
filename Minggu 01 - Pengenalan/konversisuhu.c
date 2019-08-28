// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 22 Agustus 2019
// Topik/Deskripsi 	: Pengenalan C/konersi suhu dari celcius ke yang lainnya

#include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <assert.h>
// #include "boolean.h"

int main(){
	// KAMUS
	float suhu;
	char satuan;
	
	// ALGORITMA
	scanf("%f\n", &suhu);
	scanf("%c", &satuan);

	if (satuan == 'R'){
		printf("%.2f\n", suhu*4/5);
	} else if (satuan == 'F'){
		printf("%.2f\n", suhu*9/5+32);
	} else { // satuan == 'K'
		printf("%.2f\n", suhu+273.15);
	}

	return 0;
}
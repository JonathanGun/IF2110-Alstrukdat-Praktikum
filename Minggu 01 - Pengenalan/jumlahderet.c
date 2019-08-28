// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 22 Agustus 2019
// Topik/Deskripsi 	: Pengenalan C/jumlah deret

#include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <assert.h>
// #include "boolean.h"

int main(){
	// KAMUS
	int i, n, jml;
	
	// ALGORITMA
	scanf("%d", &n);
	jml = 0;
	for(i = 1; i < n+1; i++){
		jml += i;
	}
	printf("%d\n", jml);

	return 0;
}
// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 29 Agustus 2019
// Topik/Deskripsi 	: ADT Sederhana/hitung durasi telepon
#include <stdio.h>
#include "jam.h"

long int mymin(long int a, long int b){
	if (a < b){
		return a;
	} else {
		return b;
	}
}

long int mymax(long int a, long int b){
	if (b > a){
		return b;
	} else {
		return a;
	}
}

// PROGRAM UTAMA
int main(){
	// KAMUS
	int n;
	long int mn, mx;
	long int curmn, curmx;

	// ALGORITMA
	// INPUT
	scanf("%d", &n);
	mn = 86400; mx = 0;
	JAM J, J2;
	for (int i = 0; i < n; ++i){
		printf("[%d]\n", i+1);

		// PROSES
		BacaJAM(&J); BacaJAM(&J2);
		curmn = 86400; curmx = 0;

		curmn = mymin(JAMToDetik(J), JAMToDetik(J2));
		curmx = mymax(JAMToDetik(J), JAMToDetik(J2));
		mn = mymin(mn, curmn);
		mx = mymax(mx, curmx);

		// OUTPUT
		printf("%ld\n", curmx - curmn);
	}
	TulisJAM(DetikToJAM(mn)); printf("\n");
	TulisJAM(DetikToJAM(mx)); printf("\n");

	return 0;
}
// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 22 Agustus 2019
// Topik/Deskripsi 	: Pengenalan C/maksimum 3 angka

#include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <assert.h>
// #include "boolean.h"

int main(){
	// KAMUS
	int a,b,c,jml;
	
	// ALGORITMA
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a > b){
		if (a > c){
			printf("%d\n", a);
		} else {
			printf("%d\n", c);
		} 
	} else if (b > c) {
		if (b > a){
			printf("%d\n", b);
		} else {
			printf("%d\n", a);
		}

	} else { // c >= a
		if (c > b){
			printf("%d\n", c);
		} else {
			printf("%d\n", b);
		}
	}

	return 0;
}
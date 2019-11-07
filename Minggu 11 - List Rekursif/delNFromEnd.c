// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Kamis, 7 Nov 2019
// Topik/Deskripsi  : Variasi List Rekursif/Tuan Yon minta delNFromEnd

#include "listrek.h"

int total = 0;
List simpan = Nil;
int Apa(List L, int nbelmt, int n){
	if(IsEmpty(L)) return 1;
	total++;
	Apa(Tail(L), nbelmt+1, n);
	if(n+nbelmt-1 == total) simpan = L;
	if(n+nbelmt == total)  {Dealokasi(L);if(nbelmt == 0) return 0;}
	if(n+nbelmt+1 == total) SetNext(L, simpan);
}

List delNFromEnd(List L, int n) {
	if(IsEmpty(L)) return L;
	if(!Apa(L, 0, n)) return simpan;
	return L;
}
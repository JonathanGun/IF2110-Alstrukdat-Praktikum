// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 3 September 2019
// Topik/Deskripsi  : Array/ADT Array

#include <stdio.h>
#include "array.h"
#define fori(T, i) for(IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); ++i)
#define forii(T, i) for(IdxType i = GetLastIdx(T); i >= GetFirstIdx(T); --i)
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	Neff(*T) = 0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	return Neff(T);
}


/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return Neff(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ((GetFirstIdx(T) <= i) && (i <= (GetFirstIdx(T) + MaxNbEl(T))));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return ((GetFirstIdx(T) <= i) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return Neff(T);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (Neff(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	int n;
	do{
		scanf("%d", &n);
	} while (!((0 <= n) && (n <= MaxNbEl(*T))));
	if (n == 0){
		MakeEmpty(T);
	} else {
		Neff(*T) = n;
		fori(*T, i){
			scanf("%d", TI(*T)[i]);
		}
	}
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
	int tmp, i;
	i = GetFirstIdx(*T);
	MakeEmpty(T);
	do{
		scanf("%d", &tmp);
		TI(*T)[i] = tmp;
		if (tmp != -9999){
			i++;
			Neff(*T)++;
		}
	} while (!(tmp == -9999) || (Neff(*T) == MaxNbEl(*T)));
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
	fori(T, i){
		printf("[%d]%d\n", i, TI(T)[i]);
	}
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	printf("[");
	fori(T, i){
		printf("%d", TI(T)[i]);
		if (i != GetLastIdx(T)){
			printf(",");
		}
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
	TabInt T3;
	Neff(T3) = Neff(T1);
	fori(T3, i){
		TI(T3)[i] = TI(T1)[i] + TI(T2)[i];
	}
	return T3;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	TabInt T3;
	Neff(T3) = Neff(T1);
	fori(T3, i){
		TI(T3)[i] = TI(T1)[i] - TI(T2)[i];
	}
	return T3;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
	TabInt T3;
	Neff(T3) = Neff(T1);
	fori(T3, i){
		TI(T3)[i] = TI(T1)[i] * TI(T2)[i];
	}
	return T3;
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
	TabInt Tout;
	Neff(Tout) = Neff(Tin);
	fori(Tout, i){
		TI(Tout)[i] = TI(Tin)[i] * c;
	}
	return Tout;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	boolean ans;
	ans = Neff(T1) == Neff(T2);
	if (ans){
		fori(T1, i){
			if (TI(T1)[i] != TI(T2)[i]){
				ans = false;
			}
		}
	}
	return ans;
}

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
	boolean ans;
	ans = Neff(T1) <= Neff(T2);
	if (Neff(T1) == Neff(T2)){
		fori(T1, i){
			if (TI(T1)[i] > TI(T2)[i]){
				ans = false;
			}
		}
	}
	return ans;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
	fori(T, i){
		if (TI(T)[i] == X){
			return i;
		}
	}
	return IdxUndef;
}

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
	boolean found = false;
	IdxType idx = IdxUndef;
	IdxType i = GetFirstIdx(T);
	while(!found && (i <= GetLastIdx(T))){
		if (TI(T)[i] == X){
			found = true;
			idx = i;
		}
		i++;
	}
	return idx;
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
	boolean found = false;
	IdxType i = GetFirstIdx(T);
	while(!found && (i <= GetLastIdx(T))){
		if (TI(T)[i] == X){
			found = true;
		}
		i++;
	}
	return found;
}

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
	IdxType i = GetLastIdx(T);
	while(i > 0){
		if (TI(T)[i] == X){
			return true;
		}
		i--;
	}
	return false;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
	ElType ans = TI(T)[GetFirstIdx(T)];
	fori(T, i){
		ans = max(ans, TI(T)[i]);
	}
	return ans;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
	ElType ans = TI(T)[GetFirstIdx(T)];
	fori(T, i){
		ans = min(ans, TI(T)[i]);
	}
	return ans;
}

IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
	ElType mx = ValMax(T);
	fori(T, i){
		if (TI(T)[i] == mx){
			return i;
		}
	}
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
	ElType mn = ValMin(T);
	fori(T, i){
		if (TI(T)[i] == mn){
			return i;
		}
	}
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
	fori(Tin, i){
		TI(*Tout)[i] = TI(Tin)[i];
	}
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
	TabInt T2;
	Neff(T2) = Neff(T);
	fori(T, i){
		TI(T2)[GetFirstIdx(T2)+Neff(T2)-i] = TI(T)[i];
	}
	return T2;
}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
	fori(T, i){
		if (TI(T)[GetFirstIdx(T)+Neff(T)-i] != TI(T)[i]){
			return false;
		}
	}
	return true;
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
	TabInt T2;
	Neff(T2) = Neff(*T);
	ElType mn = ValMin(*T);
	fori(T2, i){
		TI(T2)[i] = ValMax(*T);
		TI(*T)[IdxMaxTab(*T)] = mn;
	}
	CopyTab(T2, T);
}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
	fori(*T, i){
		IdxType idx = i-1;
		while(TI(*T)[idx] > TI(*T)[idx+1] && idx >= GetFirstIdx(*T)){
			swap(TI(*T)[idx],TI(*T)[idx+1]);
		}
	}
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	TI(*T)[++Neff(*T)] = X;
}

void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	Neff(*T)++;
	forii(*T, ii){
		if (ii == i){
			TI(*T)[ii] = X;
		} else if (ii > i){
			TI(*T)[ii] = TI(*T)[i-1];
		}
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	Neff(*T)--;
	fori(*T, ii){
		if (ii >= i){
			TI(*T)[ii] = TI(*T)[i+1];
		}
	}
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
	if (!SearchSentinel(*T, X)){
		AddAsLastEl(T, X);
	} else {
		printf("nilai sudah ada\n");
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
	fori(T, i){
		if (TI(T)[i] == X){
			return i;
		} else if (TI(T)[i] > X){
			return IdxUndef;
		}
	}
	return IdxUndef;
}

ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
	return TI(T)[GetLastIdx(T)];
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
	return TI(T)[GetFirstIdx(T)];
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
	AddEli(T, X, SearchUrut(*T, X));
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
	IdxType idx = SearchUrut(*T, X);
	if (idx != -9999){
		DelEli(T, idx, &X);
	}
}
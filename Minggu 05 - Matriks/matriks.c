// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Sabtu, 14 September 2019
// Topik/Deskripsi 	: Matriks/Matriknya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define ENDL          printf("\n")

#define forrow(T, i)  for(indeks i = 1; i <= NBrsEff(T); ++i)
#define forkol(T, i)  for(indeks i = 1;	i <= NKolEff(T); ++i)
#define formax(T, i)  for(indeks i = 1; i <= T.BrsMax;   ++i)
#define forn(i, n)    for(indeks i = 1; i <= n;   		 ++i)
#define forall(M,i,j) forn(i, NBrsEff(M)) forn(j, NKolEff(M))

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return (((BrsMin <= i) && (i <= BrsMax)) && ((KolMin <= j) && (j <= KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return (((BrsMin <= i) && (i <= NBrsEff(M))) && ((KolMin <= j) && (j <= NKolEff(M))));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return Elmt(M, i, i);
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	forall(MIn, i, j){
		Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	MakeMATRIKS(NB, NK, M);
	forall(*M, i, j){
		int tmp; intput(tmp);
		Elmt(*M, i, j) = tmp;
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	forn(i, NBrsEff(M)){
		forn(j, NKolEff(M)){
			if (j >= NKolEff(M)) print(Elmt(M, i, j));
			else prints(Elmt(M, i, j));
		}
		if (i != NBrsEff(M)) ENDL;
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
	forall(M1, i, j) Elmt(M1, i, j) += Elmt(M2, i, j);
	return M1;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
	forall(M1, i, j) Elmt(M1, i, j) -= Elmt(M2, i, j);
	return M1;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	MATRIKS M3; MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
	forn(i, NBrsEff(M1)){
		forn(j, NKolEff(M2)){
			Elmt(M3, i, j) = 0;
			forn(k, NBrsEff(M2)){
				Elmt(M3, i, j) += Elmt(M1, i, k)*Elmt(M2, k, j);
			}
		}
	}
	return M3;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	PKaliKons(&M, X);
	return M;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	forall(*M, i, j) Elmt(*M, i, j) *= K;
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	if (NBrsEff(M1) != NBrsEff(M2)) return false;
	if (NKolEff(M1) != NKolEff(M2)) return false;
	forn(i, NBrsEff(M1)){
		forn(j, NKolEff(M1)){
			if (Elmt(M1, i, j) != Elmt(M2, i, j)) return false;
		}
	}
	return true;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return !EQ(M1, M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	if (!IsBujurSangkar(M)) return false;
	forall(M, i, j) if (Elmt(M, i, j) != Elmt(M, j, i)) return false;
	return true;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
	if (!IsBujurSangkar(M)) return false;
	forall(M, i, j){
		if (i == j) {if (Elmt(M, i, i) != 1) return false;}
		else if (Elmt(M, i, j) != 0) return false;
	}
	return true;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
	int cnt = 0;
	forall(M, i, j) if (Elmt(M, i, j) != 0) cnt++;
	return cnt*20 <= NBElmt(M);
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	PInverse1(&M);
	return M;
}

MATRIKS reduce(MATRIKS m, int rx, int cx){
    MATRIKS newm; CopyMATRIKS(m, &newm);
    forall(m, r, c){
    	int newr = r, newc = c;
        if (r > rx) newr--;
        if (c > cx) newc--;
        Elmt(newm,newr,newc) = Elmt(m,r,c);
    }
    NBrsEff(newm)--;
    NKolEff(newm)--;
    return newm;
}

int mypow(int n) {
	if (n%2==0) return 1;
	return -1;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	// Basis
    if (NBrsEff(M) == GetFirstIdxBrs(M)) return Elmt(M,GetFirstIdxBrs(M),GetFirstIdxBrs(M));

    // Rekursi
    float ans = 0;
    for(int c = GetFirstIdxKol(M); c <= NKolEff(M); c++){
    	ans += Elmt(M,GetFirstIdxBrs(M),c)*Determinan(reduce(M, GetFirstIdxBrs(M), c))*mypow(c+1);
    }
    return ans;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	forall(*M, i, j) Elmt(*M, i, j) *= -1;
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	for(int i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
		for(int j = i+1; j <= GetLastIdxKol(*M); j++){
			swap(Elmt(*M, i, j), Elmt(*M, j, i));
		}
	}
}


float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	float sum = 0;
	forkol(M, j) sum += Elmt(M, i, j);
	return sum/NKolEff(M);
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	float sum = 0;
	forrow(M, i) sum += Elmt(M, i, j);
	return sum/NBrsEff(M);
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	*max = Elmt(M, i, 1);
	*min = Elmt(M, i, 1);
	forkol(M, j){
		*max = max(*max, Elmt(M, i, j));
		*min = min(*min, Elmt(M, i, j));
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	*max = Elmt(M, 1, j);
	*min = Elmt(M, 1, j);
	forrow(M, i){
		*max = max(*max, Elmt(M, i, j));
		*min = min(*min, Elmt(M, i, j));
	}
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	int cnt = 0;
	forkol(M, j) if (Elmt(M, i, j) == X) cnt++;
	return cnt;
}
int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	int cnt = 0;
	forrow(M, i) if (Elmt(M, i, j) == X) cnt++;
	return cnt;	
}

// int main() {
// 	MATRIKS M;
// 	int nb, nk; intput2(nb, nk);
// 	BacaMATRIKS(&M, nb, nk);
// 	TulisMATRIKS(M);
// 	// print(IsSimetri(M));
// 	// TulisMATRIKS(KaliMATRIKS(M,M));
// 	// printf("%f", Determinan(M)); ENDL;
// 	// PKaliKons(&M, 10);
// 	MATRIKS M1; CopyMATRIKS(M, &M1);
// 	M = TambahMATRIKS(M, KaliKons(M, 10));
// 	TulisMATRIKS(M1);
// 	TulisMATRIKS(M);
// 	return 0;
// }
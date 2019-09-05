// Nama/NIM 		: Jonathan Yudi Gunawan/13518084
// Hari, Tanggal 	: Kamis, 12 September 2019
// Topik/Deskripsi 	: Matriks/hayoloh

#include <stdio.h>
#include "tebakpraprak4.h"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {ElType tmp; tmp = b; b = a; a = tmp;}

#define intput(a) scanf("%d", &a)
#define intput2(a,b) scanf("%d %d", &a, &b)
#define charput(a) scanf("%c", &a)
#define floatput(a) scanf("%f", &a)
#define print(a) printf("%d\n", a)
#define ENDL printf("\n")

#define forib(M, i) for(indeks i = FirstIdxBrs(M) i <= GetNBrsEff(M) ++i)
#define foriib(M, i) for(indeks i = GetNBrsEff(M) i >= FirstIdxBrs(M) --i)
#define forik(M, i) for(indeks i = FirstIdxKol(M) i <= GetNKolEff(M) ++i)
#define foriik(M, i) for(indeks i = GetNKolEff(M) i >= FirstIdxKol(M) --i)

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS “kosong” berukuran NB x NK di “ujung kiri” memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	*M.NBrsEff = 0;
	*M.NKolEff = 0;
}

/* *** Selektor "DUNIA MATRIKS" *** */
indeks GetIdxBrsMin(MATRIKS M)
/* Mengirimkan indeks baris minimum matriks apapun */
{
	return BrsMin;
}

indeks GetIdxKolMin(MATRIKS M)
/* Mengirimkan indeks kolom minimum matriks apapun */
{
	return KolMin;
}

indeks GetIdxBrsMax(MATRIKS M)
/* Mengirimkan indeks baris maksimum matriks apapun */
{
	return BrsMax;
}

indeks GetIdxKolMax(MATRIKS M)
/* Mengirimkan indeks kolom maksimum matriks apapun */
{
	return KolMax;
}

boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid */
{
	return (((BrsMin <= i) && (i <= BrsMax)) && ((KolMin <= j) && (j <= KolMax)));
}


/* *** Untuk sebuah matriks M yang terdefinisi: *** */
indeks FirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}

indeks FirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}

indeks LastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return BRsMax;
}

indeks LastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return KolMax;
}

int GetNBrsEff (MATRIKS M)
/* Mengirimkan banyaknya baris efektif M */
{
	return NBrsEff;
}

int GetNKolEff (MATRIKS M)
/* Mengirimkan banyaknya kolom efektif M */
{
	return NKolEff;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return (((BrsMin <= i) && (i <= GetNBrsEff(M))) && ((KolMin <= j) && (j <= GetNKolEff(M))));
}

el_type GetElmt (MATRIKS M, indeks i, indeks j)
/* Mengirimkan elemen M dg nomor baris i dan nomor kolom j */
{
	return M.Mem[i][j];
}

el_type GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return M.Mem[i][i];
}


/* *** Operasi mengubah nilai elemen matriks: Set / Assign *** */
void SetBrsEff (MATRIKS * M, int NB)
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.BrsEff diisi dengan NB, */
{
	forik(M, c){
		SetEl(M, GetNBrsEff(*M), c, NB);
	}
}

void SetKolEff (MATRIKS * M, int NK)
/* I.S. M sudah terdefinisi */
/* F.S. Nilai M.NKolEff diisi dengan NK */
{
	forib(M, r){
		SetEl(M, r, GetNKolEff(*M), NK);
	}
}

void SetEl (MATRIKS * M, int i, int j, el_type X)
/* I.S. M sudah terdefinisi */
/* F.S. M(i,j) bernilai X */
/* Proses: Mengisi M(i,j) dengan X */
{
	*M.Mem[i][j] = X;
}


/* ********** Assignment MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl ← Min */
{

}


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, dan berukuran NB x NK */
/* Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
/* dari pembacaan dengan traversal per baris */
{

}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Sama dengan I.S, dan nilai M(i,j) ditulis ke layar*/
/* Menulis nilai setiap indeks dan elemen M ke layar dengan traversal per baris */
{

}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS PlusMATRIKS(MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1 berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{

}

MATRIKS MinusMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{

}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{

}

MATRIKS KaliKons (MATRIKS M, int X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{

}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, */
/* yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom */
/* M1(i,j) = M2(i,j) */
{

}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika not strongEQ(M1,M2) */
{

}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{

}

boolean isLess (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif M1 < ukuran efektif M2 */
{

}


/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{

}


/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{

}

boolean IsSymetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) dan untuk
setiap elemen M, M(i,j)=M(j,i) */
{

}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan setiap
elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{

}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{

}

MATRIKS Invers1 (MATRIKS M)
/* Menghasilkan salinan M dg setiap elemen "di-invers", yaitu dinegasikan */
{

}

MATRIKS Invers (MATRIKS M)
/* Menghasilkan salinan M dg setiap elemen "di-invers", yaitu di-invers sesuai
dengan aturan inversi matriks */
{

}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{

}

void Invers1(MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan */
{

}

void Invers(MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M "di-invers", yaitu diproses sesuai dengan aturan invers matriks */
{

}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen
M(j,i) */
{

}
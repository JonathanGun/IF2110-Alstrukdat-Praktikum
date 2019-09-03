/* File: garis.h */
/* Tanggal: 29 Agustus 2019 */
/* Definisi ADT GARIS, menggunakan ADT point */
#ifndef GARIS_H
#define GARIS_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"

/* *** Definisi TYPE GARIS *** */
typedef struct {
  POINT PAw;  /* Titik Awal  */
  POINT PAkh; /* Titik Akhir */
} GARIS;

/* *** Selektor GARIS *** */
#define PAwal(L) (L).PAw
#define PAkhir(L) (L).PAkh

#endif
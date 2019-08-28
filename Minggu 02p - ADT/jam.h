/* File: jam.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef JAM_H
#define JAM_H

#include "boolean.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

#endif
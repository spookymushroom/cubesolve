#ifndef CUBESOLVE_H
#define CUBESOLVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char bool;
#define false 0
#define true 1

typedef struct {
	unsigned char len[3];
	bool isaligned;
	bool piecedat[3][3][3];
} piece;

int init_piece(piece *ppiece, bool data[3][3][3]); /*initializes to data*/
//DANGER: clobbers data

#endif /* RPS_H_INCLUDED */

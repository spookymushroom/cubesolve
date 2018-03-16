#include "cubesolve.h"

int init_piece(piece *ppiece, bool data[3][3][3])
{
	bool emptyplanes[3][3];
	for (int pl=0;pl<3;++pl) for (int c=0;c<3;++c) emptyplanes[pl][c] = true;
	for(int x=0;x<3;x++) for(int y=0;y<3;y++) for(int z=0;z<3;z++) {
	//set emptyplanes   COPY DATA TO PIECE LATER
		if (data[x][y][z]) {
			/*printf("Setting emptyplanes[0][%d] = false (not empty)\n",x);
			printf("Setting emptyplanes[1][%d] = false (not empty)\n",y);
			printf("Setting emptyplanes[2][%d] = false (not empty)\n",z);*/
			emptyplanes[0][x] = false;
			emptyplanes[1][y] = false;
			emptyplanes[2][z] = false;
		}
	}
	printf("Emptyplanes[0] = %d %d %d\n",emptyplanes[0][0],emptyplanes[0][1],emptyplanes[0][2]);
	printf("Emptyplanes[1] = %d %d %d\n",emptyplanes[1][0],emptyplanes[1][1],emptyplanes[1][2]);
	printf("Emptyplanes[2] = %d %d %d\n",emptyplanes[2][0],emptyplanes[2][1],emptyplanes[2][2]);
	unsigned char len[3] = {0};
	for(int plane=0;plane<3;plane++) {
	//find lengths, COPY TO PIECE LATER
		for(int coord=0;coord<3;coord++) {
			if(!emptyplanes[plane][coord]) len[plane]++;
		}
		if(!emptyplanes[plane][0] && !emptyplanes[plane][2] && emptyplanes[plane][1]) len[plane]++;
	}
	int shiftdown[3] = {0};
	for (int plane=0;plane<3;plane++) {
		for (int coord=0;coord<len[plane];coord++) {
			if (emptyplanes[plane][coord]) shiftdown[plane]++; //set shiftdown
			else break;
		}
		for (int coord=0;coord<3-shiftdown[plane];coord++) {
		//shift down, FIX THIS GARBAGE PLOX [FIXED!!]
		printf("Plane: %d, Coord: %d\n",plane,coord);
			if (plane==0) {
				for (int y=0;y<3;y++) for (int z=0;z<3;z++) data[coord][y][z] = data[coord+shiftdown[plane]][y][z];
				if (coord+1==3-shiftdown[plane]) {
					for (int uc=len[plane];uc<3;++uc) {
						for (int y=0;y<3;y++) for (int z=0;z<3;z++) data[uc][y][z] = 0;
					}
				}
			}
			else if (plane==1) {
				for (int x=0;x<3;x++) for (int z=0;z<3;z++) data[x][coord][z] = data[x][coord+shiftdown[plane]][z];
				if (coord+1==3-shiftdown[plane]) {
					for (int uc=len[plane];uc<3;++uc) {
						for (int x=0;x<3;x++) for (int z=0;z<3;z++) data[x][uc][z] = 0;
					}
				}
			}
			else if (plane==2) {
				for (int x=0;x<3;x++) for (int y=0;y<3;y++) data[x][y][coord] = data[x][y][coord+shiftdown[plane]];
				if (coord+1==3-shiftdown[plane]) {
					for (int uc=3-shiftdown[plane];uc<3;++uc) {
						for (int x=0;x<3;x++) for (int y=0;y<3;y++) data[x][y][uc] = 0;
					}
				}
			}
		}
	}
	printf("Shiftdown was: %d %d %d\n",shiftdown[0],shiftdown[1],shiftdown[2]);
	for(int x=0;x<3;x++) for(int y=0;y<3;y++) for(int z=0;z<3;z++) {
	//copy data to piece
		ppiece->piecedat[x][y][z] = data[x][y][z];
	}
	for(int i=0;i<3;i++) ppiece->len[i] = len[i]; //copy len to piece

	return 0;
}


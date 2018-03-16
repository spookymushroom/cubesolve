#include "cubesolve.h"

int main() {

//currently failing, cuts off the last true
	bool data[3][3][3] = {
		{
			{false,true,true},
			{false,true,true},
			{false,false,false}
		},
		{
			{false,true,true},
			{false,true,true},
			{false,false,false}
		},
		{
			{false,false,true},
			{false,false,false},
			{false,false,false},
		}
	};

	printf("initdata: ");
	for (int x=0;x<3;++x) {
		for (int y=0;y<3;++y) {
			for (int z=0;z<3;++z) {
				printf("%d ",data[x][y][z]);
			}
		}
	}
	printf("\n");

	piece p;
	init_piece(&p,data);


	printf("piecedat: ");
	for (int x=0;x<3;++x) {
		for (int y=0;y<3;++y) {
			for (int z=0;z<3;++z) {
				printf("%d ",p.piecedat[x][y][z]);
			}
		}
	}

	printf("\nlen: ");
	for (int i=0;i<3;++i) printf("%d ",p.len[i]);
	printf("\n");

}

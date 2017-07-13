#include <stdio.h>

#define X_SIZE 40
#define Y_SIZE 60

/* 
 * 1バイトは8ビットであるため、X_SIZE/8を使用する
 */

char graphics[X_SIZE / 8][Y_SIZE];

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

int main()
{
	int loc;			/* セットするビットの現在の位置 */
	void print_graphics(void);  /* データを出力 */

	for (loc = 0; loc < X_SIZE; ++loc)
		SET_BIT(loc, loc);

	print_graphics();
	
	return(0);
}

void print_graphics(void)
{
	int x;
	int y;
	unsigned int bit;
	for (y = 0; y < Y_SIZE; ++y){
		/*  配列中の各バイトについてループ */
		for (x = 0; x < X_SIZE /8; ++x){
			/* 一つ一つのビットを処理 */
			for (bit = 0x80; bit > 0; bit = (bit >> 1)){
				if ((graphics[x][y] & bit) != 0)
					printf("X");
				else
					printf(".");
			}
		}
		printf("\n");
	}
}

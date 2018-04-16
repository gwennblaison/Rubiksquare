#include "rubiks.h"

void print_tab(int **game) {
	int x;
	int y;
	x = 0;
	y = 0;
	while (x < 4) {
		printf("-----------------\n");
		while (y < 4) {
			printf("| %d ",game[x][y]);
			if (y == 3)
				printf("|");
			y++;
		}
		printf("\n");
		y = 0;
		if (x == 3)
		{
			printf("-----------------\n\n");
		}
		x++;
	}
}
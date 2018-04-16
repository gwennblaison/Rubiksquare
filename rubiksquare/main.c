#include "rubiks.h"

int main(int argc, char *argv[]) {

	// Example of final result:
	/*
	** 		0 | 0 | 3 | 3
	** 		0 | 0 | 3 | 3
	**		1 | 1 | 2 | 2
	**		1 | 1 | 2 | 2
	*/

	// create the rubiksquare matrix
	int **tab = malloc(4 * sizeof(int*));
	tab[0] = malloc(4 * sizeof(int));
	tab[0][0] = 0;
	tab[0][1] = 1;
	tab[0][2] = 0;
	tab[0][3] = 1;
	tab[1] = malloc(4 * sizeof(int));
	tab[1][0] = 0;
	tab[1][1] = 1;
	tab[1][2] = 1;
	tab[1][3] = 0;
	tab[2] = malloc(4 * sizeof(int));
	tab[2][0] = 3;
	tab[2][1] = 2;
	tab[2][2] = 2;
	tab[2][3] = 3;
	tab[3] = malloc(4 * sizeof(int));
	tab[3][0] = 2;
	tab[3][1] = 2;
	tab[3][2] = 3;
	tab[3][3] = 3;

	print_tab(tab);

	// check if the present numbers are valid
	if (check_numbers(tab) == 1)
		return (-1);

 	// check if the rubiksquare is not already solved
	if (check_matrix(tab) == 1) {
		printf("Cette matrice est déjà rangée.\n");
		return (-1);
	}

	// shape the 0s square (top left)
	build_first_square(tab);

	// shape the 3s square (top right)
	build_second_square(tab);

	// shape the 2s and 1s squares (bottom left and right)
	build_last_squares(tab);

	print_tab(tab);

	// system("sleep 1");
	// system("clear");

	// set the allocated memory free
	int x = 0;
	while (x < 4) {
		free(tab[x]);
		x++;
	}
	free(tab);

	return (0);
}

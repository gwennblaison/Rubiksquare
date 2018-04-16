#include "rubiks.h"

void verif_return(int *ret) {
	if (ret != NULL)
		printf("line : %d\nColumn : %d\n", ret[0], ret[1]);
	else
		printf("Nothing found in the given range.\n");
}

int check_first_line(int **table) {
	int i = 0;
	int value = 0;
	int lines[TABLE_SIZE];
	int columns[TABLE_SIZE];
	int *coords;
	while (i < TABLE_SIZE) {
		lines[i] = BLOCKED;
		columns[i] = EMPTY;
		i++;
	}
	lines[value] = EMPTY;
	if (look_for_space(table,lines,columns,value) == NULL) {
		return (1);
	}
	else {
		return (0);
	}
}

int check_last_line(int **table) {
	int i = 0;
	int value = 3;
	int lines[TABLE_SIZE];
	int columns[TABLE_SIZE];
	int *coords;
	while (i < TABLE_SIZE) {
		lines[i] = BLOCKED;
		columns[i] = EMPTY;
		i++;
	}
	lines[value] = EMPTY;
	if (look_for_space(table,lines,columns,value) == NULL) {
		return (1);
	}
	else {
		return (0);
	}
}

int check_third_line(int **table) {
	int i = 0;
	int lines[TABLE_SIZE];
	int columns[TABLE_SIZE];
	int *coords;
	while (i < TABLE_SIZE) {
		lines[i] = BLOCKED;
		columns[i] = EMPTY;
		i++;
	}
	lines[2] = EMPTY;
	if (look_for_space(table,lines,columns,2) == NULL) {
		return (1);
	}
	else if (look_for_space(table,lines,columns,1) == NULL) {
		return (1);
	}
	else {
		return (0);
	}
}

int check_squares(int **table, int line, int column) {
	int i = 0;
	if (table[line][column] == table[line][column+1] && table[line+1][column] == table[line+1][column+1] && table[line][column] == table[line+1][column] && table[line][column+1] == table[line+1][column+1])
		return (1);
	return (0);
}

int check_matrix(int **table) {
	// checks if the matrix is not already resolved
	int square0 = check_squares(table,0,0);
	int square3 = check_squares(table,2,2);
	int square1 = check_squares(table,0,2);
	int square2 = check_squares(table,2,0);
	if (square0 == 1 && square1 == 1 && square2 == 1 && square3 == 1)
		return (1);
	else
		return (0);
}

int check_numbers(int **table) {
	int i = 0;
	int j = 0;
	int zero = 0;
	int un = 0;
	int deux = 0;
	int trois = 0;
	int ret = 0;
	while (i < TABLE_SIZE) {
		while (j < TABLE_SIZE) {
			switch (table[i][j]) {
				case 0:
				zero++;
				break;
				case 1:
				un++;
				break;
				case 2:
				deux++;
				break;
				case 3:
				trois++;
				break;
				default:
				printf("Erreur liée à la composition du carré.\n");
				ret = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (zero > 4 || un > 4 || deux > 4 || trois > 4) {
		printf("Erreur liée à la composition du carré.\n");
		ret = 1;
	}
	return (ret);
}

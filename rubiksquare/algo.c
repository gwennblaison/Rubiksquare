#include "rubiks.h"

// rotates a single line to the left
void algo_line(int **table, int line) {
	if (PRINT_SQUARE_DEBUG__ == 1)
		printf("Rotate Left line %d.\n",line);

	int i = 3;
	int tmp = 0;
	// switches the 4th value with the 1st, the 3rd with the 1st...
	while (i >= 0) {
		tmp = table[line][i];
		table[line][i] = table[line][0];
		table[line][0] = tmp;
		i--;
	}
}

// rotates a single column to the top
void algo_column(int **table, int column) {
	if (PRINT_SQUARE_DEBUG__ == 1)
		printf("Rotate Top column %d.\n",column);

	int i = 3;
	int tmp = 0;
	// switches the 4th value with the 1st, the 3rd with the 1st...
	while (i >= 0) {
		tmp = table[i][column];
		table[i][column] = table[0][column];
		table[0][column] = tmp;
		i--;
	}
}

// rotates a single square clockwise (voir avec modulo)
void algo_square(int **table, int square) {
	if (PRINT_SQUARE_DEBUG__ == 1)
		printf("Rotate Clockwise square %d.\n",square);

	int tmp = 0;
	int i = 0;
	int j = 0;

	switch(square) {
	   	case 0:
			tmp = table[1][1];
			table[1][1] = table[1][0];
			table[1][0] = tmp;
			tmp = table[0][1];
			table[0][1] = table[1][1];
			table[1][1] = tmp;
			tmp = table[0][0];
			table[0][0] = table[0][1];
			table[0][1] = tmp;
	      	break;
	   	case 1:
	      	tmp = table[1][3];
			table[1][3] = table[1][2];
			table[1][2] = tmp;
			tmp = table[0][3];
			table[0][3] = table[1][3];
			table[1][3] = tmp;
			tmp = table[0][2];
			table[0][2] = table[0][3];
			table[0][3] = tmp;
	      	break;
	   	case 2:
	   		tmp = table[3][1];
			table[3][1] = table[3][0];
			table[3][0] = tmp;
			tmp = table[2][1];
			table[2][1] = table[3][1];
			table[3][1] = tmp;
			tmp = table[2][0];
			table[2][0] = table[2][1];
			table[2][1] = tmp;
	      	break;
	   	case 3:
	   		tmp = table[3][3];
			table[3][3] = table[3][2];
			table[3][2] = tmp;
			tmp = table[2][3];
			table[2][3] = table[3][3];
			table[3][3] = tmp;
			tmp = table[2][2];
			table[2][2] = table[2][3];
			table[2][3] = tmp;
	      	break;
	   	default :
	   		printf("not a square\n");
	}
}

// rotates a single line on the right
void algo_line_reverse(int **table, int line) {
	if (PRINT_SQUARE_DEBUG__ == 1)
		printf("Rotate Right line %d.\n",line);

	int i = 1;
	int tmp = 0;
	// switches the 1st value with the 2nd, the 1st with the 3rd...
	while (i < 4) {
		tmp = table[line][i];
		table[line][i] = table[line][0];
		table[line][0] = tmp;
		i++;
	}
}

// rotates a single column down
void algo_column_reverse(int **table, int column) {
	if (PRINT_SQUARE_DEBUG__ == 1)
		printf("Rotate Down column %d.\n",column);

	int i = 1;
	int tmp = 0;
	// switches the 1st value with the 2nd, the 1st with the 3rd...
	while (i < 4) {
		tmp = table[i][column];
		table[i][column] = table[0][column];
		table[0][column] = tmp;
		i++;
	}
}

// rotates a single square counter clockwise
void algo_square_reverse(int **table, int square) {
	if (PRINT_SQUARE_DEBUG__ == 1)
		printf("Rotate Clockwise square %d.\n",square);

	int tmp = 0;
	int i = 0;
	int j = 0;
	switch(square) {
	   	case 0:
			tmp = table[0][1];
			table[0][1] = table[0][0];
			table[0][0] = tmp;
			tmp = table[1][1];
			table[1][1] = table[0][1];
			table[0][1] = tmp;
			tmp = table[1][0];
			table[1][0] = table[1][1];
			table[1][1] = tmp;
	      	break;
	   	case 1:
			tmp = table[0][3];
			table[0][3] = table[0][2];
			table[0][2] = tmp;
			tmp = table[1][3];
			table[1][3] = table[0][3];
			table[0][3] = tmp;
			tmp = table[1][2];
			table[1][2] = table[1][3];
			table[1][3] = tmp;
	      	break;
	   	case 2:
			tmp = table[2][1];
			table[2][1] = table[2][0];
			table[2][0] = tmp;
			tmp = table[3][1];
			table[3][1] = table[2][1];
			table[2][1] = tmp;
			tmp = table[3][0];
			table[3][0] = table[3][1];
			table[3][1] = tmp;
	      	break;
	   	case 3:
			tmp = table[2][3];
			table[2][3] = table[2][2];
			table[2][2] = tmp;
			tmp = table[3][3];
			table[3][3] = table[2][3];
			table[2][3] = tmp;
			tmp = table[3][2];
			table[3][2] = table[3][3];
			table[3][3] = tmp;
	      	break;
	   	default :
	   		printf("not a square\n");
	}
}

int is_in_line(int **table, int line, int value) {
	// returns 0 (EMPTY) if the value is found in the given line
	// if not, returns 1 (BLOCKED)
	int i = 0;
	while (i < 4) {
		if (table[line][i] == value)
			return (EMPTY);
		i++;
	}
	return (BLOCKED);
}

int is_in_col(int **table, int column, int value) {
	// returns 0 (EMPTY) if the value is found in the given column
	// if not, returns 1 (BLOCKED)
	int i = 0;
	while (i < 4) {
		if (table[i][column] == value)
			return (EMPTY);
		i++;
	}
	return (BLOCKED);
}

int* look_for_space(int **table, int *lines, int *columns, int value) {
	int i = 0;
	int j = 0;
	int *ret = malloc(2 * sizeof(int));
	ret[0] = 0;
	ret[1] = 0;

	while (i < 4) {
		if (lines[i] == EMPTY) {
			while (j < 4) {
				if (columns[j] == EMPTY) {
					if (table[i][j] != value) {
						ret[0] = i;
						ret[1] = j;
						return (ret);
					}
				}
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int* look_for_value(int **table, int *lines, int *columns, int value) {
	int i = 0;
	int j = 0;
	int *ret = malloc(2 * sizeof(int));
	ret[0] = 0;
	ret[1] = 0;
	while (i < 4) {
		if (lines[i] == EMPTY) {
			while (j < 4) {
				if (columns[j] == EMPTY) {
					if (table[i][j] == value) {
						ret[0] = i;
						ret[1] = j;
						return (ret);
					}
				}
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

void rotate_lines(int **table, int line, int offset) {
	if (offset < 0) {
		while (offset != 0) {
			algo_line_reverse(table,line);
			offset++;
		}
	}
	else if (offset > 0) {
		while (offset != 0) {
			algo_line(table,line);
			offset--;
		}
	}
}

void rotate_columns(int **table, int column, int offset) {
	if (offset < 0) {
		while (offset != 0) {
			algo_column_reverse(table,column);
			offset++;
		}
	}
	else if (offset > 0) {
		while (offset != 0) {
			algo_column(table,column);
			offset--;
		}
	}
}

int empty_table(int *table) {
	int i = 0;
	while (i < TABLE_SIZE) {
		table[i] = EMPTY;
		i++;
	}
}

int get_square_number(int x, int y) {
	// returns the current square we want to rotate
	int square = 0;
	if (x < 2 && y < 2)
		square = 0;
	if (x < 2 && y >= 2)
		square = 1;
	if (x >= 2 && y < 2)
		square = 2;
	if (x >= 2 && y >= 2)
		square = 3;
	return (square);
}

void build_first_line(int **table) {
	// aligns a value on the first line
	int i = 0;
	int value = 0;
	int lines[TABLE_SIZE];
	int columns[TABLE_SIZE];
	int *coords_value;
	int *coords_space;
	int end = check_first_line(table); // 0 until the first line is filled with 0s
	int iterations_max = TABLE_SIZE;

	while (end == 0) {
		empty_table(lines);
		empty_table(columns);

		// look for the first empty space in the first line
		i = 0;
		while (i < TABLE_SIZE) {
			lines[i] = BLOCKED;
			columns[i] = EMPTY;
			i++;
		}
		lines[0] = EMPTY;
		// only the first line remains EMPTY so that we can look for empty spaces in it
		coords_space = look_for_space(table,lines,columns,value);

		// look for the first 0 we want to move
		i = 0;
		while (i < TABLE_SIZE) {
			lines[i] = is_in_line(table,i,value);
			columns[i] = is_in_col(table,i,value);
			i++;
		}
		lines[0] = BLOCKED;
		// the last line is BLOCKED so that we don't search in it
		coords_value = look_for_value(table,lines,columns,value);

		rotate_lines(table,coords_value[0],coords_value[1]-coords_space[1]);
		rotate_columns(table,coords_space[1],coords_value[0]-coords_space[0]);
		print_tab(table);

		end = check_first_line(table);

		// if too many iterations, probably an error
		iterations_max--;
		if (iterations_max < 0) {
			end = 1;
			printf("Erreur.\n");
		}
	}

}

void build_last_line(int **table) {
	// aligns a value on the last line
	int i = 0;
	int value = 3;
	int lines[TABLE_SIZE];
	int columns[TABLE_SIZE];
	int *coords_value;
	int *coords_space;
	int end = check_last_line(table);
	int iterations_max = TABLE_SIZE;

	// the goal is to create the "3" line without disturbing the "0" square
	// we have to place the "3"s on the top right part of the rubiksquare
	// to move them to the bottom line
	// and then under the "0" square

	while (end == 0) { // while the last line is not filled with "3"s
		empty_table(lines);
		empty_table(columns);

		// look for the first empty space on the last line
		i = 0;
		while (i < TABLE_SIZE) {
			lines[i] = BLOCKED;
			columns[i] = EMPTY;
			i++;
		}
		lines[3] = EMPTY;
		// only the last line remains EMPTY so that we can look for empty spaces in it
		coords_space = look_for_space(table,lines,columns,value);

		// look for the first 3 we want to move
		i = 0;
		while (i < TABLE_SIZE) {
			lines[i] = is_in_line(table,i,value);
			columns[i] = is_in_col(table,i,value);
			i++;
		}
		lines[3] = BLOCKED;
		// the last line is BLOCKED so that we don't search in it
		coords_value = look_for_value(table,lines,columns,value);

		// 2 possibilities : a "3" can be
		// 		below the "0" square
		//		in the top right part of the rubiksquare

		if (coords_value[1] < 2) {	// 3 is below the "0" square
			// move the 3 in the far right column (on the same line)
			rotate_lines(table,coords_value[0],coords_value[1]-3);
			// move the empty space under the 3 we just moved
			rotate_lines(table,coords_space[0],coords_space[1]-3);
			// move the 3 in this empty space
			rotate_columns(table,3,-1);
		}
		else {	// 3 is in the top right part of the rubiksquare (coords_value[1] >= 2)
			rotate_lines(table,coords_space[0],coords_space[1]-coords_value[1]);
			rotate_columns(table,coords_value[1],coords_value[0]-coords_space[0]);
		}

		print_tab(table);

	// check if the line is done
	end = check_last_line(table);

	}
		// if too many iterations, probably an error
		iterations_max--;
		if (iterations_max < 0) {
			end = 1;
			printf("Erreur.\n");
		}

	free(coords_value);
	free(coords_space);
}

void build_last_squares(int **table) {
	int i = 0;
	int j = 0;
	int k = 0;
	int lines[TABLE_SIZE];
	int columns[TABLE_SIZE];
	int *coords_value;
	int *coords_space;
	int x = 0;
	int y = 0;
	int end = check_matrix(table);
	int iterations_max = 10;
	int iteration_index = 0;
	// 3 possibilities here:
	// two 2s aligned horizontally = don't touch them
	// two 2s aligned vertically = turn the square
	// two 2s side by side on a diagonal = rotate the line in one way or the other

	while (end == 0) {	// while the rubiksquare is not resolved
		empty_table(lines);
		empty_table(columns);

		i = 0;
		while (i < TABLE_SIZE-1) {
			j = 0;
			while (j < TABLE_SIZE-1) {
				// on recherche dans la ligne 2 s
				lines[j] = is_in_line(table,2,table[2][i]);
				columns[j] = is_in_col(table,2,table[2][i]);
				k = i;
				if (i > 0) {
					// if it's not the the first number of the line
					// we set to BLOCKED the columns containing the previous numbers
					// so that we don't iterate through them again
					for (k = 0; k < i; k++)
						columns[k] = BLOCKED;
				}
				j++;
			}
			coords_value = look_for_value(table,lines,columns,table[2][i]);

			// save the coordinates of the first value encountered
			x = coords_value[0];
			y = coords_value[1];

			if (x < 3 && y < 3) {	// as long as it's not the last value on the line (no segfault)
				if (table[x][y] != table[x+1][y]) {}
				// aligned vertically (REMINDER : rotate square)
				else {
					algo_square_reverse(table,get_square_number(x,y));
				}

				if (table[x][y] != table[x+1][y+1]) {}
				// side by side on a diagonal (REMINDER : rotate line)
				else {
					algo_line_reverse(table,2);
				}
			}
			else { 	// if it's the last number of the line, we rotate the line n°2
							// to bring this number to the beginning of the line
				algo_line_reverse(table,2);
			}

		print_tab(table);

		i++;
		}

		// if both lines are respectively filled with 1s and 2s
		// rotate the same square twice to shape our final squres
		if (check_third_line(table) == 1) {
			line_to_square(table, 2);
			end = 1;
		}

		// check if the rubiksquare is completely resolved
		end = check_matrix(table);

		// if too many iterations, probably an error
		iterations_max--;
		if (iterations_max < 0) {
			end = 1;
			printf("Erreur.\n");
		}
	}
	// free(coords_value);
	// free(coords_space);
}

void line_to_square(int **table, int line) {
	// transmutes the given line to a square with the same number
	algo_square_reverse(table,line);
	algo_square_reverse(table,line);
	algo_line(table,line);
	algo_line(table,line);
}

void push_it_up(int **table) {
	algo_column(table,2);
	algo_column(table,2);
	algo_column(table,3);
	algo_column(table,3);
}

void build_first_square(int **table) {
	build_first_line(table);	// align a value on the first line
	line_to_square(table,0);	// transmute the given line to a square with the same number
}

void build_second_square(int **table) {
	build_last_line(table);
	line_to_square(table, 3);
	push_it_up(table);
}

void free_table(int *ret) {
	free(ret);
}

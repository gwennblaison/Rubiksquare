#ifndef RUBIKS_H_
#define RUBIKS_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define EMPTY 0
#define BLOCKED 1
#define PRINT_SQUARE_DEBUG__ 1
#define TABLE_SIZE 4

void print_tab(int **game);
void algo_line(int **table, int line);
void algo_column(int **table, int column);
void algo_square(int **table, int square);
void algo_line_reverse(int **table, int line);
void algo_column_reverse(int **table, int column);
void algo_square_reverse(int **table, int square);
int is_in_line(int **table, int line, int value);
int is_in_col(int **table, int column, int value);
int* look_for_space(int **table, int *lines, int *columns, int value);
int* look_for_value(int **table, int *lines, int *columns, int value);
void rotate_lines(int **table, int line, int offset);
void rotate_columns(int **table, int column, int offset);
void verif_return(int *ret);
int check_first_line(int **table);
int check_last_line(int **table);
int check_third_line(int **table);
int empty_table(int *table);
void build_first_line(int **table);
void build_last_line(int **table);
void build_last_squares(int **table);
void line_to_square(int **table, int line);
void push_it_up(int **table);
void build_first_square(int **table);
void build_second_square(int **table);
int check_numbers(int **table);
int check_matrix(int **table);

#endif
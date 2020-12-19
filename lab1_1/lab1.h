#include <iostream>

struct matrix{
	int data;
	int num;
	int str;
	struct matrix *next;
};

struct init_matrix{
	struct matrix *next;
};

struct all_matrix{
	int x;
	int y;
};

struct init_matrix *init();

struct all_matrix *init_all_matrix(); 

void dump_matrix(struct init_matrix *im, struct all_matrix *am);

void out_matrix(struct init_matrix *im, struct all_matrix *am);

matrix* create_matrix(struct init_matrix *im, struct all_matrix *am);

void clean_all(struct init_matrix *im, struct all_matrix *am);

void out_matrix(struct matrix *matrix2);

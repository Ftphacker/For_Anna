#include <iostream>
#include "lab1.h"

int main(){
	struct init_matrix *im;
	struct all_matrix *am;
	am = init_all_matrix();
	//std::cout<<"1\n";
	if (am == NULL){return 0;}
	im = init();
	dump_matrix(im, am);
	out_matrix(im, am);
	//std::cout << "GG\n";
	struct matrix *matrix2;
	//std::cout << "GG\n";
	matrix2 = create_matrix(im, am);
	//std::cout << "GG\n";
	std::cout<<std::endl;
	//std::cout << "GG\n"
	if(matrix2 == NULL){
		return 0;
	}
	out_matrix(matrix2);
	std::cout<< "\n";
	clean_all(im,am);
	return 0;
}
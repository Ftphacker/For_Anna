#include <iostream>
#include "lab1.h"

struct all_matrix *init_all_matrix(){
	struct all_matrix *m = new struct all_matrix;
	int x,y;
	std::cout<<"y :: ";
	std::cin>>x;
	if (!std::cin.good()){
		std::cout<<"error\n";
		return NULL;
	}
	std::cout<<"x :: ";
	std::cin>>y;
	if (!std::cin.good()){
		std::cout<<"error\n";
		return NULL;	
	}
	m->x = x;
	m->y = y;
	return m;
}

struct init_matrix *init(){
	struct init_matrix *m = new struct init_matrix;
	m->next = NULL;
	return m;
}

void dump_matrix(struct init_matrix *im, struct all_matrix *am){
	int data = 1, str, num;
	std::cout<< im->next<<"\n";
	while (data != 0){
		//std::cout<<"1\n";
		std::cout<<"give data :: ";
		std::cin>>data;
		if (!std::cin.good()){
			break;
		}
		if (data == 0) {
			break;
		}
		std::cout<<"give num :: ";
		std::cin>>num;
		if (!std::cin.good()){
			break;
		}
		std::cout<<"give str :: ";
		std::cin>>str;
		if (!std::cin.good()){
			break;
		}
		struct matrix *pobg = im->next;
		bool value = true;
		while (pobg != NULL){
			if(pobg->str == str && pobg->num == num){
				std::cout<<"NO\n";
				value = false;
			}
			pobg = pobg->next;
		}
		if (am->x < str || am->y < num){value = false; std::cout<<"NO\n";}
		if (value == true){
			struct matrix *m = new struct matrix;
			if (im->next == NULL){
				im->next = m;
				m->next = NULL;
			}else{
				m->next = im->next;
				im->next = m;
			}
			m->data = data;
			m->str = str;
			m->num = num;
		}
	}
	struct matrix *pobg = im->next;
	while (pobg != NULL){
		std::cout<<" data :: "<< pobg->data << "str :: "<< pobg->str<< "num :: "<< pobg->num<< "\n";
		pobg = pobg->next;
	}
}

void out_matrix(struct init_matrix *im, struct all_matrix *am){
	struct matrix *pobg = im->next;
	for(int i = 0; i < am->x; i++){
		for (int j = 0; j < am->y; j++){
			bool value = false;
			pobg = im->next;
			while (pobg != NULL){
				if (pobg->str == i && pobg->num == j){value = true; break;}
				pobg = pobg->next;
			}
			if (value == true){
				std::cout<<pobg->data; 
			}else{
				std::cout<<"0";
			}
		}
		std::cout<<std::endl;
	}
}

void out_matrix(struct matrix *matrix2){
	struct matrix *pobg = matrix2;
	while (pobg != NULL){
		std::cout<<pobg->data; 
		if((pobg->next != NULL) && (pobg->str < pobg->next->str)){
			std::cout<<std::endl;
		}else if((pobg->next == NULL)){
			//std::cout<<pobg->data;
		}
		pobg = pobg->next;
	}
}



int numb(int data){
	int rang = 0;
	while (data > 0){
		data = data/10;
		++rang;
	}
	return rang;
}

struct matrix* create_matrix(struct init_matrix *im, struct all_matrix *am){
	struct matrix *pobg = im->next;
	struct matrix *pobg2 = NULL;
	//std::cout << "GG\n";
	int n = 0;
	double everage = 0;
	int counter = 0;
	int sum = 0;
	int k = 0;
	//std::cout << "GG\n";
	struct matrix *creatematrix = new struct matrix;
	struct matrix *create_matrix2 = NULL;
	creatematrix->data = 0;
	//std::cout << "GG\n";
	while (n < am->y){
		//std::cout << "GG\n";
		pobg = im->next;
		while (pobg != NULL){
			if (pobg->str == n){
				//std::cout << "GG\n";
				counter += numb(pobg->data); 
				//std::cout << "GG\n";
				++sum;
			}
			pobg = pobg->next;
		}
		pobg = im->next;
		if(sum != 0){
			everage = counter/sum;
		}else{
			pobg = NULL;
		}
		while (pobg != NULL){
			if (pobg->str == n){
				//std::cout << "GG\n";
				//std::cout<< everage << std::endl;
				//std::cout << "GG\n";
				if((numb(pobg->data)) > everage){
					//std::cout << "GG\n";
					if(creatematrix->data == 0){
						creatematrix -> data = pobg->data;
						creatematrix -> str = n;
						creatematrix -> num = k;
						creatematrix -> next = NULL;
						++k;
					}else{
						if (create_matrix2 == NULL){
							pobg2 = creatematrix;
						}else{
							pobg2 = create_matrix2;
						}
						struct matrix *create_matrix2 = new struct matrix;
						create_matrix2 -> data = pobg->data;
						create_matrix2 -> str = n;
						create_matrix2 -> num = k;
						pobg2->next = create_matrix2;
						create_matrix2 -> next = NULL;
						++k;
					}
				}
			}
			pobg = pobg->next;
		}
		n++;
		k = 0;
		sum = 0;
		//std::cout << "GG\n";
	}
	if(creatematrix -> data == 0){
		return NULL;
	}else{
		return creatematrix;
	}
}

void clean_all(struct init_matrix *im, struct all_matrix *am){
	struct matrix *pobg = im->next;
	struct matrix *pobg2 = im->next;
	while (pobg2 != NULL){
		pobg2 = pobg->next;
		delete  pobg;
		pobg = pobg2;
	}
	delete am;
	delete im;
}

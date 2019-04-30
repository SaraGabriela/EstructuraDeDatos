#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

template <class T>
class sparse_matrix
{
	struct node
	{
		T value;
		size_t pos[2];		// pos[0] = i-row, pos[1] = i-col
		node * p_next[2];	// p_next[0]: next row node
							// p_next[1]: next col node
		
		node(size_t i, size_t j, node * nr, node * nc)
		{
			pos[0] = i;
			pos[1] = j;
			p_next[0] = nr;
			p_next[1] = nc;
		}
	};
	
	private:
		node ** p_head[2];
		size_t n_rows, n_cols;
		
	public:
		sparse_matrix(size_t nr = 0, size_t nc = 0): n_rows(nr), n_cols(nc)
		{
			if(!n_cols) n_cols = n_rows;
			if(!n_rows)
			{
				p_head[0] = p_head[1] = NULL;
				return;
			}			
			
			p_head[0] = new node * [n_rows];
			p_head[1] = new node * [n_cols];
			
			memset(p_head[0], 0, sizeof(node *) * n_rows);
			memset(p_head[1], 0, sizeof(node *) * n_cols);
		}
		
		~sparse_matrix()
		{
			node **n;
			for (int j=0; j<n_rows; j++){ //OBTIENE HEAD DE CADA COLUMNA
					node **n;
					n = &p_head[0][j];
					p_head[0][j] = p_head[0][j]->p_next[1];
					delete n;
			}
			delete[]p_head[0];
			delete[]p_head[1];
		}
		
		void trans(){
			/*n_rows=m.n_rows;
			n_cols=m.n_cols; 
			
			node ** n;
			for (int i=0; i<n_cols;i++){
				for (int j=0; j<n_rows; j++){
					*n = new node(j, i, *nr, *nc); //TERMINAR
				}
			}*/
			node ** n;
			for (int i=0; i<n_rows;i++){
				for (int j=0; j<n_cols; j++){
					if(!find(n, j, i, 0)){
						cout<<0<<" ";
					}
					else{
						cout<<(*n)->value<<" ";
					}
				}
				cout<<endl;
			} 
			
		};
		bool find(node **& n, size_t i, size_t j, bool c)
		{
			n = &p_head[c][i];
			while(*n && (*n)->pos[!c] < j)
				n = &(*n)->p_next[c];
			
			return (*n) && (*n)->pos[!c] == j;
		}
		
		void delNode(size_t i, size_t j)
		{
			node ** n;
			if(find(n,i,j,0)){ //solo borra 00
				node ** temp;
				temp = n;
				p_head[0][i]= (*n)->p_next[0];
				p_head[1][j]= (*n)->p_next[1];
				delete temp;
			}
			else if(find(n,j,i,1)){
				node ** temp;
				temp = n;
				cout<<(*n)->value;
			}
		}
		T & operator () (size_t i, size_t j)
		{
			node ** nr;
			if(!find(nr, i, j, 0))
			{
				node ** nc;
				find(nc, j, i, 1);
				*nr = *nc = new node(i, j, *nr, *nc);
			}
			
			return (*nr)->value;
		}

		void print()
		{
			node **n;
			/*while((*n)->pos[0] <= n_cols){
				cout<<(*n)->value<<endl;
				n = &(*n)->p_next[0];
			}*/ //cout 12 23

			/*
			for (int j=0; j<n_cols; j++){ //OBTIENE HEAD DE CADA COLUMNA
					n = &p_head[1][j];
			*/
			for (int i=0; i<n_rows;i++){
				for (int j=0; j<n_cols; j++){
					if(!find(n, i, j, 0)){
						cout<<0<<" ";
					}
					else{
						cout<<(*n)->value<<" ";
					}
				}
				cout<<endl;
			} 
		}	
};

int main()
{
	sparse_matrix<int> m(3, 4);
	sparse_matrix<int> sq(3);
	
	sq(0, 0) = 12;
	sq(0, 2) = 23;
	sq(1, 1) = 32;
	sq(2, 0) = 12312;

	sq.print();
	cout<<endl;
	sq.delNode(0,0);
	sq.print();
	//sparse_matrix<int> tr = tr.trans(sq);
	//tr.print();
	return 0;
}

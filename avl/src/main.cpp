#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class K, class D>
class avl;

template <class K, class D>
class node
{
private:
	K key;
	D dato;
	node<K, D> * p_child[2]; // 0 left, 1 right
	int h;

public:
	node(const K & _key, const D & _dato) : key(_key), dato(_dato)
	{
		p_child[0] = p_child[1] = NULL;
	}

	~node() = default;

	friend class avl<K, D>;
};

template <class K, class D>
class avl
{
private:
	node<K, D> * p_root;

public:
	avl() : p_root(NULL) {}
	~avl()
	{
		destructor(p_root);
	}

	void destructor(node<K, D> * n)
	{
		if (n)
		{
			destructor(n->p_child[0]);
			destructor(n->p_child[1]);
			delete(n);
		}
	}

	void print(node<K, D> * n)
	{
		if (n)
		{
			print(n->p_child[0]);
			cout << n->key << " ";
			print(n->p_child[1]);
		}
	}

	void print()
	{
		print(p_root);
	}
	
	void turn(node <K,D>* n, int d){
		node<K,D> * aux = (*n)->p_child[d];
		(*n)->p_child[d]= aux -> p_child[!d];
		aux -> p_child[!d]= *n;
		*n = aux;
	}

/*	int balance(node <K,D>* n){
		int f = (*n)->p_child[0]->h - (*n)->p_child[1]->h; //factor de balance
		return f;
	}*/

	bool insert(const K & key, const D & dato)
	{
	/*	node<K, D> ** n;
		if (find(n, key)) return false;

		*n = new node<K, D>(key, dato);
		return true;*/
		return insert(&p_root,key,dato);
	}
	bool insert(node <K,D>** n, const K & key, const D & dato){ //PREGUNTAR DIFERENCIA ENTRE node <K,D>** n Y node <K,D>* n
		if(!*n){
			*n=new node<K,D>(key,dato);
			return true;
		}
		if((*n)->key == key) return false;
		int d = key > (*n)->key; //Si es mayor a la derecha
		if(!insert(&(*n)->p_child[d],key,dato)) return false;
		(*n)->h = max((*n)->p_child[0]->h,(*n)->p_child[1]->h) + 1; //altura del nodo
/*
		if((balance(*n) ==2 && balance((*n)->p_child[0]==1)) || (balance(*n) ==-2 && balance((*n)->p_child[1]==-1)) ){
			turn(*n,d);
		}
		else if ((balance(*n) ==2 && balance((*n)->p_child[0]==-1)) || (balance(*n) ==-2 && balance((*n)->p_child[1]==1))){
			turn((*n)->p_child[!d],d);
			turn(*n,!d);
		}*/
		return true;
	}
};

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
	avl<int,int> tree;
	tree.insert(3,50);
	tree.insert(7,50);
	tree.insert(1,50);

}
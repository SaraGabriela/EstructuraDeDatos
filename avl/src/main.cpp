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
	
	bool insert(const K & key, const D & dato)
	{
	/*	node<K, D> ** n;
		if (find(n, key)) return false;

		*n = new node<K, D>(key, dato);
		return true;*/
		return insert(&p_root,key,dato);
	}

	bool insert(node ** n, const K & key, const D & dato){
		if(!*n){
			*n=new node(key,dato);
			return true;
		}
		if((*n)->key == key) return false;
		int d = key > (*n)->key; //Si es mayor a la derecha
		if(!insert(&(*n)->p_child[d],key,dato)) return false;
		(*n)->h = max((*n)->p_child[0]->h,(*n)->p_child[1]->h) + 1; //altura del nodo
		int f = (*n)->p_child[0]->h - (*n)->p_child[1]->h;
		if(f==-2 || f ==2){
			//completar
		}
		return true;
	}
};

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
}
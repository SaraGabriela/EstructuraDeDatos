#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class K, class D>
class bst;

template <class K, class D>
class node
{
private:
	K key;
	D dato;
	node<K, D> * p_child[2]; // 0 left, 1 right

public:
	node(const K & _key, const D & _dato) : key(_key), dato(_dato)
	{
		p_child[0] = p_child[1] = NULL;
	}

	~node() = default;

	friend class bst<K, D>;
};

template <class K, class D>
class bst
{
private:
	node<K, D> * p_root;

public:
	bst() : p_root(NULL) {}
	~bst()
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
	
	bool find(node<K, D> **& n, const K & key)
	{
		n = &p_root;
		while (*n)
		{
			if ((*n)->key == key) return true;

			n = &(*n)->p_child[(*n)->key < key];
		}
		
		return false;
	}

	bool insert(const K & key, const D & dato)
	{
		node<K, D> ** n;
		if (find(n, key)) return false;

		*n = new node<K, D>(key, dato);
		return true;
	}

};

class personData
{
private:
	string email;
	int phone;
public:
//node(const K & _key, const D & _dato) : key(_key), dato(_dato)
	personData(const string & _email, const int & _phone) : email(_email), phone(_phone){}
	~personData() = default;
	void setEmail(string e)
	{
		email = e;
	}
	void setPhone(int num)
	{
		phone = num;
	}
	string getEmail()
	{
		return email;
	}
	int getPhone()
	{
		return phone;
	}
};

class Singleton
{
private:
	static Singleton * instance;
	Singleton();
public:
	static Singleton * get_instance()
	{
		if (!instance)
		{
			instance = new Singleton();
		}
		return instance;
	}
};

int main()
{
	bst<string, personData *> tree;

	tree.insert("Sara", new personData("correo", 123));
	tree.insert("Ana", new personData("correo1", 1235));
	tree.insert("Luis", new personData("correo3", 12553));
	tree.insert("Paola", new personData("corrfeeo", 1123));


	tree.print();

	return 0;
}
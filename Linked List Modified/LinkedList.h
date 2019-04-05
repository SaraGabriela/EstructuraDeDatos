#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <set>

template <class T>
class LinkedList;

template <class T> //Definición de clase node
class node
{
	private:
		T dato;
		node <T> * p_next;
	public:
		node(const T & d, node<T> * n = NULL):
			dato(d), p_next(n) {
			}
		~node() = default;
		friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
	public:
		class iterator //Se declara clase iterador
		{
			private:
				node <T> * p_current;
			public:
				iterator(node<T> * n = NULL) : p_current(n) {}
				~iterator() = default;
				
				iterator & operator ++ ()  //operador ++
				{
				p_current = p_current->p_next; //cada nodo tiene un puntero hacia su p_ next. Convertir p_curent a p_next
				return *this;
				}
				
				T & operator * () //Retorna el dato almacenado en p_current
				{
				return p_current->dato;
				}
				
				bool operator != (const iterator & it) //Compara valores segun posicion
				{
				return p_current != it.p_current;
				}
		};
		
	private:
		node<T> * p_head;
	public:
	LinkedList() : p_head(NULL) {}
	~LinkedList()
	{
		while (p_head)
			pop_front();
	}
	void pop_front();
	
};

#endif

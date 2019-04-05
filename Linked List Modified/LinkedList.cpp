#include "LinkedList.h"

void LinkedList :: pop_front()
{		if (!p_head) return;
		node<T> * temp;
		temp = p_head;
		p_head = p_head->p_next;
		delete temp;
}

template <class K, class D>
node<K, D>::node(const K &_key, const D &_data)
{
	key = _key;
	data = _data;
	p_child[0] = NULL;
	p_child[1] = NULL;
	color = 1;
}
static int i = 1;
template <class K, class D>
node<K, D>::~node()
{
}
template <class K, class D>
RBTree<K, D>::RBTree() {
	root = NULL;

}

template <class K, class D>
RBTree<K, D>::~RBTree() {
	destructor(root);
}

template <class K, class D>
void RBTree< K, D>::destructor(node<K, D> * n) {
	if (n)
	{
		destructor(n->p_child[0]);
		destructor(n->p_child[1]);
		delete(n);
	}
}

//Find function
template <class K, class D>
bool RBTree<K, D>::find(const K & _key, node<K, D> ** & _n) {
	_n = &root;
	while (*_n) {
		if ((*_n)->key == _key) {
			return true;
		}
		_n = &(*_n)->p_child[(*_n)->key < _key];
	}
	return false;
}


template <class K, class D>
bool RBTree<K, D>::insert(const K & _key, const D & _data) {
	insert(_key, _data, &root, NULL);
	return true;
}
template<class K, class D>
node<K, D>* RBTree<K, D>::insert(const K & key, const D & data, node<K, D> ** n, node<K, D> ** p) {
	if ((*n) == NULL) {
		*n = new node<K, D>(key, data);
		return *n;
	}
	if ((*n)->key == key) {
		return NULL;
	}
	bool child = ((*n)->key < key);

	node<K, D> *aux = insert(key, data, &(*n)->p_child[child], n); //(key,dato,padre,abuelo)
	if (!aux) {
		return (*n);
	}
	if (!p) {
		return NULL;
	}

	toRB(p, n, child, aux);
}

template<class K, class D>
void RBTree<K, D>::toRB(node<K, D> **n, node<K, D> **p, bool side, node<K, D> *&ptr) {
	node<K, D> *parent = *p;
	node<K, D> *grandparent = *n;
	while (ptr != root and ptr->getColor() == 1 and parent->getColor() == 1) {

		node<K, D> *tio = (*n)->p_child[!side];
		if (tio->getColor() == 1) {
			tio->setColor(0);
			parent->setColor(0);
			grandparent->setColor(1);
			ptr = grandparent;
		}
		else {
			if (ptr == parent->p_child[!side]) {
				turn(&parent, side);
				ptr = parent;
				parent = grandparent;
			}
			turn(&grandparent, !side);
			swap(parent->color, grandparent->color);
			ptr = parent;
		}
	}
	root->setColor(0);
}

template<class K, class D>
void RBTree<K, D>::turn(node<K, D> ** n, bool side)
{
	if ((*n)->p_child[side]) {
		node<K, D> *aux = (*n)->p_child[side];
		(*n)->p_child[side] = aux->p_child[!side];
		aux->p_child[!aux] = (*n);
		(*n) = aux;
	}

}

template<class K, class D>
bool node<K, D>::getColor() {
	if (this == NULL) {
		return 0;
	}
	return this->color;
}

template<class K, class D>
void node<K, D>::setColor(bool _color) {
	if (this == NULL) {
		return;
	}
	this->color = _color;
}
template<class K, class D>
node<K, D>* RBTree<K, D>::successor(node<K, D> *p)
{
	node<K, D> *y = NULL;
	if (p->p_child[0] != NULL)
	{
		y = p->p_child[0];
		while (y->p_child[1] != NULL)
			y = y->p_child[1];
	}
	else
	{
		y = p->p_child[1];
		while (y->p_child[0] != NULL)
			y = y->p_child[0];
	}
	return y;
}

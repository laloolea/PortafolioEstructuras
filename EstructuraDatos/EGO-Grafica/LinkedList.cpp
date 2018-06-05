//
// Created by Eduardo Gonzalez Olea on 5/22/18.
//
/*
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    Node * end = new Node;
    end->next = NULL;
    end->pre = NULL;
    first = top = end;
    size = 0;
};

//**********************************************************
template <class T>
LinkedList<T>::LinkedList(const LinkedList & _list) {
    Node * end = new Node;
    end->next = NULL;
    end->pre = NULL;
    first = top = end;
    size = 0;
    this->append(_list);
}

//**********************************************************
template <class T>
LinkedList<T>::~LinkedList() {
    for(Node * current = first; current != NULL; current = first) {
        //std::cout << "\nDelete " << current->content << " \n";
        first = first->next;
        delete current;
    }
}
//**********************************************************
template <class T>
void LinkedList<T>::insertFirst(T e) {
    Node * element = new Node;
    element->content = e;
    element->next = first;
    element->pre = NULL;
    if(empty()) top = element;
    first->pre = element;
    first = element;
    size++;
}
//**********************************************************
template <class T>
void LinkedList<T>::append(T e) {
    Node * element = new Node;
    element->content = e;
    element->next = (empty() ? top : top->next);
    (empty() ? top->pre : top->next->pre) = element;
    element->pre = (empty() ? NULL : top);
    if(empty()) first = element;
    else top->next = element;
    top = element;
    size++;
}

//**********************************************************
template <class T>
void LinkedList<T>::append(const LinkedList & _list) {
    if(_list.getSize() > 0) {
        for(ConstIterator itr = _list.begin(); itr != _list.end(); itr++) {
            append(*itr);
        }
    }
}

//**********************************************************
template <class T>
void LinkedList<T>::add(T e, int index) {
    if(index >= size) {
        append(e);
    }
    else if(index <= 0) {
        insertFirst(e);
    }
    else {
        Node * current = first;

        for(int i = 1; i < index; i++) {
            current = current->next;
        }

        Node * element = new Node;
        element->content = e;
        element->next = current->next;
        current->next->pre = element;
        current->next = element;
        element->pre = current;
        size++;
    }
}

//**********************************************************
template <class T>
void LinkedList<T>::removeFirst() {
    if(empty()) throw EmptyContainerException();

    Node * tmp = first;
    first = first->next;
    first->pre = NULL;
    delete tmp;
    size--;
    if(empty()) top = first;
}

//**********************************************************
template <class T>
void LinkedList<T>::removeLast() {
    if(empty()) throw EmptyContainerException();

    Node * tmp = top;
    top = top->pre;
    (top != NULL ? top->next : top) = tmp->next;
    tmp->next->pre = top;
    if(top == NULL) top = tmp->next;
    delete tmp;
    size--;
    if(empty()) first = top;
}

//**********************************************************
template <class T>
void LinkedList<T>::remove(int index) {
    if(index < 0 || index >= size) throw IndexOutOfBoundsException();

    else if(index + 1 == size) {
        removeLast();
    }
    else if(index == 0) {
        removeFirst();
    }else {
        Node * tmp = first;

        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
        }

        Node * _pre = tmp->pre;

        _pre->next = tmp->next;
        _pre->next->pre = _pre;

        delete tmp;

        if(top == tmp) top = NULL;
        size--;
    }
}

//**********************************************************
template <class T>
void LinkedList<T>::removeAll() {
    Node * end = (top->next == NULL ? top : top->next);
    for(Node * current = first; current != end; current = first) {
        first = first->next;
        delete current;
    }
    top = end;
    size = 0;
}

//**********************************************************
template <class T>
int LinkedList<T>::getSize() const {
    return size;
}

//**********************************************************
template <class T>
bool LinkedList<T>::empty() const {
    return top->next == NULL;
}

//**********************************************************
template <class T>
bool LinkedList<T>::search(T e) const {
    for(ConstIterator itr = begin(); itr != end(); itr++) {
        if(*itr == e) return true;
    }
    return false;
}

//**********************************************************
template <class T>
int LinkedList<T>::getIndexOf(const T & element) const {
    Node * current = first;

    for(int i = 0; i < size; i++) {
        if(element == current->content) return i;
        current = current->next;
    }

    return -1;
}

//**********************************************************
template <class T>
T LinkedList<T>::get(int index) const {
    return (*this)[index];
}

//**********************************************************
template <class T>
T LinkedList<T>::getLast() const{
    return top->content;
}

//**********************************************************
template <class T>
T & LinkedList<T>::operator[](int index) {
    if(index < 0 || index >= size) throw IndexOutOfBoundsException();
    Node * current = first;

    for(int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->content;
}

//**********************************************************
template <class T>
const T & LinkedList<T>::operator[](int index) const {
    if(index < 0 || index >= size) throw IndexOutOfBoundsException();
    Node * current = first;

    for(int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->content;
}

//**********************************************************
template <class T>
LinkedList<T> LinkedList<T>::operator()(int _first, int _final) {
    if(_first > _final ||
       _first < 0 || _first >= size ||
       _final < 0 || _first >= size) throw IndexOutOfBoundsException();

    LinkedList<T> _list;

    Iterator itr = this->iter();

    for(int i = 0; i < _first; i++) {
        itr.next();
    }

    for(int i = _first; i < _final; i++) {
        if(itr.hasNext())
            _list.append(itr.next());
    }

    return _list;
}

//**********************************************************
template <class T>
class LinkedList<T>::Iterator LinkedList<T>::begin() {
    return Iterator(first);
}
//**********************************************************
template <class T>
class LinkedList<T>::Iterator LinkedList<T>::end() {
    return Iterator(top->next == NULL ? top : top->next);
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator LinkedList<T>::begin() const{
    return ConstIterator(first);
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator LinkedList<T>::end() const{
    return ConstIterator(top->next == NULL ? top : top->next);
}

//**********************************************************
template <class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList & _list) {
    if(this != &_list) {
        this->removeAll();
        this->append(_list);
    }

    return *this;
}
//**********************************************************
template <class T>
std::ostream & operator<<(std::ostream &out, const LinkedList<T> & _list) {
    out << "[";
    for(class LinkedList<T>::ConstIterator itr = _list.begin(); itr != _list.end(); itr++)  {
        out << *itr << ", ";
    }
    out << (_list.begin() == _list.end() ? "]" : "\b\b]");

    return out;
}
*/
//
// Created by Eduardo Gonzalez Olea on 5/22/18.
//

#ifndef EGO_GRAFICA_LINKEDLIST_H
#define EGO_GRAFICA_LINKEDLIST_H

#include <iostream>
#include <iterator>
#include "Exception.h"

template <class T>
class LinkedList;

template <class T>
std::ostream & operator<<(std::ostream &out, const LinkedList<T> & _list);

template <class T>
class LinkedList {

    struct Node {
        T content;
        Node * next;
        Node * pre;
    };

public:

    class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    public:

        /**
        * @brief Creates an empty iterator.
        */
        Iterator();

        /**
        * @brief Creates an interator pointing to the
        * specified element.
        */
        Iterator(Node * first);

        /**
        * @brief Creates an interator pointing to the
        * same element than the specified.
        */
        Iterator(const Iterator & itr);

        /**
         * @brief Increment operator.
         */
        Iterator & operator++();

        /**
         * @brief Increment operator.
         */
        Iterator operator++(int);

        /**
         * @brief Decrement operator.
         */
        Iterator & operator--();

        /**
         * @brief Decrement operator.
         */
        Iterator operator--(int);

        /**
         * @brief Checks if this iterator is equal to the
         * passed by parameter.
         * @param itr iterator to be compared.
         */
        bool operator==(const Iterator & itr);

        /**
         * @brief Checks if this iterator is diferent to the
         * passed by parameter.
         * @param itr iterator to be compared.
         */
        bool operator!=(const Iterator & itr);

        /**
         * @brief Desreference operator.
         */
        T & operator*();

        /**
         * @brief Assing the value of itr to this iterator.
         * @param itr to copy the value.
         */
        Iterator & operator=(const Iterator & itr);

    private:
        Node * current;
    };

    class ConstIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    public:

        /**
        * @brief Creates an empty iterator.
        */
        ConstIterator();

        /**
        * @brief Creates an interator pointing to the
        * specified element.
        */
        ConstIterator(Node * first);

        /**
        * @brief Creates an interator pointing to the
        * same element than the specified.
        */
        ConstIterator(const ConstIterator & itr);

        /**
         * @brief Increment operator.
         */
        ConstIterator & operator++();

        /**
         * @brief Increment operator.
         */
        ConstIterator operator++(int);

        /**
         * @brief Decrement operator.
         */
        ConstIterator & operator--();

        /**
         * @brief Decrement operator.
         */
        ConstIterator operator--(int);

        /**
         * @brief Checks if this iterator is equal to the
         * passed by parameter.
         * @param itr iterator to be compared.
         */
        bool operator==(const ConstIterator & itr);

        /**
         * @brief Checks if this iterator is diferent to the
         * passed by parameter.
         * @param itr iterator to be compared.
         */
        bool operator!=(const ConstIterator & itr);

        /**
         * @brief Assing the value of itr to this iterator.
         * @param itr to copy the value.
         */
        ConstIterator & operator=(const ConstIterator & itr);

        /**
         * @brief Desreference operator.
         */
        const T & operator*();

    private:
        Node * current;
    };

    /**
    * @brief Creates an empty list.
    */
    LinkedList();

    /**
    * @brief Creates a list with the content of another.
    * @param _list the _list to copy the content from.
    */
    LinkedList(const LinkedList & _list);

    /**
    * @brief Destroys the list.
    */
    ~LinkedList();

    /**
     * @brief Insert the specified element in the first postion
     * of the list.
     * @param e element to insert.
     */
    void insertFirst(T e);

    /**
    * @brief Append specified element at the end of this list.
    * @param e element to insert in the list.
    */
    void append(T e);

    /**
    * @brief Append every element on the specified list to
    * this list.
    * @param _list the list that contains the elements to copy.
    */
    void append(const LinkedList & _list);

    /**
    * @brief Adds specified element at the specified position.
    * @param e element to insert in the list.
    */
    void add(T e, int index);

    /**
     * @brief Removes the first element of the list.
     */
    void removeFirst();

    /**
     * @brief Removes the last elemet of the list.
     */
    void removeLast();

    /**
    * @brief Removes the indicated element.
    * @param index index of the element to remove.
    * @throws IndexOutOfBoundsException if the index is out of the range.
    */
    void remove(int index);

    /**
    * @brief Remove all the elements.
    */
    void removeAll();

    /**
    * @brief Gets the size of the list.
    * @return the size of the list.
    */
    int getSize() const;

    /**
     * @brief Checks if the list is empty.
     * @return True if the list contains no objects, false otherwise.S
     */
    bool empty() const;

    /**
    * @brief Checks if the specified element is in this list.
    * @param e element to check if is in this list.
    * @return True if the element is in the list, false otherwise.
    */
    bool search(T e) const;

    /**
    * @brief Gets the index of the fist ocurrence of
    * indicated element.
    * @param element the element to search the index.
    * @return the index of the first ocurrence of the
    * element pass by the parameter, returns -1 if the
    * element is not in the list.
    */
    int getIndexOf(const T & element) const;

    /**
    * @brief Creates a list with the specified
    * element.
    * @param initial_element Element to add to the list.
    */
    T get(int index) const;

    /**
    * @brief Gets the last elemnt of this list.
    * @return The las element of this list.
    */
    T getLast() const;

    /**
    * @brief Gets a reference of the element at position index.
    * @param index index of the element to get.
    * @throws IndexOutOfBoundsException if the index is out the range.
    */
    T & operator[](int index);

    /**
    * @brief Gets a constant reference of the element at position index.
    * @param index index of the element to get.
    * @throws IndexOutOfBoundsException if the index is out the range.
    */
    const T & operator[](int index) const;

    /**
    * @brief Returns a view of the portion of this list between the
    * specified first, inclusive, and final, exclusive; if first and final
    * are equal, the returned array is empty.
    * @param first low endpoint (inclusive) of the sub list.
    * @param final high endpoint (exclusive) of the sub list.
    * @return A view of the specified range within this list.
    * @throws IllegalArgumentException if the endpoint indices are out of order.
    * @throws IndexOutOfBoundsException if an endpoint index value is out of range.
    */
    LinkedList<T> operator()(int _first, int _final);

    /**
    * @brief Gets the iterator to the first element.
    * @return The iterator of the first element of this list.
    */
    Iterator begin();

    /**
    * @brief Gets the iterator to the last element.
    * @return The iterator of the last element of this list.
    */
    Iterator end();

    /**
    * @brief Gets the const iterator to the first element.
    * @return The const iterator of the first element of this list.
    */
    ConstIterator begin() const;

    /**
    * @brief Gets the const iterator to the last element.
    * @return The const iterator of the last element of this list.
    */
    ConstIterator end() const;

    /**
    * @brief Compares to lists.
    * @param list list to compare with the instance that called the operator.
    * @return true if both instance have the seme among of element and the element
    * at positon i in the first and the second list are equals, false in other case.
    */
    LinkedList<T> operator=(const LinkedList & _list);

    /**
    * @brief Inserts in the indicated stream the representative string
    * of this list.
    * @param out ostream where this list will be inserted.
    * @param _list list to insert in the stream.
    * @returns the ostream passed by the parameter (out).
    */
    friend std::ostream & operator<< <>(std::ostream &out, const LinkedList<T> & _list);

private:
    Node * top;
    Node * first;
    int size;

};



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



template <class T>
LinkedList<T>::Iterator::Iterator() {
    current = NULL;
}
//**********************************************************
template <class T>
LinkedList<T>::Iterator::Iterator(Node * first) {
    current = first;
}
//**********************************************************
template <class T>
LinkedList<T>::Iterator::Iterator(const Iterator & itr) {
    current = itr.current;
}
//**********************************************************
template <class T>
class LinkedList<T>::Iterator & LinkedList<T>::Iterator::operator++() {
    current = current->next;
    Iterator itr(current);
    return itr;
}
//**********************************************************
template <class T>
class LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    Node * tmp = current;
    current = current->next;
    return tmp;
}
//**********************************************************
template <class T>
class LinkedList<T>::Iterator & LinkedList<T>::Iterator::operator--() {
    current = current->pre;
    Iterator itr(current);
    return itr;
}
//**********************************************************
template <class T>
class LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int) {
    Node * tmp = current;
    current = current->pre;
    return tmp;
}
//**********************************************************
template <class T>
bool LinkedList<T>::Iterator::operator==(const Iterator & itr) {
    return current == itr.current;
}
//**********************************************************
template <class T>
bool LinkedList<T>::Iterator::operator!=(const Iterator & itr) {
    return !operator==(itr);
}
//**********************************************************
template <class T>
T & LinkedList<T>::Iterator::operator*() {
    return current->content;
}
//**********************************************************
template <class T>
class LinkedList<T>::Iterator & LinkedList<T>::Iterator::operator=(const Iterator & itr) {
    current = itr.current;
    return *this;
}


template <class T>
LinkedList<T>::ConstIterator::ConstIterator() {
    current = NULL;
}
//**********************************************************
template <class T>
LinkedList<T>::ConstIterator::ConstIterator(Node * first) {
    current = first;
}
//**********************************************************
template <class T>
LinkedList<T>::ConstIterator::ConstIterator(const LinkedList<T>::ConstIterator & itr) {
    current = itr.current;
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator & LinkedList<T>::ConstIterator::operator++() {
    current = current->next;
    ConstIterator itr(current);
    return itr;
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int) {
    Node * tmp = current;
    current = current->next;
    return tmp;
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator & LinkedList<T>::ConstIterator::operator--() {
    current = current->pre;
    ConstIterator itr(current);
    return itr;
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int) {
    Node * tmp = current;
    current = current->pre;
    return tmp;
}
//**********************************************************
template <class T>
bool LinkedList<T>::ConstIterator::operator==(const ConstIterator & itr) {
    return current == itr.current;
}
//**********************************************************
template <class T>
bool LinkedList<T>::ConstIterator::operator!=(const ConstIterator & itr) {
    return !operator==(itr);
}
//**********************************************************
template <class T>
class LinkedList<T>::ConstIterator & LinkedList<T>::ConstIterator::operator=(const ConstIterator & itr) {
    current = itr.current;
    return *this;
}
//**********************************************************
template <class T>
const T & LinkedList<T>::ConstIterator::operator*() {
    return current->content;
}

#endif //EGO_GRAFICA_LINKEDLIST_H

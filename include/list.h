#include <iostream>
#include <cstdlib>
#include "node.h"

#pragma once

template <class T>
class List {
private:
  Node<T> *head, *tail;

  bool insertFirst(T);

public:
  List();
  ~List();

  Node<T>* getHead();
  Node<T>* getTail();

  bool isEmpty();

  bool prepend(T);
  bool append(T);
  bool insert(Node<T>*, T);

  void clear();

  int  getSize();
  T*   values();
};

using namespace std;

template <class T>
List<T>::List(){
  this->head = this->tail = NULL;
}

template <class T>
List<T>::~List(){
  this->clear();
}

template <class T>
Node<T>* List<T>::getHead(){
  return this->head;
}

template <class T>
Node<T>* List<T>::getTail(){
  return this->tail;
}

template <class T>
bool List<T>::prepend(T data){
  if (this->isEmpty())
    return this->insertFirst(data);

  Node<T>* node = new Node<T>();
  node->data = data;

  node->prev = NULL;
  node->next = this->head;

  this->head->prev = node;
  this->head = node;

  return true;
}

template <class T>
bool List<T>::append(T data){
  if (this->isEmpty())
    return this->insertFirst(data);

  Node<T>* node = new Node<T>();
  node->data = data;

  node->prev = this->tail;
  node->next = NULL;

  this->tail->next = node;
  this->tail = node;

  return true;
}

template <class T>
bool List<T>::insert(Node<T>* current, T data){
  if (this->isEmpty())
    return this->insertFirst(data);

  if (current == this->head)
    return this->prepend(data);

  if (current == this->tail)
    return this->append(data);

  Node<T>* node = new Node<T>();
  node->data = data;

  node->next = current->next;
  node->prev = current;

  current->next->prev = node;
  current->next = node;

  return true;
}

template <class T>
void List<T>::clear(){
  Node<T>* walker = this->head;

  while (walker != NULL){
    delete(walker);
    walker = walker->next;
  }
}

template <class T>
bool List<T>::isEmpty(){
  return (!this->head && !this->tail);
}

template <class T>
bool List<T>::insertFirst(T data){
  Node<T>* node = new Node<T>();
  node->data = data;

  node->prev = node->next = NULL;

  this->head = this->tail = node;

  return true;
}

template <class T>
int List<T>::getSize(){
  int i = 0;

  Node<T>* walker = this->head;
  while (walker != NULL){
    walker = walker->next;
    i++;
  }

  return i;
}

template <class T>
T* List<T>::values(){
  int size = this->getSize();

  if (size == 0)
    return NULL;

  T* arr = (T*) malloc(size * sizeof(T));
  int i = 0;

  Node<T>* walker = this->head;
  while (walker != NULL){
    arr[i] = walker->data;
    walker = walker->next;
    i++;
  }

  return arr;
}


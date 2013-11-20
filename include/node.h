#include <iostream>

#pragma once

template <typename T>
struct Node {
  Node<T> *prev, *next;
  T data;
};


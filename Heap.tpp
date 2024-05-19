// #ifndef HEAP_H
// #define HEAP_H

// #include <vector>
// #include <cmath>  // for floor

// template <typename T>
// class Heap {
//  private:
//   std::vector<T> values;
//   void heapify(int);

//  public:
//   Heap();  // constructs an empty heap

//   // constructs a heap with the values from the given vector
//   // the type T MUST provide comparison operators <, >, ==
//   Heap(std::vector<T>);

//   void insert(T);
//   void remove(T);
//   T getMin();
// };

// /*******************************/
// // default constructor
// /*******************************/

// template <typename T>
// Heap<T>::Heap() {}

// /*******************************/
// // constructs a heap with the values in the given vector
// // the type T MUST provide comparison operators <, >, ==
// /*******************************/

// template <typename T>
// Heap<T>::Heap(std::vector<T> start_values) {
//   // copy the values into our heap vector
//   for (int i = 0; i < start_values.size(); i++) {
//     values.push_back(start_values.at(i));
//   }

//   // starting from last non-leaf node (last parent), heapify each
//   // of the parents
//   int initial_parent_index = floor(values.size() / 2) - 1;
//   for (int parent_index = initial_parent_index; parent_index >= 0;
//        parent_index--) {
//     heapify(parent_index);
//   }
// }

// /*******************************/
// // add values to the heap
// /*******************************/

// template <typename T>
// void Heap<T>::insert(T value) {
//   // TODO: TO BE IMPLEMENTED
// }

// /*******************************/
// /* delete values from the heap */
// /*******************************/

// template <typename T>
// void Heap<T>::remove(T value) {
//   // TODO: TO BE IMPLEMENTED
// }

// /*******************************/
// // find the smallest value in the heap
// /*******************************/

// template <typename T>
// T Heap<T>::getMin() {
//   // TODO: TO BE IMPLEMENTED
// }

// /*******************************/
// // private function to heapify a given 'node'
// /*******************************/

// template <typename T>
// void Heap<T>::heapify(int parent_index) {
//   // if we're outside the index range, return
//   if (parent_index < 0 || parent_index >= values.size()) return;

//   // find children indexes
//   int left_child_index = parent_index * 2 + 1;
//   int right_child_index = parent_index * 2 + 2;

//   // if parent is larger than child, swap with smallest child
//   int index_of_smallest = parent_index;

//   // check if left child exists and if exists, is smallest value there
//   if (left_child_index < values.size() &&
//       values.at(left_child_index) < values.at(index_of_smallest)) {
//     // make this index the current smallest
//     index_of_smallest = left_child_index;
//   }

//   // check if left child exists and if exists, is smallest value there
//   if (right_child_index < values.size() &&
//       values.at(right_child_index) < values.at(index_of_smallest)) {
//     // make this index the current smallest
//     index_of_smallest = right_child_index;
//   }

//   // if parent is not smallest, swap with smallest child
//   if (index_of_smallest != parent_index) {
//     T temp = values.at(parent_index);
//     values.at(parent_index) = values.at(index_of_smallest);
//     values.at(index_of_smallest) = temp;
//   }

//   // move up the 'tree' to grandparent
//   heapify(floor(parent_index / 2) - 1);
// }

// #endif


// /*******************************/
// // add values to the heap
// /*******************************/

// template <typename T>
// void Heap<T>::insert(T value) {
//   values.push_back(value); // Add the value to the end of the vector
//   int index = values.size() - 1;
  
//   // Bubble up the inserted value to its correct position
//   while (index > 0 && values[index] < values[(index - 1) / 2]) {
//     std::swap(values[index], values[(index - 1) / 2]);
//     index = (index - 1) / 2;
//   }
// }

// /*******************************/
// /* delete values from the heap */
// /*******************************/

// template <typename T>
// void Heap<T>::remove(T value) {
//   // Find the index of the value to be removed
//   auto it = std::find(values.begin(), values.end(), value);
//   if (it == values.end()) {
//     return; // Value not found in the heap
//   }
  
//   // Replace the value with the last element in the heap
//   *it = values.back();
//   values.pop_back();
  
//   // Heapify the modified heap
//   heapify(0);
// }

// /*******************************/
// // find the smallest value in the heap
// /*******************************/

// template <typename T>
// T Heap<T>::getMin() {
//   if (values.empty()) {
//     throw std::logic_error("Heap is empty.");
//   }
//   return values[0];
// }

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Heap {
private:
    std::vector<T> values;
    void heapify(int);

public:
    Heap();
    Heap(std::vector<T>);
    void insert(T);
    void remove(T);
    T getMin();
};

template <typename T>
Heap<T>::Heap() {}

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
    for (int i = 0; i < start_values.size(); i++) {
        values.push_back(start_values.at(i));
    }

    int initial_parent_index = floor(values.size() / 2) - 1;
    for (int parent_index = initial_parent_index; parent_index >= 0; parent_index--) {
        heapify(parent_index);
    }
}

template <typename T>
void Heap<T>::insert(T value) {
    values.push_back(value);
    int index = values.size() - 1;

    while (index > 0 && values[index] < values[(index - 1) / 2]) {
        std::swap(values[index], values[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <typename T>
void Heap<T>::remove(T value) {
    auto it = std::find(values.begin(), values.end(), value);
    if (it == values.end()) {
        return;
    }

    *it = values.back();
    values.pop_back();

    heapify(0);
}

template <typename T>
T Heap<T>::getMin() {
    if (values.empty()) {
        throw std::logic_error("Heap is empty.");
    }
    return values[0];
}

template <typename T>
void Heap<T>::heapify(int parent_index) {
    if (parent_index < 0 || parent_index >= values.size()) return;

    int left_child_index = parent_index * 2 + 1;
    int right_child_index = parent_index * 2 + 2;
    int index_of_smallest = parent_index;

    if (left_child_index < values.size() && values.at(left_child_index) < values.at(index_of_smallest)) {
        index_of_smallest = left_child_index;
    }

    if (right_child_index < values.size() && values.at(right_child_index) < values.at(index_of_smallest)) {
        index_of_smallest = right_child_index;
    }

    if (index_of_smallest != parent_index) {
        T temp = values.at(parent_index);
        values.at(parent_index) = values.at(index_of_smallest);
        values.at(index_of_smallest) = temp;
    }

    heapify(floor(parent_index / 2) - 1);
}

#endif
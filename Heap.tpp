#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>  // for floor

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// add values to the heap heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
    // add the value to the end of the heap
    values.push_back(value);
    // get the index of the newly added value
    int index = values.size() - 1;
    // move the value up the heap until it is in the correct position
    while (index > 0 && values[index] < values[(index - 1) / 2]) {
        // swap the value with its parent
        std::swap(values[index], values[(index - 1) / 2]);
        // update the index to the parent's index
        index = (index - 1) / 2;
    }
}

/*******************************//
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
    // find the index of the value in the heap
    auto it = std::find(values.begin(), values.end(), value);
    if (it == values.end()) {
        // value not found in the heap
        return;
    }
    // get the index of the value
    int index = std::distance(values.begin(), it);
    // replace the value with the last value in the heap
    values[index] = values.back();
    // remove the last value from the heap
    values.pop_back();
    // move the value down the heap until it is in the correct position
    while (true) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int smallest_child_index = index;
        // check if left child exists and if it is smaller than the current value
        if (left_child_index < values.size() && values[left_child_index] < values[smallest_child_index]) {
            smallest_child_index = left_child_index;
        }
        // check if right child exists and if it is smaller than the current value
        if (right_child_index < values.size() && values[right_child_index] < values[smallest_child_index]) {
            smallest_child_index = right_child_index;
        }
        // if the current value is already in the correct position, break the loop
        if (smallest_child_index == index) {
            break;
        }
        // swap the current value with the smallest child
        std::swap(values[index], values[smallest_child_index]);
        // update the index to the smallest child's index
        index = smallest_child_index;
    }
}

/*******************************//
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
    if (values.empty()) {
        // heap is empty, return default value of type T
        return T();
    }
    // return the root value of the heap
    return values[0];
}
;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;
  }

  // move up the 'tree' to grandparent
  heapify(floor(parent_index / 2) - 1);
}

#endif

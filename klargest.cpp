#include <queue>

int kth_largest(std::vector<int> values, int k) {
  std::priority_queue<int> pq(values.begin(), values.end());
  
  // Pop the largest k-1 elements from the priority queue
  for (int i = 0; i < k - 1; ++i) {
    pq.pop();
  }
  
  // Return the kth largest element
  return pq.top();
}
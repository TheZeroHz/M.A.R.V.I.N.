#ifndef VECTOR_H
#define VECTOR_H
#include <Arduino.h>
template<typename T>
class Vector {
private:
  T* data;
  size_t capacity;
  size_t length;

public:
  // Constructor
  Vector()
    : data(nullptr), capacity(0), length(0) {}

  // Destructor
  ~Vector() {
    clear();
  }

  // Get size
  size_t size() const {
    return length;
  }

  // Get capacity
  size_t max_size() const {
    return capacity;
  }

  // Clear the vector
  void clear() {
    if (data != nullptr) {
      free(data);
      data = nullptr;
      capacity = 0;
      length = 0;
    }
  }

  // Push an element to the back of the vector
  void push_back(const T& value) {
    if (length >= capacity) {
      if (capacity == 0) {
        capacity = 1;
      } else {
        capacity *= 2;
      }
      T* newData = (T*)realloc(data, capacity * sizeof(T));
      if (newData == nullptr) {
        // Handle memory allocation failure
        Serial.println("Memory allocation failed!");
        return;
      }
      data = newData;
    }
    data[length++] = value;
  }

  // Pop an element from the back of the vector
  void pop_back() {
    if (length > 0) {
      length--;
    }
  }

    // Access an element by index
  T& operator[](size_t index) {
    if (index >= length) {
      // Handle out-of-bounds access
      Serial.println("Index out of bounds!");
      return data[0];
    }
    return data[index];
  }

  // Access an element by index for const objects
  const T& operator[](size_t index) const {
    if (index >= length) {
      // Handle out-of-bounds access
      Serial.println("Index out of bounds!");
      return data[0];
    }
    return data[index];
  }
  // Define the printVector function
};
#endif
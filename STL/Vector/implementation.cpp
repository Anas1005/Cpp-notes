#include <iostream>
#include <cstdlib> // For std::malloc and std::free

using namespace std; // Use the standard namespace

template <typename T>
class SimpleVector {
private:
    T* data;        // Pointer to the array of elements
    size_t size;    // Current number of elements
    size_t capacity; // Allocated capacity

    void resize(size_t new_capacity) {
        T* new_data = (T*)malloc(new_capacity * sizeof(T)); // Allocate new memory
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i]; // Copy old elements to new memory
        }
        free(data); // Free old memory
        data = new_data; // Update the data pointer
        capacity = new_capacity; // Update capacity
    }

public:
    SimpleVector() : size(0), capacity(1) {
        data = (T*)malloc(capacity * sizeof(T)); // Initial allocation
    }

    ~SimpleVector() {
        free(data); // Free allocated memory
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2); // Double the capacity
        }
        data[size++] = value; // Add new element and increase size
    }

    T& operator[](size_t index) {
        return data[index]; // Access element by index
    }

    size_t getSize() const {
        return size; // Return current size
    }

    size_t getCapacity() const {
        return capacity; // Return current capacity
    }
};

int main() {
    SimpleVector<int> vec;

    // Adding elements
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i); // Adding values 0 to 9
    }

    // Printing elements
    cout << "Elements in SimpleVector: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        cout << vec[i] << " "; // Accessing elements
    }
    cout << endl;

    cout << "Current Size: " << vec.getSize() << endl;
    cout << "Current Capacity: " << vec.getCapacity() << endl;

    return 0; // End of the program
}

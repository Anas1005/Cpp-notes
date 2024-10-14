#include <iostream>
#include <vector> // Include the vector library
#include <algorithm> // For std::sort
#include <numeric> // For std::accumulate

using namespace std;

int main() {
    // ========================= 1D Vector Operations =========================

    // 1. Declaring and initializing a fixed-size 1D vector
    vector<int> fixedSizeVector(5, 0); // Fixed size of 5, initialized to 0

    // 2. Assigning values to the fixed-size 1D vector
    for (size_t i = 0; i < fixedSizeVector.size(); ++i) {
        fixedSizeVector[i] = i + 1; // Assign values 1 to 5
    }

    // 3. Printing elements of the fixed-size 1D vector
    cout << "1D Fixed-Size Vector Elements:" << endl;
    for (size_t i = 0; i < fixedSizeVector.size(); i++) {
        cout << fixedSizeVector[i] << " "; // Print each element
    }
    cout << endl;

    // 4. Declaring a dynamic 1D vector
    vector<int> dynamicVector; // Declare a dynamic 1D vector

    // 5. Adding elements to a dynamic 1D vector
    for (int i = 1; i <= 5; ++i) {
        dynamicVector.push_back(i); // Add elements 1 to 5
    }

    // 6. Printing elements of the dynamic 1D vector
    cout << "1D Dynamic Vector Elements:" << endl;
    for (const auto& elem : dynamicVector) {
        cout << elem << " "; // Print each element
    }
    cout << endl;

    // 7. Modifying an element in the dynamic 1D vector
    dynamicVector[2] = 20; // Change the third element to 20
    cout << "After modifying dynamic element at index 2 to 20: ";
    for (const auto& elem : dynamicVector) {
        cout << elem << " "; // Print each element
    }
    cout << endl;

    // 8. Inserting elements at specific positions
    dynamicVector.insert(dynamicVector.begin() + 1, 15); // Insert 15 at index 1
    cout << "After inserting 15 at index 1: ";
    for (const auto& elem : dynamicVector) {
        cout << elem << " "; // Print each element
    }
    cout << endl;

    // 9. Removing an element from the dynamic vector
    dynamicVector.erase(dynamicVector.begin() + 3); // Remove element at index 3
    cout << "After removing element at index 3: ";
    for (const auto& elem : dynamicVector) {
        cout << elem << " "; // Print each element
    }
    cout << endl;

    // 10. Sorting the dynamic vector
    sort(dynamicVector.begin(), dynamicVector.end());
    cout << "After sorting the dynamic vector: ";
    for (const auto& elem : dynamicVector) {
        cout << elem << " "; // Print each element
    }
    cout << endl;

    // 11. Finding an element
    auto it = find(dynamicVector.begin(), dynamicVector.end(), 20);
    if (it != dynamicVector.end()) {
        cout << "Element 20 found at index: " << distance(dynamicVector.begin(), it) << endl;
    } else {
        cout << "Element 20 not found." << endl;
    }

    // 12. Clearing the dynamic vector
    dynamicVector.clear();
    cout << "After clearing the dynamic vector, size is: " << dynamicVector.size() << endl;

    // ========================= 2D Vector Operations =========================

    // 13. Declaring a fixed-size 2D vector (3 rows x 3 columns)
    vector<vector<int>> fixedSize2DVector(3, vector<int>(3)); // 3x3 matrix

    // 14. Initializing values in the fixed-size 2D vector
    for (size_t i = 0; i < fixedSize2DVector.size(); ++i) {
        for (size_t j = 0; j < fixedSize2DVector[i].size(); ++j) {
            fixedSize2DVector[i][j] = (i + 1) * (j + 1); // Multiplication table
        }
    }

    // 15. Printing elements of the fixed-size 2D vector
    cout << "Fixed-Size 2D Vector Elements:" << endl;
    for (size_t i = 0; i < fixedSize2DVector.size(); i++) {
        for (size_t j = 0; j < fixedSize2DVector[i].size(); j++) {
            cout << fixedSize2DVector[i][j] << " "; // Access using indices
        }
        cout << endl; // New line for each row
    }

    // 16. Declaring a dynamic 2D vector
    vector<vector<int>> dynamic2DVector; // Declare a dynamic 2D vector

    // 17. Adding rows to the dynamic 2D vector using push_back
    for (int i = 0; i < 3; ++i) {
        vector<int> row; // Create a new row
        for (int j = 1; j <= 3; ++j) {
            row.push_back(i * 3 + j); // Fill with values 1 to 9
        }
        dynamic2DVector.push_back(row); // Add the row to the dynamic 2D vector
    }

    // 18. Printing elements of the dynamic 2D vector
    cout << "Dynamic 2D Vector Elements:" << endl;
    for (size_t i = 0; i < dynamic2DVector.size(); i++) {
        for (size_t j = 0; j < dynamic2DVector[i].size(); j++) {
            cout << dynamic2DVector[i][j] << " "; // Access using indices
        }
        cout << endl; // New line for each row
    }

    // 19. Modifying an element in the dynamic 2D vector
    dynamic2DVector[1][1] = 50; // Change the element at (1,1) to 50
    cout << "After modifying element at (1,1) to 50: " << endl;
    for (const auto& row : dynamic2DVector) {
        for (const auto& elem : row) {
            cout << elem << " "; // Print each element
        }
        cout << endl; // New line for each row
    }

    // 20. Inserting a new row in the dynamic 2D vector
    vector<int> newRow = {10, 11, 12}; // Create a new row
    dynamic2DVector.push_back(newRow); // Add new row to the end
    cout << "After adding a new row: " << endl;
    for (const auto& row : dynamic2DVector) {
        for (const auto& elem : row) {
            cout << elem << " "; // Print each element
        }
        cout << endl; // New line for each row
    }

    // 21. Removing a row in the dynamic 2D vector
    dynamic2DVector.erase(dynamic2DVector.begin() + 1); // Remove row at index 1 (second row)
    cout << "After removing the second row: " << endl;
    for (const auto& row : dynamic2DVector) {
        for (const auto& elem : row) {
            cout << elem << " "; // Print each element
        }
        cout << endl; // New line for each row
    }

    // 22. Clearing all elements in the dynamic 2D vector
    dynamic2DVector.clear(); // Clear the contents of the dynamic 2D vector
    cout << "After clearing the dynamic 2D vector, size is: " << dynamic2DVector.size() << endl;

    return 0; // End of the program
}

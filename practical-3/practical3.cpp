#include <iostream>
#include <cstddef>
#include <utility>

/**
 * DynamicArray: A resource-owning class managing a dynamically allocated integer array.
 *
 * Demonstrates:
 *  - Default Constructor
 *  - Parameterized Constructor
 *  - Rule of Five:
 *      1. Destructor (~DynamicArray)
 *      2. Copy Constructor (DynamicArray(const DynamicArray&))
 *      3. Copy Assignment Operator (operator=(const DynamicArray&))
 *      4. Move Constructor (DynamicArray(DynamicArray&&) noexcept)
 *      5. Move Assignment Operator (operator=(DynamicArray&&) noexcept)
 */
class DynamicArray {
private:
    int* data_;
    std::size_t size_;

public:
    // Default Constructor: Initializes an empty dynamic array with safe null state.
    DynamicArray() : data_(nullptr), size_(0) {
        std::cout << "Default Constructor Called\n";
    }

    // Parameterized Constructor: Allocates an array of given size and initializes elements.
    explicit DynamicArray(std::size_t size, int startValue = 10, int step = 10)
        : data_(size > 0 ? new int[size] : nullptr), size_(size) {
        std::cout << "Parameterized Constructor Called\n";
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = startValue + static_cast<int>(i) * step;
        }
    }

    // Rule of Five [1/5] - Destructor:
    // Releases the dynamically allocated heap array to prevent memory leaks.
    ~DynamicArray() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        std::cout << "Destructor Called\n";
        std::cout << "Memory Released Successfully!\n";
    }

    // Rule of Five [2/5] - Copy Constructor:
    // Performs a deep copy so the new object owns an independent heap buffer.
    DynamicArray(const DynamicArray& other)
        : data_(other.size_ > 0 ? new int[other.size_] : nullptr), size_(other.size_) {
        std::cout << "Copy Constructor Called\n";
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        std::cout << "Deep Copy Created Successfully!\n";
    }

    // Rule of Five [3/5] - Copy Assignment Operator:
    // Safely handles self-assignment, frees existing resources, and deep-copies from 'other'.
    DynamicArray& operator=(const DynamicArray& other) {
        std::cout << "Copy Assignment Operator Called\n";
        if (this != &other) {
            int* newData = (other.size_ > 0) ? new int[other.size_] : nullptr;
            for (std::size_t i = 0; i < other.size_; ++i) {
                newData[i] = other.data_[i];
            }
            delete[] data_;
            data_ = newData;
            size_ = other.size_;
        }
        std::cout << "Array Copied Successfully!\n";
        return *this;
    }

    // Rule of Five [4/5] - Move Constructor:
    // Transfers ownership of 'other.data_' to '*this' without allocating new memory,
    // leaving 'other' in a valid, empty (nullptr) state safe for destruction.
    DynamicArray(DynamicArray&& other) noexcept
        : data_(other.data_), size_(other.size_) {
        std::cout << "Move Constructor Called\n";
        other.data_ = nullptr;
        other.size_ = 0;
        std::cout << "Ownership Transferred Successfully!\n";
    }

    // Rule of Five [5/5] - Move Assignment Operator:
    // Guards against self-move, releases current heap memory, steals 'other.data_',
    // and resets 'other' to a safe empty state.
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        std::cout << "Move Assignment Operator Called\n";
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            other.data_ = nullptr;
            other.size_ = 0;
        }
        std::cout << "Resource Moved Successfully!\n";
        return *this;
    }

    void print(const char* label = "Array Elements") const {
        std::cout << label << ":";
        for (std::size_t i = 0; i < size_; ++i) {
            std::cout << " " << data_[i];
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "----- RULE OF FIVE DEMONSTRATION ----- ";
    std::cout << "Student Name: Satinderpal Singh Chaney\n";
    std::cout << "Roll Number: E26B00S2034\n";

    // 1. Default constructor
    DynamicArray defaultArr;

    // 2. Parameterized constructor
    DynamicArray paramArr(5, 10, 10);
    paramArr.print("Array Elements");

    // 3. Copy constructor (deep copy)
    DynamicArray copiedArr(paramArr);

    // 4. Copy assignment operator (deep copy)
    DynamicArray copyAssignedArr;
    copyAssignedArr = paramArr;

    // 5. Move constructor (ownership transfer)
    DynamicArray movedArr(std::move(copiedArr));

    // 6. Move assignment operator (ownership transfer)
    DynamicArray moveAssignedArr;
    moveAssignedArr = std::move(copyAssignedArr);

    std::cout << "Program executed successfully.\n";
    return 0;
}

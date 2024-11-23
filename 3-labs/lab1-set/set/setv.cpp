#include "set.h"

// Constructor: Initializes an empty set with default capacity
template <typename T>
Set<T>::Set() : capacity(100) { // Default capacity can be adjusted
    elements.reserve(capacity);
}

// Constructor: Initializes an empty set with a specified capacity
template <typename T>
Set<T>::Set(int capacity) : capacity(capacity) {
    elements.reserve(capacity);
}

// Destructor: Clears the set
template <typename T>
Set<T>::~Set() {
    clear();
}

// Adds an element to the set if it is not already present
template <typename T>
bool Set<T>::add(const T& element) {
    if (!contains(element)) {
        if (elements.size() >= capacity) {
            return false; // Capacity exceeded
        }
        elements.push_back(element);
        return true;
    }
    return false; // Element already exists
}

// Removes an element from the set if present
template <typename T>
bool Set<T>::remove(const T& element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end()) {
        elements.erase(it);
        return true;
    }
    return false; // Element not found
}

// Clears all elements from the set
template <typename T>
void Set<T>::clear() {
    elements.clear();
}

// Checks if the set contains a specific element
template <typename T>
bool Set<T>::contains(const T& element) const {
    return std::find(elements.begin(), elements.end(), element) != elements.end();
}

// Returns the number of elements in the set
template <typename T>
int Set<T>::size() const {
    return elements.size();
}

// Checks if the set is empty
template <typename T>
bool Set<T>::isEmpty() const {
    return elements.empty();
}

// Prints all elements in the set in lexicographical (dictionary) order
template <typename T>
void Set<T>::print() const {
    std::vector<T> sorted_elements = elements; // Copy elements to avoid modifying the original set
    std::sort(sorted_elements.begin(), sorted_elements.end()); // Sort the elements in dictionary order
    for (const auto& element : sorted_elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Converts the set to a string representation in lexicographical order
template <typename T>
std::string Set<T>::toString() const {
    std::vector<T> sorted_elements = elements; // Copy elements to avoid modifying the original set
    std::sort(sorted_elements.begin(), sorted_elements.end()); // Sort the elements in dictionary order
    std::ostringstream oss;
    for (const auto& element : sorted_elements) {
        oss << element << " ";
    }
    return oss.str();
}

// Union operation: Returns a new set containing all elements from both sets
template <typename T>
Set<T> Set<T>::operator+(const Set<T>& other) const {
    Set<T> result(*this);
    for (const auto& element : other.elements) {
        result.add(element);
    }
    return result;
}

// Difference operation: Returns a new set containing elements in this set but not in the other
template <typename T>
Set<T> Set<T>::operator-(const Set<T>& other) const {
    Set<T> result;
    for (const auto& element : elements) {
        if (!other.contains(element)) {
            result.add(element);
        }
    }
    return result;
}

// Intersection operation: Returns a new set containing elements common to both sets
template <typename T>
Set<T> Set<T>::operator*(const Set<T>& other) const {
    Set<T> result;
    for (const auto& element : elements) {
        if (other.contains(element)) {
            result.add(element);
        }
    }
    return result;
}

// Checks if this set is a subset of the other set
template <typename T>
bool Set<T>::isSubsetOf(const Set<T>& other) const {
    for (const auto& element : elements) {
        if (!other.contains(element)) {
            return false;
        }
    }
    return true;
}

// Lowercase complement (only valid if T is char): Returns a set of lowercase letters not in the set
template <>
Set<char> Set<char>::lowercaseComplement() const {
    Set<char> result;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!contains(c)) {
            result.add(c);
        }
    }
    return result;
}

// Friend function to output the set using << operator in lexicographical order
template <typename U>
std::ostream& operator<<(std::ostream& os, const Set<U>& set) {
    std::vector<U> sorted_elements = set.elements; // Copy elements to avoid modifying the original set
    std::sort(sorted_elements.begin(), sorted_elements.end()); // Sort the elements in dictionary order
    os << "{ ";
    for (const auto& element : sorted_elements) {
        os << element << " ";
    }
    os << "}";
    return os;
}

// Returns a pointer to the first element in the set (for iteration)
template <typename T>
const T* Set<T>::begin() const {
    return elements.empty() ? nullptr : &elements[0];
}

// Returns a pointer past the last element in the set (for iteration)
template <typename T>
const T* Set<T>::end() const {
    return elements.empty() ? nullptr : &elements[0] + elements.size();
}

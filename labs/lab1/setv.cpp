#include "set.h"

// Constructor
template <typename T>
Set<T>::Set() : capacity(100) {
    elements.reserve(capacity);
}

// Constructor
template <typename T>
Set<T>::Set(int capacity) : capacity(capacity) {
    elements.reserve(capacity);
}

// Destructor
template <typename T>
Set<T>::~Set() {
    clear();
}

template <typename T>
bool Set<T>::add(const T& element) {
    if (!contains(element)) {
        if (elements.size() >= capacity) {
            return false; // exceeded
        }
        elements.push_back(element);
        return true;
    }
    return false;
}

template <typename T>
bool Set<T>::remove(const T& element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end()) {
        elements.erase(it);
        return true;
    }
    return false; // not found
}

template <typename T>
void Set<T>::clear() {
    elements.clear();
}

template <typename T>
int Set<T>::size() const {
    return elements.size();
}

template <typename T>
bool Set<T>::isEmpty() const {
    return elements.empty();
}

template <typename T>
bool Set<T>::contains(const T& element) const {
    return std::find(elements.begin(), elements.end(), element) != elements.end();
}

template <typename T>
void Set<T>::print() const {
    std::vector<T> sorted_elements = elements;
    std::sort(sorted_elements.begin(), sorted_elements.end()); // Sort in dictionary order
    for (const auto& element : sorted_elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::string Set<T>::toString() const {
    std::vector<T> sorted_elements = elements;
    std::sort(sorted_elements.begin(), sorted_elements.end()); // Sort in dictionary order
    std::ostringstream oss;
    for (const auto& element : sorted_elements) {
        oss << element << " ";
    }
    return oss.str();
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T>& other) const {
    Set<T> result(*this);
    for (const auto& element : other.elements) {
        result.add(element);
    }
    return result;
}

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

template <typename T>
bool Set<T>::isSubsetOf(const Set<T>& other) const {
    for (const auto& element : elements) {
        if (!other.contains(element)) {
            return false;
        }
    }
    return true;
}

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

template <typename U>
std::ostream& operator<<(std::ostream& os, const Set<U>& set) {
    std::vector<U> sorted_elements = set.elements;
    std::sort(sorted_elements.begin(), sorted_elements.end());
    os << "{ ";
    for (const auto& element : sorted_elements) {
        os << element << " ";
    }
    os << "}";
    return os;
}

template <typename T>
const T* Set<T>::begin() const {
    return elements.empty() ? nullptr : &elements[0];
}

template <typename T>
const T* Set<T>::end() const {
    return elements.empty() ? nullptr : &elements[0] + elements.size();
}

#include "Collection.h"

Collection::Collection() {
    capacity = 10;
    array = new double[capacity];
    size = 0;
}

Collection::Collection(int size) {
    capacity = size;
    array = new double[capacity];
    this->size = 0;
}

Collection::Collection(const Collection& other) {
    capacity = other.capacity;
    array =  new double[capacity];
    size = other.size;
    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

Collection::~Collection() {
    delete[] array;
}

Collection& Collection::operator=(const Collection &other) {
    if (this != &other) {
        delete[] array;
        capacity = other.capacity;
        array = new double[capacity];
        size = other.size;
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

int Collection::getSize() const {
    return size;
}

int Collection::getCapacity() const {
    return capacity;
}

void Collection::add(double value) {
    if (size >= capacity) {
        throw std::runtime_error("List Full");
    }
    array[size++] = value;
}

void Collection::addFront(double value) {
    if (size >= capacity) {
        throw std::runtime_error("List Full");
    }
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    size++;
}

double Collection::get(int ndx) const {
    if (ndx < 0 || ndx >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[ndx];
}

double Collection::getFront() const {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }
    return array[0];
}

double Collection::getEnd() const {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }
    return array[size - 1];
}

int Collection::find(double needle) const {
    for (int i = 0; i < size; i++) {
        if (array[i] == needle) {
            return array[i];
        }
    }
    return -1;
}

std::ostream& operator<<(std::ostream& out, const Collection & c) {
    for (int i = 0; i < c.size; i++) {
        out << c.array[i] << " ";
    }
    return out;
}


#ifndef MODULE_1_COLLECTION_H
#define MODULE_1_COLLECTION_H

#include <iostream>
#include <stdexcept>


class Collection {
public:
    Collection();
    Collection(int size) ;
    Collection(const Collection& other);
    ~Collection();

    Collection& operator=(const Collection& other);

    int getSize() const;
    int getCapacity() const;

    void add(double value);
    void addFront(double value);

    double get(int ndx) const;
    double getFront() const;
    double getEnd() const;

    int find(double needle) const;

    friend std::ostream& operator<<(std::ostream& out, const Collection & c);
private:
    double* array;
    int size;
    int capacity;
};


#endif //MODULE_1_COLLECTION_H

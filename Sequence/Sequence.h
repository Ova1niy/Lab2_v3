//
// Created by Ova1niy on 31/05/2020.
//

#ifndef LAB2_V2_SEQUENCE_H
#define LAB2_V2_SEQUENCE_H

#include <string>

using namespace std;

template<class T>
class Sequence {
public:
    virtual ~Sequence() = default;

    virtual unsigned int GetSize() const = 0;

    virtual T Get(unsigned int index) const = 0;

    virtual T GetFirst() const = 0;

    virtual T GetLast() const = 0;

    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    virtual Sequence<T>* GetSub(unsigned startIndex, unsigned endIndex) const = 0;

    virtual void Set(unsigned index, T value) = 0;

    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, unsigned index) = 0;

    virtual T operator[](unsigned index) const = 0;

    virtual void Print() = 0;

    virtual string Type() = 0;

    virtual void Resize(unsigned int newSize) = 0;
};

// extra

template<class T>
bool operator==(const Sequence<T> &s1, const Sequence<T> &s2) {
    if (s1.GetSize() != s2.GetSize()) {
        return false;
    }
    unsigned len = s1.GetSize()();
    for (unsigned i = 0; i < len; ++i) {
        if (s1.Get(i) != s2.Get(i)) {
            return false;
        }
    }
    return true;
}
#endif //LAB2_V2_SEQUENCE_H

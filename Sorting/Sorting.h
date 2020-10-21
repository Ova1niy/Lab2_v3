//
// Created by Ova1niy on 04/10/2020.
//

#ifndef LAB2_V3_SORTING_H
#define LAB2_V3_SORTING_H

#include "../Sequence/Sequence.h"
#include "../Sequence/ArraySequence.h"
#include "../Sequence/ListSequence.h"

using namespace std;

template<class T>
class Sorting {
public:
    virtual ~Sorting() = default;
    virtual void sort(Sequence<T>* seq) = 0;
};

#endif //LAB2_V3_SORTING_H

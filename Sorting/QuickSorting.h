//
// Created by Ova1niy on 04/10/2020.
//

#ifndef LAB2_V3_QUICKSORTING_H
#define LAB2_V3_QUICKSORTING_H

#include "../Sequence/Sequence.h"
#include "Sorting.h"

template<class T>
class QuickSorting : public Sorting<T> {
public:
    QuickSorting<T>() = default;
    void sort(Sequence<T>* seq) override;
};

template<class T>
void QuickSorting<T>::sort(Sequence<T> *seq) {
    int left = 0;
    int right = seq->GetSize() - 1;
    myQuickSort(seq, left, right);
}

template<class T>
void myQuickSort(Sequence<T> *seq, int left, int right) {
    int l_hold = left;
    int r_hold = right;
    int pivot = seq->Get(left);
    while (left < right) {
        while ((seq->Get(right) >= pivot) && (left < right)) --right;
        if (left != right) {
            seq->Set(left, seq->Get(right));
            ++left;
        }
        while ((seq->Get(left) <= pivot) && (left < right)) ++left;
        if (left != right) {
            seq->Set(right, seq->Get(left));
            --right;
        }
    }
    seq->Set(left, pivot);
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        myQuickSort(seq, left, pivot - 1);
    if (right > pivot)
        myQuickSort(seq, pivot + 1, right);
}

#endif //LAB2_V3_QUICKSORTING_H

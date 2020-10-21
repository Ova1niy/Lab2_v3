//
// Created by Ova1niy on 21/10/2020.
//

#ifndef LAB2_V3_SHAKESORTING_H
#define LAB2_V3_SHAKESORTING_H

#include "../Sequence/Sequence.h"
#include "Sorting.h"

template<class T>
class ShakeSorting : public Sorting<T> {
public:
    ShakeSorting<T>() = default;
    void sort(Sequence<T>* seq) override;
};

template<class T>
void ShakeSorting<T>::sort(Sequence<T> *seq) {
    int left = 0;
    int right = seq->GetSize() - 1;
    bool up = true;
    while (left != right){
        if (up) {
            for (int i = left; i < right; ++i) {
                if (seq->Get(i) > seq->Get(i+1)) {
                    T tmp = seq->Get(i);
                    seq->Set(i, seq->Get(i+1));
                    seq->Set(i+1, tmp);
                }
            }
            --right;
            up = false;
        } else {
            for (int i = right; i > left; --i) {
                if (seq->Get(i) < seq->Get(i-1)) {
                    T tmp = seq->Get(i);
                    seq->Set(i, seq->Get(i-1));
                    seq->Set(i-1, tmp);
                }
            }
            ++left;
            up = true;
        }
    }
}

#endif //LAB2_V3_SHAKESORTING_H

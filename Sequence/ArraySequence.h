//
// Created by Ova1niy on 31/05/2020.
//

#ifndef LAB2_V2_ARRAYSEQUENCE_H
#define LAB2_V2_ARRAYSEQUENCE_H

#include "Sequence.h"
#include "../DynamicArray/DynamicArray.h"

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* arr_;
    unsigned int size_ = 0;
public:
    ArraySequence();

    explicit ArraySequence(unsigned int count);

    ArraySequence(T* items, unsigned int count);

    explicit ArraySequence(Sequence<T> *arr);

    explicit ArraySequence(const DynamicArray<T> &arr);

    unsigned int GetSize() const override { return size_; };

    T GetFirst() const override { return arr_->GetFirst(); };

    T GetLast() const override { return arr_->GetLast(); };

    T Get(unsigned index) const override { return arr_->Get(index); };

    Sequence<T>* Concat(Sequence<T> *arr) override;

    Sequence<T>* GetSub(unsigned startIndex, unsigned endIndex) const override;

    void Set(unsigned index, T value) override { arr_->Set(index, value); };

    void Append(T item) override { arr_->Append(item); ++size_; };

    void Prepend(T item) override { arr_->Prepend(item); ++size_; };

    void InsertAt(T item, unsigned index) override { arr_->InsertAt(item, index); ++size_; };

    T operator[](unsigned index) const override { return arr_->Get(index); };

    void Print() override { arr_->Print(); };

    void Resize(unsigned int newSize) override { arr_->Resize(newSize); size_ = newSize; };

    string Type() override { return "ArraySequence"; };

};

template<class T>
ArraySequence<T>::ArraySequence() {
    arr_ = NULL;
    size_ = 0;
}

template<class T>
ArraySequence<T>::ArraySequence(unsigned int count) {
    arr_ = new DynamicArray<T>(count);
    size_ = count;
}

template<class T>
ArraySequence<T>::ArraySequence(T *items, unsigned int count) {
    arr_ = new DynamicArray<T>(items, count);
    size_ = count;
}

template<class T>
ArraySequence<T>::ArraySequence(Sequence<T>* arr) {
    arr_ = new DynamicArray<T>(*dynamic_cast<ArraySequence*>(arr)->arr_);
    size_ = arr->GetSize();
}

template<class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T> &arr) {
    arr_ = new DynamicArray<T>(arr);
    size_ = arr_->GetSize();
}

template<class T>
Sequence<T>* ArraySequence<T>::Concat(Sequence<T> *arr) {
    return new ArraySequence<T>(DynamicArray<T>(arr_->Concat(dynamic_cast<ArraySequence*>(arr)->arr_)));
}

template<class T>
Sequence<T>* ArraySequence<T>::GetSub(unsigned startIndex, unsigned endIndex) const {
    return new ArraySequence<T>(arr_->GetSub(startIndex, endIndex));
}


#endif //LAB2_V2_ARRAYSEQUENCE_H

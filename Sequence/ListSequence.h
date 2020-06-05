//
// Created by Ova1niy on 31/05/2020.
//

#ifndef LAB2_V2_LISTSEQUENCE_H
#define LAB2_V2_LISTSEQUENCE_H

#include "Sequence.h"
#include "../LinkedList/LinkedList.h"

template<class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T>* list_;
    unsigned int size_ = 0;
public:
    ListSequence();

    explicit ListSequence(unsigned int count);

    ListSequence(const T* items, unsigned int count);

    explicit ListSequence(Sequence<T> *list);

    explicit ListSequence(const LinkedList<T> &arr);

    unsigned int GetSize() const override { return size_; };

    T GetFirst() const override { return list_->GetFirst(); };

    T GetLast() const override { return list_->GetLast(); };

    T Get(unsigned index) const override { return list_->Get(index); };

    Sequence<T>* Concat(Sequence<T>* list) override;

    Sequence<T>* GetSub(unsigned startIndex, unsigned endIndex) const override;

    void Set(unsigned index, T value) override { list_->Set(index, value); };

    void Append(T item) override { list_->Append(item); ++size_; };

    void Prepend(T item) override { list_->Prepend(item); ++size_; };

    void InsertAt(T item, unsigned index) override { list_->InsertAt(item, index); ++size_; };

    T operator[](unsigned index) const override { return list_->Get(index); };

    void Print() override { list_->Print(); };

    void Resize(unsigned int newSize) override { list_->Resize(newSize); size_ = newSize; };

    string Type() override { return "ListSequence"; };

};

template<class T>
ListSequence<T>::ListSequence() {
    list_ = new LinkedList<T>;
    size_ = 0;
}

template<class T>
ListSequence<T>::ListSequence(unsigned int count) {
    list_ = new LinkedList<T>(count);
    size_ = count;
}


template<class T>
ListSequence<T>::ListSequence(const T *items, unsigned int count) {
    list_ = new LinkedList<T>(items, count);
    size_ = count;
}

template<class T>
ListSequence<T>::ListSequence(Sequence<T>* list) {
    list_ = new LinkedList<T>(*dynamic_cast<ListSequence*>(list)->list_);
    size_ = list->GetSize();
}

template<class T>
ListSequence<T>::ListSequence(const LinkedList<T> &arr) {
    list_ = new LinkedList<T>(arr);
    size_ = arr.GetSize();
}

template<class T>
Sequence<T>* ListSequence<T>::Concat(Sequence<T>* list) {
    return new ListSequence<T>(LinkedList<T>(list_->Concat(dynamic_cast<ListSequence*>(list)->list_)));
}

template<class T>
Sequence<T>* ListSequence<T>::GetSub(unsigned startIndex, unsigned endIndex) const {
    return new ListSequence<T>(list_->GetSub(startIndex, endIndex));
}

#endif //LAB2_V2_LISTSEQUENCE_H

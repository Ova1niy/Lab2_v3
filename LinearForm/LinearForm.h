//
// Created by Ova1niy on 31/05/2020.
//

#ifndef LAB2_V2_LINEARFORM_H
#define LAB2_V2_LINEARFORM_H

#include "../Sequence/Sequence.h"
#include "../Sequence/ArraySequence.h"
#include "../Sequence/ListSequence.h"

template<class T>
class LinearForm {
private:
    Sequence<T>* seq_;

public:
    ~LinearForm() = default;

    LinearForm(int count, string type);

    explicit LinearForm(Sequence<T>* arr);

    explicit LinearForm(LinearForm<T>* lf);

    unsigned int GetSize() const { return seq_->GetSize(); };

    T Get(unsigned int index) const { return seq_->Get(index); };

    T GetFirst() const { return seq_->GetFirst(); };

    T GetLast() const { return seq_->GetLast(); };

    LinearForm<T>* Concat(LinearForm<T>* lf);

    LinearForm<T>* GetSub(unsigned startIndex, unsigned endIndex);

    void Append(T item) { return seq_->Append(item); };

    void Prepend(T item) { return seq_->Prepend(item); };

    void InsertAt(T item, unsigned index) { return seq_->InsertAt(item, index); };

    void Set(unsigned int index, T value) { seq_->Set(index, value); };

    T Calculate(T* items, unsigned int count) const;

    T Calculate(LinearForm<T>* koefs) const;

    void Resize(unsigned int newSize) { seq_->Resize(newSize); };

    void Print() const {seq_->Print(); };

    string Type() const { return seq_->Type(); };

    T operator[](const int &index) { return Get(index); };

    friend bool operator==(const LinearForm& left, const LinearForm& right){
        if (left.GetSize() != right.GetSize()) {
            return false;
        }
        for (int i = 0; i < left.GetSize(); ++i) {
            if (left.Get(i) != right.Get(i)) {
                return false;
            }
        }
        return true;
    }

    LinearForm<T>& operator+= (const LinearForm<T>& lf) {
        if (GetSize() > lf.GetSize()) {
            for (int i = 0; i < lf.GetSize(); ++i) {
                Set(i, Get(i) + lf.Get(i));
            }
        } else {
            Resize(lf.GetSize());
            for (int i = 0; i < GetSize(); ++i) {
                Set(i, Get(i) + lf.Get(i));
            }
        }
        return *this;
    }

    LinearForm<T>& operator-= (const LinearForm<T>& lf) {
        if (GetSize() > lf.GetSize()) {
            for (int i = 0; i < lf.GetSize(); ++i) {
                Set(i, Get(i) - lf.Get(i));
            }
        } else {
            Resize(lf.GetSize());
            for (int i = 0; i < GetSize(); ++i) {
                Set(i, Get(i) - lf.Get(i));
            }
        }
        return *this;
    }

    LinearForm<T>& operator*= (const T& scalar) {
        for (int i = 0; i < GetSize(); ++i) {
            Set(i, Get(i) * scalar);
        }
        return *this;
    }

    LinearForm<T>& operator/= (const T& scalar) {
        for (int i = 0; i < GetSize(); ++i) {
            Set(i, Get(i) / scalar);
        }
        return *this;
    }

    LinearForm<T>& operator= (LinearForm<T>& lf) {
        if (GetSize() != lf.GetSize()) {
            Resize(lf.GetSize());
        }
        for (int i = 0; i < GetSize(); ++i) {
            Set(i, lf.Get(i));
        }
    }
};

template<class T>
LinearForm<T>::LinearForm(int count, string type) {
    if (type == "ArraySequence") {
        seq_ = new ArraySequence<T>(count);
    } else {
        seq_ = new ListSequence<T>(count);
    }
}

template<class T>
LinearForm<T>::LinearForm(Sequence<T> *arr) {
    if (arr->Type() == "ArraySequence") {
        seq_ = new ArraySequence<T>(arr);
    } else {
        seq_ = new ListSequence<T>(arr);
    }
}

template<class T>
LinearForm<T>::LinearForm(LinearForm<T> *lf) {
    if (lf->Type() == "ArraySequence") {
        seq_ = new ArraySequence<T>(lf->seq_);
    } else {
        seq_ = new ListSequence<T>(lf->seq_);
    }
}

template<class T>
T LinearForm<T>::Calculate(T *items, unsigned int count) const {
    if (count != GetSize()) {
        throw "NotEqualSizes";
    }
    T res = 0;
    for (int i = 0; i < GetSize(); ++i) {
        res += seq_->Get(i) * items[i];
    }
    return res;
}

template<class T>
T LinearForm<T>::Calculate(LinearForm<T> *koefs) const {
    if (koefs->GetSize() != GetSize()) {
        throw "NotEqualSizes";
    }
    T res = 0;
    for (int i = 0; i < GetSize(); ++i) {
        res += seq_->Get(i) * koefs->Get(i);
    }
    return res;
}

template<class T>
LinearForm<T>* LinearForm<T>::Concat(LinearForm<T> *lf) {
    return new LinearForm<T>(seq_->Concat(lf));
}

template<class T>
LinearForm<T> *LinearForm<T>::GetSub(unsigned startIndex, unsigned endIndex) {
    return new LinearForm(seq_->GetSub(startIndex, endIndex));
}

template<class T>
LinearForm<T>& operator+(const LinearForm<T>& lf1, const LinearForm<T>& lf2) {
    LinearForm<T> *res;
    if (lf1.GetSize() > lf2.GetSize()) {
        res = new LinearForm<T>(lf1.GetSize(), lf1.Type());
        for (int i = 0; i < lf2.GetSize(); ++i) {
            res->Set(i, lf1.Get(i) + lf2.Get(i));
        }
        return *res;
    } else {
        res = new LinearForm<T>(lf2.GetSize(), lf2.Type());
        for (int i = 0; i < lf1.GetSize(); ++i) {
            res->Set(i, lf1.Get(i) + lf2.Get(i));
        }
        return *res;
    }
}

template<class T>
LinearForm<T>& operator-(const LinearForm<T>& lf1, const LinearForm<T>& lf2) {
    LinearForm<T> *res;
    if (lf1.GetSize() > lf2.GetSize()) {
        res = new LinearForm<T>(lf1.GetSize(), lf1.Type());
        for (int i = 0; i < lf2.GetSize(); ++i) {
            res->Set(i, lf1.Get(i) - lf2.Get(i));
        }
    } else {
        res = new LinearForm<T>(lf2.GetSize(), lf2.Type());
        int i = 0;
        for (; i < lf1.GetSize(); ++i) {
//            cout << i << " step:\n"; lf1.Print(); lf2.Print(); res->Print();
            res->Set(i, lf1.Get(i) - lf2.Get(i));
        }
        for (; i < lf2.GetSize(); ++i) {
//            cout << i << " step:\n"; lf1.Print(); lf2.Print(); res->Print();
            res->Set(i, -lf2.Get(i));
        }
    }
    return *res;
}

template<class T>
LinearForm<T> operator*(const LinearForm<T> lf, T scalar) {
    LinearForm<T>* res = new LinearForm<T>(lf.GetSize(), lf.Type());
    for (int i = 0; i < res->GetSize(); ++i) {
        res->Set(i, lf.Get(i) * scalar);
    }
    return *res;
}

template<class T>
LinearForm<T> operator/(const LinearForm<T> lf, T scalar) {
    LinearForm<T>* res = new LinearForm<T>(lf.GetSize(), lf.Type());
    for (int i = 0; i < res->GetSize(); ++i) {
        res->Set(i, lf.Get(i) / scalar);
    }
    return *res;
}

#endif //LAB2_V2_LINEARFORM_H

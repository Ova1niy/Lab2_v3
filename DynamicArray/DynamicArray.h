//
// Created by Ova1niy on 30/05/2020.
//

// WORKING !!!

#ifndef LAB2_V2_DYNAMICARRAY_H
#define LAB2_V2_DYNAMICARRAY_H

#include "../Comp/Comp.h"
using namespace std;

const int BUFFER_SIZE = 10;

template<class T>
class DynamicArray {
private:
    T* head;
    int buffer = BUFFER_SIZE;
    int size;
public:

    // Создание объекта
    explicit DynamicArray(unsigned int count); // Создать массив заданной длины

    DynamicArray(T* items, unsigned int count); // Копировать элементы из переданного массива

    DynamicArray(const DynamicArray<T> & arr); // Копирующий конструктор


    //Декомпозиция
    T Get(unsigned int index); // Получить элемент по индексу

    T GetFirst(); // Получить первый элемент

    T GetLast(); // получить последний элемент

    DynamicArray<T> GetSub(unsigned int startIndex, unsigned int endIndex); // Получить часть массива

    int GetSize(); // Получить размер массива


    //Операции
    void Set(unsigned int index, T value); // Задать значение по индексу

    void Resize(unsigned int newSize); // Изменить размер массива

    void Append(T item); // Добавляет элемент в начало массива

    void Prepend(T item); // Добавляет элемент в конец массива

    void InsertAt(T item, unsigned int index); // Вставляет элемент в заданную позицию

    DynamicArray<T> Concat(DynamicArray<T> *arr); // Сцепляет два массива

    void Print(); // Вывести массив на экран

    T operator[] (unsigned int index) const{
        if (index < 0 || index > GetSize()) {
            throw "IndexOutOfRange";
        }
        return head[index];
    }
};

int BufferCount(unsigned int count) {
    if (count % BUFFER_SIZE == 0) {
        return count / BUFFER_SIZE;
    } else {
        return count / BUFFER_SIZE + 1;
    }
}

// Реализация
template <class T>
DynamicArray<T>::DynamicArray(unsigned int count) {
    size = buffer * BufferCount(count);
    head = (T*)malloc(sizeof(T) * size);
    for (int i = 0; i < count; ++i) {
        head[i] = 0;
    }
}

template <class T>
DynamicArray<T>::DynamicArray(T* items, unsigned int count) {
    size = buffer * BufferCount(count);
    head = (T*)malloc(sizeof(T) * size);
    for (int i = 0; i < count; ++i) {
        head[i] = items[i];
    }
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &arr) {
    size = arr.size; // размер по-любому учитывает буффер
    head = (T*)malloc(sizeof(T) * size);
    for (int i = 0; i < size; ++i) {
        head[i] = arr.head[i];
    }
}

template <class T>
T DynamicArray<T>::Get(unsigned int index){
    if (size <= 0) {
        throw "EmptyArray";
    } else if (index < 0 || index >= size) {
        throw "IndexOutOfRange";
    }
    return head[index];
}

template <class T>
T DynamicArray<T>::GetFirst() {
    if (size <= 0) {
        throw "EmptyArray";
    }
    return head[0];
}

template <class T>
T DynamicArray<T>::GetLast() {
    if (size <= 0) {
        throw "EmptyArray";
    }
    return head[size-1];
}

template <class T>
int DynamicArray<T>::GetSize() {
    return size;
}

template <class T>
DynamicArray<T> DynamicArray<T>::GetSub(unsigned int startIndex, unsigned int endIndex) {
    if (size <= 0) {
        throw "EmptyArray";
    } else if (startIndex < 0 || startIndex >= size) {
        throw "StartIndexOutOfRange";
    } else if (endIndex < 0 || endIndex >= size) {
        throw "EndIndexOutOfRange";
    } else if (endIndex < startIndex) {
        throw "EndLessStart";
    }
    DynamicArray<T> res = DynamicArray(endIndex - startIndex + 1);
    int j = 0;
    for (unsigned int i = startIndex; i <= endIndex; ++i) {
        res.head[j] = head[i];
        ++j;
    }
    return res;
}

template<class T>
void DynamicArray<T>::Set(unsigned int index, T value) {
    if (index < 0 || index >= size) {
        throw "IndexOutOfRange";
    }
    head[index] = value;
}

template<class T>
void DynamicArray<T>::Resize(unsigned int newSize) {
    if (newSize < 0) {
        throw "NegativeSize";
    }
    newSize = buffer * BufferCount(newSize);
    T* newHead = (T*)malloc(sizeof(T) * newSize);
    if (newSize < size) {
        for (int i = 0; i < newSize; ++i) {
            newHead[i] = head[i];
        }
    } else {
        int i = 0;
        for ( ; i < size; ++i) {
            newHead[i] = head[i];
        }
        for ( ; i < newSize; ++i) {
            newHead[i] = 0;
        }
    }
    free(head);
    head = newHead;
    size = newSize;
}

template<class T>
void DynamicArray<T>::Append(T item) {
    unsigned int newSize = buffer * BufferCount(size + 1);
    T* newHead = (T*)malloc(sizeof(T) * newSize);
    newHead[0] = item;
    for (int i = 0; i < size; ++i) {
        newHead[i+1] = head[i];
    }
    free(head);
    head = newHead;
    ++size;
}

template<class T>
void DynamicArray<T>::Prepend(T item) {
    if (BufferCount(size) != BufferCount(size + 1)) {
        unsigned int newSize = buffer * BufferCount(size + 1);
        T* newHead = (T*)malloc(sizeof(T) * newSize);
        for (int i = 0; i < size; ++i) {
            newHead[i] = head[i];
        }
        newHead[size] = item;
        free(head);
        head = newHead;
        ++size;
    } else {
        head[size] = item;
        ++size;
    }
}

template<class T>
void DynamicArray<T>::InsertAt(T item, unsigned int index) {
    if (index < 0 || index > size) {
        throw "IndexOutOfRange";
    }
    unsigned int newSize = buffer * BufferCount(size + 1);
    T* newHead = (T*)malloc(sizeof(T) * newSize);
    int i = 0;
    for ( ; i < index; ++i) {
        newHead[i] = head[i];
    }
    newHead[i] = item;
    ++i;
    for ( ; i < size + 1; ++i) {
        newHead[i] = head[i-1];
    }
    free(head);
    head = newHead;
    ++size;
}

template<class T>
DynamicArray<T> DynamicArray<T>::Concat(DynamicArray<T> *arr) {
    DynamicArray<T> res = DynamicArray(size + arr->GetSize());
    int i = 0;
    for ( ; i < size; ++i) {
        res.head[i] = head[i];
    }
    for ( ; (i-size) < arr->GetSize(); ++i) {
        res.head[i] = arr->head[i-size];
    }
    return res;
}

template<class T>
void DynamicArray<T>::Print() {
    for (int i = 0; i < size; ++i){
        cout << head[i] << " ";
    }
    cout << endl;
}


#endif //LAB2_V2_DYNAMICARRAY_H

//
// Created by Ova1niy on 30/05/2020.
//

#ifndef LAB2_V2_LINKEDLIST_H
#define LAB2_V2_LINKEDLIST_H

#include "../Comp/Comp.h"

template <class T>
struct Node {
    T value;
    Node<T>* next;
};

template <class T> class LinkedList {
private:
    Node<T>* head;
    Node<T>* back;
    int size;
public:
    // Создание объекта
    LinkedList (T* items, unsigned int count); // Копировать элементы из переданного массива

    LinkedList(unsigned int count);

    LinkedList (); // Создать пустой список

    LinkedList (const LinkedList <T> & list); // Копирующий конструктор


    //Декомпозиция
    T GetFirst(); // Получить первый элемент

    T GetLast(); // получить последний элемент

    T Get(unsigned int index); // Получить элемент по индексу

    LinkedList<T> GetSub(unsigned int startIndex, unsigned int endIndex); // Получить часть списка

    int GetSize() const; // Получить размер списка


    // Операции
    void Set(unsigned int index, T value); // Задать значение по индексу

    void Resize(unsigned int newSize); // Изменить размер массива

    void Append(T item); // Добавляет элемент в начало списка

    void Prepend(T item); // Добавляет элемент в конец списка

    void InsertAt(T item, unsigned int index); // Вставляет элемент в заданную позицию

    LinkedList<T> Concat(LinkedList<T> *list); // Сцепляет два списка

    void Print();

    T operator[] (unsigned int index) const{
        if (index < 0 || index > GetSize()) {
            throw "IndexOutOfRange";
        }
        return Get(index);
    }
};

template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    back = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(unsigned int count) {
    head = NULL;
    back = NULL;
    size = 0;
    for (int i = 0; i < count; ++i) {
        Prepend(0);
    }
    size = count;
}

template<class T>
void LinkedList<T>::Prepend(T item) {
    if (head == NULL) {
        head = (Node<T>*)malloc(sizeof(Node<T>));
        head->value = item;
        head->next = NULL;
        back = head;
        size = 1;
    } else {
        Node<T>* q = back;
        q->next = (Node<T>*)malloc(sizeof(Node<T>));
        q = q->next;
        q->value = item;
        q->next = NULL;
        back = q;
        ++size;
    }
}

template<class T>
LinkedList<T>::LinkedList(T *items, unsigned int count) {
    head = NULL;
    back = NULL;
    size = 0;
    for (int i = 0; i < count; ++i) {
        Prepend(items[i]);
    }
    size = count;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    head = NULL;
    back = NULL;
    size = 0;
    Node<T>* q = list.head;
    while (q != NULL) {
        Prepend(q->value);
        q = q->next;
    }
    size = list.size;
}

template<class T>
void LinkedList<T>::Print() {
    Node<T>* q = head;
    while (q != NULL){
        cout << q->value << " ";
        q = q->next;
    }
    cout << endl;
}

template<class T>
T LinkedList<T>::GetFirst() {
    if (size <= 0) {
        throw "EmptyList";
    }
    return head->value;
}

template<class T>
T LinkedList<T>::GetLast() {
    if (size <= 0) {
        throw "EmptyList";
    }
    return back->value;
}

template<class T>
T LinkedList<T>::Get(unsigned int index) {
    if (size <= 0) {
        throw "EmptyList";
    } else if (index < 0 || index >= size) {
        throw "IndexOutOfRange";
    }
    Node<T>* q = head;
    for (int i = 0; i < index; ++i) {
        q = q->next;
    }
    return q->value;
}

template<class T>
LinkedList<T> LinkedList<T>::GetSub(unsigned int startIndex, unsigned int endIndex) {
    if (size <= 0) {
        throw "EmptyList";
    } else if (startIndex < 0 || startIndex >= size) {
        throw "StartIndexOutOfRange";
    } else if (endIndex < 0 || endIndex >= size) {
        throw "EndIndexOutOfRange";
    } else if (endIndex < startIndex) {
        throw "EndLessStart";
    }
    LinkedList<T> res = LinkedList();
    Node<T>* q = head;
    int i = 0;
    for ( ; i < startIndex; ++i) {
        q = q->next;
    }
    for ( ; i <= endIndex; ++i) {
        res.Prepend(q->value);
        q = q->next;
    }
    res.size = endIndex - startIndex + 1;
    return res;
}

template<class T>
int LinkedList<T>::GetSize() const {
    return size;
}

template<class T>
void LinkedList<T>::Set(unsigned int index, T value) {
    if (size <= 0) {
        throw "EmptyList";
    } else if (index < 0 || index >= size) {
        throw "IndexOutOfRange";
    }
    Node<T>* q = head;
    for (int i = 0; i < index; ++i) {
        q = q->next;
    }
    q->value = value;
}

template<class T>
void LinkedList<T>::Resize(unsigned int newSize) {
    if (newSize < 0) {
        throw "NegativeSize";
    }
    if (newSize == 0) {
        Node<T>* qq = head;
        Node<T>* qqq = qq->next;
        while (qqq != NULL) {
            free(qq);
            qq = qqq;
            qqq = qqq->next;
        }
        free(qq);
        head = NULL;
        back = NULL;
    } else if(newSize < size) {
        Node<T>* q = head;
        for (int i = 0; i < newSize-1; ++i) {
            q = q->next;
        }
        back = q;
        Node<T>* qq = q->next;
        Node<T>* qqq = q->next->next;
        while (qqq != NULL) {
            free(qq);
            qq = qqq;
            qqq = qqq->next;
        }
        free(qq);
        back->next = NULL;
    } else {
        int razn = newSize - size;
        for (int i = 0; i < razn; ++i) {
            Prepend(0);
        }
    }
    size = newSize;
}

template<class T>
void LinkedList<T>::Append(T item) {
    if (head == NULL) {
        head = (Node<T>*)malloc(sizeof(Node<T>));
        head->value = item;
        head->next = NULL;
        back = head;
        size = 1;
    } else {
        Node<T>* q = (Node<T>*)malloc(sizeof(Node<T>));
        q->value = item;
        q->next = head;
        head = q;
        ++size;
    }
}

template<class T>
void LinkedList<T>::InsertAt(T item, unsigned int index) {
    if (index == 0) {
        Append(item);
    } else if (size <= 0 && index != 0) {
        throw "EmptyList";
    } else if (index < 0 || index > size) {
        throw "IndexOutOfRange";
    } else {
        Node<T> *q = head;
        for (int i = 0; i < index - 1; ++i) {
            q = q->next;
        }
        Node<T> *tmp = (Node<T> *) malloc(sizeof(Node<T>));
        tmp->value = item;
        tmp->next = q->next;
        q->next = tmp;
        ++size;
    }
}

template<class T>
LinkedList<T> LinkedList<T>::Concat(LinkedList<T> *list) {
    LinkedList<T> res = LinkedList(*this);
    Node<T>*qq = list->head;
    while (qq != NULL) {
        res.Prepend(qq->value);
        qq = qq->next;
    }
    res.size = size + list->size;
    return res;
}


#endif //LAB2_V2_LINKEDLIST_H

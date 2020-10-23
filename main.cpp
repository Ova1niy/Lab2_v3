#include <iostream>
#include <cstdio>
#include <ctime>
#include "Comp/Comp.h"
#include "LinearForm/LinearForm.h"
#include "Sequence/Sequence.h"
#include "Sequence/ArraySequence.h"
#include "Sequence/ListSequence.h"
#include "Sorting/Sorting.h"
#include "Sorting/QuickSorting.h"
#include "Sorting/ShakeSorting.h"
#include <random>

using namespace std;

void TestInt () {
    LinearForm<int> l1 = LinearForm<int>(new ArraySequence<int>(10));
    for (int i = 0; i < l1.GetSize(); ++i) {
        l1.Set(i, i);
//        l1->Set(i, random() % 10);
    }
    LinearForm<int> l2 = LinearForm<int>(l1.GetSub(2, 6));
    for (int i = 0; i < l2.GetSize(); ++i) {
        l2.Set(i, i);
//        l2->Set(i, random() % 10);
    }
    LinearForm<int>*res = new LinearForm<int>(l2 - l1);
    cout << "l2 "; l2.Print();
    cout << "l1 "; l1.Print();
    cout << "res "; res->Print();
    cout << "------------\n";
    l1 /= 3;
    cout << "l1 "; l1.Print();
    l1 *= 3;
    cout << "l1 "; l1.Print();
    l2.Resize(l1.GetSize());
    cout << "l2 "; l2.Print();
    l2 /= 3;
    cout << "l2 "; l2.Print();
    cout << "l2 with l1 koefs " << l2.Calculate(&l1) << endl;
}
void TestComp () {
    LinearForm<Comp> l1 = LinearForm<Comp>(new ListSequence<Comp>(10));
    for (int i = 0; i < l1.GetSize(); ++i) {
        l1.Set(i, Comp(i, i));
//        l1->Set(i, random() % 10);
    }
    LinearForm<Comp> l2 = LinearForm<Comp>(l1.GetSub(2, 6));
    for (int i = 0; i < l2.GetSize(); ++i) {
        l2.Set(i, Comp(i, i));
//        l2->Set(i, random() % 10);
    }
    LinearForm<Comp>*res = new LinearForm<Comp>(l2 - l1);
    cout << "l2 "; l2.Print();
    cout << "l1 "; l1.Print();
    cout << "res "; res->Print();
    cout << "------------\n";
    l1 /= 3;
    cout << "l1 "; l1.Print();
    l1 *= 3;
    cout << "l1 "; l1.Print();
    l2.Resize(l1.GetSize());
    cout << "l2 "; l2.Print();
    l2 /= 3;
    cout << "l2 "; l2.Print();
    cout << "l2 with l1 koefs " << l2.Calculate(&l1) << endl;
}
void TestQuickSorting (int SIZE) {
    ArraySequence<int>* mySeq =  new ArraySequence<int>(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        mySeq->Set(i, int(random() % 100 + 1));
    }
    QuickSorting<int>* myQSort = new QuickSorting<int>();
    myQSort->sort(mySeq);
}

void TestShakeSorting (int SIZE) {
    ArraySequence<int>* mySeq =  new ArraySequence<int>(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        mySeq->Set(i, int(random() % 100 + 1));
    }
    ShakeSorting<int>* myShSort = new ShakeSorting<int>();
    myShSort->sort(mySeq);
}

template <class T>
void makeSeq (ArraySequence<T>* seq, int mode, int SIZE) {
    if (mode == 1) {
        int prev = 0;
        for (int i = 0; i < SIZE; ++i) {
            prev += random() % 100 + 1;
            seq->Set(i, prev + (random() % 100 + 1));
        }
    } else if (mode == 2) {
        int prev = 1000000;
        for (int i = 0; i < SIZE; ++i) {
            prev += random() % 100 + 1;
            seq->Set(i, prev - (random() % 100 + 1));
        }
    } else {
        for (int i = 0; i < SIZE; ++i) {
            seq->Set(i, (random() % 100 + 1));
        }
    }
}

int main() {
//    TestInt();
    string input = "";
    do {
        cout << "SUPER_SORT_3000\n"
                "Commands:\n"
                "QuickSort - проверить быструю сортировку\n"
                "ShakeSort - проверить шейкерную сортировку\n"
                "Compare - сравнить сортировки\n";
        cin >> input;
        if (input == "QuickSort") {
            int mode = 1;
            while (true) {
                cout << "Какая должна быть последовательность?\n"
                        "1 - Остсортирована в прямом порядке\n"
                        "2 - Отсортирована в обратном порядке\n"
                        "3 - Составлена из случайных чисел\n";
                cin >> mode;
                if (mode == 1 || mode == 2|| mode == 3) {
                    break;
                } else {
                    cout << "Неверный формат, повторите ввод!\n";
                }
            }
            int size = 0;
            while (size <= 0) {
                cout << "Введите размер последовательности > 0\n";
                cin >> size;
            }
            ArraySequence<int>* mySeq = new ArraySequence<int>(size);
            makeSeq(mySeq, mode, size);
            clock_t start = clock();
            QuickSorting<int>* myQSort = new QuickSorting<int>();
            myQSort->sort(mySeq);
            clock_t end = clock();
            double seconds = (double) (end - start) / CLOCKS_PER_SEC;
            cout << size << " elements -- " << seconds << endl;
        } else if (input == "ShakeSort") {
            int mode = 1;
            while (true) {
                cout << "Какая должна быть последовательность?\n"
                        "1 - Остсортирована в прямом порядке\n"
                        "2 - Отсортирована в обратном порядке\n"
                        "3 - Составлена из случайных чисел\n";
                cin >> mode;
                if (mode == 1 || mode == 2|| mode == 3) {
                    break;
                } else {
                    cout << "Неверный формат, повторите ввод!\n";
                }
            }
            int size = 0;
            while (size <= 0) {
                cout << "Введите размер последовательности > 0\n";
                cin >> size;
            }
            ArraySequence<int>* mySeq = new ArraySequence<int>(size);
            makeSeq(mySeq, mode, size);
            clock_t start = clock();
            ShakeSorting<int>* myShSort = new ShakeSorting<int>();
            myShSort->sort(mySeq);
            clock_t end = clock();
            double seconds = (double) (end - start) / CLOCKS_PER_SEC;
            cout << size << " elements -- " << seconds << endl;
        } else if (input == "Compare") {
            int mode = 1;
            while (true) {
                cout << "Какая должна быть последовательность?\n"
                        "1 - Остсортирована в прямом порядке\n"
                        "2 - Отсортирована в обратном порядке\n"
                        "3 - Составлена из случайных чисел\n";
                cin >> mode;
                if (mode == 1 || mode == 2|| mode == 3) {
                    break;
                } else {
                    cout << "Неверный формат, повторите ввод!\n";
                }
            }
            int size = 0;
            while (size <= 0) {
                cout << "Введите размер последовательности > 0\n";
                cin >> size;
            }
            ArraySequence<int>* seq1 = new ArraySequence<int>(size);
            makeSeq(seq1, mode, size);
            ArraySequence<int>* seq2 = new ArraySequence<int>(seq1);
            clock_t start1 = clock();
            ShakeSorting<int>* myShSort = new ShakeSorting<int>();
            myShSort->sort(seq1);
            clock_t end1 = clock();
            double seconds1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
            cout << "ShakeSort: " << size << " elements -- " << seconds1 << endl;
            clock_t start2 = clock();
            QuickSorting<int>* myQSort = new QuickSorting<int>();
            myQSort->sort(seq2);
            clock_t end2 = clock();
            double seconds2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
            cout << "QuickSort: " << size << " elements -- " << seconds2 << endl;
        } else if (input == "quit"){
            cout << "До свидания!\n";
        } else {
            cout << "Неверный формат, повторите ввод!\n";
        }
    } while (input != "quit");



//    int printTimePer = 10000;
//    for (int i = printTimePer; i < 1000000; i += printTimePer) {
//        clock_t start = clock();
//        TestQuickSorting(i);
//        clock_t end = clock();
//        double seconds = (double) (end - start) / CLOCKS_PER_SEC;
//        cout << i << " elements -- " << seconds << endl;
//    }
//    for (int i = printTimePer; i < 1000000; i += printTimePer) {
//        clock_t start = clock();
//        TestShakeSorting(i);
//        clock_t end = clock();
//        double seconds = (double) (end - start) / CLOCKS_PER_SEC;
//        cout << i << " elements -- " << seconds << endl;
//    }
    return 0;
}

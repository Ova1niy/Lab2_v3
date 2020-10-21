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

int main() {
//    TestInt();
    int printTimePer = 10000;
    for (int i = printTimePer; i < 1000000; i += printTimePer) {
        clock_t start = clock();
        TestQuickSorting(i);
        clock_t end = clock();
        double seconds = (double) (end - start) / CLOCKS_PER_SEC;
        cout << i << " elements -- " << seconds << endl;
    }
    for (int i = printTimePer; i < 1000000; i += printTimePer) {
        clock_t start = clock();
        TestShakeSorting(i);
        clock_t end = clock();
        double seconds = (double) (end - start) / CLOCKS_PER_SEC;
        cout << i << " elements -- " << seconds << endl;
    }
    return 0;
}

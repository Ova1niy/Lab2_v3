//
// Created by Ova1niy on 04/06/2020.
//

#include <iostream>
#include "../LinearForm/LinearForm.h"
#include <ctime>

using namespace std;

template<class T>
void InitializeRandom(LinearForm<T>* p, int range){
    for (int i = 0; i < p->GetSize(); ++i) {
        p->Set(i, rand() % range);
    }
}

void TestInt () {
    LinearForm<int>* l1 = new LinearForm<int>(new ArraySequence<int>(5));
    InitializeRandom(l1, 10);
    cout << "LinearForm #1\n";
    l1->Print();
    LinearForm<int>* l2 = new LinearForm<int>(new ArraySequence<int>(5));
    InitializeRandom(l2, 10);
    cout << "LinearForm #2\n";
    l2->Print();
}

int main () {
    TestInt();
    return 0;
}
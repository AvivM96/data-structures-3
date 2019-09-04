#include <iostream>

#include "heap.h"

int main() {
    int a[8] = {1, 2, 55, 19, 40, 3, 4, 234};
    Heap heap;
    for (int i : a) {
        string name("Bidder");
        Bidder bidder(i, name);
        heap.insertNode(bidder);
    }

    heap.print();
}
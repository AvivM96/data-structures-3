#include <utility>

#ifndef DATA_STRUCTURES_3_HEAP_H
#define DATA_STRUCTURES_3_HEAP_H

#include <vector>
#include "bidder.h"
#include <iostream>

using namespace std;

// Structure for the heap
class Heap {
    vector<Bidder> arr;
    int n; // Size of the heap

    // heapify bottom up
    void heapify_last_node(int i)
    {
        // Find parent
        int parent = (i - 1) / 2;

        if (arr[parent].getBid() > 0) {
            // For Max-Heap
            // If current node is greater than its parent
            // Swap both of them and call heapify again
            // for the parent
            if (arr[i].getBid() > arr[parent].getBid()) {
                swap(arr[i], arr[parent]);

                // Recursively heapify the parent node
                heapify_last_node(parent);
            }
        }
    }

public:

    explicit Heap()
    {
        n = 0;
        arr = vector<Bidder>();
    }

    static void swap(Bidder& a, Bidder& b)
    {
        Bidder temp = a;
        a = b;
        b = temp;
    }

    void insertNode(Bidder& newBidder)
    {
        // Increase the size of Heap by 1
        this->n = n + 1;

        // Insert the element at end of Heap
        arr.push_back(newBidder);

        heapify_last_node(n - 1);
    }

    // A utility function to print array of size n
    void print()
    {
        for (int i = 0; i < n; ++i)
            cout << this->arr[i].getBid() << " " << arr[i].getName() << endl;
        cout << "\n";
    }
};

#endif //DATA_STRUCTURES_3_HEAP_H

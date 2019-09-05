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
    void heapify_up(int i)
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
                heapify_up(parent);
            }
        }
    }
    void heapify_down(int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l].getBid() > arr[largest].getBid())
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r].getBid() > arr[largest].getBid())
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify_down(largest);
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
    Bidder& operator[]( int index )
    {
        return this->arr[index];
    }
    Bidder& GetRoot()
    {
        return arr[0];
    }
    void PopRoot()
    {
        // Get the last element
        Bidder lastBid = arr[n - 1];
        // Replace root with first element
        arr[0] = lastBid;
        // Decrease size of heap by 1
        n = n - 1;
        //removes the last element
        arr.pop_back();
        // heapify the root node
        heapify_down(0);
    }
    int GetSize()
    {
        return this->n;
    }
    void insertNode(Bidder& newBidder)
    {
        // Increase the size of Heap by 1
        this->n = n + 1;

        // Insert the element at end of Heap
        arr.push_back(newBidder);

        heapify_up(n - 1);
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

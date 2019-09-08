
#include "heap.h"
#include "bidder.h"
#ifndef DATA_STRUCTURES_3_PRIORITY_QUEUE_H
#define DATA_STRUCTURES_3_PRIORITY_QUEUE_H
class Priority_q {
    Heap H;
public:
    Priority_q()
    {
    }
    void Push(Bidder bid)
    {
        H.insertNode(bid);
    }
    void Pop()
    {
        H.PopRoot();
    }
    Bidder& Top()
    {
        return H[0];
    }

};
#endif //DATA_STRUCTURES_3_PRIORITY_QUEUE_H

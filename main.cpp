#include <iostream>
#include <ctime>
#include "heap.h"
#include "priority_queue.h"
inline int left(int i)
{
    return 2 * i + 1;
}
// Returns the index of
// the right child node
inline int right(int i)
{
    return 2 * i + 2;
}
int kBig(Heap &h,int k)
{
    Priority_q p;
    p.Push(h[0]);
    for (int i = 0; i <k - 1; ++i) {

        int l = left(i), r = right(i);
        p.Pop();
        if(l <h.GetSize())
            p.Push(h[l]);
        if(r<h.GetSize())
            p.Push(h[r]);

    }
    cout<<"The "<<k<<" bid is :"<<p.Top().getBid()<<endl;
    return p.Top().getBid();
}
void init_lottery(Heap & heap,int k)//Gets empty heap and k the number of participants
{
    int bid;
    string name("Bidder");
    srand(std::time(nullptr));
    for (int i=0;i<k;i++)
    {
        auto bid_name=name+"_"+to_string(i);
        bid=rand()%9999+1;
        Bidder bidder(bid, bid_name);
        heap.insertNode(bidder);
    }
}
void  Max_bid(Heap &h)// print winner details
{
    Bidder b=h.GetRoot();
    cout<< "winner name: "<< b.getName()<<endl;
    cout<< "winner bid: "<< b.getBid()<<endl;
}

int main() {
    Heap heap;
    init_lottery(heap,10);
    heap.print();
    kBig(heap,2);
    Max_bid(heap);
    //cout<< x;
}
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Item 
{
    int  x;    
    Item *next, *prev;
};

class LinkedList 
{
    private:
        Item *head_,*tail_;
        int   size_;
    
    public:
        LinkedList(): head_(NULL),tail_(NULL),size_(0){};
        ~LinkedList();
        
        void Print();
        void Add(int x);
        int  getSize();
        
        int operator[](int index);
};

LinkedList::~LinkedList() 
{
    while (head_) 
    {
        tail_ = head_->next;
        delete head_;
        head_ = tail_;
    }
    size_ = 0;
}

void LinkedList::Add(int x) 
{
    Item *temp   = new Item;
    temp -> next = NULL;
    temp -> x    = x;
    
    if (head_ != NULL) 
    {
        temp -> prev  = tail_;
        tail_ -> next = temp;
        tail_         = temp;
    } 
    else 
    {
        temp -> prev  = NULL;
        head_ = tail_ = temp;    
    }
    size_++;
}

int LinkedList::getSize()
{
    return size_;
}

void LinkedList::Print()
{
    Item *temp = head_;
    while (temp != NULL) 
    {
        cout << temp -> x << " ";
        temp = temp -> next; 
    }
    cout << endl;
}

int LinkedList::operator[] (int index)
{
    Item *temp = new Item;
    int i(0);
    
    for (temp = head_; temp != NULL; temp = temp -> next) 
    {
        if (i == index) 
        {
            return temp->x;    
        }
        i++;
    }
}

int main (int argc, char** argv)
{
    LinkedList linkedList;
    
    linkedList.Add(100); 
    linkedList.Add(200);
    linkedList.Add(900);
    linkedList.Add(888);
    
    linkedList.Print(); 
    for (int i=0; i < linkedList.getSize(); i++)
    {
        cout << i << " " << linkedList[i] << endl;
    }
    
    return 0;
}

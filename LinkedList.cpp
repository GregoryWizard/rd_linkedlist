#include "LinkedList.h"

// Constructor.
LinkedList::LinkedList()
{
    head_ = tail_ = NULL;
    size_ = 0;
}

// Destructor.
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

// Add int type to end of list.
void LinkedList::Add(int x) 
{
    Item* temp   = new Item;
    temp -> next = NULL;
    temp -> type = t_int; 
    temp -> x    = new int(x);
    
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

// Add double type to end of list.
void LinkedList::Add(double x) 
{
    Item* temp   = new Item;
    temp -> next = NULL;
    temp -> type = t_float; 
    temp -> x    = new float(x);
    
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

// Add string type to end of list.
void LinkedList::Add(string x) 
{
    Item* temp   = new Item;
    temp -> next = NULL;
    temp -> type = t_string; 
    temp -> x    = new string(x);
    
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

// Get size of list.
int LinkedList::getSize()
{
    return size_;
}

// Remove item from list by index.
void LinkedList::Remove(int index)
{
    Item* temp = head_;
    
    if (index < 0 || index > (size_ - 1))
    {
        cout << "Item with this index not founded." << endl;
    }
    
    // Delete first item in list.
    if (index == 0)
    {
        // If list is empty.
        if (size_ == 0)
        {
            cout << "List is empty." << endl;
            return;    
        }
        // If list have only 1 item.
        else if (size_ == 1)
        {
            head_   = NULL;
            tail_   = NULL;
            size_   = 0;
            return;
        }
        
        Item* buf   = temp -> next;
        
        buf -> prev = NULL;
        head_       = buf;
        size_--;
        return;
    }
    
    // Delete last item in list.
    if (index == size_ - 1)
    {
        Item* lastItem   = tail_;
        Item* prevItem   = tail_ -> prev;
        
        prevItem -> next = NULL;
        tail_            = prevItem;
        delete lastItem;
        size_--;
        return;
    }
    
    // Delete middle item in list.
    int i(0);
    while (temp -> next != NULL)
    {
        if (i+1 == index)
        {
            Item* deletedItem = temp -> next;
            Item* nextItem    = deletedItem -> next;
            
            temp     -> next = nextItem;
            nextItem -> prev = temp;
            
            delete deletedItem;
            size_--;        
            break;
        }
        temp = temp -> next;
        i++;
    }
    
}

// Print list.
void LinkedList::Print()
{
    Item* temp = head_;
    int i(0);
    
    cout << "List with " << size_ << " item(s):" << endl; 
    for (temp = head_; temp != NULL; temp = temp -> next) 
    {
        switch(temp->type)
        {
            case t_int:
                cout << "[" << i << " Type: int]: " << *((int*)(temp->x)) << endl;
                break;
                
            case t_float:
                cout << "[" << i << " Type: float]: " << *((float*)(temp->x)) << endl;
                break;
                
            case t_string:
                cout << "[" << i << " Type: string]: " << *((string*)(temp->x)) << endl;
                break;
        }
        i++;
    }
    
    cout << endl;
}
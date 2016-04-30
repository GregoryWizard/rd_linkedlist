#include <iostream>
using namespace std;

// Data types.
enum t_type { t_int,t_float,t_string };

// Struct of item in list.
struct Item 
{
    void*  x;    
    t_type type;
    Item*  next, *prev;
};

// List class.
class LinkedList 
{
    private:
        Item* head_, *tail_;
        int   size_;
    
    public:
        LinkedList();
        ~LinkedList();
        
        void Print();
        void Add(int x);
        void Add(double x);
        void Add(string x);
        void Remove(int index);
        int  getSize();    
        
};
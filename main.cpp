#include "LinkedList.h"

int main (int argc, char** argv)
{
    LinkedList linkedList;
    
    linkedList.Add(100); 
    linkedList.Add(900.85);
    linkedList.Add(888);
    linkedList.Add("hello world!");
    linkedList.Add(30); 
    linkedList.Add(11.85);
    
    linkedList.Print(); 
    
    // Delete first item.
    linkedList.Remove(0);
    linkedList.Print();
    
    // Delete last item.
    linkedList.Remove(linkedList.getSize()-1);
    linkedList.Print();
    
    // Delete middle item - 888.
    linkedList.Remove(1);
    linkedList.Print();
    
    return 0;
}
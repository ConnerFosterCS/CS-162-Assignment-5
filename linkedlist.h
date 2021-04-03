#include "linkedlistnode.h"

using namespace std;

class Linked_List : public Linked_List_Node {
    private:
        unsigned int length; // the number of nodes contained in the list
        Linked_List_Node *first; // a pointer to the first node in the list
        Linked_List_Node *last;
    public:
        //constructor & deconstructor
        Linked_List();
        ~Linked_List();

        //my functions
        float error();
        void get_val();
        void ui();
        void get_sort();
        bool prime_check(int n);
        int print_prime();
        void FrontBackSplit(Linked_List_Node* source, Linked_List_Node** frontRef, Linked_List_Node** backRef);
        int MergeSort(Linked_List_Node** headRef);
        Linked_List_Node* SortedMerge(Linked_List_Node* a, Linked_List_Node* b);

        //given functions
        int get_length();
        void print(); // output a list of all integers contained within the list
        void clear(); // delete the entire list (remove all nodes and reset length to 0)
        unsigned int push_front(int val); // insert a new value at the front of the list (returns the new length of the list)
        unsigned int push_back(int val); // insert a new value at the back of the list (returns the new length of the list)
        unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
        void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
        // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
        void sort_descending(); // sort the nodes in descending order
};
/**********************************************************************
 ** Program: assignment5.cpp (Linked Listing)
 ** Author: Conner Foster
 ** Date: 06/09/2019
 ** Decription: The objective of this program is to create a linked list and sort it with merge sorting.
 ** Ouput: ui to enter in numbers and a sorted list of the users choice.
 *********************************************************************/

#include <cstdlib>
#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
    Linked_List l;
    int n;
    //Linked_List_Node* a = NULL;
    
    cout << endl;
    l.get_val();
    l.ui();
    l.prime_check(n);
    l.print_prime();
    l.~Linked_List();
    //l.MergeSort(&a);
}
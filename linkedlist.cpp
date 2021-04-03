#include "linkedlist.h"

Linked_List::Linked_List() {
    this -> first = nullptr;
    this -> val = 0;
}

Linked_List::~Linked_List() {
    clear();
}

/*********************************************************************
** Function: error
** Description: This function takes all user input and makes sure that it is a float or an int.
** Parameters: none
** Pre-Conditions: user input = to function.
** Post-Conditions: i/user input or error msg.
*********************************************************************/ 
float Linked_List::error() {
	float i;
	string s;
	bool error;
	do {
		error = false;
		cin >> s;

		for (float i = 0; i < s.size(); i++) {
			if(!(s.at(i) >= '0' && s.at(i) <= '9')) {
				cout << "error: your input must be a number" << endl;
                cout << "Enter your input here: ";
				error = true;
                break;
			}
		}
	} while(error);
    
	i = atof(s.c_str());
    return i;
}

/*********************************************************************
** Function: get_val
** Description: This function takes user input for numbers and adds to end of list.
** Parameters: none
** Pre-Conditions: user inputs number.
** Post-Conditions: number added to list and list incremented by one.
*********************************************************************/ 
void Linked_List::get_val() {
    cout << "Enter a number: ";
    val = error();
    push_back(val);
}

/*********************************************************************
** Function: ui
** Description: This function controlls the user interface to make sure the functions run in the correct order.
*********************************************************************/ 
void Linked_List::ui() {
    char choice;
    int tf = 1;
    while (tf == 1) {
        cout << "Do you want to enter another num (y or n): ";
        cin >> choice;
        if (choice == 'y') {
            get_val();
        } else if (choice == 'n') {
            tf = 0;
        } else
            ui();
    } get_sort();
}

/*********************************************************************
** Function: get_sort
** Description: This function takes user input for the type of sorting they want.
** Parameters: none
** Pre-Conditions: user inputs a or d
** Post-Conditions: the correct sot function runs
*********************************************************************/ 
void Linked_List::get_sort() {
    char sort;
    cout << "Sort ascending or descending (a or d)? ";
    cin >> sort;
    
    if (sort == 'a') {
        sort_ascending();
    } else if (sort == 'd') {
        sort_descending();
    } else
        get_sort();    
}

/*********************************************************************
** Function: get_length
** Description: This function returns the length of the linked list
*********************************************************************/ 
int Linked_List::get_length() {
    return length;
} // note: there is no set_length(unsigned int) (the reasoning should be intuitive)

/*********************************************************************
** Function: print
** Description: This function prints the list to the screen
** Parameters: none
** Pre-Conditions: list must have 1 number
** Post-Conditions: list is printed to terminal
*********************************************************************/ 
void Linked_List::print() {
    Linked_List_Node *first = this -> first;
    int i = 1;
    while(first){
        cout << first -> val << "  ";
        first = first -> next;
        i++;
    } cout << endl;
    //exit(0);
} // output a list of all integers contained within the list

/*********************************************************************
** Function: clear
** Description: This function frees all of the pointers and sets them equal to null.
*********************************************************************/ 
void Linked_List::clear() {
    Linked_List_Node* tmp = first;
    Linked_List_Node* node;
    while(tmp!=NULL) {
        node = tmp->next;
        free(tmp);
        tmp = node;
    } first = NULL;
    length = 0;
} // delete the entire list (remove all nodes and reset length to 0)

/*********************************************************************
** Function: push_front
** Description: This function takes user number input and adds it to the front of the list
** Parameters: int value
** Pre-Conditions: user chooses to push to front
** Post-Conditions: the number is added to front of list
*********************************************************************/ 
unsigned int Linked_List::push_front(int val) {
    Linked_List_Node *temp = new Linked_List_Node();
    temp -> val = val;
    temp -> next = first;
    first = temp;
    length++;
    return length;
} // insert a new value at the front of the list (returns the new length of the list)

/*
This info was learned from https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
This article teaches about linked listing and was published by Codementor Team on Dec 08, 2016
*/
/*********************************************************************
** Function: push_front
** Description: This function takes user number input and adds it to the back of the list
** Parameters: int val
** Pre-Conditions: user chooses to push to back
** Post-Conditions: the number is added to back of list
*********************************************************************/ 
unsigned int Linked_List::push_back(int val) {
    Linked_List_Node* tmp = new Linked_List_Node();
    if (first != NULL) {
        tmp -> val = val;
        last -> next = tmp;
        last = tmp;
    } else if (first == NULL) {
        tmp -> val = val;
        first = tmp;
        last = tmp;
    } else {
        tmp -> val = val;
        last = tmp;
    } length++;
    return length;
} // insert a new value at the back of the list (ret urns the new length of the list)

/*********************************************************************
** Function: insert
** Description: This function takes user number input and adds it to the insert position of the list
** Parameters: int val, unsigned int index
** Pre-Conditions: user chooses to insert at certain location
** Post-Conditions: the number is added to isertion point
*********************************************************************/ 
unsigned int Linked_List::insert(int val, unsigned int index) {
    Linked_List_Node *pre=new Linked_List();
    Linked_List_Node *cur=new Linked_List();
    Linked_List_Node *temp=new Linked_List();
    cur = first;
    for(int i=1; i<index; i++) {
      pre = cur;
      cur = cur -> next;
    }
    temp -> val = val;
    pre -> next = temp;	
    temp -> next = cur;
    length++;
    return length;
} // insert a new value in the list at the specified index (returns the new length of the list)

/*********************************************************************
** Function: sort_ascending
** Description: This function sorts the list in ascending order
*********************************************************************/ 
void Linked_List::sort_ascending() {
    Linked_List_Node *i, *j;
    int tmp;

    for (i=first; i->next!=NULL; i=i->next) {
        for (j=i->next; j!=NULL; j=j->next) {
            if (i->val > j->val) {
                tmp = i->val;
                i->val = j->val;
                j->val = tmp;
            }
        }
    } cout << "\nASCENDING: ";
    print();
} // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.

/*********************************************************************
** Function: sort_decending
** Description: This function sorts the list in decending order
*********************************************************************/ 
void Linked_List::sort_descending() {
Linked_List_Node *i, *j;
    int tmp;

    for (i=first; i->next!=NULL; i=i->next) {
        for (j=i->next; j!=NULL; j=j->next) {
            if (i->val < j->val) {
                tmp = i->val;
                i->val = j->val;
                j->val = tmp;
            }
        }
    } cout << "\nDECENDING: ";
    print();
} // sort the nodes in descending order
// you can add extra member variables or functions as desired

/*********************************************************************
** Function: prime_check
** Description: This function takes the linked list and returns true when a prime number is found
** Parameters: int num
*********************************************************************/ 
bool Linked_List::prime_check(int num) { 
    // edge cases 
    if (num <= 1) 
        return false; 
    if (num <= 3) 
        return true; 
  
    // This is checked to skip middle five numbers in loop below 
    if (num % 2 == 0 || num % 3 == 0) 
        return false; 

    //checks numbers after 5
    for (int i=5; i*i<=num; i=i+6) 
        if (num%i==0 || num%(i+2)==0) 
            return false; 
    return true; 
} 

/*********************************************************************
** Function: print_prime
** Description: This function check the true or false returns from the function above and prints if it is prime
*********************************************************************/ 
// Function print prime numbers when true is returned
int Linked_List::print_prime() { 
    int count = 0; 
    Linked_List_Node* ptr = first; 
    cout << "PRIME NUMBERS: ";

    while (ptr != NULL) { 
        // If current node is prime 
        if (prime_check(ptr->val)) { 
            // Update count 
            cout << ptr -> val << "  ";
            count++;
        } ptr = ptr->next; 
    } cout << "\nThere are " << count << " prime numbers." << endl; 
    cout << endl; 
    return count; 
} 
/*********************************************************************
** TA PLEASE READ!!: These are my merge sorting functions that was getting a seg fault. The seg fault it happening on line 293.
*********************************************************************/ 
void Linked_List::FrontBackSplit(Linked_List_Node* source, Linked_List_Node** frontRef, Linked_List_Node** backRef) { 
    Linked_List_Node* fast; 
    Linked_List_Node* slow; 
    slow = source; 
    fast = source->next;
    
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

int Linked_List::MergeSort(Linked_List_Node** headRef) { 
    Linked_List_Node* first = *headRef; 
    Linked_List_Node* a; 
    Linked_List_Node* b; 
    
    /* Base case -- length 0 or 1 */
    if (get_length() < 2) { 
        return 0; 
    } 
    
    /* Split first into 'a' and 'b' sublists */
    FrontBackSplit(first, &a, &b); 
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
}    

Linked_List_Node* Linked_List::SortedMerge(Linked_List_Node* a, Linked_List_Node* b) { 
    Linked_List_Node* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->val <= b->val) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
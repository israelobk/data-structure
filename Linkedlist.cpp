#include<iostream>
#include<string>

using namespace std;

struct Item {
    int day;
    string dayname;
    Item *next;
};


void buildList3(Item*&, int dayofweek = 0);
void displayList(Item*);

/***********************
    global constants
***********************/
const int DAYS = 7;
const string days[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

/**********************************************************
    creates a singly linked list of the days of the week
**********************************************************/

void buildList3(Item*& last_ptr, int dayofweek) {
    
    if (dayofweek < DAYS) {
        last_ptr = new Item;
        last_ptr->day = dayofweek;
        last_ptr->dayname = days[dayofweek];
        buildList3(last_ptr->next, dayofweek + 1);
    } else
        last_ptr = NULL;
}


/**********************************************************
    displays a singly linked list of the days of the week
**********************************************************/
void displayList(Item *head) {
    Item *current = head;

    cout << "Listing the days of the week" << endl;
    cout << "============================" << endl;
    for(int i=0; i<DAYS && current != NULL; i++){
        cout << current->day << ": " << current->dayname << endl;
        current = current->next;
    }
}


/********************************************************************
    creates a head pointer, sends it to buildList, then displayList
********************************************************************/
int main() {

    Item *headptr = NULL;


    buildList3(headptr);
    displayList(headptr);

    return 0;
}
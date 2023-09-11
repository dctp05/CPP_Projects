/* Author: Dylan Cohen
 * Course: Data Structures
 * Taught by: Professor Nojoumian
 * Date: April 6th, 2023
 */

#include <iostream>

using namespace std;

/* Define the structure for a double linked list
 with two pointers for the nodes to the left and
 right. These pointers are pointing to nodes that
 are of this structure type. */
struct d_linked_list{
    struct d_linked_list *left;
    int data;
    struct d_linked_list *right;
};

// Rename double linked list to node for convenience
typedef struct d_linked_list node;

// Define a node pointer 'start' to store the 
//  starting node address of the list
node *start = nullptr;

node* get_node();                   //Create node and return pointer to node address
void create_list(int n);            //Use user input to create linked list
void traverse();                    //Displays data of each node in linked list
int count_node(node *start_ptr);    //Count number of nodes in list, return int
void insert_beg();                  //Insert node at beginning of list
void delete_end();                  //Delete last node of list

int main(){
    int b;
    cout << sizeof(long);
    
    //Declare var to store number of nodes for the list
    int num_nodes;

    //Prompt and store input from user
    cout << "How many nodes in the list? ";
    cin >> num_nodes;

    //Call create_list to make list of num_nodes size
    //  then display data in list with traverse
    create_list(num_nodes);
    traverse();

    //Call insert_beg, and display new list after
    insert_beg();
    traverse();

    //Call delete_end, and display new list data after
    delete_end();
    traverse();

    //Exit program
    return 0;
}

node *get_node(){
    //Declare new node pointer
    node *new_node;

    //Dynamically allocate memory with 'new' keyword
    //  size determined by struct 'node'
    new_node = new node;

    //Prompt and store int to 'data' in node
    cout << "Enter data: ";
    cin >> new_node->data;

    //Initialize 'right' and 'left' pointers to nullptr
    //  to be assigned by functions
    new_node->right = nullptr;
    new_node->left = nullptr;

    //Return node pointer to function calling the method
    return new_node;
}

void create_list(int n){

    //Display the number of nodes being created
    cout << "-----Creating " << n << " nodes-----" << endl;
    
    //Declare two node pointers to keep track of position
    //  in the list
    node *new_node, *temp;
    
    //Initialize for loop to run 'n' times
    int i;
    for(i=0; i<n; i++){
        //Store pointer of node in 'new_node'
        new_node = get_node();

        //If it's the first time through the for loop,
        //  set 'start' pointer to point to the new node
        if (start == nullptr){
            start = new_node;
        }

        //Otherwise, get to last node and add new_node after
        else{
            //Start temp at start of list
            temp = start;

            //Get to the last node
            while(temp->right != nullptr){
                temp = temp->right;
            }

            //Set last node to point right to new node, and the new
            //  node to point left to the last, making new last node
            temp->right = new_node;
            new_node->left = temp;
        }
    }
}

void traverse(){
    //If list empty, alert user and return to program
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }

    //Declare temp node ptr to start, display note to user
    node *temp=start;
    cout << "The contents from left to right, then right to left: " << endl;

    //Print out temp data, go to node at right pointer, and
    //  repeat until end of list
    while(temp->right != nullptr){
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << temp->data << endl;     //extra print for last node

    //Same as above, but going right to left, to assure left pointer accuracy
    while(temp->left != nullptr){
        cout << temp->data << " ";
        temp = temp->left;
    }
    cout << temp->data << endl;     //extra print for last node
}

int count_node(node *start_ptr){

    //initialize temp pointer to pointer passed in param
    node *temp=start_ptr;
    int ctr=1;

    //if list empty, go back to method
    if(temp == nullptr)
        return 0;
    
    //Increment ctr and shift temp to right node pointer,
    //  until end of list
    while(temp->right != nullptr){
        temp = temp->right;
        ctr++;
    }

    //Return length of list
    return ctr;
}

void insert_beg(){

    //Display function info, declare 'temp' and 'new_node' node pointers
    cout << "-----Inserting node at beginning-----" << endl;
    node *temp, *new_node;

    //Get new node and make new_node point to its address
    new_node = get_node();

    //If list is empty, insert at beginning and exit function
    if(start == nullptr){
        start = new_node;
        return;
    }

    //Otherwise, 
    temp = start;               //make temp point to address of beginning of list
    start = new_node;           //make start point to address of new_node
    start->right = temp;        //make start node right pointer point to old beginning
    temp->left = new_node;      //make old beginning left pointer point to new start
}

void delete_end(){

    //Display info about function
    cout << "-----Deleting node at end-----" << endl;

    //If empty list, alert user and exit function
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }

    //Otherwise, if only one node, delete node at start pointer address,
    //  and set start address to null
    else if(count_node(start) == 1){
        delete start;
        start = nullptr;
        return;
    }

    //Declare prev and temp node pointers, and make them point to start node
    node *prev, *temp;
    prev = start;
    temp = start;

    //Shift temp to right pointer until temp is at last,
    //  and prev is one before last
    while(temp->right != nullptr){
        prev = temp;
        temp = temp->right;
    }

    //Make node pointed to by prev->right the last node, and free the
    //  memory of the old last node with delete keyword
    prev->right = nullptr;
    delete temp;
}
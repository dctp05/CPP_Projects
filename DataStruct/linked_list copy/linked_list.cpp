/* Author: Dylan Cohen
 * Course: Data Structures
 * Taught by: Professor Nojoumian
 * Date: April 6th, 2023
 */

#include <iostream>

using namespace std;

/* Define the structure for a single linked list
 with a pointers for the node to the right. The pointer
 is pointing to a node of this structure type. */
struct s_linked_list{
    int data;
    struct s_linked_list *next;
};

// Rename single linked list to node for convenience
typedef struct s_linked_list node;

// Define a node pointer 'start' to store the 
//  starting node address of the list
node *start = nullptr;

node *get_node();                       //Create node and return pointer to node address
void create_list(int n);                //Use user input to create linked list
void traverse();                        //Displays data of each node in linked list
int count_node(node *start_ptr);        //Count number of nodes in list, return int
void insert_mid();                      //Insert node at middle of list det by user input
void delete_mid();                      //Delete node in middle of list det by user input

int main(){
    //Declare var to store number of nodes for the list
    int num_nodes;

    //Prompt and store input from user
    cout << "How many nodes in the list? ";
    cin >> num_nodes;

    //Call create_list to make list of num_nodes size
    //  then display data in list with traverse
    create_list(num_nodes);
    traverse();

    //Call insert_mid, and display new list after
    insert_mid();
    traverse();

    //Call delete_mid, and display new list data after
    delete_mid();
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

    //Initialize node next pointer to nullptr
    new_node->next = nullptr;

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
            while(temp->next != nullptr){
                temp = temp->next;
            }
            //set the last node->next to point to new node
            temp->next = new_node;
        }
    }
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
    while(temp->next != nullptr){
        temp = temp->next;
        ctr++;
    }

    //Return length of list
    return ctr;
}

void traverse(){
    cout << "The list contents from left to right:" << endl;
    if(start == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    node* temp;
    temp = start;
    while(temp->next != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void insert_mid(){
    //Display info
    cout << "-----Inserting node in middle-----" << endl;

    //Initialize and set a new node
    node *new_node;
    new_node = get_node();

    //If empty insert at beginning and exit function
    if(start == nullptr){
        start = new_node;
        return;
    }
    //initialize temp and prev node ptr, plus a ctr
    node *prev, *temp;
    int pos, node_ctr, ctr=1;

    //get number of nodes in list
    node_ctr = count_node(start);

    //prompt and store pos to insert
    cout << "Enter the position: ";
    cin >> pos;

    //if valid position
    if(pos > 1 && pos <= node_ctr){
        //initialize to start node
        temp = start;
        prev = start;

        //advance until temp is right before desired pos
        //  and prev is one before that
        while(ctr < pos){
            prev = temp;
            temp = temp->next;
            ctr++;
        }

        //assign prev node to new node
        //  and new_node to temp to insert at position
        prev->next = new_node;
        new_node->next = temp;
    }

    //if invalid position, alert user
    else cout << "Not a valid position" << endl;
}

void delete_mid(){

    //display info
    cout << "-----Deleting node in middle-----" << endl;

    //alert if empty
	if(start == nullptr){
		cout << "List is empty!" << endl;
		return;
	}

    //Must have 3 nodes to delete in middle
    else if(count_node(start) < 3){
        cout << "Not enough nodes to delete in the middle!" << endl;
        return;
    }

    //initialize vars
	node *temp, *prev;
    int ctr=1, pos, node_ctr;
    cout << "Enter the position: ";
    cin >> pos;
    node_ctr = count_node(start);

    //invalid position exit function
    if(pos > node_ctr || pos < 2){
        cout << "Invalid position" << endl;
        return;
    }

    temp = start;
    prev = start;
    //Get to position
    while(ctr < pos){
        prev = temp;
        temp = temp->next;
        ctr++;
    }
    //assign pointers and free memory of unused node
    prev->next = temp->next;
    delete temp;
}

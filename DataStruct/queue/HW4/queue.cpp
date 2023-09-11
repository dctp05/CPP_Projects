#include <nullptrptriostream>

using namespace std;

//Define structure of entry in the queue, with one
//  pointer to the next entry in the queue, and
//  placeholder data of type int
struct s_linked_list{
    int data;
    struct s_linked_list *next;
};

//Redefine linked list type as single entry in a queue
typedef struct s_linked_list entry;

//Define pointer to front and rear of the queue
entry *front = nullptr;
entry *rear = nullptr;

entry * get_entry(int data);
void insert_entry(entry *new_entry);
void delete_entry();
void display_queue();

int main() {
    display_queue();
    delete_entry();
    for(int i=0; i<10; i++){
        insert_entry(get_entry(i));
        display_queue();
    }
    for(int i=0; i<10; i++){
        delete_entry();
        display_queue();
    }
    delete_entry();

    return 0;
}

entry * get_entry(int data){
    entry *new_entry;
    new_entry = new entry;
    new_entry->data = data;
    new_entry->next = nullptr;
    return new_entry;
}

void insert_entry(entry *new_entry){
    cout << "Inserting '" << new_entry->data << "' into the queue..." << endl;
    if(front == nullptr){
        front = new_entry;
        rear = new_entry;
        return;
    }
    rear->next = new_entry;
    rear = new_entry;
}

void delete_entry(){
    cout << "Deleting entry at front of queue..." << endl;
    if(front == nullptr){
        cout << "Nothing to delete, queue is empty!" << endl << endl;
        return;
    }
    else if(front == rear){
        delete front;
        front = nullptr;
        rear = nullptr;
        return;
    }
    entry *temp = front;
    front = front->next;
    temp->next = nullptr;
    delete temp;
}

void display_queue(){
    cout << "Queue entry data displayed front to rear: " << endl;
    if(front == nullptr){
        cout << "Queue is empty!" << endl << endl;
        return;
    }
    entry *temp = front;
    int j=1;
    do {
        if(temp == rear){
            cout << j << ": " << temp->data << endl;
            break;
        }
        cout << j << ": " << temp->data << " | ";
        temp = temp->next;
        j++;
    } while(1);
    cout << endl;
}
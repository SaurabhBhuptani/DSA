#include <iostream>
using namespace std;

class Node{

public:

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Singly_Linked_List{

private:

    Node* head;

public:

    Singly_Linked_List(){
        head = nullptr;
    }

    void insert_at_begin(int data){
        Node* new_node = new Node(data);
        if (head == nullptr){
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    void insert_at_end(int data){
        Node* new_node = new Node(data);
        if (head == nullptr){
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        if (head == nullptr){
            cout << "Empty Linked List" << endl;
            return;
        }
        Node* temp = head;
        cout << "Displaying linked list : ";
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int key){
        if (head == nullptr){
            cout << "Empty Linked List" << endl;
            return false;
        }
        Node* temp = head;
        while (temp != nullptr){
            if (temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int count(int key){
        if (head == nullptr){
            cout << "Empty Linked List" << endl;
            return -1;
        }
        int cnt = 0;
        Node* temp = head;
        while (temp != nullptr){
            if (temp->data == key){
                cnt++;
            }
            temp = temp->next;
        }
        return cnt;
    }
};

int main()
{
    Singly_Linked_List list;

    list.insert_at_begin(5);
    list.insert_at_begin(7);
    list.insert_at_begin(9);
    list.insert_at_begin(3);

    list.insert_at_end(1);
    list.insert_at_end(10);
    list.insert_at_end(10);
    list.insert_at_end(15);

    list.display();

    cout << "The count of 7 is : " << list.count(7) << endl;
    cout << "The count of 10 is : " << list.count(10) << endl;

    list.search(10)? cout << "Element found" << endl : cout << "Element not found" << endl;
    list.search(16)? cout << "Element found" << endl : cout << "Element not found" << endl;

    return 0;
}
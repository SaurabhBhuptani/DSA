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

    Node* get_head(){
        return head;
    }

    void display(){
        if (head == nullptr){
            cout << "Empty Linked List" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
};

class List_Operations{

public:

    void merging(Node* list1, Node* list2){
        Singly_Linked_List result;
        Node* temp1 = list1;
        Node* temp2 = list2;
        int dat = INT16_MAX;
        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1->data < temp2->data){
                if (temp1->data == dat){
                    temp1 = temp1->next;
                }else{
                    dat = temp1->data;
                    result.insert_at_end(temp1->data);
                    temp1 = temp1->next;
                }
            }else{
                if (temp2->data == dat){
                    temp2 = temp2->next;
                }else{
                    dat = temp2->data;
                    result.insert_at_end(temp2->data);
                    temp2 = temp2->next;
                }
            }
        }
        while (temp1 != nullptr){
            result.insert_at_end(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr){
            result.insert_at_end(temp2->data);
            temp2 = temp2->next;
        }
        result.display();
    }
};

int main()
{
    Singly_Linked_List list1;
    Singly_Linked_List list2;
    List_Operations op;

    list1.insert_at_end(2);
    list1.insert_at_end(3);
    list1.insert_at_end(5);
    list1.insert_at_end(7);
    list1.insert_at_end(9);
    list2.insert_at_end(1);
    list2.insert_at_end(3);
    list2.insert_at_end(4);
    list2.insert_at_end(6);

    cout << "list 1 : ";
    list1.display();
    cout << "list 2 : ";
    list2.display();
    cout << "Merged list : ";
    op.merging(list1.get_head(), list2.get_head());
    
    return 0;
}
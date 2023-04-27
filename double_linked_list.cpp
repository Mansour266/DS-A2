/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: single linked list
 * Last Modification Date: 11/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: Implement double linked list from scratch.
 */

#include <bits/stdc++.h>

using namespace std;


template <typename T>

class Node{

public:
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node(){
        next = nullptr;
        prev = nullptr;
    }

    Node(T element){
        this->data = element;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(T element, Node prv = nullptr, Node nxt = nullptr){
        this->data = element;
        this->prev = prv;
        this->next = nxt;
    }

};

template<typename T>

class double_linked_list{

public:
    Node<T> *head;
    Node<T> *tail;

    double_linked_list(){
        head = nullptr;
        tail = nullptr;
    }

    void insert_at_head(T element){
        Node<T> *node = new Node<T>;
        node->data = element;
        if(head == nullptr){
            head = node;
            tail = node;
            return;
        }
        node->next = head;
        head = node;
        node->next->prev = head;


    }

    void insert_at_tail(T element){
        Node<T> *node = new Node<T>;
        node->data = element;

        //if the node is the first element or no head exists we assign the node to head.
        if(head == nullptr){
            head = node;
            tail = node;
            return;
        }
        node->prev = tail;
        tail = node;
        node->prev->next = tail;


    }

    void insert_at(T element, int index){
        Node<T> *node = new Node<T>;
        node->data = element;

        Node<T> *temp = head;

        int count{0};
        while (temp->next != nullptr && count < index) {
            if(count == index - 1){
                /*
                 * we check if the there is an element after the required index we shift them
                 * otherwise just add the element.
                */
                if(temp->next != nullptr){
                    node->next = temp->next;
                    node->prev = temp->prev;
                }
                temp->next = node;
                node->prev = temp;
                break;
            }
            //increase count the move on to the next element.
            count++;
            temp = temp->next;

        }
        //this should add the last element of the list and modify the tail to be the last element.
        if(temp == tail) {
            temp->next = node;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insert_after(Node<T> *previous, T element){
       Node<T> *node = new Node<T>;
       node->data = element;
       node->next = previous->next;
       node->prev = previous;
       previous->next = node;
       node->next->prev = node;
       if(previous->next == tail)
           tail = node->next;
    }

    void remove_at_head(){
        Node<T> *node = head;
        head = node->next;
        node->next->prev = nullptr;
    }

    void remove_at_tail(){
        Node<T> *node = tail;
        tail = node->prev;
        node->prev->next = nullptr;
    }

    void remove_at(int index){
        Node<T> *node = head;

        //This should handle the head case
        if(index == 0){
            remove_at_head();
            return;
        }
        //decrement the index to get the item before the removed element
        index--;
        while (index--)
            node = node->next;

        //This should handle the tail case
        if(node->next == tail){
            remove_at_tail();
        }
        //This should handle the elements between the head and tail.
        else {
            node->next = node->next->next;
            node->next->prev = node;
        }
    }

    T retrieve_at(int index){
        Node<T> *node = new Node<T>;
        node = head;

        while (index--){
            if(node->next == nullptr) {
                cout << "Out of index\n";
                cout << "This is the last element: ";
                break;
            }
            node = node->next;
        }

        return node->data;
    }

    void replace_at(T element, int index){
        Node<T> *node = head;
        while (index--){
            node = node->next;
        }
        node->data = element;
    }

    bool is_exist(T element){
        Node<T> *node = head;

        //This should check the head and tail if the element is found in them otherwise loop through all elements.
        if(head->data == element || tail->data == element)
            return true;
        while (node->next != nullptr){
            if(node->data == element)
                return true;

            node = node->next;
        }
        return false;
    }

    bool is_item_at_equal(T element, int index){
        Node<T> *node = head;
        while (index--)
            node = node->next;

        return node->data == element;
    }

    int double_linked_list_size(){
        int size{0};
        if(head != nullptr){
            size++;
            Node<T> *node = head;
            while (node->next != nullptr){
                node = node->next;
                size++;
            }
        }

        return size;
    }

    //Swap is still not working
    void swap(int first_index, int second_index){

        //This should check if the two indexes are similar or if one of them is out of range then exit
        if (first_index == second_index || first_index < 0 || second_index < 0 || first_index >= double_linked_list_size()
        || second_index >= double_linked_list_size()) {
            return;
        }

        Node<T> *current_first = head, *current_second = head;

        while (first_index--){
            current_first = current_first->next;
        }

        while (second_index--){
            current_second = current_second->next;
        }

        Node<T>* temp;
        temp = current_first->next;
        current_first->next = current_second->next;
        current_second->next = temp;

        if (current_first->next != nullptr)
            current_first->next->prev = current_first;
        if (current_second->next != nullptr)
            current_second->next->prev = current_second;

        temp = current_first->prev;
        current_first->prev = current_second->prev;
        current_second->prev = temp;

        if (current_first->prev != nullptr)
            current_first->prev->next = current_first;
        if (current_second->prev != nullptr)
            current_second->prev->next = current_second;

        //This should swap the head and tail
        if(current_first == head)
            head = current_second;
        else if(current_second == head)
            head = current_first;

        if(current_first == tail)
            tail = current_second;

        else if(current_second == tail)
            tail = current_first;

    }

    void reverse(){
        Node<T> *current = head;

        while (current != nullptr)
        {
            //This should swap all the previous and next pointers of each element
            //swap(current->next, current->prev);
            current = current->prev;
        }
        //This should finish by swapping the head and tail.
        //swap(head, tail);

    }

    bool is_empty(){
        return head == nullptr;
    }


    //See about freeing memory
    void clear(){
        head = tail = nullptr;
    }

    void forward_print(){
        Node<T> *node = head;
        //protective condition
        if(head == nullptr)
            return;

        while (node->next != nullptr){
            cout << node->data << ' ';
            node = node->next;
        }
        //print last element
        cout << tail->data << '\n';
    }

    void backward_print(){
        Node<T> *node = tail;
        if(head == nullptr)
            return;

        while (node->prev != nullptr){
            cout << node->data << ' ';
            node = node->prev;
        }
        cout << head->data << '\n';
    }

};


int main(){
    double_linked_list<int> dll;
    dll.insert_at_tail(5);
    dll.insert_at_tail(6);
    dll.insert_at_tail(7);
    dll.insert_at_tail(8);
    dll.insert_at_tail(9);

   dll.swap(3,4);
   dll.forward_print();

}





















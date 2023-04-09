/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: single linked list
 * Last Modification Date: 9/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: Implement single linked list from scratch.
 */

#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Node{
public:
    T data;
    Node<T> *next;

    //Default constructor
    Node(){
        data = 0;
        next = nullptr;
    }

    //element only constructor
    Node(T element){
        this->data = element;
        this->next = nullptr;
    }

    //Full data constructor
    Node(T element, Node ptr = nullptr){
        this->data = element;
        this->next = ptr;
    }
};

template <typename T>
class array_list{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    array_list(){
        head = nullptr;
    }

    void insert_at_head(T element){
        Node<T> *node = new Node<T>;
        node->data = element;

        //if the node is the first element or no head exists we assign the node to head.
        if(head == nullptr){
            head = node;
            tail = node;
            return;
        }

        node->next = head;
        head = node;

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

        //if head already exists we start from head and move to the last elements then add the node.
        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = node;
        tail = node;

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
                }
                temp->next = node;
                break;
            }
            //increase count the move on to the next element.
            count++;
            temp = temp->next;
        }
        //this should add the last element of the list and modify the tail to be the last element.
        temp->next = node;
        tail = node;
    }

    T retrieve_at(int index){
        Node<T> *node = new Node<T>;
        node = head;

        while (index--){
            node = node->next;
        }

        return node->data;
    }

    void remove_at_head(){
        Node<T> *node = head;

        head = node->next;
    }

    void remove_at_tail(){

        //if head already exists we start from head and move to the last elements then add the node.
        Node<T> *temp = head;
        while (temp->next != tail)
            temp = temp->next;

        temp->next = nullptr;
        tail = temp;
    }

    void remove_at(int index){
        Node<T> *node = new Node<T>;
        node = head;
        //decremenet the index to get the item before the removed element
        index--;
        while (index--)
            node = node->next;
        node->next = node->next->next;
    }

    void replace_at(T element, int index){
        Node<T> *node = new Node<T>;
        node = head;
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
        Node<T> *node = new Node<T>;
        node = head;
        while (index--)
            node = node->next;

        return node->data == element;
    }

    void swap(int first_index, int second_index){

    }

    bool is_empty(){
        return head == nullptr;
    }

    //try to make static variable for better performance
    int linked_list_size(){
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


};


int main(){
    array_list<int> ls;

    ls.insert_at_tail(4);
    ls.insert_at_tail(4);
    ls.insert_at_tail(4);
    ls.insert_at_tail(4);

    cout << ls.linked_list_size();

}
/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: array linked list
 * Last Modification Date: 9/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: Implement array based linked list from scratch.
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

public:
    array_list(){
        head = nullptr;
    }

    void insert(T element){
        Node<T> *node = new Node<T>;
        node->data = element;

        //if the node is the first element or no head exists we assign the node to head.
        if(head == nullptr){
            head = node;
            return;
        }

        //if head already exists we start from head and move to the last elements then add the node.
        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = node;
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
            //increase count the move on to the first element.
            count++;
            temp = temp->next;
        }
        //this should add the last element of the list.
        temp->next = node;
    }

    T retrieve_at(int index){
        Node<T> *node = new Node<T>;
        node = head;

        while (index--){
            node = node->next;
        }

        return node->data;
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

    bool is_item_at_equal(T element, int index){
        Node<T> *node = new Node<T>;
        node = head;
        while (index--)
            node = node->next;

        return node->data == element;
    }

    bool is_empty(){
        return head == nullptr;
    }

};


int main(){
    array_list<int> ls;
    ls.insert(4);
    ls.insert(1);
    ls.insert(7);
    ls.insert(9);
    ls.insert(2);


}
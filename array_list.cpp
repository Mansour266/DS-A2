/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: array linked list
 * Last Modification Date: 24/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: Implement array based list from scratch.
 */

#include <iostream>

using namespace std;

template <typename T>
class array_list{
private:
    T *arr;
    int capacity;
    int max_length;

public:

    array_list(){
        arr = new T[1];
        capacity = 1;
        max_length = 0;
    }

    array_list(int size){
        if(size <= 0)
            cout << "Wrong size\n";
        else{
           max_length = size;
           capacity = 0;
           arr = new T[size];
        }
    }

    ~array_list(){
        delete[] arr;
    }

    bool is_empty(){
        return capacity == 0;
    }

    bool is_full(){
        return capacity == max_length;
    }

    int list_size(){
        return capacity;
    }

    int max_list_size(){
        return max_length;
    }

    void insert(T element){
        if(is_full())
            cout << "List is full\n";
        else{
            arr[capacity] = element;
            capacity++;
        }
    }

    void insert_at(T element, int indx){
        if(is_full())
            cout << "List is full\n";
        else if(indx < 0 || indx > max_length){
            cout << "Out of bounds\n";
        }
        else{
            for(int i = capacity; i > indx; i--)
                arr[i] = arr[i - 1];	//shift right

            arr[indx] = element;
            capacity++;
        }

    }

    T retrieve_at(int indx){
        if(indx < 0 || indx > max_length)
            cout << "Out of bounds\n";
        else
            return arr[indx];
    }

    void remove_at(int indx){
        if(indx < 0 || indx >= capacity)
            cout << "Out of bounds\n";
        else
        {
            //shift the items located after the element
            for(int i = indx; i < capacity - 1; i++)
                arr[i] = arr[i+1];

            capacity--;
        }
    }

    bool is_item_at_equal(T element, int indx){
        return arr[indx] == element;
    }

    void clear(){
        capacity = 0;
    }

    void print(){
        for(int i = 0; i < capacity; i++)
            cout << arr[i] << " ";

        cout << '\n';
    }

};



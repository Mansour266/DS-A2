/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#1
 * Last Modification Date: 27/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve first problem of the assignment.
 */
#include "single_linked_list.cpp"


using namespace std;


int main(){
    single_linked_list<int> test, final;
    //first test case
//    test.insert_at_tail(0);
//    test.insert_at_tail(3);
//    test.insert_at_tail(1);
//    test.insert_at_tail(0);
//    test.insert_at_tail(4);
//    test.insert_at_tail(5);
//    test.insert_at_tail(2);
//    test.insert_at_tail(0);


    //second test case
    test.insert_at_tail(0);
    test.insert_at_tail(1);
    test.insert_at_tail(0);
    test.insert_at_tail(3);
    test.insert_at_tail(0);
    test.insert_at_tail(2);
    test.insert_at_tail(2);
    test.insert_at_tail(0);

    int sum{0};
    for (int i = 0; i < test.linked_list_size(); ++i) {
        if(test.retrieve_at(i) == 0) {
            if(sum == 0)
                continue;
            else {
                final.insert_at_tail(sum);
                sum = 0;
            }
        }
        else{
            sum += test.retrieve_at(i);
        }
    }

final.print();

}
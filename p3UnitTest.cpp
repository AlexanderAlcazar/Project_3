//
// Created by alcaz on 5/9/2025.
//
#include "listtests.h"
#include "dllist.h"
int main() {
    //test #1
    for (int i = 0; i <= 1; i++)
        runTest(test_empty,i);
    //test #2
    for (int i = 0; i <= 1; i++)
        runTest(test_add_front,i);
    //test #3
    for (int i = 0; i <= 1; i++)
        runTest(test_add_rear,i);
    //test #4
    for (int i = 0; i <= 6; i++)
        runTest(test_add,i);
    //test #5
    for (int i = 0; i <= 4; i++)
        runTest(test_search,i);
    //test #6
    for (int i = 0; i <= 1; i++)
        runTest(test_front,i);
    //test #7
    for (int i = 0; i <= 1; i++)
        runTest(test_rear,i);
    //test #8
    for (int i = 0; i <= 1; i++)
        runTest(test_peek,i);
    //test #9
    for (int i = 0; i <= 2; i++)
        runTest(test_remove_front,i);
    //test #10
    for (int i = 0; i <= 2; i++)
        runTest(test_remove_rear,i);
    //test #11
    for (int i = 0; i <= 7; i++)
        runTest(test_remove_index,i);
    //test #12
    for (int i = 0; i <= 5; i++)
        runTest(test_remove_item,i);
    //test #13
   for (int i = 0; i <= 1; i++)
        runTest(test_print,i);
    //test #14
    for (int i = 0; i <= 1; i++)
        runTest(test_size,i);
    //test #15
     for (int i = 0; i <= 5; i++)
        runTest(test_items,i);
    //test #16
    for (int i = 0; i <= 2; i++)
        runTest(test_copyCtor,i);
    //test #17
     for (int i = 0; i <= 2; i++)
        runTest(test_assgnOper,i);
    //test #18
    for (int i = 0; i <= 0; i++)
        runTest(test_mem_destructor,i);
    //test #19
    for (int i = 0; i <= 1; i++)
        runTest(test_mem_assgnOper,i);
    //test #20
    for (int i = 0; i <= 12; i++)
        runTest(test_sub_list,i);
    return 0;
}
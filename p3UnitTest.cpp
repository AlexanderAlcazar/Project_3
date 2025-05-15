//
// Created by alcaz on 5/9/2025.
//
#include "listtests.h"
#include "dllist.h"
int main() {
    for (int i = 0; i <= 1; i++)
        runTest(test_empty,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_add_front,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_add_rear,i);
    for (int i = 0; i <= 6; i++)
        runTest(test_add,i);
    for (int i = 0; i <= 4; i++)
        runTest(test_search,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_front,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_rear,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_rear,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_peek,i);
    for (int i = 0; i <= 2; i++)
        runTest(test_remove_front,i);
    for (int i = 0; i <= 2; i++)
        runTest(test_remove_rear,i);
    for (int i = 0; i <= 7; i++)
        runTest(test_remove_index,i);
    for (int i = 0; i <= 5; i++)
        runTest(test_remove_item,i);
    for (int i = 0; i <= 12; i++)
        runTest(test_sub_list,i);
    for (int i = 0; i <= 5; i++)
        runTest(test_items,i);
    for (int i = 0; i <= 0; i++)
        runTest(test_mem_destructor,i);
    for (int i = 0; i <= 2; i++)
        runTest(test_copyCtor,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_size,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_print,i);
    for (int i = 0; i <= 2; i++)
        runTest(test_assgnOper,i);
    for (int i = 0; i <= 1; i++)
        runTest(test_mem_assgnOper,i);
    return 0;
}
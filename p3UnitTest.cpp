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
    return 0;
}
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
    return 0;
}
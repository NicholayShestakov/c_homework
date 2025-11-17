#include "sorted_list.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
    List *testList = createList();
    assert(testList != NULL && "Error! List does not created correctly.");
    appendValue(testList, 123);
    int *arr = getListAsArray(testList);
    assert(arr[0] == 1 && arr[1] == 123 && "Error! Value does not appended correctly.");
    free(arr);
    deleteValue(testList, 123);
    int *arr = getListAsArray(testList);
    assert(arr[0] == 0 && "Error! Value does not deleted correctly.");
    free(arr);
    deleteList(testList);
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        if (strcmp(argv[1], "--test") == 0) {
            test();
            printf("All tests has successfully passed.\n");
        }
    }

    int command = -1;
    int value = 0;
    List *list = createList();
    printf("Available commands: \n0 - Exit. \n1 - Append value. \n2 - Delete value. \n3 - Print list. \n");

    while (command != 0) {
        printf("Input command: ");
        scanf("%d", &command);

        if (command == 1) {
            printf("Input value: ");
            scanf("%d", &value);
            appendValue(list, value);
        }
        if (command == 2) {
            printf("Input value: ");
            scanf("%d", &value);
            deleteValue(list, value);
        }
        if (command == 3) {
            printList(list);
        }
    }

    deleteList(list);
    return 0;
}

#include "sorted_list.h"
#include <stdio.h>

int main()
{
    int command = -1;
    int value = 0;
    List* list = createList();
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

#include "cyclic_list.h"
#include <stdio.h>

int main()
{
    int peopleCount, everyM;
    printf("Enter people count and after how many people we kill human (Каждый k+1-ый будет убит) (separated by space): ");
    scanf("%d %d", &peopleCount, &everyM);

    List* people = createList(peopleCount);
    int humanNumber = 0;
    for (; !humanNumber; humanNumber = deleteElement(people, everyM)) { }
    printf("Number %d is alive! \n", humanNumber);

    deleteList(people);
    return 0;
}

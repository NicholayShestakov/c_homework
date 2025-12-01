#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
Compares two numbers in binary form без ведущих нулей, исключая число 0.
If first is bigger, returns 1, if second - -1.
If they equvalent, returns 0.
*/
int compare(bool* a, bool* b, int aLen, int bLen)
{
    if (aLen > bLen) {
        return 1;
    }
    if (bLen > aLen) {
        return -1;
    }
    for (int i = aLen - 1; i >= 0; --i) {
        if (a[i] > b[i]) {
            return 1;
        }
        if (b[i] > a[i]) {
            return -1;
        }
    }
    return 0;
}

int main()
{
    bool a[] = { 1, 1, 0 };
    bool b[] = { 1, 0, 1 };
    assert(compare(a, b, 3, 3) == 1 && "Compare 1 incorrect");
    bool a2[] = { 0 };
    bool b2[] = { 1 };
    assert(compare(a2, b2, 1, 1) == -1 && "Compare 2 incorrect");
    bool a3[] = { 1 };
    bool b3[] = { 1 };
    assert(compare(a3, b3, 1, 1) == 0 && "Compare 3 incorrect");

    printf("All test are correct.\n");

    return 0;
}

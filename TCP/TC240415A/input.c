#include <stdio.h>

int main() {
    int x = 0;
    int array[1000000];
    memset(array, 0, sizeof(array));
    printf("The value of x is: %d\n", array[99999]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *ptr = malloc(10); // memory leak on purpose
    strcpy(ptr, "Hello World"); // buffer overflow
    printf("%s\n", ptr);
    return 0;
}
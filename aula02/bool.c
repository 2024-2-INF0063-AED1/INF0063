#include <stdio.h>
#include <stdbool.h>

int main() {
    bool emCrash = true; // Tipo logico (boolean)

    if(!emCrash)
        printf("Sistema OK!\n");
    else
        printf("Sistema em CRASH.\n");

    return (0);
}

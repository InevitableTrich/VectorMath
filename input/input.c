#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// gets a character input, given menu and accepted characters
// returns NULL if 'x' is chosen
char get_char_input(char* display, char wanted[]) {
    char* input = malloc(50 * sizeof(char));

    menu:

    // output display
    printf("%s\n::", display);
    // get menu choice
    fgets(input, 50, stdin);

    // check for exit / bad input
    if (input[0] == 'x') {
        free(input);
        return '\0';
    } else if (strrchr(wanted, input[0]) == NULL) {
        printf("\nInput `%c` not recognized.\n", input[0]);
        goto menu;
    }

    free(input);
    return input[0];
}
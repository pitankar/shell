/**
 * File:        main.c
 * Description: implements the shell
 **/

/**
 * Copyright 2017 Piyush Itankar
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * this is the first function to be called.
 * it initiates the main shell prompt and loop
 **/
 int main() {

    // launch the shell
    while (TRUE) {
        shell();
    }

    return 0;
 }

/**
 * records the user input
 * gets the lineand stores it
 **/
 void shell() {
    char c;
    int  count = 0;
    int  size = SHELL_BUFFER_SIZE;
    char *line = (char *) malloc (size);

    printf ("%s", PROMPT);

    while (TRUE) {
        c = getchar();

        line[count] = c;

        if ( c == '\n' || c == EOF) {
            line[count] = '\0';
            break;
        }

        count ++;
        if ( (count % SHELL_BUFFER_SIZE) == 0) {
            size += SHELL_BUFFER_SIZE;
            line = realloc (line, size);
        }   
    }

    // parse the line
    // execute the command

    free(line);
}
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
#include "cmd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern cmd_tb table[];

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
    int  argument_size = SHELL_NUMBER_OF_ARGUMENTS;
    char *line = (char *) malloc (sizeof(char) * size);
    char **argv = (char **) malloc (sizeof(char*) * argument_size);

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
    parse_line(argv, line, argument_size);

    // execute the parsed commands
    execute(argv);

    free(line);
    free(argv);
}

void parse_line(char** argv, char *line, int argument_size) {
    int argc = 0;
    int pos  = 0;
    int length = strlen(line);

    while (pos < length) {
        if (argc == argument_size) {
            argument_size += SHELL_NUMBER_OF_ARGUMENTS;
            argv = (char **) realloc (argv, argument_size);
        }

        argv[argc++] = &line[pos];

        for (; line[pos] != '\t' && line[pos] != ' ' && line[pos] != '\n' && line[pos] != EOF; pos++);

        if (line[pos] == '\n' || line[pos] == EOF) {
            line[pos] = '\0';
            return;
        } else {
            line[pos++] = '\0';
        }        
    }
}

void execute(char **argv) {
    int arg = 0;

    for (int i = 0; table[i].command_name != NULL; i++) {
        if (strcmp(argv[0], table[i].command_name) == 0)
            table[i].command (0, &argv[1]);
    }
}
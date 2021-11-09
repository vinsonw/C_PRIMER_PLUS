/*
* used with test.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Wrong input.");
        exit (0);
    }
    char ch = *argv[1];
    // printf("ch=%c\n", ch);
    long begin, end, count;
    begin = 0L;

    FILE *ptr;
    if ((ptr = fopen(argv[2], "r")) == NULL)
        fprintf(stderr,"Can't open %s\n",argv[2]);

    char ch_iter, ch_inner;
    int gotcha = 0;
    while ((ch_iter = getc(ptr)) != EOF)
    {
        if ( ch_iter == ch )
            gotcha = 1;
        if ( ch_iter == '\n' )
        {
            // this line is the key to making the following fseek() right:
            // after ch_iter reads '\n', file postion indicator of "ptr" moves to the char after '\n',
            // thus, in order to make "end" the position of '\n', you need "-1L"
            end = ftell(ptr)-1L; 
            if (gotcha)
            {
                // version 1
                // fseek(ptr, begin, SEEK_SET);

                // version 2
                // I don't get it why it has to be
                // begin-end-1 instead of begin-end, which
                // is right amount of offset
                // -- I got it!
                // SEEK_CUR is pointing to the char after 
                // "end" right now, which is why you need the extra "1L" to 
                // go back to the "begin" 
                fseek(ptr, begin-end-1L, SEEK_CUR);

                for (count=begin;count<=end;count++)
                {
                    ch_inner = getc(ptr);
                    putchar(ch_inner);
                }
                gotcha = 0;
            }
            begin = end+1L;
        }

    }

    // Because Unix-like systems add a newline automatically at the end of FILE
    // even there is a newline
    // experiment with: hexdump -C foo1.txt
    // see for more detail: https://github.com/microsoft/vscode/issues/35181
    // therefore, the logic above always captures all lines, including the last
    // line without an explicit terminating newline.

    // if the mechanism doesn't exit, we need to take care of the possible last line
    // without an explicit terminating newline because it wouldn't be captured by
    // the "begin"/"end" logic above.

    // the below statements will print the implicit newline(won't be shown on Unix, usually)
    fseek(ptr, -1L, SEEK_END);
    printf("The previous char is %c\n", getc(ptr));

    return 0;
}
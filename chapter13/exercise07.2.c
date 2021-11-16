#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line_id {
    FILE *f;
    long begin;
    long end;
    long ln_num;
};

void display_line(struct line_id *);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Wrong input.");
        exit (EXIT_FAILURE);
    }

    FILE *f0, *f1;
    
    struct line_id line_f0;
    line_f0.begin = 0L;
    line_f0.ln_num = 0L;
    struct line_id line_f1;
    line_f1.begin = 0L;
    line_f1.ln_num = 0L;

    if ((f0 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((f1 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    line_f0.f = f0;
    line_f1.f = f1;

    int line_cnt = 0;

    char ch_iter0, ch_iter1;
    char ch_inner0, ch_inner1;

    int sameLine;
    while ( (ch_iter0 = getc(f0)) != EOF )
    {
        if ( ch_iter0 == '\n' )
        {
            sameLine = 0;
            // this line is the key to making the following fseek() right:
            // after ch_iter reads '\n', file postion indicator of "ptr" moves to the char after '\n',
            // thus, in order to make "end" the position of '\n', you need "-1L"
            line_f0.end = ftell(f0)-1L; 

            while ( (ch_iter1 = getc(f1)) != EOF  )
            {
                if ( ch_iter1 == '\n')
                {
                    line_f1.end = ftell(f1) - 1L;
                    sameLine = 1;
                    break;
                }
            }

            if (sameLine)
            {
                // file position pointer is 1 char before "end"
                // and display_line() relies on this relationship
                // in order to display one char less( don't display '\n' )
                // we need to move 1 character back for both "end" and file position pointer.
                fseek(f0, -1L, SEEK_CUR);
                line_f0.end--;

                display_line(&line_f0); // display the line without ending '\n'

                line_f0.end++;
                line_f0.begin++; // move "begin" one char after "end"
                fseek(f0, 1L, SEEK_CUR);

                putchar(' ');

                display_line(&line_f1);
            }
            else
                display_line(&line_f0);

        }

    }

    while ( (ch_iter1 = getc(f1)) != EOF  )
    {
        if ( ch_iter1 == '\n')
        {
            line_f1.end = ftell(f1) - 1L;
            display_line(&line_f1);
        }
    }

    fclose(f0);
    fclose(f1);

    return 0;
}

void display_line(struct line_id * p)
{
    fseek(p->f, p->begin - p->end - 1L, SEEK_CUR);

    (p->ln_num)++;
    printf("#line %ld: ", p->ln_num);
    char ch;
    for (int count = p->begin; count <= p->end; count++)
    {
        ch = getc(p->f);
        putchar(ch);
    }

    p->begin = p->end + 1L;

}
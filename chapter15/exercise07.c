#include <stdio.h>
#include <stdlib.h>


unsigned long MASK_FONT_ID = 255;          //                 1111 1111
unsigned long MASK_FONT_SIZE = 32512; //            0111 1111 0000 0000
unsigned long MASK_ALGINMENT = 196608; //      0011 0000 0000 0000 0000
unsigned long MASK_BOLD = 262144; //           0100 0000 0000 0000 0000
unsigned long MASK_ITALIC = 524288; //         1000 0000 0000 0000 0000
unsigned long MASK_UNDERLINE = 1048576; //0001 0000 0000 0000 0000 0000


enum alignement { left, center, right };
enum on_or_off { off, on };

void show_settings(unsigned long *p);
void display_meanu(void);
void eatline(void);
void f_change_font(unsigned long *p);
void s_change_size(unsigned long *p);
void a_change_alignment(unsigned long *p);
void b_toggle_bold(unsigned long *p);
void i_toggle_italic(unsigned long *p);
void u_toggle_underline(unsigned long *p);

int main(void)
{
    unsigned long SETTINGS = 68609; // 0000 0001 0000 1100 0000 0001

    show_settings(&SETTINGS);
    display_meanu();
    while (1)
    {
        char ch;
        scanf("%c", &ch);
        eatline();

        switch (ch)
        {
            case 'f':
                f_change_font(&SETTINGS);
                break;
            case 's':
                s_change_size(&SETTINGS);
                break;
            case 'a':
                a_change_alignment(&SETTINGS);
                break;
            case 'b':
                b_toggle_bold(&SETTINGS);
                break;
            case 'i':
                i_toggle_italic(&SETTINGS);
                break;
            case 'u':
                u_toggle_underline(&SETTINGS);
                break;
            case 'q':
                exit(0);
            default:
                printf("wrong input, try again.\n");
                break;
        }

        show_settings(&SETTINGS);
        display_meanu();
    }
}

void show_settings(unsigned long *p)
{
    printf("ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3d %3d ", *p & MASK_FONT_ID, (*p & MASK_FONT_SIZE) >> 8);

    switch ((*p & MASK_ALGINMENT) >> 16)
    {
        case 0:
            printf("  left   ");
            break;
        case 1:
            printf("  center   ");
            break;
        case 2:
            printf("  right   ");
            break;
        default:
            break;
    }

    if (0 == ((*p & MASK_BOLD) >> 18))
        printf("  off ");
    else
        printf("   on ");

    if (0 == ((*p & MASK_ITALIC) >> 19))
        printf("off ");
    else
        printf("on ");

    if (0 == ((*p & MASK_UNDERLINE) >> 20))
        printf(" off \n");
    else
        printf(" on \n");
    
}

void display_meanu(void)
{
    printf("f)change font s)change size a)change alignment\n"
    "b)toggle bold i)toggle italic u)toggle underline\n"
    "q)quit\n"
    );
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void f_change_font(unsigned long *p)
{
    printf("Enter font id(0-255): \n");
    unsigned long num; 
    scanf("%u", &num);
    // printf("num=%u\n", num);
    eatline();
    *p = ~MASK_FONT_ID & *p | num;
}

void s_change_size(unsigned long *p)
{
    printf("Enter font size(0-127): \n");
    unsigned int num;
    scanf("%u", &num);
    num <<= 8;
    // printf("num=%d\n", num);
    eatline();
    *p = ~MASK_FONT_SIZE & *p | num;

}

void a_change_alignment(unsigned long *p)
{
    printf("Select alignment:\n");
    printf("l)left c)center r)right\n");
    char ch;
    scanf("%c", &ch);
    eatline();
    unsigned long num;
    if ('l' == ch)
        num = left;
    else if ('c' == ch)
        num = center;
    else if ('r' == ch)
        num = right;
    else
        exit(0);
    num <<= 16;
    *p = ~MASK_ALGINMENT & *p | num;
}

void b_toggle_bold(unsigned long *p)
{
    *p = (1 << 18) ^ *p;
}

void i_toggle_italic(unsigned long *p)
{
    *p = (1 << 19) ^ *p;
}

void u_toggle_underline(unsigned long *p)
{
    *p = (1 << 20) ^ *p;
}

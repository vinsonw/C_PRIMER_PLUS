#include <stdio.h>
#include <stdlib.h>

struct font { 
    unsigned int font_id: 8;
    unsigned int font_size: 7;
    unsigned int : 1;
    unsigned int alignment: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
    unsigned int underline: 1;
    unsigned int : 3;
};

enum alignement { left, center, right };
enum on_or_off { off, on };

void show_settings(struct font *);
void display_meanu(void);
void eatline(void);
void f_change_font(struct font *);
void s_change_size(struct font *);
void a_change_alignment(struct font *);
void b_toggle_bold(struct font *);
void i_toggle_italic(struct font *);
void u_toggle_underline(struct font *);

int main(void)
{
    struct font usr_font = {1, 12, left, off, off, off};

    show_settings(&usr_font);
    display_meanu();
    while (1)
    {
        char ch;
        scanf("%c", &ch);
        eatline();

        switch (ch)
        {
            case 'f':
                f_change_font(&usr_font);
                break;
            case 's':
                s_change_size(&usr_font);
                break;
            case 'a':
                a_change_alignment(&usr_font);
                break;
            case 'b':
                b_toggle_bold(&usr_font);
                break;
            case 'i':
                i_toggle_italic(&usr_font);
                break;
            case 'u':
                u_toggle_underline(&usr_font);
                break;
            case 'q':
                exit(0);
            default:
                printf("wrong input, try again.\n");
                break;
        }

        show_settings(&usr_font);
        display_meanu();
    }
}

void show_settings(struct font *p)
{
    printf("ID SIZE ALIGNMENT   B   I   U\n");
    printf("%3d %3d ", p->font_id, p->font_size);

    switch (p->alignment)
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

    if (0 == p->bold)
        printf("  off ");
    else
        printf("   on ");

    if (0 == p->italic)
        printf("off ");
    else
        printf("on ");

    if (0 == p->underline)
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

void f_change_font(struct font * p)
{
    printf("Enter font id(0-255): \n");
    // there seems be a bug if the type of "num" is not "usigned int"
    unsigned int num; 
    scanf("%u", &num);
    printf("num=%u\n", num);
    eatline();
    p->font_id = num;
}

void s_change_size(struct font * p)
{
    printf("Enter font size(0-127): \n");
    unsigned int num;
    scanf("%u", &num);
    // printf("num=%d\n", num);
    eatline();
    p->font_size = num;

}

void a_change_alignment(struct font * p)
{
    printf("Select alignment:\n");
    printf("l)left c)center r)right\n");
    char ch;
    scanf("%c", &ch);
    eatline();
    if ('l' == ch)
        p->alignment = left;
    else if ('c' == ch)
        p->alignment = center;
    else if ('r' == ch)
        p->alignment = right;
    else
        exit(0);
}

void b_toggle_bold(struct font * p)
{
    p->bold = ~p->bold;
}

void i_toggle_italic(struct font * p)
{
    p->italic = ~p->italic;
}

void u_toggle_underline(struct font * p)
{
    p->underline = ~p->underline;
}

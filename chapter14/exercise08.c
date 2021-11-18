#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct seat {
    int seat_id;
    int isAssigned;
    char last_name[20];
    char first_name[20];
};

void eatline(void);
void a_show_num_of_empty_seats(struct seat *, int n);
void b_show_list_of_empty_seats(struct seat *, int);
void c_show_alphab_list_of_seats(struct seat * ps, int n);
void d_assign_a_customer_to_a_seat(struct seat * ps, int n);
void e_delete_a_seat_assignment(struct seat * ps, int n);
void display_menu(void);

int main(void)
{
    FILE *fp;
    struct seat seats[12];
    for (int i=0; i<12; i++)
    {
        seats[i].seat_id = i+1;
        seats[i].isAssigned = 0;
        strcpy(seats[i].first_name , "#");
        strcpy(seats[i].last_name , "#");
    }

    if ( (fp = fopen("seats.dat", "r+b")) == NULL )
    {
        fputs("Can't open seats.dat file to load data.\n", stderr);
        exit(1);
    }

    rewind(fp);

    struct seat tmp_seat;
    size_t size = sizeof (struct seat);
    int count=0;
    int occupied_seat_cnt=0;
    // while (  fscanf(fp, "%d %d %s %s", &tid, &tisAssigned, tlast_name, tfirst_name) == 4 )
    int index;
    while (  fread(&tmp_seat, size, 1, fp) == 1 )
    {

        // wrong version: index = tmp_seat.seat_id;
        index = tmp_seat.seat_id-1;
        // wrong version: seats[index].isAssigned = tmp_seat.seat_id;
        seats[index].isAssigned = tmp_seat.isAssigned;
        strcpy(seats[index].last_name, tmp_seat.last_name);
        strcpy(seats[index].first_name, tmp_seat.first_name);
        count++;
        occupied_seat_cnt += tmp_seat.isAssigned;
    }

    fclose(fp);

    if ( count > 0 )
        printf(">>> %d records loaded, %d seats available.\n", count, 12-occupied_seat_cnt);
    else
        printf(">>> No previous data to load from seats.dat.\n");

    display_menu();

    while (1)
    {
        char ch;
        while ( scanf("%c", &ch) != 1 || 
        ('a' != ch && 'b' != ch && 'c' != ch && 'd' != ch && 'e' != ch && 'f' != ch) )
            printf("wrong input, try again: ");
        eatline();

        switch (ch)
        {
            case 'a':
                a_show_num_of_empty_seats(seats, 12);
                break;
            case 'b':
                b_show_list_of_empty_seats(seats, 12);
                break;
            case 'c':
                c_show_alphab_list_of_seats(seats, 12);
                break;
            case 'd':
                d_assign_a_customer_to_a_seat(seats, 12);
                break;
            case 'e':
                e_delete_a_seat_assignment(seats, 12);
                break;
            case 'f':
                exit(0);
                break;
            default:
                break;
        }

        if ( (fp = fopen("seats.dat", "w")) == NULL )
        {
            fputs("Can't open seats.dat file to load data.\n", stderr);
            exit(1);
        }
        rewind(fp);

        fwrite(seats, sizeof(struct seat), 12, fp);
        fclose(fp);
        
        printf("----------------------------\n");
        printf("Do you want to continue, y to proceed, q to quit.\n");
        scanf("%c", &ch);
        eatline();
        if ( 'y' != ch )
            exit(0);

        display_menu();
    }

    

}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void a_show_num_of_empty_seats(struct seat * ps, int n)
{
    char occupied_cnt=0;
    for (int i=0; i<n; i++)
        occupied_cnt += ps[i].isAssigned;
    printf("%d seats are available.\n", n-occupied_cnt);
}


void b_show_list_of_empty_seats(struct seat * ps, int n)
{
    for (int i=0; i<n; i++)
        if (!ps[i].isAssigned)
            printf("Seat %d is available.\n", ps[i].seat_id);
}

void c_show_alphab_list_of_seats(struct seat * ps, int n)
{
    struct seat * pa[n];
    struct seat * temp;
    for (int i=0; i<n; i++)
        pa[i] = ps+i; // ps[i] == *(ps+i) is not what we want here!
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
            if (strcmp(pa[i]->last_name, pa[j]->last_name) > 0) // strcmp: str1 - str2
            {
                temp = pa[i];
                pa[i] = pa[j];
                pa[j] = temp;
            }  
            else if (strcmp(pa[i]->last_name, pa[j]->last_name) == 0)
            {
                if (strcmp(pa[i]->first_name, pa[j]->first_name) > 0)
                {
                    temp = pa[i];
                    pa[i] = pa[j];
                    pa[j] = temp;
                }  
            }
    }
    for (int i=0; i<n; i++)
        if (pa[i]->isAssigned)
            printf("%s, %s is at Seat %d.\n", pa[i]->last_name, pa[i]->first_name, pa[i]->seat_id);

}
void d_assign_a_customer_to_a_seat(struct seat * ps, int n)
{
    a_show_num_of_empty_seats(ps, n);
    b_show_list_of_empty_seats(ps, n);
    printf("Please enter the seat number, q to quit:\n");

    char ch;
    scanf("%c", &ch);

    if (ch == 'q')
        exit(0);
    else
        ungetc(ch, stdin);

    unsigned int seat_num;
    while ( scanf("%d", &seat_num) != 1 || seat_num > 12 || seat_num < 1 ||
    ps[seat_num-1].isAssigned)
    {
        eatline();
        printf("wrong input, try again: ");
    }
    eatline();
    printf("Please enter the customer's last name:\n");
    scanf("%s", ps[seat_num-1].last_name);
    eatline();
    printf("Please enter the customer's first name:\n");
    scanf("%s", ps[seat_num-1].first_name);
    eatline();
    ps[seat_num-1].isAssigned = 1;
    puts("Done.");

}
void e_delete_a_seat_assignment(struct seat * ps, int n)
{
    for (int i=0; i<n; i++)
        if (ps[i].isAssigned)
            printf("Seat %d is occupied by %s, %s.\n", 
            ps[i].seat_id, ps[i].last_name, ps[i].first_name);

    printf("Please enter the seat number to be removed assignment from:, q to quit:\n");

    char ch;
    scanf("%c", &ch);

    if (ch == 'q')
        exit(0);
    else
        ungetc(ch, stdin);

    int seat_num;
    while ( scanf("%d", &seat_num) != 1 || seat_num > 12 || seat_num < 1 ||
    !(ps[seat_num-1].isAssigned))
    {
        eatline();
        printf("wrong input, try again: ");
    }
    eatline();

    ps[seat_num-1].isAssigned = 0;
    printf("Asignment of Seat %d deleted.\n" , seat_num);
    
}

void display_menu(void)
{
    printf(
    ">>> To choose a function, enter its letter label: \n"
    "a) Show number of empty seats\n"
    "b) Show list of empty seats\n"
    "c) Show alphabetical list of seats\n"
    "d) Assign a customer to a seat assignment\n"
    "e) Delete a seat assigment\n"
    "f) quit <<<\n"
    );
}
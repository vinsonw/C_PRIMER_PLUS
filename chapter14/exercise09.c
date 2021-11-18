#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct seat {
    int seat_id;
    int isAssigned;
    int confirm_status;
    char last_name[20];
    char first_name[20];
};

void eatline(void);
void a_show_num_of_empty_seats(int, struct seat *, int n);
void b_show_list_of_empty_seats(int, struct seat *, int);
void c_show_alphab_list_of_seats(int, struct seat *, int n);
void d_assign_a_customer_to_a_seat(int, struct seat *, int n);
void e_delete_a_seat_assignment(int, struct seat *, int n);
void display_menu(int);
void display_flight(void);

int fid_to_index(int);

int main(void)
{
    FILE *fp;
    struct flight {
        int flight_id;
        struct seat seats[12];
    };
    struct flight flights[4];

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<12; j++)
        {
            flights[i].seats[j].seat_id = j+1;
            flights[i].seats[j].isAssigned = 0;
            flights[i].seats[j].confirm_status = 0;
        }
    }
    flights[0].flight_id = 102;
    flights[1].flight_id = 311;
    flights[2].flight_id = 444;
    flights[3].flight_id = 519;

    if ( (fp = fopen("flights_seats.dat", "r+b")) == NULL )
    {
        fputs("Can't open flights_seats.dat file to load data.\n", stderr);
        exit(1);
    }

    rewind(fp);

    struct flight tmp_flight;
    size_t size = sizeof (struct flight);
    int count=0;
    int occupied_seat_cnt=0;

    int index;
    while (  fread(&tmp_flight, size, 1, fp) == 1 )
    {

        index = fid_to_index(tmp_flight.flight_id);

        flights[index].flight_id = tmp_flight.flight_id;
        for (int j=0; j<12; j++)
        {
            flights[index].seats[j].seat_id = tmp_flight.seats[j].seat_id;
            flights[index].seats[j].isAssigned = tmp_flight.seats[j].isAssigned;
            flights[index].seats[j].confirm_status = tmp_flight.seats[j].confirm_status;
            strcpy(flights[index].seats[j].last_name, tmp_flight.seats[j].last_name);
            strcpy(flights[index].seats[j].first_name, tmp_flight.seats[j].first_name);

            occupied_seat_cnt += tmp_flight.seats[j].isAssigned;
        }

        count++;
    }

    fclose(fp);

    if ( count > 0 )
        printf(">>> %d records loaded, %d seats available.\n", count, 4*12-occupied_seat_cnt);
    else
        printf(">>> No previous data to load from seats.dat.\n");

    display_flight();
    while (1) // Flight loop
    {
        char ch;
        scanf("%c", &ch);

        if (ch == 'q')
            exit(0);
        else
            ungetc(ch, stdin);
        int flight_id;
        while ( scanf("%d", &flight_id) != 1 || fid_to_index(flight_id) == 100 )
        {
            eatline();
            printf("wrong input, try again: ");
        }
        eatline();

        while (1) // Seats loop
        {
            display_menu(flight_id);
            int flight_index = fid_to_index(flight_id);

            while ( scanf("%c", &ch) != 1 || 
            ('a' != ch && 'b' != ch && 'c' != ch && 'd' != ch && 'e' != ch && 'f' != ch) )
                printf("wrong input, try again: ");
            eatline();

            if ( 'f' == ch )
                break; // exit to Flight loop

            switch (ch)
            {
                case 'a':
                    a_show_num_of_empty_seats(flight_id, flights[flight_index].seats, 12);
                    break;
                case 'b':
                    b_show_list_of_empty_seats(flight_id, flights[flight_index].seats, 12);
                    break;
                case 'c':
                    c_show_alphab_list_of_seats(flight_id, flights[flight_index].seats, 12);
                    break;
                case 'd':
                    d_assign_a_customer_to_a_seat(flight_id, flights[flight_index].seats, 12);
                    break;
                case 'e':
                    e_delete_a_seat_assignment(flight_id, flights[flight_index].seats, 12);
                    break;
                default:
                    break;
            }
        }

        if ( (fp = fopen("flights_seats.dat", "w")) == NULL )
        {
            fputs("Can't open flights_seats.seats.dat file to load data.\n", stderr);
            exit(1);
        }
        rewind(fp);
        fwrite(flights, size, 4, fp);
        fclose(fp);
        
        printf("----------------------------\n");
        printf("Do you want to continue, y to proceed, q to quit.\n");
        scanf("%c", &ch);
        eatline();
        if ( 'y' != ch )
            exit(0);

        display_flight();
    }
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void a_show_num_of_empty_seats(int flight_id,struct seat * ps, int n)
{
    char occupied_cnt=0;
    for (int i=0; i<n; i++)
        occupied_cnt += ps[i].isAssigned;
    printf("Flight %d: %d seats are available.\n", flight_id, n-occupied_cnt);
}


void b_show_list_of_empty_seats(int flight_id,struct seat * ps, int n)
{
    for (int i=0; i<n; i++)
        if (!ps[i].isAssigned)
            printf("On Flight %d: Seat %d is available.\n", flight_id, ps[i].seat_id);
}

void c_show_alphab_list_of_seats(int flight_id, struct seat * ps, int n)
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
            printf("%s, %s is at Flight %d: Seat %d.\n", 
            pa[i]->last_name, pa[i]->first_name, flight_id, pa[i]->seat_id);

}
void d_assign_a_customer_to_a_seat(int flight_id, struct seat * ps, int n)
{
    a_show_num_of_empty_seats(flight_id, ps, n);
    b_show_list_of_empty_seats(flight_id, ps, n);
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
    printf("Flight %d: Please enter the customer's last name:\n", flight_id);
    scanf("%s", ps[seat_num-1].last_name);
    eatline();
    printf("Flight %d: Please enter the customer's first name:\n", flight_id);
    scanf("%s", ps[seat_num-1].first_name);
    eatline();
    ps[seat_num-1].isAssigned = 1;
    printf("Flight %d >>> Done.", flight_id);

}
void e_delete_a_seat_assignment(int flight_id, struct seat * ps, int n)
{
    for (int i=0; i<n; i++)
        if (ps[i].isAssigned)
            printf("Flight %d: Seat %d is occupied by %s, %s.\n", 
            flight_id, ps[i].seat_id, ps[i].last_name, ps[i].first_name);

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
    printf("Flight %d: Asignment of Seat %d deleted.\n" , flight_id, seat_num);
    
}

void display_menu(int flight_id)
{
    printf(
    ">>> Welcome aboard Flight %d\n"
    ">>> To choose a function, enter its letter label: \n"
    "a) Show number of empty seats\n"
    "b) Show list of empty seats\n"
    "c) Show alphabetical list of seats\n"
    "d) Assign a customer to a seat assignment\n"
    "e) Delete a seat assigment\n"
    "f) exit to up-level menu <<<\n"
    , flight_id);
}

void display_flight(void)
{
    printf(
    ">>> We have Flight 102, 311, 444, 519\n"
    "Please enter the flight number or 'q' to quit <<< \n"
    );
}

int fid_to_index(int flight_id)
{
    if (flight_id == 102)
        return 0;
    else if (flight_id == 311)
        return 1;
    else if (flight_id == 444)
        return 2;
    else if (flight_id == 519)
        return 3;
    else
        return 100;
}
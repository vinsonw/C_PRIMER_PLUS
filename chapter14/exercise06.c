#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player {
    int id;
    char first[20];
    char last[20];
    int at_bats;
    int hits;
    int walks;
    int runs;
    float batting_avg;
};

int main(void)
{
    struct player players[19];
    for (int i=0; i<19; i++)
    {
        players[i].id = i;
        players[i].at_bats = 0;
        players[i].hits = 0;
        players[i].walks = 0;
        players[i].runs = 0;
        players[i].batting_avg = 0.;
    }
    FILE *fp;
    if ( !(fp=fopen("softball.txt", "r")) )
    {
        fprintf(stderr, "Couldn't open softball.dat\n");
        exit(EXIT_FAILURE);
    }
    
    int tid;
    char first[20];
    char last[20];
    int tat_bats;
    int thits;
    int twalks;
    int truns;
    // fscanf() returens EOF itself when encounters EOF
    // unlkie fgets() return NULL pointer
    while ( fscanf(fp, "%d %s %s %d %d %d %d", &tid, first, last,
    &tat_bats, &thits, &twalks, &truns) != EOF) 
    {

        strcpy(players[tid].first, first);
        strcpy(players[tid].last, last);
        players[tid].at_bats += tat_bats;
        players[tid].hits += thits;
        players[tid].walks += twalks;
        players[tid].runs += truns;
    }

    tat_bats=0;
    thits=0;
    twalks=0;
    truns=0;
    

    for (int i=0; i<19; i++)
    {
        players[i].batting_avg = (float) players[i].hits / players[i].at_bats;
        tat_bats += players[i].at_bats;
        thits += players[i].hits;
        twalks += players[i].walks;
        truns += players[i].runs;

        printf("%02d %-10s %-10s: %4.2f %4d %4d %4d %4d\n", players[i].id, players[i].first, players[i].last,
        players[i].batting_avg, players[i].at_bats, players[i].hits, players[i].walks, players[i].runs);
    }
    float ttl_batting_avg = (float) thits / tat_bats;
    printf("%-24s: %4.2f %4d %4d %4d %4d\n","Entire team:", ttl_batting_avg, tat_bats, thits, twalks, truns);

    return 0;
}
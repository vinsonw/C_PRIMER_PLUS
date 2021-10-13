/* extract two functions from Listing 10.7 Vol.1 P395 */
#define MONTHS 12
#define YEARS 5

void stats_years(float (*arr)[MONTHS])
{
    int y,m;
    double subtot, tot=0;
    printf( "YEAR RAINFALL (inches)\n");
    for (y=0; y<YEARS; y++)
    {
        for (m=0, subtot=0; m<MONTHS; m++)
            subtot += arr[y][m];
        printf("%5d %15.1lf\n", 2010+y, subtot);
        tot += subtot;
    }

    printf("\nThe yearly average is %.1f inches.\n\n", tot/YEARS);

}

void stats_months(float (*arr)[MONTHS])
{
    int y,m;
    double subtot, tot=0;
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct "
    " Nov Dec\n" 
    );
    for (m=0; m<MONTHS; y++)
    {
        for (y=0, subtot=0; y<YEARS; y++)
            subtot += arr[y][m];
        printf("%4.1f", subtot/YEARS);
    }

    printf("\n");
}
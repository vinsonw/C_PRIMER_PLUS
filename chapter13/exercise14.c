#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "int (*)[30]" is how you declear a 2d array type
int de_glitch(int, int (*)[30], int, int, int, int); 
int differ(int a1, int a2);

int main(int argc, char *argv[])
{
    const char SYMBOL[11] = {' ', '.', '\'', ':',  '~', '*' ,'=','@','%','#','\0'};
    int arr_2d[20][30];
    char arr_2d_c[20][31];
    FILE *fp;

    if ( (fp = fopen(argv[1], "r")) == NULL )
    {
        printf("fuck");
        exit(0);
    }
    
    // read numbers from the file into arr_2d
    int num;
    for (int i=0; i<20; i++)
        for (int j=0; j<30; j++)
            if ( (fscanf(fp,"%d", &num)) == 1 ) 
                arr_2d[i][j] = num;

    //deglitch the numbers
    int num1;
    for (int i=0; i<20; i++)
        for (int j=0; j<30; j++)
        {
                num1 = de_glitch(arr_2d[i][j], arr_2d, i, j, 20, 30);
                arr_2d[i][j]  = num1;
        }

    // map the numbers to characters
    int num2;
    for (int i=0; i<20; i++)
        for (int j=0; j<31; j++)
            if (j == 30)
                arr_2d_c[i][j] = '\0';
            else
            {
                num2 = arr_2d[i][j];
                arr_2d_c[i][j] = SYMBOL[num2]; // this works as intended
            }


    char saved_file[40];
    strcpy(saved_file, argv[1]);
    strcat(saved_file, ".14.txt");
    FILE *fd = fopen(saved_file, "w");
    puts("alright, this is the converted image:");
    for (int i=0; i<20; i++)
    {
        puts(arr_2d_c[i]);
        fprintf(fd, "%s", arr_2d_c[i]);
        fprintf(fd,"\n");
    }

    fclose(fp);
    fclose(fd);

    return 0;
}

int de_glitch(int ch, int (*arr)[30], int i, int j, int I, int J)
{
    float ch1 = 20; 
    // four corners
    if (i==0 && j==0)
    {
        if (differ(ch, arr[i+1][j]) && differ(ch, arr[i][j+1]))
            ch1 = (arr[i+1][j] + arr[i][j+1]) / 2.0; // round to the nearest integer
    }
    if (i==0 && j==J-1)
    {
        if (differ(ch, arr[i+1][j]) && differ(ch, arr[i][j-1]))
            ch1 = (arr[i+1][j] + arr[i][j-1]) / 2.0; 
    }
    if (i==I-1 && j==J-1)
    {
        if (differ(ch, arr[i][j-1]) && differ(ch, arr[i-1][j]))
            ch1 = (arr[i][j-1] + arr[i-1][j]) / 2.0; 
    }
    if (i==I-1 && j==0)
    {
        if (differ(ch, arr[i][j+1]) && differ(ch, arr[i-1][j]))
            ch1 = (arr[i][j+1] + arr[i-1][j]) / 2.0; 
    }
    // four boundary rows (excluding four corners)
    if (i==0 && j !=0 && j != J-1)
    {
        if (differ(ch, arr[i][j+1]) && differ(ch, arr[i][j-1]) && differ(ch, arr[i+1][j]))
            ch1 = (arr[i][j+1] + arr[i][j-1] + arr[i+1][j]) / 3.0; 
    }

    if (i==I-1 && j !=0 && j != J-1)
    {
        if (differ(ch, arr[i][j+1]) && differ(ch, arr[i][j-1]) && differ(ch, arr[i-1][j]))
            ch1 = (arr[i][j+1] + arr[i][j-1] + arr[i-1][j]) / 3.0; 
    }

    if (j==0 && i != 0 && i != I-1)
    {
        if (differ(ch, arr[i][j+1]) && differ(ch, arr[i-1][j]) && differ(ch, arr[i+1][j]))
            ch1 = (arr[i][j+1] + arr[i-1][j] + arr[i+1][j]) / 3.0; 
    }
    if (j==J-1 && i != 0 && i != I-1)
    {
        if (differ(ch, arr[i][j-1]) && differ(ch, arr[i-1][j]) && differ(ch, arr[i+1][j]))
            ch1 = (arr[i][j-1] + arr[i-1][j] + arr[i+1][j]) / 3.0;
    }
    // other 
    if ( i > 0 && i < I-1 && j > 0 && j <J-1) 
    // I wasted a lot of time when I didn't have this
    // warp the inner part,
    // arr[i][j] form could access memory cell out of the arr,
    // which cause a lot of confusion 
    {
        if ( differ(ch, arr[i][j-1]) && differ(ch, arr[i][j+1]) && differ(ch, arr[i-1][j]) && differ(ch, arr[i+1][j]))
            ch1 = (arr[i][j-1] + arr[i][j+1] + arr[i+1][j] + arr[i-1][j]) / 4.0; 
    }

    if ( ch1 != 20)
    {
    ch = (int) ch1;
    if (ch1 - ch < 0.5 )
        return ch; 
    else
        return ch+1;
    }
    else
     return ch;
}

int differ(int a1, int a2)
{
    int increment = a2 - a1;
    if ( increment * increment > 1)
        return 1;
    else
        return 0;
}
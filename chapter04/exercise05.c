#include <stdio.h>

int main(void)
{
    float download_speed; // Megabits per second
    float size_of_a_file; // Megabytes
    printf("Please enter download speed and size of a file respectively:\n");
    scanf("%f %f", &download_speed, &size_of_a_file);
    printf("At %.2f meagabits per second, a file of %.2f megabytes downloads \
in %.2f seconds.\n", download_speed, size_of_a_file, size_of_a_file * 8 / download_speed);

    return 0;



}
// assuming "2nd booth" means "2nd consultant at 2nd booth at the same time",
// which makes more sense.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0
#define NUM_OF_QUEUE 2

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    Queue lines[NUM_OF_QUEUE];
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways = 0;

    // for simplicity, customers, served, sum_line 
    // don't get divided into multiple queues
    // according to NUM_OF_QUEUE,
    // which is of course also okay.
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time[NUM_OF_QUEUE] = {0};
    double min_per_cust;
    long line_wait = 0;

    for (int i=0; i<NUM_OF_QUEUE; i++)
        InitializeQueue(&lines[i]);
    
    srand((unsigned int) time(0));
    puts("case Study: Sigmund Lander's Advice Booth(with one associate)\n");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) 
    {
        if (newcustomer(min_per_cust))
        {
            bool queueIsFull = true;
            // if all the queues are full
            for (int i=0; i<NUM_OF_QUEUE; i++)
                queueIsFull = queueIsFull && QueueIsFull(&lines[i]);
            if (queueIsFull)
                turnaways++;
            // else new customer added to one queue
            else
            {
                customers++;
                temp = customertime(cycle);
                for (int i=0; i<NUM_OF_QUEUE; i++)
                {
                    if (!QueueIsFull(&lines[i]))
                        EnQueue(temp, &lines[i]);
                    break;
                }
            }
        }


        for (int i=0; i<NUM_OF_QUEUE; i++)
            if (wait_time[i] <=0 && !QueueIsEmpty(&lines[i])) 
            {
                DeQueue(&temp, &lines[i]);
                wait_time[i] = temp.processtime;
                line_wait += cycle - temp.arrive;
                served++;
            }

        for (int i=0; i<NUM_OF_QUEUE; i++)
            if (wait_time[i] > 0)
                    wait_time[i]--;

        for (int i=0; i<NUM_OF_QUEUE; i++)
            sum_line += QueueItemCount(&lines[i]);
    }

    if (customers > 0)
    {
        printf("Customers accepted: %ld\n", customers);
        printf("Customers Served: %ld\n", served);
        printf("turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f persons\n", (double) sum_line / cyclelimit);
        printf("average wait time: %.2f minutes\n", (double) line_wait / served);
    }
    else
        printf("No customers!\n");

    for (int i=0; i<NUM_OF_QUEUE; i++)
        EmptyTheQueue(&lines[i]);

    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;
    cust.processtime = rand() % 10 + 10;
    cust.arrive = when;

    return cust;
}
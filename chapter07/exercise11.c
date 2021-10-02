#include <stdio.h>
#define ARTICHOKE_PER_POUND 2.05
#define BEET_PER_POUND 1.15
#define CARROT_PER_POUND 1.09
#define SHIPPING_WEIGHT_THRESHOLD0 5
#define SHIPPING_WEIGHT_THRESHOLD1 20 

int main(void)
{
    char pmt_ch;
    double ttl_pounds=0.;
    double ttl_cost=0.;
    double ttl_shipping_fee=0.;
    double ttl_dt=0.;
    double ac_pounds=0., bt_pounds=0., ct_pounds=0.;
    double ac_cost=0., bt_cost=0., ct_cost=0.;
    printf("You could start ordering by typing a, b, c(type 'q' to quit.)\n" \
    "a) Enter the pounds of artichokes desired.\n" \
    "b) Enter the pounds of beets desired.\n" \
    "c) Enter the pounds of carrots desired.\n" \
    "q) quit.\n" 
    );
    

    while (1)
    {
        pmt_ch = getchar();
        if (pmt_ch == '\n') continue;
        double intput_pound;
        switch (pmt_ch)
        {
            case 'a':
                printf("artichokes pounds: ");
                scanf("%lf", &intput_pound);
                ac_pounds += intput_pound; 
                break;
            case 'b':
                printf("beet pounds: ");
                scanf("%lf", &intput_pound);
                bt_pounds += intput_pound; 
                break;
            case 'c':
                printf("carrot pounds: ");
                scanf("%lf", &intput_pound);
                ct_pounds += intput_pound; 
                break;
            case 'q': // when type 'q', it means to finishing the ordering
                ttl_pounds = ac_pounds + bt_pounds + ct_pounds;
                if (ttl_pounds < SHIPPING_WEIGHT_THRESHOLD0)
                    ttl_shipping_fee = 5.00;
                else if (ttl_pounds < SHIPPING_WEIGHT_THRESHOLD1)
                    ttl_shipping_fee = 14.00;
                else
                    ttl_shipping_fee = 14.00 + 0.5*(ttl_pounds-SHIPPING_WEIGHT_THRESHOLD1);
                ac_cost = ARTICHOKE_PER_POUND*ac_pounds;
                bt_cost = BEET_PER_POUND*bt_pounds;
                ct_cost = CARROT_PER_POUND*ct_pounds;
                ttl_cost = ac_cost + bt_cost + ct_cost;
                if (ttl_cost>=100) 
                    ttl_dt = 0.05 * ttl_cost;
                printf("---------------------\n");
                printf("cost per pound $%.2f\n", ttl_cost / ttl_pounds);
                printf("total pounds ordered $%2.f\n", ttl_pounds);
                printf("cost for each vegetable:\n");
                printf("artichoke: $%.2f\n", ac_cost);
                printf("beet: $%.2f\n", bt_cost);
                printf("carrot: $%.2f\n", ct_cost);
                printf("total cost $%.2f\n", ttl_cost);
                printf("discount $%.2f\n", ttl_dt);
                printf("shapping charge $%.2f\n", ttl_shipping_fee);
                printf("----------------------------\n");
                printf("The grand total: $%.2f\n", ttl_cost-ttl_dt+ttl_shipping_fee);
                return 0;
            
        }

        printf("Please select from a/b/c/q:\n") ;
    }
    


    return 0;
}

#include <stdio.h>

int Bit(int decimal) /* Converting given integer to binary */
{
    return (decimal % 2); /* Return remainer */
}

void Binary_Consecutive_Zero_Counter(int val) /* Checking for consecutive zeros on a given integer */
{   
    int prev_bit=0, counter=0, highest_counter=0; /* Creating flags */

    for(int i = 0; val > 0; i++) /* Loopin up UNTIL zero */
    {
        if(Bit(val) == 1) /* Bit is one */
        {
            prev_bit=1; /* Set previous bit as one */
            counter=0; /* Clear current counter */
        }
        else if(Bit(val) == 0) /* Bit is zero */
        {
            prev_bit=0; /* Set previous bit as zero */
            counter++; /* Increase counter */
        }
        if(counter > highest_counter) /* Check if we have highest counter */
            highest_counter = counter; /* Assign new highest counter */
        printf("bit number [%d], bit [%d] \n", i, val % 2); /* Printing bit number and bit value */
        val = val / 2; /* Halved the value */
    }
    printf("Highest amount of consecutive zeros on the binary is %d", highest_counter); /* Printing result */
}

int main()
{   
    int input; /* Creating input variable */
    printf("State your input for Binary Consecutive Zero Counter: "); /* Printing input request */
    scanf("%d", &input); /* Taking input */
    Binary_Consecutive_Zero_Counter(input); /* Calculating result */
    return 0;
}
#include <stdio.h>

int binary[32]; /* Creating binary value array for 32 bit integer */

int *Binary_Conversion(int decimal) /* Converting given integer to binary */
{
    for(int i=0; decimal > 0; i++)
    {
        binary[i] = decimal % 2; /* Storing the remainder from 2 divison */
        decimal = decimal / 2; /* Halving the number */
    }
    return binary; /* Return binary[0] address */
}

void Binary_Consecutive_Zero_Counter(int val) /* Checking for consecutive zeros on a given integer */
{   
    int *binary_ptr; /* Pointer to gather binary value from binary converter */
    int prev_bit=0, counter=0, highest_counter=0; /* Creating flags */
    binary_ptr = Binary_Conversion(val); /* Getting converted binary array */
    for (int i = 31; i >= 0; i-- ) 
    {
        printf( "(Parse %d) : %d\n", i, *(binary_ptr + i));
        if(prev_bit == 0 && counter == 0 && *(binary_ptr + i) == 0)
        {/* Do nothing, ignore padded zeros on the array */}
        else
        {
            if(*(binary_ptr+i) == 0) /* Bit is zero */
            {
                if(prev_bit == 1) /* Previous bit zero */
                    counter=1; /* First zero in the chain */
                else
                    counter++; /* Not the first zero in the chain */
                prev_bit=0; /* Set previous bit as zero */
            }
            else /* Bit is one */
            {
                counter=0; /* Clear current counter */
                prev_bit=1; /* Set previous bit as one */
            }
                
            if(counter > highest_counter) /* Check if we have highest counter */
                highest_counter=counter; /* Assign new highest counter */
        }
    }
    printf("Highest amount of consecutive zeros on the binary is %d", highest_counter);
}

int main()
{   
    int input;
    printf("State your input for Binary Consecutive Zero Counter: ");
    scanf("%d", &input);
    Binary_Consecutive_Zero_Counter(input);
    return 0;
}
//
//  main.c
//  Bitwize
//
//  Created by Bradley Morgan on 7/9/12.
//  Copyright (c) 2012 Morgan Consulting. All rights reserved.
//

#include <stdio.h>

void show_bits(int decimal_value) {
    
    int byte_position = 16;  // allow a number of 16 bits (or 2 bytes) in length
    int counter = 0;  // count the number of loops
  
    char byte_value[byte_position];  // a string to hold the 1s and 0s for displaying the binary number
    
    byte_value[byte_position - 1] = '0';  // initialize the string by setting the significant (leftmost) digit to zero
    
     /*
     
     Okay, here's where the primary logic is done...
     
     The maximum integer value of a 16 bit number is 65536, so we'll use that as our starting point.
     
     Then, with each iteration, we divide that number by two to get the next maximum bit value.
     This is the reverse of 1 times X to the power of 2, the basis for the binary number system.
     So, were just working our way from left to right down the bits.
    
     On each bit iteration, we need to compare the bit's binary value to our integer to see if the bits are both set.
     To do this, we use a bitwise AND operation.
     
     So, for bit number 4 (8 in decimal), with our input value as, let's say, 13:
     
                          128  64  32  16  8   4   2   1
     Bit Value in Binary: [0] [0] [0] [0] [1] [0] [0] [0]
     Int Value in Binary: [0] [0] [0] [0] [1] [1] [0] [1]
     
     
     We would have a match, resulting in a nonzero number (in this case 8).
     
     */
    
    for(int bit_value = 65536; bit_value > 0; bit_value /= 2) {  
        
        int bit_match = (bit_value & decimal_value);  // this is the bitwise AND operation
        
        // print out where we are in the loop and the result of our check
        
        printf("----------\nIteration: %i\nBit Value: %i\nInteger Value:%i\nBitwise AND Result:%i\n", counter, bit_value, decimal_value, bit_match);
        
        // if we have a match on the bitwise AND operation, the current bit in the binary equivalent to our integer needs to be set to 1
        // if not, we need to set it to zero
        
        if(bit_match) {
            
            byte_value[--byte_position] = '1';
            
        } else {
            
            byte_value[--byte_position] = '0';
        }
        
        counter++;  
        
    }
    
    
    // now we've got a string representation of our binary number figured out, so let's see it
    
    int len = sizeof(byte_value);
    
    printf("\n\n");
           
    for(int i = (len - 1); i >= 0; i--) {
        
        printf("[%c]", byte_value[i]);
        
    }
           
    printf("\n\n");
    
        
}

int main() {

   	int input = 0;
	
    while(1) {
	
        printf("What number would you like to convert to binary? ");

		if (scanf("%d", &input) == 1) {
		
            show_bits(input);
            
        } else {
            
            printf("\nPlease give me a number.\n");
            
        }
	
    }
    
}



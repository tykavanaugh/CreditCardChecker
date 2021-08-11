#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    long ccNum = 0;
    ccNum = get_long("Enter Card Number: ");
    int total = 0;
    for (long i = 100 ; i < ccNum*10 ; i = i * 100) { //First step of check
        long digit = 0;
        digit = (ccNum % i) ;
        digit = digit / (i/10);
        digit *= 2 ;
        if (digit > 9){
            total += (digit % 10);
            total += 1;
        }
        else{
            total += digit;
        };

    }
    for (long i = 10 ; i < ccNum*10 ; i = i * 100) { //Second step of check
        long digit = 0;
        digit = (ccNum % i) ;
        digit = digit / (i/10);
        total += digit;
    }
    if (total % 10 == 0){
    long ccNumLen = 0 ;
    int firstTwo = 0;
    for (long i = 1 ; i < ccNum ; i *= 10){
            ccNumLen = i;
        }
    printf("%li",ccNumLen);
    firstTwo = ((ccNum % (ccNumLen * 10 )) / (ccNumLen/10) );
    if ((firstTwo == 34 || firstTwo == 37 ) && ccNumLen == 100000000000000) {//amex
    printf("AMEX\n");

    } else if ((firstTwo < 56 && firstTwo > 50) && ccNumLen == 1000000000000000 ) {//Mastercard
    printf("MASTERCARD\n");
    } else if (firstTwo < 50 && firstTwo > 39) {//Visa
        if (ccNumLen == 1000000000000000 || ccNumLen == 1000000000000) {
            printf("VISA\n");} else {
                printf("INVALID\n");
            }
    } else {
        printf("INVALID\n");
    }
    } else {
    printf("INVALID\n");
    };
}

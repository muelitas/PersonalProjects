/****************************************************************
  * File:    pointersAndStrings.C
  * Author:  Mario Esparza
  * Date:    04/27/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following:
  *     1. How to loop through a String using Pointers
  *     2. How to copy one string to another using Pointers
  * 
****************************************************************/ 

#include <stdio.h>

/*Function that copies one string into the other. Whichever string "orig" points
  to, will be copied into the string that "copy" points to.*/
void copyStr(char *orig, char *copy){
    while(*orig != '\0'){   //loop until end of string is reached
        *copy = *orig;
        orig++;
        copy++;
    }
    *copy = *orig; //Don't foget to copy the null character '\0'
    return;
}


int main(){
    char str[] = "Coding is awesome";
    char *ptc; //pointer to character
    ptc = str; //remember, same as: ptc = &str[0];
    
    //First, let's loop through the string and print its characters
    while(1){
        printf("%c", *ptc);     //dereference and print
        ptc++;                  //point to the next location in memory
        if(*ptc == '\0'){       //break loop when end of string is reached
            break;
        }
    }
    printf("\n");
    
    //We can save a few lines of code if we implement it in the following way:
    ptc = str;
    while(*ptc != '\0'){   //loop until end of string is reached
        printf("%c", *ptc);
        ptc++;
    }
    printf("\n");
    //Both methods do the same, one being slightly more efficient than the other.
    
    //Next, let's copy str into str2 with the help of a function
    char str2[70];
    copyStr(str, str2);
    
    //Let's check it was copied correctly
    ptc = str2; //have your pointer point to the new string
    printf("str2 = \"");
    while(*ptc != '\0'){
        printf("%c", *ptc);
        ptc++;
    }
    printf("\"\n");
    //Success!
    
    /*It seems we printed strings quite some times. Can you make a function that
      does this for you, implementing the while-loop method in your function?*/
    return 0;
}
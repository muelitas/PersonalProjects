/******************************************************************************
  * File:	05a_functions_intro.c
  * Author:	Mario Esparza
  * Date:	09/13/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this file we will talk about:
  * - TODO
  * - You might have to use -lm when compiling
******************************************************************************/
#include <stdio.h>
#include <math.h>

void error_message(){
    printf("Sorry, but there is something wrong with your input.\n");
    return;
}
void sqrt_error(){
    printf("ERROR: You can't have negative values inside a square root.\n");
    return;
}
void under0_error(){
    printf("ERROR: You can't have zero as the divisor.\n");
    return;
}
void error(int error_number){
    //Notice that we have to specify the datatype of error_number
    if(error_number == 0){
        printf("ERROR: You can't have negative values inside a square root.\n");
    }else if(error_number == 1){
        printf("ERROR: You can't have zero as the divisor.\n");
    }else{
        printf("I can't recognize this error number.\n");
        printf("The error number provided is: %d\n", error_number);
    }
    return;
}
void rect_get_details(float height, float width){
    //Again, notice that we have to declare the datatype of width and heigth
    float area, perimeter;
    area = height*width;
    perimeter = 2*width + 2*height;
    printf("The area of your rectangle is %.2f\n", area);
    printf("The perimeter of your rectangle is %.2f\n", perimeter);
    return;
}
void rect_get_dets(){
    float h, w;
    printf("What is the height of your rectangle? ");
    scanf("%f", &h);
    printf("What is the width of your rectangle? ");
    scanf("%f", &w);

    float area, perimeter;
    area = h*w;
    perimeter = 2*w + 2*h;
    printf("The area of your rectangle is %.2f\n", area);
    printf("The perimeter of your rectangle is %.2f\n", perimeter);
    return;
}
void rect_ask_values(){
    //First, we scan the values from the user
    float h, w;
    printf("What is the height of your rectangle? ");
    scanf("%f", &h);
    printf("What is the width of your rectangle? ");
    scanf("%f", &w);
    //Then, we call another function to get the details (area & perimeter). In
    //other words rect_ask_values calls rect_get_details.
    rect_get_details(h,w);
    return
}

int main(){
    /*There will be times in our programs where a certain amount or kind of
     * operations will be repeated. Sometimes, occupying more space in our co-
     * de than what they need. Just like loops allowed us to repeat an opera-
     * tion multiple times, "Functions" allow us to use a certain operation
     * whenever we want, without having to re-type all the code again. Before
     * I dive into an example however, let's look at its syntax first:*/

    /* datatype nameOfFunction( parameters ){
     *     //code that will run in the function
     *     return somethingOrNothing;
     * }
     *
     * TODO Expand on the syntax.
     *
     * And I like to think there are 4 general ways of calling a function:
     * 1) void and zero parameters
     * 2) void and one or more parameters
     * 3) with a datatype and zero parameters
     * 4) with a datatyoe and one or more parameters
     *
     * Let's give a look to the first case. Imagine that throughout your pro-
     * gram you want to display a general error message in case the user makes
     * a mistake. You could create a function that prints out this message for
     * you. Let's say you have this equation x*sqrt(y)/z and you create a pro-
     * that does it for you:*/
    float x, y, z;
    int error_counter = 0;
    printf("What is the value of x? ");
    scanf("%f", &x);
    printf("What is the value of y? ");
    scanf("%f", &y);
    if(y<0){
        error_message();
        error_counter++;
    }
    printf("What is the value of z? ");
    scanf("%f", &z);
    if(z == 0){
        error_message();
        error_counter++;
    }
    if(error_counter != 0){
        printf("I can't solve the equation since there are problems with");
        printf(" your input.\n");
    }else{
        float result = x*sqrt(y)/z;
        printf("The result is %.2f.\n", result);
    }
	/*The function was defined on top, before and outside of main. This way the
     * program knows it exists and what it does. If you define the function af-
     * ter main, you will get an error. TODO in class, define the function af-
     * ter main and try to compile.*/
    /*Going back to the function, you can see that it is defined as void, mea-
     * ning that the function won't return anything. And rest assured, after
     * return, we are not returning anything. Also, notice that the parenthe-
     * sis of the function don't have anything. This means the function is not
     * receiving/accepting any parameters. If you ask me however, there is a 
     * change I would make to the program we just did:*/
    error_counter = 0;
    printf("What is the value of x? ");
    scanf("%f", &x);
    printf("What is the value of y? ");
    scanf("%f", &y);
    if(y<0){
        sqrt_error();
        error_counter++;
    }
    printf("What is the value of z? ");
    scanf("%f", &z);
    if(z == 0){
        under0_error();
        error_counter++;
    }
    if(error_counter != 0){
        printf("I can't solve the equation since there are problems with");
        printf(" your input.\n");
    }else{
        float result = x*sqrt(y)/z;
        printf("The result is %.2f.\n", result);
    }
    /*Instead of having one function outputting a general message, we create 2
     * functions with each having a detailed message. Both void and with zero
     * parameters. To use each function, what we have to do is to "call" it, 
     * you type the name of the function followed by its parenthesis. Now, if
     * you don't like the idea of having 2 functions, but you want to keep the
     * detailed messages, we can do the following:*/
    error_counter = 0;
    printf("What is the value of x? ");
    scanf("%f", &x);
    printf("What is the value of y? ");
    scanf("%f", &y);
    if(y<0){
        error(0);
        error_counter++;
    }
    printf("What is the value of z? ");
    scanf("%f", &z);
    if(z == 0){
        error(1);
        error_counter++;
    }
    if(error_counter != 0){
        printf("I can't solve the equation since there are problems with");
        printf(" your input.\n");
    }else{
        float result = x*sqrt(y)/z;
        printf("The result is %.2f.\n", result);
    }
    /*We define a function called "error". It is of type void and it accepts
     * one parameter. As defined in the function, this parameter is an integer
     * called error_number, this means that every time you call the function,
     * you will have to send an integer to such inside the parenthesis. If you
     * send a float, char, double or bool, the compiler might not yell at you,
     * but you would risk getting unexpected results later on.*/
    error('a');
    error(2.0);
    error(1.5684);
    /*To avoid unexpected behaviors, keep your datatypes the same. The parame-
     * ters you "send" must match the datatype of the paramters your function
     * is supposed to receive.* Let's look at another example of void with pa-
     * rameters:*/
    float h, w;
    printf("What is the height of your rectangle? ");
    scanf("%f", &h);
    printf("What is the width of your rectangle? ");
    scanf("%f", &w);
    rect_get_details(h,w);
    /*If we have a second rectangle, we can repeat the process:*/
    printf("What is the height of your rectangle? ");
    scanf("%f", &h);
    printf("What is the width of your rectangle? ");
    scanf("%f", &w);
    rect_get_details(h,w);
    /*However, we can improve this (make our function more efficient). Can you
     * see how? Answer: we can incude the scanning inside the function:*/
    rect_get_dets();
    /*With only one line of code (in main), you can ask the user for the rec-
     * tangle's information and you can output the details of such. Before we
     * dive into functions that return something (have datatypes) I want to
     * show you how functions can call other functions:*/
    rect_ask_values();
    /* For this to work however, the function that is being called, has to be
     * defined before the function that is making the calling. Otherwise, it
     * won't work. TODO try defining rect_get_details below rect_ask_values and
     * see what happens.*/

    /*Now we are ready to move into functions that return something.*/
	return 0;
}

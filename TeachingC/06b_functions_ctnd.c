/******************************************************************************
  * File:	05b_functions_ctnd.c
  * Author:	Mario Esparza
  * Date:	09/13/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this file we will talk about:
  * - TODO
******************************************************************************/
#include <stdio.h>

int calculate_number(float lw, float ld, float cw, float cd){
    /*When the function is called, these four variables are initialized. In our
     * first example, lw will be equal to lot_w; ld = lot_d; cw = car_w; and
     * cd = car_d.*/
    //First, we check to see how many cars fit depth wise:
    int depth_num = ld / cd;
    printf("Depth-wise, we can fit %d cars.\n", depth_num);
    //Next, we check to see how many cars fit width wise:
    int width_num = lw / cw;
    printf("Width-wise, we can fit %d cars.\n", width_num);
    int total_num = depth_num * width_num;
    return total_num;
    /*I could have also returned the multiplication:
     * return depth_num * width_num; */
}
int ask_and_calc_number(){
/*****************************************************************************/
    /*This function doesn't receive any parameters, thus, we have to declare
     * them somewhere in the function:*/
    float lot_w, lot_d;
    float car_w, car_d;
    printf("What are the width and depth of the lot?\n");
    printf("Please separate them by a dash (-), width first:\n");
    scanf("%f-%f", &lot_w, &lot_d);
    printf("Same for the width and depth of the cars:\n");
    scanf("%f-%f", &car_w, &car_d);

    //First, we check to see how many cars fit depth wise:
    int depth_num = lot_d / car_d;
    printf("Depth-wise, we can fit %d cars.\n", depth_num);
    //Next, we check to see how many cars fit width wise:
    int width_num = lot_w / car_w;
    printf("Width-wise, we can fit %d cars.\n", width_num);
    int total_num = depth_num * width_num;
    return total_num;
}
float CeltoFah(float c){
    float f = c * 1.8 + 32;
    return f;
}
float CeltoKel(float c){
    float k = c + 273.15;
    return k;
}
float KeltoCel(float k){
    return k - 273.15;
}
float KeltoFah(float k){
    float c = KeltoCel(k);
    float f = CeltoFah(c);
    return f;
}
void convert_celsius(float celsius){
    float f = celsius * 1.8 + 32;
    float k = celsius + 273.15;
    printf("The equivalent temperature in Fahrenheit is: %.2f\n", f);
    printf("The equivalent temperature in Kelvin is: %.2f\n", k);
    return;
}
void ask_and_convert(){
    float C, F, K;
    printf("Please provie the temperature in Celsius: ");
    scanf("%f", &C);
    F = C * 1.8 + 32;
    K = C + 273.15;
    printf("The equivalent temperature in Fahrenheit is: %.2f\n", F);
    printf("The equivalent temperature in Kelvin is: %.2f\n", K);
    return;
}

int main(){
    /*A function that "returns" something is a function that can be used to
     * assign values. In other words, the function call returns something and
     * this something can be assigned to a variable. That's a function call of
     * this type would look like this: float area = get_area(); Not only do you
     * have the function call (right side of the equal sign), but you also have
     * a variable (left side). Let's look at an example. Imagine you have a
     * piece of land that you are trying to get into a parking lot (good passi-
     * ve income), but you don't know how many cars you could fit, so you crea-
     * te a program to help you figure this out:*/
    float lot_w, lot_d;
    float car_w, car_d;
    printf("What are the width and depth of the lot?\n");
    printf("Please separate them by a dash (-), width first:\n");
    scanf("%f-%f", &lot_w, &lot_d);
    printf("Same for the width and depth of the cars:\n");
    scanf("%f-%f", &car_w, &car_d);
    int num_of_cars;
    num_of_cars = calculate_number(lot_w, lot_d, car_w, car_d);
    printf("\nIn total, we can fit %d cars.\n", num_of_cars);
    /*We declare an integer in main and set it equal to calculate_number. What-
     * ever this function calculates and returns (total_num) will be assigned
     * to num_of_cars. You can think of it as us saying:
     * num_of_cars = total_num; (but with some magic hehe). The four parameters
     * sent to the function are floats, thus, they have to be floats in the
     * function definition as well. Lastly, we could have also declared and
     * initialized num_of_cars in a single line:
     * int num_of_cars = calculate_number(lot_w, lot_d, car_w, car_d);*/
    
    /*Making sense? ... Now, you might tell me "Well, this makes sense, but
     * why is it needed? We could have done it without a function" And that is
     * correct, we could have done it without a function. However, what would
     * happend if later in the program, the depth of the lot changes (you buy
     * and adjacent land to yours)? Or the width of the lot shrinks (someone
     * buys a piece of your land)? Without the function, we would have to re-
     * write everything again. With the function however, we only have to call
     * it again. For example:*/
    printf("\nI heard you bought more land. What are the new values of");
    printf(" your lot's [depth-width]?\n");
    scanf("%f-%f", &lot_w, &lot_d);
    num_of_cars = calculate_number(lot_w, lot_d, car_w, car_d);
    printf("\nNow, you can fit %d cars.\n", num_of_cars);
    /*Is this neat or what? Instead of re-typing all lines of code inside the
     * function, we only needed to call it with the updated dimensions of the
     * lot. We didn't have to do anything to car_d and car_w because these di-
     * mensions remained the same.*/

    /*There is one case that we haven't discussed; datatype without parameters.
     * Before I show you how, can you tell me how we could implement this case
     * in the example of cars and lots? Answer:*/
    int number_cars;
    number_cars = ask_and_calc_number();
    printf("\nYou can fit %d cars.\n", number_cars);
    /*With only three lines of code in main, you can calculate the number of
     * cars that can fit in the lot. At the end, good programming practices are
     * exactly this. To have main with the least number of code-lines.*/

    /*Let's look at another example using temperature conversions. Imagine you
     * have to create a program that converts celsius to farenheit and kelvin.
     * If we were to do it in main, it would look like this:*/
    float C, F, K;
    printf("Please provie the temperature in Celsius: ");
    scanf("%f", &C);
    F = C * 1.8 + 32;
    K = C + 273.15;
    printf("The equivalent temperature in Fahrenheit is: %.2f\n", F);
    printf("The equivalent temperature in Kelvin is: %.2f\n", K);
    /*Now, let me repeat the process but using two different functions:*/
    F = CeltoFah(C);
    K = CeltoKel(C);
    printf("The equivalent temperature in Fahrenheit is: %.2f\n", F);
    printf("The equivalent temperature in Kelvin is: %.2f\n", K);
    /*I send C to my functions. In each one, I receive C, calculate their res-
     * pective equivalent and return such. We can also implement a function
     * does both operations for us and prints them out:*/
    convert_celsius(C);
    /*This would be another example of a void function with one parameter. AND
     * we can also do a void function with no parameters:*/
    ask_and_convert();
    /*Making sense? Again, most important thing about functions that return so-
     * mething is that they have an equal sign to the left of their function
     * call; and whatever they return will be assigned to the variable that is
     * to the left of the equal sign. Let's complicate things a little. Let's
     * ask the user for kind of degrees that are being inputted, and let's ask
     * to which degrees he/she would like them converted:*/
    char init_unit, desired_unit;
    float init_value, converted_value;
    printf("What is the value of your degrees? ");
    scanf("%f", &init_value);
    printf("What is the unit of temperature? [F, C or K]\n");
    scanf(" %c", &init_unit);
    printf("To which unit would you like to convert them to? [F, C or K]\n");
    scanf(" %c", &desired_unit);

    //If initial unit is Kelvin:
    if(init_unit == 'K'){
        if(desired_unit == 'C'){
            //Converting Kelvin to Celsius
            converted_value = KeltoCel(init_value);
            printf("%.2f Kelvin = %.2f Celsius\n", init_value, converted_value);
        }else if(desired_unit == 'F'){
            //Converting Kelvin to Fahrenheit
            converted_value = KeltoFah(init_value);
            printf("%.2f Kelvin = %.2f Fahrenheit\n", init_value, converted_value);
        }else{
            printf("You inputted %c as the desired unit.\n", desired_unit);
            printf("I don't know what kind of unit it is.\n");
        }
    }else if(init_unit == 'C'){ //If initial unit is Celsius
        if(desired_unit == 'K'){
            //Converting Celsius to Kelvin
            converted_value = CeltoKel(init_value);
            printf("%.2f Celsius = %.2f Kelvin\n", init_value, converted_value);
        }else if(desired_unit == 'F'){
            //Converting Celsius to Fahrenheit
            converted_value = CeltoFah(init_value);
            printf("%.2f Celsius = %.2f Fahrenheit\n", init_value, converted_value);
        }else{
            printf("You inputted %c as the desired unit.\n", desired_unit);
            printf("I don't know what kind of unit it is.\n");
        }
    }//This will be a task of your assignment.

/*****************************************************************************/
//nested loops
//multi dimensional arrays
//post/pre increment/decrement
//numeric systems
//%i vs %d

    return 0;
}

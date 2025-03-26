//EECS 348 Lab 7 - Part 2
//A temperature converter
//Inputs: A temperature, a scale, and a new scale
//Outputs: The temperature in the new scale
//Myself, ChatGPT
//Joey Ippolito, 3114450
// 3/24/2025
#include <stdio.h>
#include <string.h> //Imports libraries

//Looked up conversion formulas on Google
float celsius_to_fahrenheit(float celsius) {        //Converts celsius to fahrenheit
    return celsius * 9 / 5 + 32;
}

float celsius_to_kelvin(float celsius) {    //Converts celsius to kelvin
    return celsius + 273.15;
}

float fahrenheit_to_celsius(float fahrenheit) {   //Converts fahrenheit to celsius
    return (fahrenheit - 32) * 5 / 9;
}

float fahrenheit_to_kelvin(float fahrenheit) {  //Converts fahrenheit to kelvin
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvin_to_celsius(float kelvin) {     //Converts kelvin to celsius
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {    //Converts kelvin to fahrenheit
    return (kelvin - 273.15) * 9 / 5 + 32;
}

void categorize_temperature(float celsius) {    //Sets categories for freezing, cold, comfortable, hot, and extreme heat
    if (celsius < 0) {          //sets condition for freeing, below 0 in celsius
        printf("Freezing. Stay indoors!\n");        //returns category
    } else if (celsius < 10) {      //Because using else if statements, do not need a lower bound as it is covered by the previous statemnt. Thus, <10 is the same as 0<=celsius<10
        printf("It's cold. Wear a jacket!\n");  //returns cold
    } else if (celsius < 25) {      //if 10<=celsius<25
        printf("It's comfortable outside.\n");  //returns comfortable
    } else if (celsius < 35) {      //if 25<=celsius<35
        printf("It's hot. Stay hydrated!\n");   //returns hot
    } else {        //if celsius>=35
        printf("There is extreme heat. Stay indoors!\n");   //returns extreme heat
    }
}

int main() {    //Main function
    float temperature;  //Declares variables
    char scale[10], new_scale[10];  //sets size of scale and new_scale to 10

    printf("Enter the temperature: ");  //Asks for temperature
    if(scanf("%f", &temperature)!=1){   //Used Chatgpt to help me with input validity for temp
        printf("Invalid input. Please enter a number.\n");  //raises error if input is not a number
        return 1;
    }

    printf("Enter Celsius, Fahrenheit, or Kelvin (Use C, F, K): "); //Asks user for scale. Used letters instead of full words for testing convenience/simplicity
    scanf("%s", scale); //Scans for scale

    printf("Enter the new scale (C, F, K): ");  //Asks for new scale
    scanf("%s", new_scale); //Scans for new scale
    //Used chatgpt to help with strcmp and the proper syntax for it
    if ((strcmp(scale, "C") == 0 && temperature < -273.15) ||  (strcmp(scale, "F") == 0 && temperature < -459.67) || (strcmp(scale, "K") == 0 && temperature < 0)) {    //Checks if temperature is impossible, i.e. below absolute zero
        printf("Invalid input. The temperature is below absolute zero.\n"); //returns error message for impossible temperature
        return 1;   //exits program
    }
    if(strcmp(scale, new_scale) ==0 ){  //Checks if the scales are the same
        printf("Invalid input. Please enter two different scales.\n");  //returns error message for same scales
        return 1;   //exits program
    }
    //Used print statement that calls conversion function for each conversion
    if (strcmp(scale, "C") == 0 && strcmp(new_scale, "F") == 0) {   //runs for celsius to fahrenheit conversion
        printf("The temperature in Fahrenheit is: %f\n", celsius_to_fahrenheit(temperature));   //prints converted temperature
    } else if (strcmp(scale, "C") == 0 && strcmp(new_scale, "K") == 0) {    //runs for celsius to kelvin conversion
        printf("The temperature in Kelvin is: %f\n", celsius_to_kelvin(temperature));   //prints converted temperature
    } else if (strcmp(scale, "F") == 0 && strcmp(new_scale, "C") == 0) {    //runs for fahrenheit to celsius conversion
        printf("The temperature in Celsius is: %f\n", fahrenheit_to_celsius(temperature));  //prints converted temperature
    } else if (strcmp(scale, "F") == 0 && strcmp(new_scale, "K") == 0) {    //runs for fahrenheit to kelvin conversion
        printf("The temperature in Kelvin is: %f\n", fahrenheit_to_kelvin(temperature));    //prints converted temperature
    } else if (strcmp(scale, "K") == 0 && strcmp(new_scale, "C") == 0) {    //runs for kelvin to celsius conversion
        printf("The temperature in Celsius is: %f\n", kelvin_to_celsius(temperature));  //prints converted temperature
    } else if (strcmp(scale, "K") == 0 && strcmp(new_scale, "F") == 0) {    //runs for kelvin to fahrenheit conversion
        printf("The temperature in Fahrenheit is: %f\n", kelvin_to_fahrenheit(temperature));    //prints converted temperature
    } else {
        printf("Invalid input. Please enter C, F, or K.\n");    //returns error message for invalid input, i.e. not one of the 3 letters
    }
    //Because the categorize function is just for celsius, I wrote a seperate if-else block to handle categories. This way, the new scale can be anything without having to change the categorize function
    if (strcmp(scale, "C") == 0) {  //Checks if the scale is celsius
        categorize_temperature(temperature);    //categorizes temperature
    } else if (strcmp(scale, "F") == 0) {   //Checks if the scale is fahrenheit
        categorize_temperature(fahrenheit_to_celsius(temperature));    //converts to temperature to celsius and categorizes it
    } else if (strcmp(scale, "K") == 0) {   //Checks if the scale is kelvin
        categorize_temperature(kelvin_to_celsius(temperature));    //same as fahrenheit
    }
    
    return 0;   //exits program
}

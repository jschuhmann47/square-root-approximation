#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const MAX_ITERATIONS = 10;

// Function declarations

// Calculates f(x) = x^2 - n where n is the user input
double original_function(double x, int root);

// Calculates f'(x) = 2 * x
double derivative_function(double x);

// Calculates an aproximate square root using Newton - Raphson, with iterations equal to MAX_ITERATIONS
double square_root(int root);

// Shows the percentage of error bewteen the approximate square root and the user input
void showErrorPercentage(int originalNumber, double result);

int main(){
    //Input
    int input;
    printf("Enter an integer number: ");
    scanf("%d", &input);

    // Result

    double squareRoot = square_root(input);

    printf("The square root is %f",squareRoot); 
    printf("\n");

    showErrorPercentage(input, squareRoot);

    return 0;
}

double square_root(int userInput){
    double previousValue = 1; // A decent starting guess is 1, no matter what the input. (check why is this)
    
    for (int i = 0; i < MAX_ITERATIONS; i++){
        previousValue =
        previousValue - 
                        (original_function(previousValue,userInput) 
                        / 
                        derivative_function(previousValue));
        printf("loop number: %d, value: %f\n",i,previousValue);

        if(previousValue * previousValue == userInput){
            break;
        }
    }

    return previousValue;
}

double original_function(double x, int root){
    return x * x - root;
}

double derivative_function(double x){
    return 2 * x;
}

double absolute_error(int originalNumber, double result){
    return fabs(sqrt(originalNumber) - result);
}

void showErrorPercentage(int originalNumber, double result){

    double percentage = absolute_error(originalNumber, result) * 100.0 / originalNumber;
    printf("The error is a %.2f percent", percentage);
}
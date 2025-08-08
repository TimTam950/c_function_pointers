#include "stdio.h"
#include "stdbool.h"

void function(int x) {
    printf("x: %d\n", x);
}

double add(double x, double y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

// function is called select operation, it returns pointer to a function that accepts two ints and returns an int
int (*select_operation())(int, int) {
    int option = 0;
    printf("select an operation\n");
    printf("1) Subtract\n");
    printf("2) Multiply\n");
    printf("3) Divide\n");
    printf("Enter: \n");
    scanf("%d", &option);

    if (option == 1) return subtract;
    if (option == 2) return multiply;
    if (option == 3) return divide;
    return NULL;
}

bool freeze_C(int temp) {
    if (temp <= 0) return true;
    return false;
}

bool freeze_F(int temp) {
    if (temp <= 32) return true;
    return false;
}

// function that accepts pointer to function as parameter
void is_freezing( bool (*freeze_check)(int) ) {
    int temperature = 0;
    printf("Please enter temperature\n");
    scanf("%d", &temperature);
    if (freeze_check(temperature)) {
        printf("It is freezing\n");
    } else {
        printf("it is not freezing\n");
    }
}

int main() {
    // function pointer declaration (that we will set equal to function)
    void (*function_pointer)(int);
    function_pointer = &function;
    (*function_pointer)(4);

    // dont need to pass pointer to declaration or dereference it during a call
    double (*add_pointer)(double, double) = add;
    double result = add_pointer(1,2);
    printf("add: %f\n", result);

    // array of function pointers
    int (*array[])(int, int) = {subtract, multiply, divide};
    int product = (*array[1])(15,3);
    printf("product: %d\n", product);

    // using function that returns function pointer
    int (*operation)(int, int) = select_operation();
    printf("answer: %d\n", operation(20,5));

    // using function that accepts function as parameter
    is_freezing(freeze_C);

    return 0;
}
#include <stdio.h>
#include <math.h>
#include <cctype>
#include <stdio_ext.h>
#include "interface.h"

bool compare_zero(const double a) {
    if (fabs(a) < 1e-6) return true;
    return false;
}

int get_solution_equation(const double a, const double b, const double c, double solution[]) {
    int number_solution = 0; // TODO add my_assert(0)
    double x1_re = NAN, x1_im = NAN, x2_re = NAN, x2_im = NAN;

    if (compare_zero(a)) { // bx + c = 0
        if (compare_zero(b)) { // c = 0
            if (compare_zero(c)) 
                number_solution = INFINIT_SOLUTIONS;
            else
                number_solution = NO_SOLUTIONS;
        }
        else { //bx + c = 0
            number_solution = ONE_SOLUTION;
            x1_re = -c/b;   
        }
    }

    else { //ax^2 +bx + c
        double D = b*b - 4*a*c;

        if (D > 0 && !compare_zero(D)) { // D > 0
            double sqrt_D = sqrt(D);
            number_solution = TWO_SOLUTIONS;
            x1_re = (-b + sqrt_D) / (2 * a);
            x2_re = (-b - sqrt_D) / (2 * a);
        }
        else if (compare_zero(D)) { // D = 0
            number_solution = ONE_SOLUTION;
            x1_re = -b / 2 * a;
        }
        else { // D < 0
            double sqrt_D = sqrt(-D);
            number_solution = TWO_COMPLEX_SOLUTIONS;
            x1_re = -b / (2 * a);
            x1_im = sqrt_D / (2 * a);
            x2_re = -b/ (2 * a);
            x2_im = -sqrt_D / (2 * a);
        }
    }

    if (number_solution == ONE_SOLUTION) {
        solution[0] = x1_re; // *(solution + 0)
    }

    else if (number_solution == TWO_SOLUTIONS) {
        solution[0] = x1_re;
        solution[1] = x2_re;
    }

    else if (number_solution == TWO_COMPLEX_SOLUTIONS) {
        solution[0] = x1_re;
        solution[1] = x2_re;
        solution[2] = x1_im;
        solution[3] = x2_im;
    }

    return number_solution;
}

int solution_compare(const double sol[], const double sol_res[]) {
    if ((isnan(sol[0]) && isnan(sol_res[0])) || (compare_zero(sol_res[0] - sol[0])))
        if ((isnan(sol[1]) && isnan(sol_res[1])) || (compare_zero(sol_res[1] - sol[1])))
            if ((isnan(sol[2]) && isnan(sol_res[2])) || (compare_zero(sol_res[2] - sol[2])))
                if ((isnan(sol[3]) && isnan(sol_res[3])) || (compare_zero(sol_res[3] - sol[3]))) {
                    return true;
                }
    return false;
}

bool get_coeffs(double* a, double* b, double* c) {
    printf("*--*--*--*--*--*--*--*--*--*--*--*\nEnter a, b & c for quadratic equation:\n");

    #define inp_coef(coef) \
    //     printf(#coef " = ");   \
    //     if (!scanf("%lf", coef)) {\
    //         printf("Wrong format!\n*--*--*--*--*--*--*--*--*--*--*--*\n");\
    //         while (getchar() != '\n') {};\
    //         return false;               \
    //     }

    // inp_coef(a)
    // inp_coef(b)
    // inp_coef(c)

    if (scanf("%lf %lf %lf", a, b, c) != 3)
    {
        printf("Wrong format!\n*--*--*--*--*--*--*--*--*--*--*--*\n");
        while (getchar() != '\n') {};
        return false;
    }

    // printf("a = ");
    // if (!scanf("%lf", a)) {
    //     printf("Wrong format!\n*--*--*--*--*--*--*--*--*--*--*--*\n");
    //     while (getchar() != '\n') {};
    //     return false;
    // }
    // printf("b = ");
    // if (!scanf("%lf", b)) {
    //     printf("Wrong format!\n*--*--*--*--*--*--*--*--*--*--*--*\n");
    //     while (getchar() != '\n') {};
    //     return false;
    // }
    // printf("c = ");
    // if (!scanf("%lf", c)) {
    //     printf("Wrong format!\n*--*--*--*--*--*--*--*--*--*--*--*\n");
    //     while (getchar() != '\n') {};
    //     return false;
    // }
    while (getchar() != '\n') {};
    return true;
}

void print_solutions(const int number_solution, const double solution[]) {
    switch (number_solution) { // TODO combine to a "print solution" function
            case NO_SOLUTIONS:
                printf("There's no solutions\n");
                break;
            
            case INFINIT_SOLUTIONS:
                printf("There's many solutions\n");
                break;

            case ONE_SOLUTION:
                printf("There's one solution:\nx1 = %lf\n", solution[0]);
                break;

            case TWO_SOLUTIONS:
                printf("There's two solutions:\nx1 = %lf\nx2 = %lf\n", solution[0], solution[1]);
                break;

            case TWO_COMPLEX_SOLUTIONS:
                printf("There's only complex solutions:\nx1 = %lf + %lf i\nx2 = %lf - %lf i\n",
                    solution[0], solution[2], solution[1], -solution[3]);
                break;
            }
    printf("*--*--*--*--*--*--*--*--*--*--*--*\n");
}

int repeat_program() {
    printf("Do you want to continue? y/n\n");
    char c;
    if (scanf("%c", &c)) {
        while (getchar() != '\n') {};
        if (c == 'y')
            return 1;
        else if (c == 'n') 
            return 0;
        else {
            printf("Please, write y/n. ");
            repeat_program();
        } 
    }
    //while (getchar() != '\n') {};
    return 1;
}

int use_program() {
    while(1) {
        double a = NAN, b = NAN, c = NAN;
        double solution[4] = {NAN, NAN, NAN, NAN};
        int number_solution = INPUT_VALUE;

        if (get_coeffs(&a, &b, &c)) { // TODO combine to an "input" function
            number_solution = get_solution_equation(a, b, c, solution);
            print_solutions(number_solution, solution);
        }

        if (!repeat_program())
            return 0;
    }
    return 1;
}

int test_program(const char* file) {
    double a = NAN, b = NAN, c = NAN, sol[4] = {NAN, NAN, NAN, NAN};
    int num = INPUT_VALUE;

    FILE* tests = fopen(file, "r"); // pass filename as a function arg 
    int i = 1, counter = 0;
    while (fscanf(tests, "%lf %lf %lf %lf %lf %lf %lf %d", 
                &a, &b, &c, &sol[0], &sol[1], &sol[2], &sol[3], &num) != EOF) {
        double sol_res[4] = {NAN, NAN, NAN, NAN};
        int num_res = INPUT_VALUE;

        num_res = get_solution_equation(a, b, c, sol_res);
        if ((num_res == num) && (solution_compare(sol, sol_res))) {
            printf("TEST[%d]: is OK\n", i);
            counter++;
        }
        else {
            printf("TEST[%d]: is WRONG\nGET: a = %lf, b = %lf, c = %lf, x1 = %lf + %lf i x2 = %lf + %lf i num = %d\n",
            i, a, b, c, sol_res[0], sol_res[2], sol_res[1], sol_res[3], num_res);
            printf("NEED:                                          x1 = %lf + %lf i x2 = %lf + %lf i num = %d\n",
            sol[0], sol[2], sol[1], sol[3], num);
        }
        i++;
    }
    printf("END TESTING. %d/%d TESTS PASSING\n", counter, i - 1);
    return 0;
}
/**
 * @file interface.h
 * @author Sofyaa Savelyeva
 * @brief file with interface function
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief enumeration of cases of solving a quadratic equation
 * 
 */
enum CASES {
    INPUT_VALUE = 13, // rename default
    TWO_COMPLEX_SOLUTIONS = -2, //< Constant to define that solutions are complex
    INFINIT_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2,
};


#define my_assert(condition, ret_on_err)                                                    \
    if (!condition) {                                                                       \
        fprintf(stderr, "ERROR %s in FILE %s:%d", #condition, __FILE__, __LINE__);          \
        return ret_on_err;                                                                  \
    }


/**
 * @brief this function compare double a with EPS = 1e-6 
 * which is almost zero
 * 
 * return 1 if true, 0 if false
 * 
 * @param a (double number)
 * @return true if double is zero
 * @return false 0 if double is not zero
 */
bool compare_zero(const double a);

/**
 * @brief Get the solution of quadratic equation
 * and puts it in massiv of duble numbers solution[]
 * 
 * @param[in] a coefficient of x^2
 * @param[in] b coefficient of x
 * @param[in] c constant
 * @param[out] solution massiv of solutions
 * solution[0] -- if there's only real solutions contains x1, or x1_re if there's only complex solutionss
 * solution[1] -- if there's only real solutions contains x2, or x2_re if there's only complex solutions
 * solution[2] -- contains x1_im if there's only complex solution
 * solution[3] -- contains x2_im if there's only complex solution
 * Initially solution[] contains only NAN
 * @return int -- number solution by enumiration of cases
 */
int get_solution_equation(const double a, const double b, const double c, double solution[]);

/**
 * @brief interface in my programm, get coefficients and print solutions
 * 
 * @return int 
 */
int use_program();

/**
 * @brief repeat use_program while we enter 'y'
 * 
 * @return true if user wants to repeat programm, false otherwithe 
 */

int repeat_program();

/**
 * @brief compare two massives of solutions
 * 
 * @param sol in tests
 * @param sol_res by get_solution
 * @return int bool
 */
int solution_compare(const double sol[], const double sol_res[]);

/**
 * @brief run unit tests for quadratic equation
 * 
 * @return int 
 */
int test_program(const char* file);

 /**
  * @brief print solutions
  * 
  * @param number_solution 
  * @param solution 
  */
void print_solutions(const int number_solution, const double solution[]);

/**
 * @brief Get the coeffs for equation
 * 
 * @param a[out]
 * @param b[out]
 * @param c[out] 
 * @return 
 */
bool get_coeffs(double* a, double* b, double* c); // TODO make bool
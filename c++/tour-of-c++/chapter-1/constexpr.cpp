#include <iostream>

/* 
 * Constexpr function
 * Must be able to compute everything at compile time
 * This means it can only use local variables
 * Passed in arguments must be constant values, i.e. 1, 2.2, "hello", etc.
 * 
 * Constexpr functions can also be used with non-constant values
 * However this means the function will not result in a constant expression
 * The reason it can be used like this is it would be silly to have to write
 * two versions of a function where one is a constexpr and one is not
 */
constexpr double square(double x) { return x * x; }

int main()
{
    // 2 constant expressions, all values are known at compile time
    constexpr auto num1 = square(5);
    constexpr auto num2 = square(num1);
    std::cout << "num1: " << num1 << "\n";
    std::cout << "num2: " << num2 << "\n";

    double num3{0};
    std::cout << "Enter a number to square: ";
    std::cin >> num3;

    // Still using the constexpr function, however the result is not a constant expression
    // This is because num3 is not known at compile time
    const auto num4 = square(num3);
    std::cout << "That number squared is: " << num4 << std::endl;

    return 0;
}
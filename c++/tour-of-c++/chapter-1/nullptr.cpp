#include <iostream>

// Counts characters of a string and returns total count
int count_char(const char *str)
{
    int count = 0;

    /* 
     * By default tests if the pointer is not equal to nullptr
     * str != nullptr
     * However placing a NOT (!) reverses that here
     * This reads as if str IS nullptr'
     * str == nullptr
     */ 
    if (!str)
        return 0;

    /* 
     * By default tests if the numeric value is not 0
     * Equivalent to *str != 0
     * Think of it as while *str is true, i.e. not false (0)
     */ 
    while (*str)
    {
        ++count;
        ++str;
    }

    return count;
}

int main()
{
    int count = count_char("Hello, world!");
    std::cout << "String has " << count << " characters in it\n";

    return 0;
}
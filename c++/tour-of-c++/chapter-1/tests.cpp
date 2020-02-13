#include <iostream>
#include <vector>

template <typename T>
void pretty_vec_size(const std::vector<T> &vec)
{
    /* 
     * Declaring variable n within the if condition statement
     * As it is computed first, it will read as "if(n)"
     * This is the same as "if(n != 0)"
     * You could also write:
     * if (auto n = vec.size(); n != 0)
     * However this equates to the same thing as "if(n)"
     * As n was declared within the condition statement it is within the if-statement's scope
     */
    if (auto n = vec.size())
    {
        std::cout << "Your vector contains " << n << " elements\n";
    }
}

int main()
{
    std::vector<char> va(5, 'e');
    std::vector<int> vb(6, 10);
    std::vector<double> vc;

    pretty_vec_size<char>(va);
    pretty_vec_size<int>(vb);
    pretty_vec_size<double>(vc);

    return 0;
}
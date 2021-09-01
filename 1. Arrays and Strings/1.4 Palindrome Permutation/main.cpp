#include <string>
#include <unordered_map>
#include <cassert>

/**
 * Decides if a string is a permutation of a palindrome
 * 
 * @param str some string to be checked
 * @returns whether or not 'str' is a permutation of a palindrome
*/
bool isPalindromePermutation(const std::string &str)
{
    std::unordered_map<char, int> mem;
    for (const char &c : str)
    {
        mem[c]++;
    }

    // 0 - not seen any odd number
    // 1 - encountered an odd number
    int state = 0;
    for (const auto &kv : mem)
    {
        if (kv.second % 2 != 0)
        {
            if (state == 0)
            {
                state = 1;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    assert(argc > 1);                         // Expected one argument
    return !isPalindromePermutation(argv[1]); // 0 is True, 1 is False
}

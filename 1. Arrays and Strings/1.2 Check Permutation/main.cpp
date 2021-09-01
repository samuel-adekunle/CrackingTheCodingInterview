#include <string>
#include <set>
#include <cassert>

/**
 * Decide if one string is a permutation of the other
 * 
 * @param str1 first string
 * @param str2 second string
 * @return whether or not 'str1' is a permutation of 'str2'
*/
bool checkPermutation(const std::string &str1, const std::string &str2)
{
    if (str1.length() != str2.length())
        return false;

    std::multiset<char> mem;

    for (const char &c : str1)
    {
        mem.insert(c);
    }

    for (const char &c : str2)
    {
        if (mem.contains(c))
            mem.erase(mem.find(c)); // erase the first occurrence of 'c'
        else
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    assert(argc > 2);                           // Expected two arguments
    return !checkPermutation(argv[1], argv[2]); // 0 is True, 1 is False
}

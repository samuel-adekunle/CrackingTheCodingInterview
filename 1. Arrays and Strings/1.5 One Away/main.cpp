#include <string>
#include <set>
#include <cassert>
#include <iostream>

/**
 * Decides whether or not two strings are at most one edit apart
 * 
 * @param str1 one of the strings to be checked
 * @param str2 one of the strings to be checked
 * 
 * @return whether or not 'str1' and 'str2' are at most one edit apart
*/
bool isOneAway(const std::string &str1, const std::string &str2)
{
    std::multiset<char> mem;

    for (const char &c : str1)
    {
        mem.insert(c);
    }

    for (const char &c : str2)
    {
        auto it = mem.find(c);
        if (it != mem.end())
        {
            mem.erase(it);
        }
        else
        {
            mem.insert(c);
        }
    }

    std::cerr << mem.size() << std::endl;

    return mem.size() <= 2;
}

int main(int argc, char const *argv[])
{
    assert(argc > 2); // Expected two arguments
    return !isOneAway(argv[1], argv[2]);
}

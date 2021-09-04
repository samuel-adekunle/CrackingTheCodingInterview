#include <string>
#include <iostream>
#include <cassert>

/**
 * Performs basic string compression using character counting
 * 
 * @param str string to be compressed
 * 
 * @return 
 * the shorter between the compressed and original string.
 * Will return the original string if they are the same length
*/
std::string stringCompression(const std::string &str)
{
    std::string compressed;
    int limit = str.length();
    int count = '\0'; // NULL Character

    compressed.reserve(limit + 1);
    char current = NULL;

    for (const char &c : str)
    {
        if (current != c)
        {
            compressed += std::to_string(count);
            compressed += c;
            current = c;
            count = 0;
        }

        count++;
    }
    compressed += std::to_string(count);
    compressed.erase(0, 1);
    return compressed.length() >= limit ? str : compressed;
}

int main(int argc, char const *argv[])
{
    assert(argc > 1); // Expected one argument
    std::cout << stringCompression(argv[1]);
    return 0;
}

#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>

/**
 * Replaces all the spaces in a string with '%20'
 * 
 * @param str string with spaces
 * @return 'str' with spaces replaced with '%20'
*/
std::string urlify(const std::string &str)
{
    std::string url;
    for (const char &c : str)
    {
        if (c == ' ')
            url.append("%20");
        else
            url.append({c});
    }
    return url;
}

/**
 * Reverse of urlify, replaces all '%20' with spaces
 * 
 * @param url string with '%20'
 * @return 'url' with '%20' replaced with spaces
*/
std::string reverseUrlify(const std::string &url)
{
    std::string str;

    // 0 - default
    // 1 - '%'
    // 2 - '%' -> '2'
    int state = 0;

    for (int i = 0; i < url.length(); i++)
    {
        char c = url[i];

        switch (state)
        {
        case 0:
            if (c == '%')
            {
                state = 1;
            }
            else
            {
                str.append({c});
            }
            break;
        case 1:
            if (c == '2')
            {
                state = 2;
            }
            else
            {
                str.append({'%', c});
                state = 0;
            }
            break;
        case 2:
            if (c == '0')
            {
                str.append({' '});
                state = 0;
            }
            else if (c == '%')
            {
                str.append({'%', '2'}, c);
                state = 1;
            }
            else
            {
                str.append({'%', '2'}, c);
                state = 0;
            }
            break;
        default:
            throw std::runtime_error("Invalid state");
        }
    }

    return str;
}

int main(int argc, char const *argv[])
{
    assert(argc > 1); // Expected two arguments
    std::cout << urlify(argv[1]);
    return 0;
}

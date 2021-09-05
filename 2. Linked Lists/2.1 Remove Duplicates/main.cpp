#include <list>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>

/**
 * Converts list to string
 * 
 * @param head list to be converted
 * @param sep separator character between elements. defaults to ' '
 * 
 * @return string containing list values
*/
std::string listToString(const std::list<int> &head, const std::string &sep = " ")
{
    std::string listStr;
    listStr.reserve(head.size() * (sep.size() + 1));
    for (auto it = head.begin(); it != head.end(); std::advance(it, 1))
    {
        listStr += std::to_string(*it);
        if (std::next(it, 1) != head.end())
        {
            listStr += sep;
        }
    }
    return listStr;
}

/**
 * Remove duplicate elements from an unsorted list.
 * 
 * @param head list to be filtered
*/
void removeDuplicates(std::list<int> &head)
{
    std::unordered_set<int> mem;
    const auto predicate = [&mem](const int &n) -> bool
    {
        if (mem.contains(n))
        {
            return true;
        }
        mem.insert(n);
        return false;
    };
    head.remove_if(predicate);
}

int main(int argc, char const *argv[])
{
    std::list<int> head;
    for (int i = 1; i < argc; i++)
    {
        head.push_back(std::atoi(argv[i]));
    }
    removeDuplicates(head);
    std::cout << listToString(head, "->");
    return 0;
}

#include <list>
#include <string>
#include <cassert>
#include <iostream>

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

void deleteMiddleNode(const std::list<int>::iterator &node)
{
    const std::list<int>::iterator prev = std::next(node, -1);
    const std::list<int>::iterator next = std::next(node, 1);

    prev._M_node->_M_next = next._M_node;
}

int main(int argc, char const *argv[])
{
    std::list<int> head;
    assert(argc > 1); // Expected at least one argument
    int deleteIndex = std::atoi(argv[1]);

    for (int i = 2; i < argc; i++)
    {
        head.push_back(std::atoi(argv[i]));
    }

    assert(deleteIndex < head.size());
    const std::list<int>::iterator node = std::next(head.begin(), deleteIndex);

    std::cout << listToString(head) << std::endl;
    deleteMiddleNode(node);
    std::cout << listToString(head) << std::endl;

    return 0;
}

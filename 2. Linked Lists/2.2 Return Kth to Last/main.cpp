#include <list>
#include <cstdlib>
#include <iostream>
#include <cassert>

/**
 * @param head input list
 * @param k reverse index of element to be returned
 * 
 * @return kth to the last element of a list
*/
int kthToLastElement(const std::list<int> &head, const int k)
{
    return *std::next(head.end(), -1 * k);
}

int main(int argc, char const *argv[])
{
    assert(argc > 1); // Expected at least one argument
    const int k = std::atoi(argv[1]);
    std::list<int> head;

    for (int i = 2; i < argc; i++)
    {
        head.push_back(std::atoi(argv[i]));
    }

    assert(k > 0 && k <= head.size()); // Validate k
    std::cout << kthToLastElement(head, k);
    return 0;
}

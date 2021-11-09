#include <list>
#include <string>
#include <iostream>

/**
 * Converts list to string
 * 
 * @param head list to be converted
 * @param sep separator character between elements. defaults to ' '
 * 
 * @return string containing list values
*/
std::string listToString(const std::list<int> &head, const std::string &sep = " ") {
    std::string listStr;
    listStr.reserve(head.size() * (sep.size() + 1));
    for (auto it = head.begin(); it != head.end(); std::advance(it, 1)) {
        listStr += std::to_string(*it);
        if (std::next(it, 1) != head.end()) listStr += sep;
    }
    return listStr;
}

std::list<int> sumLists(std::list<int> l1, std::list<int> l2) {
    // enforce l1.size() >= l2.size()
    if (l2.size() > l1.size()) std::swap(l1, l2);

    // make l1.size() == l2.size()
    while (l1.size() > l2.size()) l2.push_back(0);

    std::list<int> res;

    auto i1 = l1.begin();
    auto i2 = l2.begin();

    int carry = 0;
    while (i1 != l1.end()) {
        int sum = *i1 + *i2 + carry;
        res.push_back(sum % 10);
        carry = sum / 10;

        i1 = std::next(i1);
        i2 = std::next(i2);
    }

    if (carry > 0) res.push_back(carry);

    return res;
}

int main() {
    std::list<int> l1 = {1, 2};
    std::list<int> l2 = {1, 9};

    std::cout << listToString(sumLists(l1, l2)) << std::endl;

    return 0;
}

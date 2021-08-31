#include <string>
#include <unordered_set>
#include <cassert>

/**
 * Determine if a string has all unique characters
 * 
 * @param str string to be checked
 * @return whether or not 'str' has all unique characters
*/
bool isUnique(const std::string &str)
{
	std::unordered_set<char> mem;
	for (const char &c : str)
	{
		if (mem.contains(c))
			return false;

		mem.insert(c);
	}
	return true;
}

int main(int argc, char *argv[])
{
	assert(argc > 1);		   // Expected 1 command line argument
	return !isUnique(argv[1]); // 0 is True, 1 is False
}

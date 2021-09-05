#include <vector>
#include <memory>
#include <unordered_set>
#include <iostream>

typedef std::vector<std::vector<int>> matrix;
typedef std::shared_ptr<::matrix> matrixPtr;

/**
 * Prints out matrix values to supplied ostream
 * 
 * @param mat matrix to be printed
 * @param dst ostream where 'img' values are printed
 * @param separator separator character between matrix elements. Defaults to single space
 * 
*/
void printMatrix(const ::matrixPtr &mat, std::ostream &dst, const char separator = ' ')
{
    for (const std::vector<int> &row : *mat)
    {
        for (const int item : row)
        {
            dst << item << separator;
        }
        dst << std::endl;
    }
}

/**
 * If an element is '0', it's row and column are set to zero.
 * 
 * @param mat matrix to be transformed
*/
void zeroMatrix(const ::matrixPtr &mat)
{
    const int numRows = mat->size();
    if (numRows == 0)
    {
        return;
    }
    const int numCols = (*mat)[0].size();

    std::unordered_set<int> zeroRows;
    std::unordered_set<int> zeroCols;

    for (int rowIndex = 0; rowIndex < numRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < numCols; colIndex++)
        {
            if ((*mat)[rowIndex][colIndex] == 0)
            {
                zeroRows.insert(rowIndex);
                zeroCols.insert(colIndex);
            }
        }
    }

    for (int rowIndex = 0; rowIndex < numRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < numCols; colIndex++)
        {
            if (zeroCols.contains(colIndex) || zeroRows.contains(rowIndex))
            {
                (*mat)[rowIndex][colIndex] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    const ::matrixPtr mat(new ::matrix);
    *mat = {{1, 0},
            {1, 1}};
    std::cout << "Before transformation" << std::endl;
    printMatrix(mat, std::cout);

    zeroMatrix(mat);
    std::cout << "After transformation" << std::endl;
    printMatrix(mat, std::cout);

    return 0;
}

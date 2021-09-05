#include <vector>
#include <memory>
#include <unordered_set>
#include <iostream>

typedef std::vector<std::vector<int>> matrix;
typedef std::shared_ptr<::matrix> matrixPtr;

/**
 * Converts matrix to string
 * 
 * @param mat matrix to be converted
 * @param colSep separator character between columns. defaults to ' '
 * @param rowSep separator character between rows. defaults to '\\n'
 * 
 * @return string containing matrix values
*/
std::string matrixToString(const ::matrixPtr &mat, const std::string &colSep = " ", const std::string &rowSep = "\n")
{
    std::string matStr;

    for (auto rowIt = mat->begin(); rowIt != mat->end(); std::advance(rowIt, 1))
    {
        for (auto colIt = rowIt->begin(); colIt != rowIt->end(); std::advance(colIt, 1))
        {
            matStr += std::to_string(*colIt);
            if (std::next(colIt, 1) != rowIt->end())
            {
                matStr += colSep;
            }
        }

        if (std::next(rowIt, 1) != mat->end())
        {
            matStr += rowSep;
        }
    }

    return matStr;
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
    std::cout << matrixToString(mat) << std::endl;

    zeroMatrix(mat);

    std::cout << "After transformation" << std::endl;
    std::cout << matrixToString(mat) << std::endl;

    return 0;
}

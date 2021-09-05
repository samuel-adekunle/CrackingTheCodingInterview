#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>

typedef std::vector<std::vector<int>> image;
typedef std::shared_ptr<::image> imagePtr;

constexpr int pixelSize = 9;
const int pixelLength = std::sqrt(pixelSize);

/**
 * Converts image matrix to string
 * 
 * @param colSep separator character between columns. defaults to ' '
 * @param rowSep separator character between rows. defaults to '\\n'
 * 
 * @return string containing image matrix values
*/
std::string imageToString(const ::imagePtr &img, const std::string &colSep = " ", const std::string &rowSep = "\n")
{
    std::string imgStr;

    for (auto rowIt = img->begin(); rowIt != img->end(); std::advance(rowIt, 1))
    {
        for (auto colIt = rowIt->begin(); colIt != rowIt->end(); std::advance(colIt, 1))
        {
            imgStr += std::to_string(*colIt);
            if (std::next(colIt, 1) != rowIt->end())
            {
                imgStr += colSep;
            }
        }

        if (std::next(rowIt, 1) != img->end())
        {
            imgStr += rowSep;
        }
    }

    return imgStr;
}

/**
 * Rotate given image matrix by 90 degrees clockwise.
 * The original matrix is preserved and a new matrix is created and returned.
 * 
 * @param oldImage image matrix to be transformed
 * 
 * @return transformed image
*/
::imagePtr rotateImageBy90(const ::imagePtr &oldImage)
{
    const int oldRowCount = oldImage->size();
    if (oldRowCount == 0)
    {
        return oldImage;
    }
    const int oldColCount = oldImage->at(0).size();

    assert(oldColCount % pixelLength == 0 && oldRowCount % pixelLength == 0); // Valid dimensions given pixelSize

    const int newRowCount = oldColCount, newColCount = oldRowCount;

    ::imagePtr newImage(new image);
    newImage->reserve(newRowCount);
    for (int i = 0; i < newRowCount; i++)
    {
        newImage->push_back(std::vector<int>(newColCount, 0));
    }

    for (int oldRowIndex = 0; oldRowIndex < oldRowCount; oldRowIndex += pixelLength)
    {
        const std::vector<int> &row = oldImage->at(oldRowIndex);
        const int newColIndex = newColCount - oldRowIndex - 1;
        for (int oldColIndex = 0; oldColIndex < oldColCount; oldColIndex += pixelLength)
        {
            const int newRowIndex = oldColIndex;
            for (int rowPixelOffset = 0; rowPixelOffset < pixelLength; rowPixelOffset++)
            {
                for (int colPixelOffset = 0; colPixelOffset < pixelLength; colPixelOffset++)
                {
                    newImage->at(newRowIndex + rowPixelOffset)[newColIndex - colPixelOffset] = oldImage->at(oldRowIndex + rowPixelOffset)[oldColIndex + colPixelOffset];
                }
            }
        }
    }

    return newImage;
}

int main(int argc, char const *argv[])
{
    assert(std::pow(pixelLength, 2) == pixelSize); // validate pixelLength
    const ::imagePtr oldImage(new image);
    *oldImage = {{1, 1, 1, 2, 2, 2, 3, 3, 3},
                 {1, 1, 1, 2, 2, 2, 3, 3, 3},
                 {1, 1, 1, 2, 2, 2, 3, 3, 3},
                 {4, 4, 4, 5, 5, 5, 6, 6, 6},
                 {4, 4, 4, 5, 5, 5, 6, 6, 6},
                 {4, 4, 4, 5, 5, 5, 6, 6, 6}};

    std::cout << "Before rotation" << std::endl;
    std::cout << imageToString(oldImage) << std::endl;

    const ::imagePtr newImage = rotateImageBy90(oldImage);

    std::cout << "After rotation" << std::endl;
    std::cout << imageToString(newImage) << std::endl;

    return 0;
}
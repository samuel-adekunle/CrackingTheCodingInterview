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
 * Prints out image matrix values to supplied ostream
 * 
 * @param img image matrix to be printed
 * @param dst ostream where 'img' values are printed
 * @param separator separator character between matrix elements. Defaults to single space
 * 
*/
void printImage(const ::imagePtr &img, std::ostream &dst, const char separator = ' ')
{
    for (const std::vector<int> &row : *img)
    {
        for (const int item : row)
        {
            dst << item << separator;
        }
        dst << std::endl;
    }
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
    printImage(oldImage, std::cout, ' ');

    const ::imagePtr newImage = rotateImageBy90(oldImage);
    std::cout << "After rotation" << std::endl;
    printImage(newImage, std::cout, ' ');
    return 0;
}
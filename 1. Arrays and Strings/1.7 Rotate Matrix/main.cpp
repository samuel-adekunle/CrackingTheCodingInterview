#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

typedef std::vector<std::vector<int>> image;
constexpr int pixelSize = 9;
const int pixelLength = std::sqrt(pixelSize);

void printImage(const ::image &mat, std::ostream &dst, const char separator = ' ')
{
    for (const std::vector<int> &row : mat)
    {
        for (const int item : row)
        {
            dst << item << separator;
        }
        dst << std::endl;
    }
}

::image rotateImageBy90(const ::image &oldImage)
{
    const int oldRowCount = oldImage.size();
    if (oldRowCount == 0)
    {
        return oldImage;
    }
    const int oldColCount = oldImage[0].size();

    assert(oldColCount % pixelLength == 0 && oldRowCount % pixelLength == 0); // Valid dimensions given pixelSize

    const int newRowCount = oldColCount, newColCount = oldRowCount;

    ::image newImage;
    newImage.reserve(newRowCount);
    for (int i = 0; i < newRowCount; i++)
    {
        newImage.push_back(std::vector<int>(newColCount, 0));
    }

    std::cout << "Before rotation" << std::endl;
    printImage(oldImage, std::cout, ' ');

    for (int oldRowIndex = 0; oldRowIndex < oldRowCount; oldRowIndex += pixelLength)
    {
        const std::vector<int> &row = oldImage[oldRowIndex];
        const int newColIndex = newColCount - oldRowIndex - 1;
        for (int oldColIndex = 0; oldColIndex < oldColCount; oldColIndex += pixelLength)
        {
            const int newRowIndex = oldColIndex;
            for (int rowPixelOffset = 0; rowPixelOffset < pixelLength; rowPixelOffset++)
            {
                for (int colPixelOffset = 0; colPixelOffset < pixelLength; colPixelOffset++)
                {
                    newImage[newRowIndex + rowPixelOffset][newColIndex - colPixelOffset] = oldImage[oldRowIndex + rowPixelOffset][oldColIndex + colPixelOffset];
                }
            }
        }
    }

    std::cout << "After rotation" << std::endl;
    printImage(newImage, std::cout, ' ');

    return newImage;
}

int main(int argc, char const *argv[])
{
    assert(std::pow(pixelLength, 2) == pixelSize); // validate pixelLength
    const ::image image = {{1, 1, 1, 2, 2, 2, 3, 3, 3},
                           {1, 1, 1, 2, 2, 2, 3, 3, 3},
                           {1, 1, 1, 2, 2, 2, 3, 3, 3},
                           {4, 4, 4, 5, 5, 5, 6, 6, 6},
                           {4, 4, 4, 5, 5, 5, 6, 6, 6},
                           {4, 4, 4, 5, 5, 5, 6, 6, 6}};
    rotateImageBy90(image);
    return 0;
}
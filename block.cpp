
#include <cmath>
#include <iostream>
#include <exception>

#include <algorithm>

#include "block.h"



int Block::width() const
{
return this->_width;
}

int Block::height() const
{
return this->_height;
}

void Block::render(PNG &im, int column, int row) const
{
    int w = std::min((int)im.width() - column, _width);
    int h = std::min((int)im.height() - row, _height);

    for(int i = 0; i < h; i++){
        for(int j =0; j < w; j++){
            *im.getPixel(column + j, row + i) =  this->_data[i][j]; 
        }
    }
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
    _width = width;
    _height = height;

    if (column + width > (int)im.width()){
        throw "Invalid width";
    }
    if (row + height > (int)im.height()){
        throw "Invalid height";
    }
    

    for(int i = 0; i < height; i++){
        vector<HSLAPixel> tmp_row;

        for(int j = 0; j < width; j++){
            tmp_row.push_back(*im.getPixel(column + j, row + i));
        }
        _data.push_back(tmp_row);
    }
}

void Block::flip()
{
/* your code here */
}


#include <cmath>
#include <iostream>
#include <exception>

#include <algorithm>

#include "block.h"



int Block::width() const
{
    if (height() == 0) return 0;
    return this->data[0].size();
}

int Block::height() const
{
return this->data.size();
}

void Block::render(PNG &im, int column, int row) const
{
    int w = std::min((int)im.width() - column,  width());
    int h = std::min((int)im.height() - row,  height());

    for(int i = 0; i < h; i++){
        for(int j =0; j < w; j++){
            *im.getPixel(column + j, row + i) =  this->data[i][j]; 
        }
    }
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
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
        data.push_back(tmp_row);
    }
}

void Block::flip()
{
    const int W = width();
    const int H = height();
    for(int i = 0; i < H >> 1; i++){
        int j = H - i - 1;

        auto & s = data[i];
        auto & t = data[j];

        for(int k = 0; k < W; k++){
            auto tmp = s[k];
            s[k] = t[k];
            t[k] = tmp;
        }
    }
}

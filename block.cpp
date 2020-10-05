#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
return this->width;
}

int Block::height() const
{
return this->height;
}

void Block::render(PNG &im, int column, int row) const
{
/* your code here */
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
/* your code here */

this->img = &im;
this->x = column;
this->y = row;
this->width = width;
this->height = height;
}

void Block::flip()
{
/* your code here */
}

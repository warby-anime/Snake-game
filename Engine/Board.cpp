#include "Board.h"
#include <assert.h>

Board::Board (Graphics& gfx)
	:gfx(gfx)
{
}

void Board::DrawCell (const Location& loc, Color c)
{
	assert (loc.x >= 0);
	assert (loc.x < width);
	assert (loc.y >= 0);
	assert (loc.y < height);
	gfx.DrawRectDim (x + loc.x * dimension, y + loc.y * dimension, dimension, dimension, c);

}

int Board::GetGridWidth ( ) const
{
	return width;
}

int Board::GetGridHeight ( ) const
{
	return height;
}

void Board::DrawGridBorder ()
{
  int  top = y;
  int left = x;
  int right = borderPadding * borderWidth;
  int bottom = borderPadding * borderWidth;

  // border top
	gfx.DrawRectDim (left, top, right * x, bottom, borderColor);

	// border left
	gfx.DrawRectDim (left, top, right, bottom * y, borderColor);

	// border right
	gfx.DrawRectDim (left + right * x, top, right, bottom * y, borderColor);

	// border bottom
	gfx.DrawRectDim (left , top + bottom * y,right + right * x, bottom, borderColor);

}

bool Board::IsInsideBoard (const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

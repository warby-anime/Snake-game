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
	gfx.DrawRectDim (x + loc.x * dimension , y + loc.y * dimension, dimension, dimension, c);

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
	const int top = y;
	const int left = x;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	// top
	gfx.DrawRect (left, top, right, top + borderWidth, borderColor);
	// left
	gfx.DrawRect (left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	// right
	gfx.DrawRect (right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);
	// bottom
	gfx.DrawRect (left, bottom - borderWidth, right, bottom, borderColor);

}

bool Board::IsInsideBoard (const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

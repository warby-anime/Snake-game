#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board (Graphics& gfx);
	void DrawCell (const Location& loc,Color c );
	int GetGridWidth ( ) const;
	int GetGridHeight ( ) const;
	void DrawGridBorder ();
	bool IsInsideBoard (const Location& loc) const;
 
private:
	static constexpr int dimension = 20;
	static constexpr int width = 33;
	static constexpr int height = 25;
	static constexpr int borderWidth = 2;
	static constexpr int borderPadding = 5;
	static constexpr int x = 66;
	static constexpr int y = 50;
	Color borderColor = Colors::Gray;
	Graphics& gfx;
	

};


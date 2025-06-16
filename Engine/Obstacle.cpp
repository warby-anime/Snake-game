#include "Obstacle.h"

Obstacle::Obstacle (std::mt19937& rng, const Board& brd, const Snake& snake)
	:rng (rng)
{
	Respawn (rng, brd, snake);
}



void Obstacle::Respawn (std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist (1, brd.GetGridWidth ( ) - 1);
	std::uniform_int_distribution<int> yDist (1, brd.GetGridHeight ( ) - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist (rng);
		newLoc.y = yDist (rng);
	} while (snake.IsInTile (newLoc));

	loc = newLoc;
}

void Obstacle::Draw (Board& brd) const
{
	brd.DrawCell (loc, c);
}

const Location& Obstacle::GetLocation ( ) const
{
	return loc;
}
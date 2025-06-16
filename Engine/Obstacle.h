#pragma once
#include "Snake.h"
#include "Board.h"
#include <random> 


class Obstacle
{
	public:
		Obstacle ( ) = default;
		Obstacle (std::mt19937& rng, const Board& brd, const Snake& snake);
		void Respawn (std::mt19937& rng, const Board& brd, const Snake& snake);
		void Draw (Board& brd) const;
		const Location& GetLocation ( ) const;
	private:
		std::mt19937 rng;
		static constexpr Color c = Colors::Cyan;
		Location loc;
	
};


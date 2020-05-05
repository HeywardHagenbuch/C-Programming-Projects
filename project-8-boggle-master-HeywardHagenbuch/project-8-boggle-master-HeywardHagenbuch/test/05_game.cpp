#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../game.hpp"
#include <regex>

TEST_CASE("Testing fixed game initialization")
{
	Game g("GNTRHIFHHISTDSRA");
	REQUIRE("G N T R\nH I F H\nH I S T\nD S R A\n" == g.ShowBoard());
//	G N T R
//	H I F H
//	H I S T
//	D S R A

	REQUIRE(g.Guess("STAR"));
	REQUIRE(g.GetScore() == 1);

	REQUIRE(!g.Guess("STAR")); // since it was already used
	REQUIRE(!g.Guess("FIST")); // no diagonals allowed
	REQUIRE(g.GetIncorrectGuesses() == 1); // Re-guessing a word isn't "incorrect", it jus doesn't add to the score

	REQUIRE(g.Guess("DART"));
	REQUIRE(g.Guess("STARS"));
	REQUIRE(g.GetScore() == 4);

	REQUIRE(g.GetTotalPointsPossible() == 34);
}

TEST_CASE("Testing random game initialization")
{
	Game g;
	std::string board = g.ShowBoard ();
	/*
	Since we're using randomization, all we can asset is that the
	board layout matches the basic pattern:
		A B C D
		E F G H
		I J K L
		M N O P
	*/
	std::regex boardFormat("([A-Z] [A-Z] [A-Z] [A-Z]\n){4}");
	REQUIRE(std::regex_match(board, boardFormat));
	// The below would only happen 1 in every 6^16 runs, so pretty safe to assert it isn't a match
	REQUIRE("G N L T\nH I F H\nH I S T\nD J A R\n" != g.ShowBoard());
}

// Compile & run:
// make clean test

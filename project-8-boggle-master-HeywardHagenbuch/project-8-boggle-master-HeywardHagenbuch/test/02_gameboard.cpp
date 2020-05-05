#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../gameboard.hpp"

TEST_CASE("Test GameBoard initialization")
{
	GameBoard g("GNLTHIFHHISTDJAR");
	REQUIRE('G' == g.GetLetterByRowCol(0, 0));
	REQUIRE('T' == g.GetLetterByRowCol(0, 3));
	REQUIRE('R' == g.GetLetterByRowCol(3, 3));

	REQUIRE("G N L T\nH I F H\nH I S T\nD J A R\n" == g.ShowBoard());
}

// Compile & run:
// make clean test

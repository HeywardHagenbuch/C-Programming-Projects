#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../word_find.hpp"
#include "../gameboard.hpp"

TEST_CASE("Checking word list finder")
{
	WordFind wordFinder; // need instance to house an instance of a lookup dictionary
	GameBoard g("GGGGGGGGGGGGGGGG"); // No words
	REQUIRE(wordFinder.GetAllWords(g).size() == 0);

	GameBoard g2("AAAAAAAAAAAAAAAH"); // AHA should be only word

	REQUIRE(wordFinder.GetAllWords(g2).size() == 1);

	GameBoard g3("ABHGDGEINSGEHTAC");
	REQUIRE(wordFinder.GetAllWords(g3).size() == 38);
}

// Compile & run:
// make clean test

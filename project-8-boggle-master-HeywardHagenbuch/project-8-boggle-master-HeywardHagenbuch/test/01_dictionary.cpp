#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../dictionary.hpp"

TEST_CASE("Basic dictionary creation and lookup tests")
{
	Dictionary wordList;

	REQUIRE(wordList.IsWord("AARDVARK")); // verify that we didn't skip the first word
	REQUIRE(wordList.IsWord("ZYMURGY")); // verify that the entire file got written by checking last word
	REQUIRE(!wordList.IsWord("ZZZZ"));
	REQUIRE(!wordList.IsWord("MARCUS")); // proper noun not in the list given
}

// Compile & run:
// make clean test

#include <iostream>
#include <string>
#include <limits>

#include "game.hpp"

/**
 * Default Constructor for Game
 */
Game::Game()
{
  questions = new QuestionBank();
  amountWagered = 0;
  currentScore = 0;
}

/**
 * Parameterized Constructor for Game
 * 
 * *qs QuestionBank: Pointer to a QuestionBank object
 * It contains all the questions that will be asked during a game
 */
Game::Game(QuestionBank *qs)
{
  questions = qs;
  amountWagered = 0;
  currentScore = 200;
}

/**
 * Destructor for Game
 *
 */
Game::~Game()
{
	delete questions;
}

/**
 * The driving function of the Game
 * 
 * This function handles all the interactions
 * with the other functions in the Game class
 * as well as the interactions with the Questions
 * and QuestionBank classes.
 */
int Game::AskQuestion()
{
  std::vector<char> guess;           // Player guesses are stored in a vector
  std::string incorrectGuesses = ""; // String to track incorrect guesses
  bool goodWager = false;            // Ensure the wager made is ok
  char input;                        // The input for the players guess
  int numGuesses = 2;                // The amount of incorrect guesses a player has before losing
  std::string stringGuess = "";      // The player guesses but as a string instead of vector

  // Get the next Questions object
  Question quest = questions->GetNextQuestion();

  // Print the next Question to the console
  std::cout << "Next Question: " << quest.GetText() << std::endl;
  std::cout << "Current Points: " << currentScore << std::endl;

  // Make sure the player has points left before starting the loop
  if (GetCurrentScore() > 0)
  {
    // The players wager loop
    do
    {
      // Take in the wager
      std::cout << "What would you like to wager? ";
      std::cin >> amountWagered;

      // If the cin gets a fail bit due to input that was not a number
      if (!std::cin)
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input; please re-enter." << std::endl;
      }
      else
      {
        Game::SetWager(amountWagered);
        // Next two lines stop the input from carrying over if a decimal is wagered
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goodWager = true;
      }

    } while (!goodWager);

	// Check the guess and assign #'s to placeholders if any match
	// If first guess get initial placeholders
    std::cout << quest.GetAnswerWithPlaceholders(guess);

	// Append the incorrect guesses next to the placeholders
    std::cout << "\t" << incorrectGuesses;

	// Digit guess loop
    do
    {
      std::cout << "\nGuess a Digit: ";
      std::cin >> input;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	  // If the guess matches a char in the answer
      if (quest.AnswerContainsDigit(input))
      {
		// Push it into the guess vector
        guess.push_back(input);

		// The string version of guesses with placeholders assigned
        stringGuess = quest.GetAnswerWithPlaceholders(guess);

		// Check to see if the answer is 'complete'
        if (quest.AllDigitsGuessed(stringGuess))
        {
		  // If it is add points
          Game::AdjustPoints(true);
          std::cout << "\nCorrect Answer: " << quest.GetAnswerWithPlaceholders(guess) << std::endl;
          std::cout << "\nYou win this round!\n\n\n";
          break;
        }
      }
	  // If the guess doesn't match
      else
      {
		// Append the incorrectGuesses string
        incorrectGuesses += "~~";
        incorrectGuesses += input;
		// Decrement the amount of guesses
        numGuesses--;
      }

	  // Get answer with placeholders and incorrect guesses appended on the end
      std::cout << "\n"
                << quest.GetAnswerWithPlaceholders(guess) << "\t" << incorrectGuesses;
    } while (numGuesses > 0);

	// If the player runs out of guesses
    if (numGuesses == 0)
    {
	  
	  // Decrement points because the player ran ut of guesses
      Game::AdjustPoints(false);
      std::cout << "\n\nYou Lose this Round!\n\n\n" << std::endl;
    }
  }
  return GetCurrentScore();
}


/**
 * Adjust the players points based on a boolean.
 */
void Game::AdjustPoints(bool isCorrect)
{
  // If the player guessed correcly add the wager to their points
  if (isCorrect)
  {
    currentScore += GetWager();
  }

  // If guessed incorrectly take points
  else
  {
    currentScore -= GetWager();
  }
}

/**
 * Set the players wager
 */
void Game::SetWager(int wager)
{
  // If their wager is <= 0 wager = 1
  if (wager <= 0)
  {
    amountWagered = 1;
  }

  // If their wager is larger than their current score wager = Current Score
  else if (wager > GetCurrentScore())
  {
    amountWagered = GetCurrentScore();
  }

  // Else wager = amount wagered
  else
  {
    amountWagered = wager;
  }
}

/**
 * Get the players Wager
 */
int Game::GetWager()
{
  return amountWagered;
}

/*
* Get the players current score 
*/
int Game::GetCurrentScore()
{
  return currentScore;
}

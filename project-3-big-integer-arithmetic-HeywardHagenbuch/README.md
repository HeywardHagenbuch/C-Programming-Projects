## Project 3 - Big Integer Arithmetic

## Project Outcomes:
Develop a C++ program that uses:
* Multiple stacks
* File I/O
* Logic to decide how to perform arithmetic operations of addition and subtraction

## Preparatory Readings:
ZyBooks chapter 14

## Background Information:
Physical machines have fixed maximum sizes for the representation of numbers. For instance, integers are often 32 bits and signed, meaning the largest integer value that can be held is + or - approximately 2 billion. The goal of this project is to use multiple stack data structures to enable addition and subtraction of arbitrarily large integers.

![Integer overflow when counting sheep](https://imgs.xkcd.com/comics/cant_sleep.png)

### Project Requirements:
Your application must function as described below:

In this project we will add or subtract arbitrarily large numbers. We will add or subtract arbitrarily large unsigned numbers. We must decide:
* if we must reverse operands 
* if we must prepend a minus (-) sign to the result.

The first case, reversing operands, must be performed if we are subtracting and the [subtrahend](https://www.merriam-webster.com/dictionary/subtrahend) has a larger absolute value than the [minuend](https://www.merriam-webster.com/dictionary/minuend). In that case, we must prepend a minus (-) sign to the result.

The program will involve arbitrarily large operands represented as strings.
This will involve:
* creating three stacks
* padding the shorter operand to the length of the longer one
* pushing chars or int equivalents onto the two operand stacks
* popping
	* applying the appropriate operation
		* possibly setting a carry or borrow flag
* and pushing the result digit-by-digit onto a result stack.

Then, of course, we get the answer by popping the result stack until empty.

#### We will have the following classes
1. `ExpressionReader`: reads a file of arithmetic expressions and creates instances of class `ArithmeticExpression`.
2. `ArithmeticExpression`: class that holds an operator and two operands.
3. `Operand`:  a class to provide a string for the numeric value; it will be able to pad on the left by a specified amount. 
4. `BigIntegerArithmetic`: Takes an `ArithmeticExpression` instance, makes the decisions about reversing operands and sign on result, performs the operation(s) and displays the result.
5. `Stack`: used by `BigIntegerArithmetic` to add or subtract. The program will use three of them, as mentioned.
6. `Node`: used by the stack to hold individual digits.

\.\.\. and, of course, `main()` to get the whole ball rolling by constructing an `ExpressionReader` with a file name as a parameter to the constructor. `main()` should be a one-liner.

#### Sample data
    12 + 5
    5 + 12
    12 - 5
    5 - 12
    364287462834623846283426384 + 923742938742934723947239847
    364287462834623846283426384 - 923742938742934723947239847

#### Output for the above input should look like this:
     12
    + 5
     17

      5
    +12
     17

     12
    - 5
      7

      5
    -12
    - 7

     364287463834623846283426384
    +923742938742934723947239847
    1288030402577558570230666231

     364287463834623846283426384
    -923742938742934723947239847
    -559455474908310877663813463


### Implementation Notes:
1. Create a project that is object oriented, therefore there should be several classes as described above.
2. The input file will match the exact format given above.

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
	1. After pushing, with `git push origin master`, visit the web URL of your repository to verify that your code is there.
	If you don't see the code there, then we can't see it either.
3. Your code must compile and run in Travis-CI or it might not be graded.
	1. The Travis-CI build should begin automatically when you push your code to GitHub.
	2. If your program will not compile, the graders will not be responsible for trying to test it.
	3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
* Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
* Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
* Please review the academic honesty policy.
	* Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
	* Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty.
	* All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.

#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../node.hpp"
#include "../stack.hpp"
#include "../expression_reader.hpp"
#include "../arithmetic_expression.hpp"
#include "../big_integer_arithmetic.hpp"

TEST_CASE("class Node")
{
  Node n(50);
  REQUIRE(n.GetValue() == 50);
  REQUIRE(n.GetNext() == nullptr);
}

TEST_CASE("class Stack")
{
  Stack s;
  s.Push(50);
  REQUIRE(!s.IsEmpty());
  REQUIRE(s.Pop() == 50);
  REQUIRE(s.IsEmpty());
}

TEST_CASE("class Operand")
{
  Operand o("1234567");
  REQUIRE(o.IsNegative() == false);
  REQUIRE(o.GetValue() == "1234567");
  REQUIRE(o.GetLengthOfString() == 7);
  o.Pad(4);
  REQUIRE(o.GetValue() == "00001234567");
  o.SetValue("7654321");
  REQUIRE(o.GetValue() == "7654321");
  Operand o2("-1234567");
  REQUIRE(o2.IsNegative() == true);
}

TEST_CASE("class ArithmeticExpression")
{
  ArithmeticExpression ae("1234567","23456",'+');
  std::ostringstream oss;
  oss << ae;
  REQUIRE(oss.str() == "1234567 0023456 +");

  ArithmeticExpression ae2("23456","1234567",'+');
  std::ostringstream oss2;
  oss2 << ae2;
  REQUIRE(oss2.str() == "0023456 1234567 +");

}

TEST_CASE("class BigIntegerArithmetic")
{
   ArithmeticExpression * ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'+');
   BigIntegerArithmetic bia(ae);
   bia.SetUp();
   bia.Add();
   REQUIRE(bia.ShowResults()== "     364287463834623846283426384\n    +923742938742934723947239847\n    1288030402577558570230666231\n\n");
   delete ae;

   ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'-');
   BigIntegerArithmetic bia2(ae);
   bia2.SetUp();
   bia2.Subtract();
   REQUIRE(bia2.ShowResults()== "     364287463834623846283426384\n    -923742938742934723947239847\n    -559455474908310877663813463\n\n");
   delete ae;

   ae = new ArithmeticExpression("923742938742934723947239847","364287463834623846283426384",'-');
   BigIntegerArithmetic bia9(ae);
   bia9.SetUp();
   bia9.Add();
   REQUIRE(bia9.ShowResults()=="     923742938742934723947239847\n    -364287463834623846283426384\n    559455474908310877663813463\n\n");
   delete ae;

   ae = new ArithmeticExpression("200","100",'+');
   BigIntegerArithmetic bia1(ae);
   REQUIRE(bia1.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()) == true);
   delete ae;

   ae = new ArithmeticExpression("100","200",'+');
   BigIntegerArithmetic bia3(ae);
   REQUIRE(bia3.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()) == false);
   delete ae;


   ae = new ArithmeticExpression("200","200",'+');
   BigIntegerArithmetic bia4(ae);
   REQUIRE(bia4.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()) == true);
   delete ae;


   ae = new ArithmeticExpression("2000","100",'+');
   BigIntegerArithmetic bia5(ae);
   REQUIRE(bia5.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()) == true);
   delete ae;


   ae = new ArithmeticExpression("200","1000",'+');
   BigIntegerArithmetic bia6(ae);
   REQUIRE(bia6.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()) == false);
   delete ae;
}

TEST_CASE("class ExpressionReader")
{
  std::ostringstream oss;
  ExpressionReader er;
  er.ReadExpressions("expressions.txt");
  REQUIRE(er.ToString() == "12 + 5\n5 + 12\n12 - 5\n5 - 12\n364287463834623846283426384 + 923742938742934723947239847\n364287463834623846283426384 - 923742938742934723947239847\n");
}




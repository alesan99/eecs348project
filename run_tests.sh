#!/bin/bash
# Path to executable
PATH="./bin/aee.out --test "
# Variables to track stats
TOTAL=0
PASSED=0
FAILED=0

# Reusable function
function run_test_case {
  TOTAL=$((TOTAL + 1))
  OUTPUT=$($PATH "$1")
  if [[ $OUTPUT == $2 ]]; then
          echo "Test $TOTAL: passed"
          PASSED=$((PASSED + 1))

  else
          echo ""
          echo "!!!! Test $TOTAL: failed !!!!"
          echo "Expected output: $1=$2 | Actual: $OUTPUT"
          echo ""
          FAILED=$((FAILED + 1))
  fi
}
# Big wall of test cases. $1 is the expression, $2 is the expected result
run_test_case "2+3" "5"
run_test_case "2-3" "-1"
run_test_case "2*3" "6"
run_test_case "4/2" "2"
run_test_case "2^3" "8"
run_test_case "2/3" "0"
run_test_case "-2+3" "1"
run_test_case "2+(-3)" "-1"
run_test_case "2+3+4+5" "14"
run_test_case "2*3*4*5" "120"
run_test_case "2^2^2" "16"
run_test_case "10 - 3 + 2" "9"
run_test_case "1+2-3*4" "-9"
run_test_case "2*3^2" "18"
run_test_case "10-8/2" "6"
run_test_case "5+(6/2)*3-2^2" "10"
run_test_case "(2+3)" "5"
run_test_case "((2*(4/2))+2)" "6"
run_test_case "(2+(3*4))*(5+6)" "154"
run_test_case "2 + 3" "5"
run_test_case "2+3 + 2" "7"
run_test_case "[2+{2+(2+2)}]" "8"
run_test_case "1/0" "Error: Division by zero"
run_test_case "+" "Error: Operator in invalid position"
run_test_case "1+" "Error: Expression ends with an operator"
run_test_case "(1+1)(1+1)" "Error: Operator in invalid position"
# Bug with test code.
# TODO: Fix test input being broken if no argument is given.
run_test_case "" "Error: Empty input string"
run_test_case "a" "Error: Invalid character in input"
run_test_case "(1+3))" "Error: Empty parentheses or invalid use of ')'"
run_test_case "()" "Error: Empty parentheses or invalid use of ')'"

# PRINT THE RESULST
echo ""
echo ""
printf "Tests:\n$PASSED/$TOTAL passed\n$FAILED/$TOTAL failed\n"
if [[ $PASSED != $TOTAL ]]; then
  exit 1
fi


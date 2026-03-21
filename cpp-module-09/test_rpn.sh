#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Counters
PASSED=0
FAILED=0

# Function to run valid tests
test_valid() {
    local input="$1"
    local expected="$2"
    
    echo -n "Testing: ./RPN \"$input\" ... "
    result=$(./RPN "$input" 2>&1)
    
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}✓ PASS${NC} (got: $result)"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC} (expected: $expected, got: $result)"
        ((FAILED++))
    fi
}

# Function to run error tests
test_error() {
    local input="$1"
    local description="$2"
    
    echo -n "Testing: ./RPN \"$input\" ($description) ... "
    result=$(./RPN "$input" 2>&1)
    
    if echo "$result" | grep -q "Error"; then
        echo -e "${GREEN}✓ PASS${NC} (Error detected)"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC} (Should show error, got: $result)"
        ((FAILED++))
    fi
}

# Function to test no arguments
test_no_args() {
    echo -n "Testing: ./RPN (no arguments) ... "
    result=$(./RPN 2>&1)
    
    if echo "$result" | grep -q "Error"; then
        echo -e "${GREEN}✓ PASS${NC} (Error detected)"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC} (Should show error)"
        ((FAILED++))
    fi
}

echo "================================"
echo "   RPN COMPREHENSIVE TESTS"
echo "================================"

# Check if executable exists
if [ ! -f "./RPN" ]; then
    echo -e "${RED}Error: ./RPN executable not found!${NC}"
    echo "Please compile your project first with 'make'"
    exit 1
fi

echo -e "\n${YELLOW}=== VALID CASES ===${NC}\n"

# Basic operations
test_valid "1 2 +" "3"
test_valid "4 2 -" "2"
test_valid "3 4 *" "12"
test_valid "8 2 /" "4"

# Subject examples
test_valid "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
test_valid "7 7 * 7 -" "42"
test_valid "1 2 * 2 / 2 * 2 4 - +" "0"

# Single digits 0-9
test_valid "0 5 +" "5"
test_valid "9 1 -" "8"
test_valid "9 9 *" "81"

# Complex expressions
test_valid "1 2 + 3 +" "6"
test_valid "5 1 2 + 4 * + 3 -" "14"
test_valid "9 8 7 + *" "135"

# Multiple spaces
test_valid "1  2  +" "3"
test_valid "3   4   *" "12"

# Single number
test_valid "5" "5"
test_valid "0" "0"
test_valid "9" "9"

# Zero operations
test_valid "0 0 +" "0"
test_valid "0 5 *" "0"
test_valid "5 5 -" "0"

# Order matters
test_valid "5 3 -" "2"
test_valid "3 5 -" "-2"
test_valid "8 4 /" "2"
test_valid "4 8 /" "0"

echo -e "\n${YELLOW}=== ERROR CASES ===${NC}\n"

# Invalid characters
test_error "(1 + 1)" "parentheses"
test_error "1 2 a +" "invalid character"
test_error "1 2 & +" "special character"
test_error "1.5 2 +" "decimal point"

# Multi-digit numbers (CRITICAL TEST!)
test_error "11 1 +" "multi-digit with space"
test_error "12 3 +" "multi-digit 12"
test_error "123 4 +" "multi-digit 123"
test_error "10 5 -" "multi-digit 10"
test_error "99 1 +" "multi-digit 99"
test_error "100 1 +" "multi-digit 100"

# Insufficient operands
test_error "1 +" "insufficient operands"
test_error "+" "no operands"
test_error "1 2 + +" "not enough for second +"
test_error "5 *" "needs 2 operands"
test_error "1 2 3 + + +" "too many operators"

# Too many operands
test_error "1 2 3" "too many numbers"
test_error "1 2 3 4" "no operations"
test_error "1 2 + 3" "leftover number"

# Division by zero
test_error "5 0 /" "division by zero"
test_error "1 0 / 2 +" "division by zero in chain"

# Empty or spaces only
test_error "" "empty input"
test_error "   " "only spaces"

# Invalid operator placement
test_error "+ 1 2" "operator first"
test_error "1 + 2" "infix notation"

# Negative numbers
test_error "-1 2 +" "negative number"

# No arguments
test_no_args

echo -e "\n================================"
echo -e "   TEST SUMMARY"
echo -e "================================"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"
echo -e "Total:  $((PASSED + FAILED))"
echo "================================"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed. Please review your code.${NC}"
    exit 1
fi
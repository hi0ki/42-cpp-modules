#!/bin/bash

# Colors
G='\033[0;32m'
R='\033[0;31m'
Y='\033[1;33m'
B='\033[0;34m'
NC='\033[0m'

PASSED=0
FAILED=0

# Check executable
if [ ! -f "./PmergeMe" ]; then
    echo -e "${R}Error: ./PmergeMe not found. Run 'make' first.${NC}"
    exit 1
fi

# Test that should ACCEPT input
test_accept() {
    local input="$1"
    local name="$2"
    
    printf "%-60s" "✓ $name"
    
    output=$(./PmergeMe $input 2>&1)
    exit_code=$?
    
    if [ $exit_code -eq 0 ] && ! echo "$output" | grep -qi "error"; then
        echo -e "${G}PASS${NC}"
        ((PASSED++))
    else
        echo -e "${R}FAIL (should accept)${NC}"
        echo "  Input: $input"
        echo "  Output: $output"
        ((FAILED++))
    fi
}

# Test that should REJECT input
test_reject() {
    local input="$1"
    local name="$2"
    
    printf "%-60s" "✗ $name"
    
    output=$(./PmergeMe $input 2>&1)
    exit_code=$?
    
    if [ $exit_code -ne 0 ] || echo "$output" | grep -qi "error"; then
        echo -e "${G}PASS${NC}"
        ((PASSED++))
    else
        echo -e "${R}FAIL (should reject)${NC}"
        echo "  Input: $input"
        echo "  Output: $output"
        ((FAILED++))
    fi
}

echo "=========================================="
echo "    PMERGEME PARSING TEST"
echo "=========================================="

echo -e "\n${B}=== VALID INPUTS (Should Accept) ===${NC}\n"

test_accept "1" "Single positive number"
test_accept "1 2 3" "Multiple positive numbers"
test_accept "0" "Zero"
test_accept "0 1 2" "Starting with zero"
test_accept "42 1 99 7" "Random positive integers"
test_accept "2147483647" "INT_MAX"
test_accept "2147483647 1 2147483646" "Multiple INT_MAX values"
test_accept "1 1 1 1 1" "Duplicate values"
test_accept "007 042 0100" "Numbers with leading zeros"
test_accept "$(seq 1 100 | tr '\n' ' ')" "100 numbers"
test_accept "$(seq 1 1000 | tr '\n' ' ')" "1000 numbers"

echo -e "\n${B}=== INVALID INPUTS (Should Reject) ===${NC}\n"

echo -e "${Y}--- Negative Numbers ---${NC}"
test_reject '"-1"' "Negative number"
test_reject '"-1" "2"' "Negative with positive"
test_reject '"1" "-5" "3"' "Negative in middle"
test_reject '"-10" "5" "3"' "Negative at start"
test_reject '"-0"' "Negative zero"
test_reject '"-2147483648"' "INT_MIN"

echo -e "\n${Y}--- Out of Range ---${NC}"
test_reject "2147483648" "INT_MAX + 1"
test_reject "2147483649" "INT_MAX + 2"
test_reject "9999999999" "Very large number"
test_reject "99999999999999999" "Extremely large number"
test_reject "21474836470" "10x INT_MAX"

echo -e "\n${Y}--- Decimal / Float ---${NC}"
test_reject "1.5" "Decimal number"
test_reject "1.0" "Float with .0"
test_reject "3.14" "Pi"
test_reject '"1" "2.5" "3"' "Float in middle"
test_reject "0.5" "Decimal less than 1"
test_reject "42.42" "Decimal greater than 1"

echo -e "\n${Y}--- Invalid Characters ---${NC}"
test_reject "abc" "Letters only"
test_reject "1a2" "Number with letter"
test_reject "12a" "Number ending with letter"
test_reject "a12" "Letter then number"
test_reject '"1" "abc" "3"' "Letter in middle"
test_reject "hello" "Word"
test_reject "1 2 three" "Word in sequence"

echo -e "\n${Y}--- Special Characters ---${NC}"
test_reject '"@"' "At symbol"
test_reject '"#"' "Hash"
test_reject '"$"' "Dollar sign"
test_reject '"%"' "Percent"
test_reject '"&"' "Ampersand"
test_reject '"*"' "Asterisk"
test_reject '"!"' "Exclamation"
test_reject '"1" "@" "3"' "Special char in middle"
test_reject "1+2" "Plus in number"
test_reject "1-2" "Minus in number"
test_reject "1*2" "Multiply in number"
test_reject "1/2" "Divide in number"

echo -e "\n${Y}--- Expressions ---${NC}"
test_reject "1+1" "Addition expression"
test_reject "2*3" "Multiplication expression"
test_reject "10/2" "Division expression"
test_reject "5-3" "Subtraction expression"

echo -e "\n${Y}--- Empty / Whitespace ---${NC}"
test_reject "" "No arguments"
test_reject '""' "Empty string"
test_reject '"" "" ""' "Multiple empty strings"
test_reject '"   "' "Only spaces"
test_reject '"	"' "Only tab"

echo -e "\n${Y}--- Multiple Numbers in One Argument ---${NC}"
test_reject '"1 2 3"' "Three numbers in quotes"
test_reject '"42 84"' "Two numbers in quotes"
test_reject '"1 2" "3"' "Mixed format"

echo -e "\n${Y}--- Invalid Format ---${NC}"
test_reject '"++1"' "Double plus"
test_reject '"+-1"' "Plus and minus"
test_reject '"-+1"' "Minus and plus"
test_reject '"--1"' "Double minus"
test_reject '"1 "' "Trailing space in arg"
test_reject '" 1"' "Leading space in arg"
test_reject "01a" "Leading zero with letter"

echo -e "\n${Y}--- Mixed Invalid ---${NC}"
test_reject '"1" "2" "-3" "4"' "Valid with negative"
test_reject '"1" "2.5" "3"' "Valid with decimal"
test_reject '"1" "abc" "3"' "Valid with letters"
test_reject '"0" "2147483648"' "Valid with overflow"

echo ""
echo "=========================================="
echo "           RESULTS"
echo "=========================================="
echo -e "${G}Passed: $PASSED${NC}"
echo -e "${R}Failed: $FAILED${NC}"
echo "Total:  $((PASSED + FAILED))"
echo "=========================================="

if [ $FAILED -eq 0 ]; then
    echo -e "${G}✓ All parsing tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${R}✗ $FAILED test(s) failed${NC}"
    exit 1
fi
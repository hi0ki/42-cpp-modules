#!/bin/bash

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Function to test and show detailed comparison
debug_test() {
    local input="$1"
    local description="$2"
    
    echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${YELLOW}Test: $description${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "Command: ${YELLOW}./PmergeMe $input${NC}"
    echo ""
    
    # Run program
    output=$(./PmergeMe $input 2>&1)
    exit_code=$?
    
    echo -e "${BLUE}Program Output:${NC}"
    echo "$output"
    echo ""
    
    # Extract Before and After
    before=$(echo "$output" | grep "^Before:" | sed 's/Before: //' | sed 's/\[...\]//')
    after=$(echo "$output" | grep "^After:" | sed 's/After: //' | sed 's/\[...\]//')
    
    if [ -z "$before" ] || [ -z "$after" ]; then
        echo -e "${RED}✗ Missing Before/After lines!${NC}"
        return
    fi
    
    # Create expected sorted output using system sort
    expected=$(echo "$input" | tr ' ' '\n' | sort -n | tr '\n' ' ')
    
    # Clean up whitespace
    after_clean=$(echo "$after" | xargs)
    expected_clean=$(echo "$expected" | xargs)
    
    echo -e "${BLUE}Comparison:${NC}"
    echo -e "  Input:    ${YELLOW}$input${NC}"
    echo -e "  Expected: ${GREEN}$expected_clean${NC}"
    echo -e "  Got:      ${after_clean}${NC}"
    echo ""
    
    if [ "$after_clean" = "$expected_clean" ]; then
        echo -e "${GREEN}✓ CORRECT - Output matches expected sorted array${NC}"
    else
        echo -e "${RED}✗ WRONG - Output does NOT match expected sorted array${NC}"
        
        # Show differences
        echo ""
        echo -e "${RED}Detailed Comparison:${NC}"
        
        # Convert to arrays
        IFS=' ' read -ra expected_arr <<< "$expected_clean"
        IFS=' ' read -ra got_arr <<< "$after_clean"
        
        echo "Position | Expected | Got      | Status"
        echo "---------|----------|----------|--------"
        
        max_len=${#expected_arr[@]}
        if [ ${#got_arr[@]} -gt $max_len ]; then
            max_len=${#got_arr[@]}
        fi
        
        for ((i=0; i<max_len; i++)); do
            exp="${expected_arr[$i]:-MISSING}"
            got="${got_arr[$i]:-MISSING}"
            
            if [ "$exp" = "$got" ]; then
                printf "%-8s | %-8s | %-8s | ${GREEN}✓${NC}\n" "$i" "$exp" "$got"
            else
                printf "%-8s | %-8s | %-8s | ${RED}✗${NC}\n" "$i" "$exp" "$got"
            fi
        done
        
        # Check for duplicates or missing
        echo ""
        if [ ${#got_arr[@]} -ne ${#expected_arr[@]} ]; then
            echo -e "${RED}✗ Array size mismatch!${NC}"
            echo "  Expected size: ${#expected_arr[@]}"
            echo "  Got size:      ${#got_arr[@]}"
        fi
    fi
    
    echo ""
}

# Check if executable exists
if [ ! -f "./PmergeMe" ]; then
    echo -e "${RED}Error: ./PmergeMe executable not found!${NC}"
    echo "Please compile with: make"
    exit 1
fi

echo "========================================"
echo "   PMERGEME DEBUG TESTER"
echo "========================================"

# Test cases
debug_test "3 5 9 7 4" "Simple test"
debug_test "1 2 3 4 5" "Already sorted"
debug_test "5 4 3 2 1" "Reverse sorted"
debug_test "42" "Single element"
debug_test "2 1" "Two elements"
debug_test "30 49 60 1 31 29 42 46 13 8 5 88 45 95 35 46 84 12 62" "Subject example with duplicates"
debug_test "5 3 5 1 5" "Multiple duplicates"
debug_test "1 1 1 1 1" "All same"

echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Testing complete!${NC}"
echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
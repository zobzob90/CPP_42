#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Test counter
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local expected_success="$3"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${CYAN}================================${NC}"
    echo -e "${YELLOW}Test $TOTAL_TESTS: $test_name${NC}"
    echo -e "${BLUE}Input: $input${NC}"
    echo -e "${CYAN}================================${NC}"
    
    # Run the test and capture output
    local output
    output=$(./scalar "$input" 2>&1)
    local exit_code=$?
    
    # Display the output
    echo "$output"
    
    # Check if output contains "Invalid Input" - this means successful rejection
    if echo "$output" | grep -q "Invalid Input"; then
        if [ "$expected_success" = "false" ]; then
            echo -e "${GREEN}✓ Test passed (correctly rejected invalid input)${NC}"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -e "${RED}✗ Test failed (unexpectedly rejected valid input)${NC}"
        fi
    else
        # Output does not contain "Invalid Input" - conversion was attempted
        if [ "$expected_success" = "true" ]; then
            echo -e "${GREEN}✓ Test passed (valid conversion)${NC}"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -e "${RED}✗ Test failed (should have been rejected)${NC}"
        fi
    fi
    echo ""
}

# Compile the program
echo -e "${MAGENTA}Compiling scalar...${NC}"
make re
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Compilation successful!${NC}"
echo ""

echo -e "${MAGENTA}==============================${NC}"
echo -e "${MAGENTA}  SCALAR CONVERSION TESTS${NC}"
echo -e "${MAGENTA}==============================${NC}"
echo ""

# CHAR TESTS
echo -e "${MAGENTA}=== CHAR TESTS ===${NC}"
run_test "Valid printable char" "'a'" true
run_test "Valid printable char (digit)" "'5'" true
run_test "Valid printable char (symbol)" "'@'" true
run_test "Valid printable char (space)" "' '" true
run_test "Non-printable char (tab)" "'\t'" false
run_test "Non-printable char (newline)" "'\n'" false
run_test "Invalid char format (no quotes)" "a" false
run_test "Invalid char format (single quote)" "'a" false
run_test "Invalid char format (too long)" "'ab'" false

# INT TESTS
echo -e "${MAGENTA}=== INT TESTS ===${NC}"
run_test "Positive integer" "42" true
run_test "Negative integer" "-42" true
run_test "Zero" "0" true
run_test "Large positive integer" "2147483647" true
run_test "Large negative integer" "-2147483648" true
run_test "Integer with plus sign" "+42" true
run_test "Integer overflow" "2147483648" true
run_test "Invalid integer (with letters)" "42a" false
run_test "Valid double (was wrongly marked as invalid)" "42.5" true

# FLOAT TESTS
echo -e "${MAGENTA}=== FLOAT TESTS ===${NC}"
run_test "Positive float" "42.5f" true
run_test "Negative float" "-42.5f" true
run_test "Float with zero decimal" "42.0f" true
run_test "Float with multiple decimals" "3.14159f" true
run_test "Float with plus sign" "+42.5f" true
run_test "Float NaN" "nanf" true
run_test "Float positive infinity" "+inff" true
run_test "Float negative infinity" "-inff" true
run_test "Valid double without f suffix" "42.5" true
run_test "Invalid float (double f)" "42.5ff" false
run_test "Invalid float (no decimal)" "42f" true

# DOUBLE TESTS
echo -e "${MAGENTA}=== DOUBLE TESTS ===${NC}"
run_test "Positive double" "42.5" true
run_test "Negative double" "-42.5" true
run_test "Double with zero decimal" "42.0" true
run_test "Double with multiple decimals" "3.14159265359" true
run_test "Double with plus sign" "+42.5" true
run_test "Double NaN" "nan" true
run_test "Double positive infinity" "+inf" true
run_test "Double negative infinity" "-inf" true
run_test "Large double" "1.7976931348623157e+308" true

# EDGE CASES
echo -e "${MAGENTA}=== EDGE CASES ===${NC}"
run_test "Empty string" "" false
run_test "Just a minus" "-" false
run_test "Just a plus" "+" false
run_test "Multiple dots" "42.5.3" false
run_test "Invalid special value" "infinity" false
run_test "Case sensitive nan" "NAN" false
run_test "Case sensitive inf" "INF" false

# BOUNDARY TESTS
echo -e "${MAGENTA}=== BOUNDARY TESTS ===${NC}"
run_test "ASCII boundary (space char 32)" "32" true
run_test "ASCII boundary (DEL char 127)" "127" true
run_test "ASCII boundary (below printable)" "31" true
run_test "ASCII boundary (above printable)" "128" true
run_test "Char boundary test" "'~'" true  # ASCII 126

# ARGUMENT TESTS
echo -e "${MAGENTA}=== ARGUMENT TESTS ===${NC}"
echo -e "${CYAN}Testing with no arguments:${NC}"
./scalar 2>/dev/null
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ Correctly rejected no arguments${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ Should have rejected no arguments${NC}"
fi
TOTAL_TESTS=$((TOTAL_TESTS + 1))

echo -e "${CYAN}Testing with multiple arguments:${NC}"
./scalar "42" "43" 2>/dev/null
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ Correctly rejected multiple arguments${NC}"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ Should have rejected multiple arguments${NC}"
fi
TOTAL_TESTS=$((TOTAL_TESTS + 1))

# RESULTS
echo ""
echo -e "${MAGENTA}==============================${NC}"
echo -e "${MAGENTA}        TEST RESULTS${NC}"
echo -e "${MAGENTA}==============================${NC}"
echo -e "${YELLOW}Total tests: $TOTAL_TESTS${NC}"
echo -e "${GREEN}Passed: $PASSED_TESTS${NC}"
echo -e "${RED}Failed: $((TOTAL_TESTS - PASSED_TESTS))${NC}"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}"
    exit 0
else
    echo -e "${RED}❌ SOME TESTS FAILED ❌${NC}"
    echo -e "${YELLOW}Success rate: $(( PASSED_TESTS * 100 / TOTAL_TESTS ))%${NC}"
    exit 1
fi
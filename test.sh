#!/bin/bash
cd Tests
for file in */*/Inputs.txt
do
    output="$(dirname "$file")/Outputs.txt"
    expected_output="$(dirname "$file")/ExpectedOutputs.txt"
    results="$(dirname "$file")/Results.txt"
    echo "$file"
    ../auction ../currentUsers.txt ../dailyTransactionFile.txt ../availableItems.txt  < $file > $output
    if diff --strip-trailing-cr $output $expected_output
    then
        echo "Test Passed!" > $results
        diff --strip-trailing-cr $output $expected_output >> $results
    else
        echo "Test Failed!" > $results
        diff --strip-trailing-cr $output $expected_output >> $results
    fi
done
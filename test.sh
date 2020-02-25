#!/bin/bash
cd Tests
for file in */inputs.txt
do
    output="$(dirname "$file")/outputs.txt"
    expected_output="$(dirname "$file")/expected_outputs.txt"
    results="$(dirname "$file")/results.txt"
    ../auction ../currentUsers.txt < $file > $output
    if diff --strip-trailing-cr $output $expected_output
    then
        echo "Test Passed!" >> $results
    else
        echo "Test Failed!" >> $results
    fi
done
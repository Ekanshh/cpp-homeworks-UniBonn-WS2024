# to count number of lines 
wc -l data.dat | grep -o "[0-9]*"
# to count the occurence of given words 
grep -E "dolor|dalor" data.dat | wc -l
# to count total number of words
wc -w data.dat | grep -o "[0-9]*"
# to count the occurence of words starting with a given string
grep -E "\bmol" data.dat | wc -l

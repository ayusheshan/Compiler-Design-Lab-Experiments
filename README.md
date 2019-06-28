Conversion of regular expression to NFA will always produce a 8 X 8 matrix. 0 means no transition while E means Epsilon transition. Any other character is the input symbol required for respective transition. Please note that this code will only work on simple regular expressions like
a, a*, a+, a.b, a|b, (a.b)*, (a.b)+, (a|b)*, (a|b)+

Left Factoring code will work only on one production at the time of execution. Also, the production must not have left recursion.

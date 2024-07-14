/*
Time Complexity: O(b), the recursive function will be called b times
Space Complexity: O(b), b*2 number of arguments will be pushed into the stack frame
*/

long long int multiplyHelper(long long int a, long long int b) {
  if(b == 0) return 0;
  return a + multiplyHelper(a, b - 1);
}

long long int multiply(long long int a, long long int b) {
  if(a > b) swap(a, b);
  return multiplyHelper(a, b);
}

/*
Explanation:
Multiplication is basically repeated addition.
We are repeatedly adding the same number to itself using recursion instead of iteration.
The swap is an optimization to ensure that the function is called fewer times.
The lesser number acts as a counter to how many times we need to add the greater number to itself.
*/

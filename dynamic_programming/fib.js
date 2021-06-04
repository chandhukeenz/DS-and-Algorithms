const fib = (n,memo={})=>{
    if(n in memo) return memo[n];
    if(n<=2) return 1;
    memo[n]= fib(n-1,memo)+fib(n-2,memo);
    return memo[n];
};

console.log(fib(4));
console.log(fib(7));
console.log(fib(50));

/*brute force
o(2^n) time
o(n) space
memoized 
o(n) time
o(n) space
*/
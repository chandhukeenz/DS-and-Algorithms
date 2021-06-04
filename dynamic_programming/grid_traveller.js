//how many ways can you travel from the top left to the bottom right using only down and right move.
const gridTraveller =(m,n,memo={}) =>{
    const index =m+','+n;
    if(index in memo) return memo[index];
    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;
    memo[index] = gridTraveller(m-1,n,memo)+gridTraveller(m,n-1,memo);
    return memo[index];
};
console.log(gridTraveller(1,1));
console.log(gridTraveller(2,3));
console.log(gridTraveller(3,2));
console.log(gridTraveller(4,3));
console.log(gridTraveller(18,18));
/*
bruteforce
o(2^(n+m)) time
o(n+m) space
memoized
o(m*n) time
o(n+m) space
*/
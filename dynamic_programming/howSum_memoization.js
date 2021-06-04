//howSum should return the array of elements or null based on if we
//could create the target sum with the array elements or not
const howSum = (targetSum,arr,memo={})=>{
    if(targetSum in memo) return memo[targetSum];
    if(targetSum==0) return [];
    if(targetSum<0) return null;
    for(let num of arr){
        const remainingSum = targetSum - num;
        const remainderResult=howSum(remainingSum,arr,memo);
        if(remainderResult!==null){
            memo[targetSum]= [...remainderResult,num];
            return memo[targetSum];
        }            
    }
    memo[targetSum]=null;
    return null;
};

console.log(howSum(7,[2,3]));//[3,2,2]
console.log(howSum(7,[5,3,4,7]));//[4,3]
console.log(howSum(7,[2,4]));//null
console.log(howSum(8,[2,3,5]));//[2,2,2,2]
console.log(howSum(300,[7,14]));//null

/*
bruteforce
o(n^m * m) time
o(m) space
memoized
o(n*m^2)
o(m*2)
*/
//canSum should return true or false based on if we
// could create the target sum with the array elements or not
const canSum=(targetSum,arr,memo={})=>{
    if(targetSum in memo) return memo[targetSum];
    if(targetSum==0) return true;
    if(targetSum<0) return false;
    for (let num of arr){
        const remainingSum = targetSum - num;
        if(canSum(remainingSum,arr,memo)===true) {
            memo[targetSum]=true;
            return true;
        }
    }
    memo[targetSum]=false;
    return false;
};

console.log(canSum(7,[2,3]));//true
console.log(canSum(7,[5,3,4,7]));//true
console.log(canSum(7,[2,4]));//false
console.log(canSum(8,[2,3,5]));//true
console.log(canSum(300,[7,14]));//false
/*
bruteforce
o(n^m) time
o(m) space
memoized
o(m*n) time
o(m) space
*/
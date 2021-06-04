const bestSum=(targetSum,arr,memo={})=>{
    if(targetSum in memo) return memo[targetSum];
    if(targetSum==0) return [];
    if(targetSum<0) return null;
    let bestarr=null;
    for(let num of arr){
        const remainingSum=targetSum-num;
        const remainderResult = bestSum(remainingSum,arr,memo);
        if(remainderResult!==null){
            const combinationarr = [...remainderResult,num];
            if(bestarr===null || combinationarr.length<bestarr.length){
                bestarr=combinationarr;
            }
        }
    }
    memo[targetSum]=bestarr;
    return bestarr;
}

console.log(bestSum(7,[5,3,4,7]));
console.log(bestSum(8,[2,3,5]));
console.log(bestSum(8,[1,4,5]));
console.log(bestSum(100,[1,2,5,25]));

/*
bruteforce
o(n^m *m) time
o(m^2) space
memoized
o(m^2*n) time
o(m^2) space
*/
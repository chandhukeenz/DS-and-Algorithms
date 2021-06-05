/*write a function "allConstruct(target,wordBank)" which accepts a target string and an array of strings
The function should return a 2D array containing all of the ways that the "target" can be constructed 
by concatenating elements of the "wordBank" array
*/
const allConstruct = (target,wordBank,memo={})=>{
    if(target in memo) return memo[target];
    if(target==='') return [[]];
    const allways =[];
    for(let word of wordBank){
        if(target.indexOf(word)===0){
            const suffix = target.slice(word.length);
            const suffixways = allConstruct(suffix,wordBank,memo);
            const targetways = suffixways.map(way =>[word, ...way]);
            allways.push(...targetways);
        }
    }
    memo[target]=allways;
    return allways;
};

console.log(allConstruct("purple",["purp","p","ur","le","purpl"]));
console.log(allConstruct("abcdef",["ab","abc","cd","def","abcd","ef","a","bcde","f"]));
console.log(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeek",["e","ee","eee","eeee","eeeee"]));

/*
O(n^m) leaves => combinations =>subarrays
O(n^m) time]
O(m) space
*/
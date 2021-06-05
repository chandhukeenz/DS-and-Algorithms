/*write a function "countConstruct(target,wordBank)" which accepts a target string and an array of strings
The function should return the number of ways that the "target" can be constructed 
by concatenating elements of the "wordBank" array
*/
const countConstruct = (target,wordBank,memo={})=>{
    if(target in memo) return memo[target];
    if(target=='') return 1;
    let count =0;
    for(let word of wordBank){
        if(target.indexOf(word)===0){
            const suffix = target.slice(word.length);
            const suffixways = countConstruct(suffix,wordBank,memo);
            count += suffixways;
        }
    }
    memo[target] = count;
    return count;
};

console.log(countConstruct("purple",["purp","p","ur","le","purpl"]));
console.log(countConstruct("abcdef",["ab","abc","cd","def","abcd"]));
console.log(countConstruct("skateboard",["bo","rd","ska","ate","t","sk","boar"]));
console.log(countConstruct("chandhanakeerthana",["chandh","andh","hand","ana","kee","rtha","na"]));
console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeek",["e","ee","eee","eeee","eeeee"]));

/*
bruteforce
o(n^m * m) time
o(m^2) space
memoized
o(n*m^2) time
o(m^2) space 
*/
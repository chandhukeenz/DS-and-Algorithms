//return true or false based on if you could create the given string or not from the given substrings
const canConstruct = (target,wordBank,memo={})=>{
    if(target in memo) return memo[target];
    if(target==='') return true;
    for(let word of wordBank){
        if(target.indexOf(word)===0){
            const suffix = target.slice(word.length);
            if(canConstruct(suffix,wordBank,memo)===true){
                memo[target]=true;
                return true;
            }
        }
    }
    memo[target]=false;
    return false;
};

console.log(canConstruct("abcdef",["ab","abc","cd","def","abcd"]));
console.log(canConstruct("skateboard",["bo","rd","ska","ate","t","sk","boar"]));
console.log(canConstruct("chandhanakeerthana",["chandh","andh","hand","ana","kee","rtha","na"]));
console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeek",["e","ee","eee","eeee","eeeee"]));

/*
bruteforce
O(n^m * m) time
O(m^2) space
memoized
O(n*m^2) time
O(m^2) space
*/
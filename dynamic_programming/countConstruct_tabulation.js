const countConstruct=(target, wordBank)=>{
    const table = Array(target.length+1).fill(0);
    table[0]=1;
    let count=0;
    for(let i=0;i<=target.length;i++){
        if(table[i]!==0){
            for(let word of wordBank){
                if(target.slice(i,i+word.length)===word){
                    table[i+word.length]+=table[i];
                }
            }
        }
    }
    return table[target.length];
};

console.log(countConstruct("purple",["purp","p","ur","le","purpl"]));
console.log(countConstruct("abcdef",["ab","abc","cd","def","abcd"]));
console.log(countConstruct("skateboard",["bo","rd","ska","ate","t","sk","boar"]));
console.log(countConstruct("chandhanakeerthana",["chandh","andh","hand","ana","kee","rtha","na"]));
console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeek",["e","ee","eee","eeee","eeeee"]));
/*
O(m^2 n) time
O(m) space
*/
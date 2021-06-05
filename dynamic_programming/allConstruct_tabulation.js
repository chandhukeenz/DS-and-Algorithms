const allConstruct=(target, wordBank)=>{
    const table = Array(target.length+1).fill().map(()=>[]);
    table[0]=[[]];
    for(let i=0;i<=target.length;i++){
        for(let word of wordBank){
            if(target.slice(i,i+word.length)===word){
                const combination = table[i].map(subArray =>[...subArray,word]);
                table[i+word.length].push(...combination);
            }
        }
    }
    return table[target.length];
};

console.log(allConstruct("purple",["purp","p","ur","le","purpl"]));
console.log(allConstruct("abcdef",["ab","abc","cd","def","abcd","ef","a","bcde","f"]));
console.log(allConstruct("eeeeeeeeeeeeeeeek",["e","ee","eee","eeee","eeeee"]));

/*
o(n^m) time
o(n^m) space
*/
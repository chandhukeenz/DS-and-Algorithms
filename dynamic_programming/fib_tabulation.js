const fib =(n)=>{
    const table = Array(n+1).fill(0);
    table[1] = 1;
    for(let i=0; i<=n;i++){
        table[i+1]+=table[i];
        table[i+2]+=table[i];
    }
    return table[n];
};

console.log(fib(6));
console.log(fib(7));
console.log(fib(9));
console.log(fib(50));
//O(n) time O(n) space
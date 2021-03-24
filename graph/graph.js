class Graph{
    constructor(){
        this.adjacencyList={};
    }
    addVertex(vertex){
        if(!this.adjacencyList[vertex]) this.adjacencyList[vertex]=[];
    }
    addEdge(v1,v2){
        this.adjacencyList[v1].push(v2);
        this.adjacencyList[v2].push(v1);
    }
    removeEdge(v1,v2){
        this.adjacencyList[v1] =this.adjacencyList[v1].filter(
        v=>v!==v2
        );
        this.adjacencyList[v2] =this.adjacencyList[v2].filter(
        v=>v!==v1
        );
    }
    removeVertex(vertex){
        while(this.adjacencyList[vertex].length){
            const adjacenctVertex =this.adjacencyList[vertex].pop();
            this.removeEdge(vertex,adjacenctVertex);
        }
        delete this.adjacencyList[vertex];
    }
    depthFirstRecursive(start){
        const result=[];
        const visited ={};
        const  adjacencyList = this.adjacencyList;
        (function dfs(vertex){
            if(!vertex) return null;
            visited[vertex] =true;
            result.push(vertex);
            adjacencyList[vertex].forEach(neighbor=>{
                if(!visited[neighbor]){
                    return dfs(neighbor);}
            })
        })(start);
        return result;
    }
    depthFirstIterative(start){
        const stack =[start];
        const result =[];
        const visited={};
        let currentVertex;
        visited[start]=true;
        while(stack.length){
            currentVertex = stack.pop();
            result.push(currentVertex);
            this.adjacencyList[currentVertex].forEach(neighbor=>{
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    stack.push(neighbor);
                }
            });
        }
        return result;
    }
    breadthFirst(start){
        const queue =[start];
        const result=[];
        const visited={};
        let currentVertex;
        visited[start]=true;
        while(queue.length){
            currentVertex =queue.shift();
            result.push(currentVertex);
            this.adjacencyList[currentVertex].forEach(neighbor=>{
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    queue.push(neighbor);
                }
            });
        }
        return result;
    }
}


let k = new Graph;
k.addVertex("A");
k.addVertex("B");
k.addVertex("C");
k.addVertex("D");
k.addVertex("E");
k.addVertex("F");
k.addEdge("A","B")
k.addEdge("A","C")
k.addEdge("B","D")
k.addEdge("C","E")
k.addEdge("D","E")
k.addEdge("D","F")
k.addEdge("E","F")
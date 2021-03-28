class priorityQueue{
	constructor(){
		this.values = [];
	}
	
	enqueue(val,priority){
	    let newnode =new Node(val,priority);
		this.values.push(newnode);
		this.bubbleup();
	}
	bubbleup(){
		let idx = this.values.length - 1;
		const element = this.values[idx];
		while(idx > 0){
			let parentidx = Math.floor((idx-1)/2);
			let parent = this.values[parentidx];
			if(element.priority >= parent.priority)break;
			this.values[parentidx] = element;
			this.values[idx]=parent;
			idx = parentidx;
		}
	}

	dequeue(){
		const min =this.values[0];
		const end =this.values.pop();
		if(this.values.length>0){
			this.values[0]=end;
		    this.sinkDown();	
		}
		return min;
	}
	sinkDown(){
		let idx=0;
		const length =this.values.length;
		const element = this.values[0];
		while(true){
			let leftChildIdx =2*idx+1;
			let rightChildIdx =2*idx+2;
			let leftChild,rightChild;
			let swap=null;
			if(leftChildIdx<length){
				leftChild=this.values[leftChildIdx];
				if(leftChild.priority<element.priority){
					swap=leftChildIdx;
				}
			}
			if(rightChildIdx<length){
				rightChild=this.values[rightChildIdx];
				if((swap===null && rightChild.priority<element.priority)||
				(swap!==null &&rightChild.priority<leftChild.priority)){
					swap=rightChildIdx;
				}
			}
			if(swap===null) break;
			this.values[idx]=this.values[swap];
			this.values[swap]=element;
			idx=swap;
		}
	}
}
class Node{
    constructor(val,priority){
        this.val=val;
        this.priority =priority;
    }
}

class weightedGraph{
    constructor(){
        this.adjacencyList={};
    }
    addVertex(vertex){
        if(!this.adjacencyList[vertex]) this.adjacencyList[vertex]=[];
    }
    addEdge(v1,v2,weight){
        this.adjacencyList[v1].push({node:v2,weight});
        this.adjacencyList[v2].push({node:v1,weight});
    }
    dijkstra(start,finish){
        const nodes =new priorityQueue();
        const distances = {};
        const previous ={};
        let path=[];
        let smallest;
        for(let vertex in this.adjacencyList){
            if(vertex===start){
                distances[vertex]=0;
                nodes.enqueue(vertex,0);
            }else{
                distances[vertex]=Infinity;
                nodes.enqueue(vertex,Infinity);
            }
            previous[vertex]=null;
        }
        while(nodes.values.length){
            smallest =nodes.dequeue().val;
            if(smallest==finish){
                while(previous[smallest]){
                    path.push(smallest);
                    smallest=previous[smallest];
                }
                break;
            }
            if(smallest||distances[smallest]!==Infinity){
                for(let neighbor in this.adjacencyList[smallest]){
                    let nextNode =this.adjacencyList[smallest][neighbor];
                    let candidate = distances[smallest]+nextNode.weight;
                    let nextNeighbor =nextNode.node;
                    if(candidate<distances[nextNeighbor]){
                        distances[nextNeighbor]=candidate;
                        previous[nextNeighbor]=smallest;
                        nodes.enqueue(nextNeighbor,candidate);
                    }
                }
            }
        }
        return path.concat(smallest).reverse();
    }
}
var graph = new weightedGraph()
graph.addVertex("A");
graph.addVertex("B");
graph.addVertex("C");
graph.addVertex("D");
graph.addVertex("E");
graph.addVertex("F");

graph.addEdge("A","B", 4);
graph.addEdge("A","C", 2);
graph.addEdge("B","E", 3);
graph.addEdge("C","D", 2);
graph.addEdge("C","F", 4);
graph.addEdge("D","E", 3);
graph.addEdge("D","F", 1);
graph.addEdge("E","F", 1);

console.log(graph.dijkstra("A","E"));
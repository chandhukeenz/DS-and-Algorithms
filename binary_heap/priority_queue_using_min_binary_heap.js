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

let er =new priorityQueue();
er.enqueue("common cold",5)
er.enqueue("gunshot wound",1)
er.enqueue("high fever",4)
er.enqueue("broken arm",2)
er.enqueue("glass cut",3)
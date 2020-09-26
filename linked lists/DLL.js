class Node{
	constructor(val){
		this.val=val;
		this.next=null;
		this.prev=null;
	}
}
class dll{
	constructor(){
		this.head=null;
		this.tail=null;
		this.length=0;
	}
	push(val){
		var newnode = new Node(val);
		if(this.length==0){
			this.head=newnode;
			this.tail=this.head;
		}else{
			this.tail.next=newnode;
			newnode.prev=this.tail;
			this.tail=newnode;
		}
		this.length++;
		return this;
	}
	
    pop(){
        if(!this.head) return undefined;
        var poppedNode = this.tail;
        if(this.length === 1){
            this.head = null;
            this.tail = null;
        } else {
            this.tail = poppedNode.prev;
            this.tail.next = null;
            poppedNode.prev = null;
        }
        this.length--;
        return poppedNode;
    }
	shift(){
		if(!this.head) return undefined;
		var shiftnode=this.head;
		if(this.length === 1){
            this.head = null;
            this.tail = null;
        } else {
			this.head=shiftnode.next;
			this.head.prev=null;
			shiftnode.next=null;
        }
        this.length--;
        return shiftnode;
	}
	unshift(val){
		var newhead= new Node(val);
		if(!this.head){
			this.head=newhead;
			this.tail=this.head;
		}else{
			this.head.prev=newhead;
			newhead.next=this.head;
			this.head=newhead;
		}
		this.length++;
		return this;
	}
	get(index){
		if(index>this.length-1 || index<0) return undefined;
		var count,current;
		if(index<this.length/2){
			count=0;
			current=this.head;
			while(count!=index){
				current=current.next;
				count++;
			}
		}else{
			count=this.length-1;
			current=this.tail;
			while(count!=index){
				current=current.prev;
				count--;
			}
		}
		return current.val;
	}
	set(index,val){
		var foundindex=this.get(index);
		if(foundindex){
			foundindex.val=val;
			return true;
		}
		return false;
	}
	insert(index,val){
		if(index==0)return this.unshift(val);
	    if(index==this.length)return this.push(val);
	    if(index>this.length || index<0)return undefined;
		var prevnode = this.get(index-1);
		var nextnode =prevnode.next;
		var newnode = new Node(val);
		prevnode.next =newnode;
		newnode.prev=prevnode;
		newnode.next=nextnode;
		nextnode.prev=newnode;
		this.length++;
		return this;
	}
	remove(index){
		if(index>=this.length||index<0)return undefined;
		if(index==0)return this.shift();
		if(index==this.length-1)return this.pop();
		var beforeNode = this.get(index-1);
        var afterNode = this.get(index+1);
		beforeNode.next=afterNode;
		afterNode.prev=beforeNode;
		this.length--;
        return this;
	}
}

var list = new dll();
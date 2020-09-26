class Node{
	constructor(val){
		this.val=val;
		this.next=null;
	}
}

class sll{
	constructor(){
		this.head=null;
		this.tail=null;
		this.length=0;
	}
	
	push(val){
		var newnode = new Node(val);
		if(!this.head){
			this.head=newnode;
			newnode.val=val;
			this.tail=newnode;
		}else{
			this.tail.next=newnode;
			this.tail=newnode;
		}
		this.length++;
		return this;
	}
	pop(){
		if(this.length==0)return undefined;
		var current = new Node;
		current=this.head;
		for(var i=0;i<this.length-1;i++){
			current=current.next;
		}
		this.tail=current;
		current.next=null;
		this.length--;
		if(this.length==0){
            this.head=null;
            this.tail=null;
        }
		return current;
	}
	shift(){
		if(!this.head)return undefined;
		var removed = new Node;
		removed=this.head;
		this.head=this.head.next;
		this.length--;
		if(this.length==0){
            this.tail=null;
        }
		return removed;
	}
	unshift(val){
		var newhead = new Node(val);
		if(!this.head){
			this.head=newhead;
			this.tail=this.head;
		}else{
		newhead.next = this.head;
		this.head=newhead;			
		}
		this.length++;
		return this;
	}
	get(index){
		if(index>=this.length || index<0) return undefined;
		var found = new Node;
		found=this.head;
		var count=0;
		while(index!==count){
			count++;
			found=found.next;
		}
		return found;
	}
	set(index,val){
		var change = new Node;
		change = this.get(index);
		change.val=val;
		return this;
	}
	insert(index,val){
		if(index===0)return this.unshift(val);
		if(index===this.length)return this.push(val);
		var newnode = new Node(val);
		var prevnode = this.get(index-1);
		var nextnode =this.get(index);
		prevnode.next=newnode;
		newnode.next=nextnode;
		this.length++;
		return this;
	}
	remove(index){
		if(index===0)return this.shift();
		if(index===this.length-1)return this.pop();
		var prevnode = this.get(index-1);
		var nextnode =this.get(index+1);
		prevnode.next=nextnode;
		this.length--;
		return this;
	}
	reverse(){
		if(!this.head)return this;
		var prev =null;
		var current=this.head;
		this.head=this.tail;
		this.tail=current;
		var next=null;
		for(var i=0;i<this.length;i++){
			next=current.next;
			current.next=prev;
			prev=current;
			current=next;
		}
		var a=[];
		for(var i=0;i<this.length;i++){
			var m=this.get(i);
			a.push(m.val);
		}
		return a;
	}
}











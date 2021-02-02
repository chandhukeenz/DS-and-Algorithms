class Node{
    constructor(value){
        this.value=value;
        this.next=null;
    }
}

class Queue{
    constructor(){
        this.first=null;
        this.last=null;
        this.size=0;
    }
    enqueue(val){
        var newnode =new Node(val);
        if(!this.first){
            this.first=newnode;
            this.last=newnode;
        }else{
            this.last.next=newnode;
            this.last=newnode;
        }
        return ++this.size;
    }
    dequeue(){
        if(!this.first) return null;
        var temp=this.first;
        if(this.first===this.last){
            this.last=null;
        }
        this.first=this.first.next;
        this.size--;
        return temp.value;
    }
    peek(){
        return this.first;
    }
    isfull(maxsize){
        if(this.size==maxsize) return true;
        else return false;
    }
    isempty(){
        if(!this.first) return true;
        else return false;
    }
}
var queue =new Queue();
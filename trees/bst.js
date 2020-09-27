class Node{
	constructor(val){
		this.val=val;
		this.left=null;
		this.right=null;
	}
}

class tree{
	constructor(){
		this.root=null;
	}
	insert(val){
		var newnode = new Node(val);
		if(!this.root){
			this.root=newnode;
			return this;
		}
		var current=this.root;
		while(true){
			if(newnode.val===current.val)return undefined;
			if(newnode.val<current.val){
				if(current.left==null){
					current.left=newnode;
				    return this;
				}
				current=current.left;
			}else{
				if(current.right==null){
					current.right=newnode;
				    return this;
				}
				current=current.right;
			}
		}
	}
	contains(value){
		if(this.root==null)return false;
		var current=this.root;
		while(true){
			if(current.val==value)return true;
			if(value<current.val){
				if(current.left==null)return false;
				current=current.left;
			}else{
				if(current.right==null)return false;
				current=current.right;
			}
		}
	}
	bfs(){
		var node=this.root,
		    data=[],
			queue=[];
		queue.push(node);
		while(queue.length){
			node=queue.shift();
			data.push(node.val);
			if(node.left) queue.push(node.left);
			if(node.right) queue.push(node.right);
		}
		return data;
	}
	dfspreorder(){
		var data=[];
		function traverse(node){
			data.push(node.val);
			if(node.left) traverse(node.left);
			if(node.right) traverse(node.right);
		}
		traverse(this.root);
		return data;
	}
	dfspostorder(){
		var data=[];
		function traverse(node){
			if(node.left) traverse(node.left);
			if(node.right) traverse(node.right);
			data.push(node.val);
		}
		traverse(this.root);
		return data;
	}
	dfsinorder(){
		var data=[];
		function traverse(node){
			if(node.left) traverse(node.left);
			data.push(node.val);
			if(node.right) traverse(node.right);
		}
		traverse(this.root);
		return data;
	}
//	contains(value){
//        if(this.root === null) return false;
//        var current = this.root,
//            found = false;
//        while(current && !found){
//            if(value < current.value){
//                current = current.left;
//            } else if(value > current.value){
//                current = current.right;
//            } else {
//                return true;
//            }
//        }
//        return false;
//    }


}


var list = new tree();
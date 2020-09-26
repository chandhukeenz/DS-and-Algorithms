function merge(arr1,arr2){
	var a=[],i=0,j=0;
	while(i<arr1.length && j<arr2.length){
		if(arr1[i]<arr2[j]){
			a.push(arr1[i]);
			i++;
		}else{
			a.push(arr2[j]);
			j++;
		}
	}
	while(i<arr1.length){
		a.push(arr1[i]);
		i++;
	}
	while(j<arr2.length){
		a.push(arr2[j]);
		j++;
	}
	return a;
}

function mergesort(arr){
	if(arr.length<=1) return arr;
	let mid = arr.length/2;
	let left = mergesort(arr.slice(0,mid));
    let right = mergesort(arr.slice(mid));
	return merge(left,right);
}

//pseudocode
//1.merge helper function 2 arrays
//2.  initialise empty array a, i=0,j=0
//3.  while i <arr1 length and j < arr2 length
//4.    push smallest value b/w arr1[i] and arr2[j]
//5.    increment i or j respectively
//6.  push the remaining values of the bigger array if any 
//
//1.mergesort
//2. if array length =1 return array
//3. find mid index
//4. left calls mergesort(array.slice(0,mid))
//5. right calls mergesort( array.slice(mid))
//6. return the output from merge(left,right)
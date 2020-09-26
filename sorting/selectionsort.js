function selectionsort(arr){
	var lowest;
	var temp;
	for(var i=0;i<arr.length;i++){
		lowest=i;
		for(var j=i+1;j<arr.length;j++){
			if(arr[j]<arr[lowest]){
				lowest=j
			}
		}
		if(i!== lowest){
			temp=arr[lowest];
			arr[lowest]=arr[i];
			arr[i]=temp;
		}
	}
	return arr;
}

//pseudocode
//1.selection sort
//2.var i from 0 increase to array length
//3   lowest as i
//4.  var j from i+1 increase to array length
//5.    if arr[j]< arr[lowest]
//6.      lowest=j
//7.  if i not= lowest
//8.    exchange arr[i] and arr[lowest]
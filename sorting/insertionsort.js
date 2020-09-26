function insertionsort(arr){
	for(var i=1;i<arr.length;i++){
		currentval=ar[i];
		for(var j=i-1;j>=0 && arr[j]>currentval;j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=currentval;
	}
	return arr;
}

//[3,1,5,39,2]
//pseudocode
//1.insertionsort
//2.  var i from 1 to array length
//3.    currentval=array[i]
//4.    var j from i-1 to 0 and array[j]>currentval
//5.      move arr[j] to arr[j+1] 
//6.    set the currentval at array[j+1]
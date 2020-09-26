function bubblesort(arr){
	var temp;
	for(var i=arr.length;i>0;i--){
		var swap=false;
		for(var j=0;j<i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
				swap=true;
			}
		}
		if(swap==false)break;
	}
	return arr;
}

//pseudocode:
//  bubblesort:
//1. for i = length-1 to 1
//2.  for j = 0:length upto i – 1
//3    if A[j] > A[j+1]
//4     exchange A[j] with A[j +1]
int search(int* arr, int n, int k) {
    // Write your code here.
    
     
        //we have to check whether the left half is sorted or not 
        //if it is sorted check our target value is present in between those elements

        int i = 0;
        int j = n - 1;
        while(i <= j){
            int mid = i + (j - i)/2;
            if(arr[mid] == k) {
                return mid;
            }
            //checking left array is sorted or not
            else if(arr[i] <= arr[mid]) {
                if(k >= arr[i] && k <= arr[mid]) {
                    j = mid -1;
                }
                else i = mid + 1;
            }
            else{
                if(k >= arr[mid] && k <= arr[j]) {
                    i = mid + 1;
                }else j = mid - 1;
            }
            }
        return -1;
}

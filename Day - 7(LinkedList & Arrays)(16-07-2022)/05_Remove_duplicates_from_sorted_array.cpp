int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int i = 0;
    int j = 0;
    for(i = 0; i<n-1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = arr[n-1];
    return j+1;
}

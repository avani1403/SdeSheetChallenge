void sort012(int *arr, int n)
{
   //   Write your code here
    //  int n=sizeof(arr)/sizeof(arr[0]);
        int i=0;
    int mid = 0;
    int j=n-1;
    while(mid <= j){
        if(arr[mid] == 0)
        {
            swap(arr[i], arr[mid]);
            i++;
            mid++;
        }else if(arr[mid] == 2)
        {
            swap(arr[j], arr[mid]);
            j--;
        }
        else mid++;
    }
}

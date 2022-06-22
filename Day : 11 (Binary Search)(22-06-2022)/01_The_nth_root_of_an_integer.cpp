//Using binary search - not working

// double multiple(double m, int n)
// {
//     double ans = 1.0;
//     for( int i = 1; i<=n; i++)
//     {
//         ans *= m;
//     }
//     return ans;
// }

// double findNthRootOfM(int n, long long m) {
// 	// Write your code here.
//     // n = 3, m = 27  3 root 27 = 3.000000
//     // n = 4 m = 15    4 root 15 = 1.96798
    
//     double start = 1;
//     double end = m;
//     double eps = 1e-6;   //means diff = 10 power -6
//     //as we r shrinking the search space - so we r using this condition in while loop
//     while((end - start ) > eps)
//     {
//         double mid = start + (end-start)/2.0;
//         if(multiple(mid, n) < m)
//         {
//             start = mid;
//         }
//         else end = mid ;
//     }
//     return start;
// }


/*
    Time Complexity : O(log(M) * log(N))
    Space Complexity : O(1),
        
    where N and M are given integers.
*/

double findNthRootOfM(int n, long long m) {

    // Variable to store maximum possible error in order
    // to obtain the precision of 10^(-6) in the answer.
    double error = 1e-7;

    // Difference between the current answer, and the answer
    // in next iteration, which we take as big as possible initially.
    double diff = 1e18;

    // Guessed answer value
    double xk = 2;

    // We keep on finding the precise answer till the difference between
    // answer of two consecutive iteration become less than 10^(-7).
    while (diff > error) {

        // Answer value in the next iteration.
        double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));

        // Difference of answer in consecutive states updated.
        diff = abs(xk - xk_1);

        // Updating the current answer with the answer of next iteration.
        xk = xk_1;
    }

    // Returning the nthRootOfM with precision upto 6 decimal places
    // which is xk.
    return xk;
}


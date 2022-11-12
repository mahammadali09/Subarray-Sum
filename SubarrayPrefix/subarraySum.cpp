#include <iostream>

/*
    This function will be return largest sum of subarrays. 
    Also this function will take an array and array length 
    as a parameter. We will slove this problem with Prefix 
    Sum approach. Unlike Brute Force Sum, Prefix Sum 
    reduces time complexity.
*/
int largestSubarrSum(int arr[], int n) {
    //Prefix Sum approach.....

    //This array will hold sum of subarrays
    int prefix[n] = {0};
    prefix[0] = arr[0];

    //This loop time complexity is N
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1]+arr[i];
    }

    int largestSum {0};

    //This nested loop time complexity is N^2
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int subarraySum = i>0 ? prefix[j]-prefix[i-1] : prefix[j];
            largestSum = std::max(largestSum, subarraySum);
    }
    }
    //Ultimately time complexity will be N^2 from N + N^2
    return largestSum;
}

int main() {
    int array[] = {1, -3, 6, 9, 43, -17, -37};

    //Measurement of array length
    int arrLength {sizeof(array)/sizeof(int)};

    std::cout<<largestSubarrSum(array, arrLength);

}
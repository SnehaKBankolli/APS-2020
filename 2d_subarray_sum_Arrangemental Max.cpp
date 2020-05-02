// Program to find maximum sum subarray 
// in a given 2D array 
#include<bits/stdc++.h> 
using namespace std; 



// Implementation of Kadane's algorithm for 
// 1D array. The function returns the maximum 
// sum and stores starting and ending indexes 
// of the maximum sum subarray at addresses 
// pointed by start and finish pointers 
// respectively. 
int kadane(int* arr, int* start, 
        int* finish, int n) 
{ 
    // initialize sum, maxSum and 
    int sum = 0, maxSum = INT_MIN, i; 

    // Just some initial value to check 
    // for all negative values case 
    *finish = -1; 

    // local variable 
    int local_start = 0; 

    for (i = 0; i < n; ++i) 
    { 
        sum += arr[i]; 
        if (sum < 0) 
        { 
            sum = 0; 
            local_start = i + 1; 
        } 
        else if (sum > maxSum) 
        { 
            maxSum = sum; 
            *start = local_start; 
            *finish = i; 
        } 
    } 

    // There is at-least one 
    // non-negative number 
    if (*finish != -1) 
        return maxSum; 

    // Special Case: When all numbers 
    // in arr[] are negative 
    maxSum = arr[0]; 
    *start = *finish = 0; 

    // Find the maximum element in array 
    for (i = 1; i < n; i++) 
    { 
        if (arr[i] > maxSum) 
        { 
            maxSum = arr[i]; 
            *start = *finish = i; 
        } 
    } 
    return maxSum; 
} 

// The main function that finds 
// maximum sum rectangle in M[][] 
void findMaxSum(int M[][1005],int ROW,int COL) 
{ 
    // Variables to store the final output 
    int maxSum = INT_MIN, finalLeft, finalRight, 
                        finalTop, finalBottom; 

    int left, right, i; 
    int temp[ROW], sum, start, finish; 

    // Set the left column 
    for (left = 0; left < COL; ++left) 
    { 
        // Initialize all elements of temp as 0 
        memset(temp, 0, sizeof(temp)); 

        // Set the right column for the left 
        // column set by outer loop 
        for (right = left; right < COL; ++right) 
        { 
            
            // Calculate sum between current left 
            // and right for every row 'i' 
            for (i = 0; i < ROW; ++i) 
                temp[i] += M[i][right]; 

            // Find the maximum sum subarray in temp[]. 
            // The kadane() function also sets values 
            // of start and finish. So 'sum' is sum of 
            // rectangle between (start, left) and 
            // (finish, right) which is the maximum sum 
            // with boundary columns strictly as left 
            // and right. 
            sum = kadane(temp, &start, &finish, ROW); 

            // Compare sum with maximum sum so far. 
            // If sum is more, then update maxSum and 
            // other output values 
            if (sum > maxSum) 
            { 
                maxSum = sum; 
                finalLeft = left; 
                finalRight = right; 
                finalTop = start; 
                finalBottom = finish; 
            } 
        } 
    } 

    // Print final values
    int sum1=0;
    int neg=0;
    
    for(int i=finalTop;i<=finalBottom;i++)
    {
        for(int j=finalLeft;j<=finalRight;j++)
        {
            sum1=sum1+abs(M[i][j]);
            if(M[i][j]<0)
            {
                neg+=M[i][j];
            }
        }
    }
   // cout<<sum1<<endl;
    cout<<maxSum<<endl;
    cout<<sum1+neg<<endl;
} 

// Driver Code 
int main() 
{ 
    
    int sum=0;
    int ROW,COL;
    cin>>ROW>>COL;
    
    int M[1005][1005]; 
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
            cin>>M[i][j];
    }
    
    findMaxSum(M,ROW,COL); 

    return 0; 
} 

// This code is contributed by 
// rathbhupendra 


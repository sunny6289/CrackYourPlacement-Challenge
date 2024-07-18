/*
    Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume that the array is sorted in non-decreasing order. Write efficient functions to find the floor and ceiling of x. 
    Examples : 

    For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
    For x = 0:    floor doesn't exist in array,  ceil  = 1
    For x = 1:    floor  = 1,  ceil  = 1
    For x = 5:    floor  = 2,  ceil  = 8
    For x = 20:   floor  = 19,  ceil doesn't exist in array
*/

//  Dry run and you will understand that the 
//  low will always be "ceil" and high will always be "floor"

int findCeilIndex(vector<int>&arr, int low, int high, int x)
{
    if (arr.size() == 0) {
        return -1;
    }
    // If the given 'x' is smaller than the smallest value of 'arr' then 'arr[0]' is the ceil of 'x'
    if(x<arr[0]) return 0;
    // If the given 'x' is greater than the highest value of 'arr' then 'arr' doesn't contain the ceil of 'x'
    if(x>arr[arr.size()-1]) return -1; 
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
/*                                      ***** Question *****
    Given two arrays of equal size n and an integer k. The task is to permute both arrays such that sum of their corresponding element is greater than or equal to k i.e a[i] + b[i] >= k. The task is to print “Yes” if any such permutation exists, otherwise print “No”.
*/

bool isPossible(int a[], int b[], int n, int k)
{
    /*
        Here the idea is to sort on of those in increasing order and another in decreasing order
        If for any 'i' a[i]+b[i] is not equalt or greater than 'K'
        Then return 'false' else 'true'
    */ 
    sort(a, a + n);
    sort(b, b + n, greater<int>());

    // Checking condition on each index.
    for (int i = 0; i < n; i++)
        if (a[i] + b[i] < k)
            return false;

    return true;
}
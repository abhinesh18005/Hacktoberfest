class Solution {
public:
    
    double fun(vector<int> &A, vector<int> &B,int desire){
        int n = A.size();
        int m = B.size();
        int start = -1e8;
        int end = 1e8;

        while(start<end){
            int mid = start+(end-start)/2;

            int count =0;
            count+=upper_bound(A.begin(),A.end(),mid)-A.begin();
            count+=upper_bound(B.begin(),B.end(),mid)-B.begin();
            if(count<desire){
                start = mid+1;
            }else{
                end = mid;
            }
        }
    return start;
}
    
    
    
    
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        
        int n = A.size();
        int m = B.size();
       
        return (n+m)/2;
    }
};
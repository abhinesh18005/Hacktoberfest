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
       
        if( (n+m)%2==1){
            return fun(A,B,(n+m+1)/2);
        }else{
            int mid = (n+m)/2;
            double a = fun(A,B,mid);
            double b = fun(A,B,mid+1);
            //cout<<a<<" "<<b<<"\n";
            return (a+b)/2;
        }
    }
};

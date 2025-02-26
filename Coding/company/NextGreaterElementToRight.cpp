//User function Template for C++

class Solution{
public:
    void merge(int st, int mid, int en, vector<pair<int,int>> &arr, vector<int> &ans){
        vector<pair<int,int>> temp;
        int left = st;
        int right = mid + 1;
        while(left <= mid && right <= en){
            if(arr[left].first < arr[right].first){
                ans[arr[left].second] += en - right + 1;
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= en){
            temp.push_back(arr[right++]);
        }
        int k = st;
        for(auto it: temp){
            arr[k++] = it;
        }
    }
    void merge_sort(int st, int en, vector<pair<int,int>> &arr, vector<int> &ans){
        if(st == en) return;
        int mid = st + (en - st) / 2;
        merge_sort(st,mid,arr,ans);
        merge_sort(mid + 1, en, arr, ans);
        merge(st, mid, en, arr, ans);
    }
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> count(n,0);
        vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++){
            a[i] = {arr[i],i};
        }
        merge_sort(0,n-1,a,count);
        vector<int> res;
        for(auto i = 0; i<queries; i++){
            res.push_back(count[indices[i]]);
        }
        return res;
        
    }

};

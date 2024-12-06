class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int i=1;
        sort(banned.begin(),banned.end());
        int count=0;
        while(i<=n){
          auto it= lower_bound(banned.begin(),banned.end(),i);
        //   cout<<*it<<endl;
    //    If i is not found in the banned vector, lower_bound will return an iterator pointing to the first element greater than i, or to banned.end() if i is larger than all elements in banned. Accessing *it without checking if it == banned.end() can lead to undefined behavior.
    //    it == banned.end() checks whether the iterator it has reached the end of the banned vector.
        if(it == banned.end() || *it!=i){
             maxSum-=i;
            if(maxSum>=0)
            count++;

            else break;
        }
          i++;
        }
return count;
    }
};
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //maintain a window of size minutes for every window add the customer who are satisfied when owner is not grumpy, meanwhile maintain a maxunsatisfied customre by calculating
        // unsatisfied customer in each window ,when you hit the window size just shift the window
        int maxUnsatisfiedCustomer=INT_MIN,satisfiedCustomer=0;
        int unsatisfiedCustomer=0;
        int n=customers.size();
        int i=0,j=0;
        while(j<n){
            if(grumpy[j]==0) satisfiedCustomer+=customers[j];
             if(grumpy[j]==1) unsatisfiedCustomer+=customers[j];
            if(j-i+1<minutes) j++;
            else if(j-i+1==minutes){
                maxUnsatisfiedCustomer=max(maxUnsatisfiedCustomer, unsatisfiedCustomer);
               if(grumpy[i]==1) unsatisfiedCustomer-=customers[i];
                i++;
                j++;
            }
        }
        return (satisfiedCustomer+maxUnsatisfiedCustomer);
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        
        int n=asteroids.size();
        for(int i=0;i<n;i++){
bool alive=true;
// they can collide only if one asteroid is coming from right direction and other from left direction 
         while(!st.empty() && st.top() >0 && asteroids[i]<0) {
            if(st.top()<-asteroids[i]) {//only one asteroid will be destroyed
                st.pop();
                continue;
            }
            else if(st.top()==-asteroids[i]){ //both the asteroids will be destroyed and alive will be false;
                st.pop();
            }
            alive=false;
            break;
         }
   if(alive)
            st.push(asteroids[i]);

        }
vector<int>ans;
while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}
reverse(ans.begin(),ans.end());
return ans;
    }
};

// [-2,-1,1,2]
// output:[-2,-1,1,2]
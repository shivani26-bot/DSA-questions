class LockingTree {
public:

// vector<int> parent;
// This is the class member variable that you want to store permanently.
// But in the constructor:
// LockingTree(vector<int>& parent)
// parent here is just a local variable (parameter) that exists only when the constructor runs.
// To avoid confusion:
// this->parent → member variable
// parent → constructor parameter
// Since both have the same name, you must use this-> to refer to the member.
// If you do NOT store it in this->parent, then the node parents information will be lost when the constructor ends.


//visited unordered set is optional, even if we don't take it the solution will run successfully
vector<int>parent;
 unordered_map<int,vector<int>>mp;
 unordered_map<int,int>locked;
    LockingTree(vector<int>& parent) {
        int n=parent.size();
         this->parent=parent;
          for(int i=1;i<n;i++){
            // parent---->node 
            mp[parent[i]].push_back(i);
          }
    }
    
    bool lock(int num, int user) {
               if(locked.find(num)!=locked.end()){
           return false;
               }
               locked[num]=user;
               return true;
             
    }
    
    bool unlock(int num, int user) {

        // if(locked.find(num)!=locked.end()){
        //      if(locked[num]==user){
        //         locked.erase(num);
        //         return true;
        //      }
        // }
        //    return false;
        if(locked.find(num)==locked.end() || locked[num]!=user) return false;
     locked.erase(num);
     return true;
    }

    bool lockedAncestor(int num){
while(num!=-1){
    num=parent[num];
    if(locked.count(num)) return false;

}
return true;
    }


    bool lockedDescendant(int num ,  unordered_set<int>&visited){
   if(locked.find(num)!=locked.end()) return true;
    if(visited.count(num)) return false;
    visited.insert(num);
            for(auto it: mp[num]){       
if(lockedDescendant(it,visited)) return true;     
        }
        return false;
    }


    bool unlock(int num,int user, unordered_set<int>&visited){
    if(locked.count(num))  {
        locked.erase(num); //unlocks all of its descendants regardless of who locked it  
    }
    if(visited.count(num)) return false;
visited.insert(num);
for(auto it: mp[num]){
    if(unlock(it,user,visited)) return true;
}
return false;
}



    bool upgrade(int num, int user) {
    //node which we want to upgrade must be unlocked, but if it's present in the locked map then return false;
        if(locked.find(num)!=locked.end()) return false;

        unordered_set<int>visited;
        //check if current node has any descendent as locked
if(!lockedDescendant(num,visited)) return false;
           //check if current node has no ancestor as locked
if(!lockedAncestor(num)) return false;
//upgrade
// lock the given node and unlock all it's descendants regardless of who locked it 
visited.clear();
unlock(num,user,visited);
locked[num]=user;//lock the given node
return true;
    }




};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
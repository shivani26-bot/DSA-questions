struct trieNode{
    trieNode* links[26];
    int val=0;
     bool characterExists(char ch){
       return links[ch-'a'] != NULL;
    }
    void insertCharacter(char ch, trieNode*node){
        links[ch-'a']=node;
    }
    trieNode* moveNext(char ch){
        return links[ch-'a'];
    }
    // void setEnd(){
    //     flag=true;
    // }
    // bool getVal(){
    //     return flag;
    // }
};


class MapSum {
public:
map<string,int> keyVal;
trieNode* mapSum;
    MapSum() {
        mapSum=new trieNode();
    }
    
    void insert(string key, int val) {
        trieNode* node=mapSum;
        int currVal=0;
        if(keyVal.find(key)!=keyVal.end()){
            currVal=keyVal[key];
            keyVal[key]=val;
        }
        else{
            keyVal[key]=val;
        }
        for(auto c: key){
            if(!node->characterExists(c)){
                node->insertCharacter(c,new trieNode());
                
            }
            node=node->moveNext(c);
            node->val+=val;
            node->val-=currVal;
        }
    }
    
    int sum(string prefix) {
         trieNode* node=mapSum;
         int val=0;
         for(auto c: prefix){
             if(!node->characterExists(c)){
                 return 0;
             }
             node=node->moveNext(c);
             val=node->val;
         }
         return val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
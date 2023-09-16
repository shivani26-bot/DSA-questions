/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
//When converting the integer value to a string and appending it to the ans string, you need to add a delimiter to separate values to ensure correct deserialization.
 void preOrder(TreeNode* root,string &ans){
        if(!root) {
           ans+="N ";
            return;
        }
      ans+=to_string(root->val)+' ';
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // binary tree can be serialized to a string 
        string ans="";
        preOrder(root,ans);
        return ans;
        
    }

    TreeNode* binaryTree(string &data, int &index){
         if (index == data.length() || data[index]=='N') {
        index+=2; 
        return NULL;
    }
    string temp="";
    while(data[index]!=' '){
    temp+=data[index];
index++;
    }
        TreeNode* root = new TreeNode(stoi(temp));
       index++;
        root->left=binaryTree(data,index);
        root->right=binaryTree(data,index);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // string can be deserialized to the original tree structure.
          int index=0;
    return binaryTree(data,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
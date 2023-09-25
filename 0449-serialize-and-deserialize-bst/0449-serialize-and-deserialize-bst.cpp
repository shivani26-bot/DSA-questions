/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define node TreeNode
#define pb push_back
class Codec {
public:
//      string ans;
//  void preOrder(TreeNode* root){
//         if(!root) {
         
//             return;
//         }
//        string s= to_string(root->val);
//           ans+=s;
//           ans+='.';
//     preOrder(root->left);
       
//     preOrder(root->right);
//     }

  
//     string serialize(TreeNode* root) {
       
  
//         preOrder(root);
//         return ans;
//     }

 void preOrder(TreeNode* root,string &ans){
        if(!root) {
         
            return;
        }
       string s= to_string(root->val);
          ans+=s;
          ans+='.';
    preOrder(root->left,ans);
       
    preOrder(root->right,ans);
    }

  
    string serialize(TreeNode* root) {
       
  string ans="";
        preOrder(root,ans);
        return ans;
    }
    

 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
   string s;
    vector<int> v;
    for(int i=0;i<data.size();i++)
    {
        if(data[i]!='.')
        {
            s+=data[i];
        }
        else
        {
            v.push_back(stoi(s));
            s.clear();
        }
    }
    
    TreeNode *root=NULL;
    for(int i=0;i<v.size();i++)
    {
        root=InsertInBST(root,v[i]);
    }
    
    return root;
    }

       TreeNode* InsertInBST(TreeNode *root,int d)
{
    //base case
    if(root==NULL)
    {
        root=new TreeNode(d);
        return root;
    }
    
    //recursive case
    if(d<root->val)
    {
        root->left=InsertInBST(root->left,d);
    }
    else
    {
        root->right=InsertInBST(root->right,d);
    }
    
    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
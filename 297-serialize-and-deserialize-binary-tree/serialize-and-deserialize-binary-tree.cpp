class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr) s+="null,";
            else
            {
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream ss(data);
        string item;
        getline(ss,item,',');
        TreeNode* root=new TreeNode(stoi(item));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            getline(ss,item,',');
            if(item!="null")
            {
                node->left=new TreeNode(stoi(item));
                q.push(node->left);
            }

            getline(ss,item,',');
            if(item!="null")
            {
                node->right=new TreeNode(stoi(item));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root))
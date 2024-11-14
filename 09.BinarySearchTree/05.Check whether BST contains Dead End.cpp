

// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

//Notes :  In a binary search tree, the parent of a node is either the immediate predecessor or successor in the inorder traversal. However, this is only true for binary search trees.


class Solution{
  public:
  
  
    void inorder(Node *root , vector<int> &inArr , vector<int> &leaf){
        if(!root){
            return;
        }
        
        inorder(root->left,inArr , leaf);
        inArr.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->data);
        }
        inorder(root->right, inArr , leaf);
    }
  
    bool isDeadEnd(Node *root)
    {
        //Your code here
        vector<int> inArr;
        vector<int> leaf;
        
        inorder(root , inArr , leaf);
        
        for(int i = 0  , j = 0; i < inArr.size() && j < leaf.size() ; i++ ){
            if(inArr[i] == leaf[j]){
                //leaf node found
                //now check if it is a end node
                if(inArr[i-1] == leaf[j] - 1 && inArr[i+1] == leaf[j] + 1){
                    return true;
                }
                
                ++j;
            }
            
        }
        return false;
        
        
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends
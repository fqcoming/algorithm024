/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

    if(preorderSize==0||inorderSize==0||preorder==NULL||inorder==NULL||preorderSize!=inorderSize)
        return NULL;

    // 建立根结点
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];

    int rootInPos;        // 标记根结点在中序序列中位置
    int leftSize;         // 标记中序序列中根结点左边结点个数
    int rightSize;        // 标记中序序列中根结点右边结点个数

    for(rootInPos=0; inorder[rootInPos]!=root->val; rootInPos++);  // 找到根结点在中序序列中位置
    leftSize = rootInPos;
    rightSize = inorderSize - rootInPos - 1;

    root->left = buildTree(preorder+1, leftSize, inorder, leftSize);
    root->right = buildTree(preorder+leftSize+1, rightSize, inorder+leftSize+1, rightSize);

    return root;
}
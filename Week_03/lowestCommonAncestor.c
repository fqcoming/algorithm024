/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_STACK_SIZE 20000

typedef struct TreeNode* TreeNode_ptr;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    TreeNode_ptr *stack1 = (TreeNode_ptr*)malloc(sizeof(TreeNode_ptr)*MAX_STACK_SIZE);
    int top1 = -1;
    TreeNode_ptr *stack2 = (TreeNode_ptr*)malloc(sizeof(TreeNode_ptr)*MAX_STACK_SIZE);
    int top2 = -1;

    int pfind = 0;
    int qfind = 0;

    TreeNode_ptr t = root;
    TreeNode_ptr r = NULL;

    int i;

    while(t||top1!=-1){
        if(t){
            stack1[++top1] = t;
            t = t->left;
        }
        else{
            t = stack1[top1];
            if(t->right&&t->right!=r){
                t = t->right;
                stack1[++top1] = t;
                t = t->left;
            }
            else{
                if(!qfind&&t==p){
                    for(i=0; i<=top1; i++){
                        stack2[++top2] = stack1[i];
                    }
                    pfind = 1;
                }
                if(!pfind&&t==q){
                    for(i=0; i<=top1; i++){
                        stack2[++top2] = stack1[i];
                    }
                    qfind = 1;
                }
                if((pfind&&t==q) || (qfind&&t==p)){
                    break;
                }
                top1--;
                r = t;
                t = NULL;
            }
        }
    }
    for(i=top1<=top2?top1:top2; stack1[i]!=stack2[i]; i--);
    t = stack1[i];
    free(stack1);
    free(stack2);
    return t;
}
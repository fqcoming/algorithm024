
// N 叉树的层序遍历

#define QueueMaxSize 5000
#define MaxRow 1000
#define MaxCol 10000

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(root==NULL){
        *returnColumnSizes = NULL;
        return NULL;
    }
    *returnColumnSizes = (int *)malloc(sizeof(int)*MaxRow);
    int **ret = (int **)malloc(sizeof(int *)*MaxRow);
    // 构造一个循环队列,并初始化
    struct Node **q = (struct Node **)malloc(sizeof(struct Node *) * QueueMaxSize);
    memset(q, '0', sizeof(struct Node *) * QueueMaxSize);
    int front = 0;
    int rear = 0;
    q[rear++] = root;
    struct Node *p;    // 工作指针
    int capacity;
    while(front!=rear){    // 队列判空
        // 计算树当前层结点数
        capacity = (rear - front + QueueMaxSize) % QueueMaxSize;
        // 申请存储当前层结点值空间
        ret[*returnSize] = (int *)malloc(sizeof(int)*capacity);
        // 记录当前层结点个数
        (*returnColumnSizes)[*returnSize] = capacity;
        int i, j;
        for(i=0; i<capacity; i++){
            // 出队
            p = q[front];
            front = (front + 1) % QueueMaxSize;
            // 访问
            ret[*returnSize][i] = p->val;
            // 将结点的孩子结点全部入队
            for(j=0; j<p->numChildren; j++)
                if(p->children[j]){
                    q[rear] = p->children[j];
                    rear = (rear + 1) % QueueMaxSize;
                }
        }
        ++(*returnSize);
    }
    return ret;
}
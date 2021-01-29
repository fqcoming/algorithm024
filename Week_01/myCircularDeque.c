
/** 641. 设计循环双端队列 */

typedef struct {
    int *data;     // 存放双端队列元素
    int front;     // 指向对头元素位置
    int rear;      // 指向队尾下一个位置
    int size;      // 定义队列中最大元素个数
    int count;     // 队列中已存放元素的个数
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj;
    obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));

    obj->front = 0;
    obj->rear = 0;
    obj->size = k;
    obj->count = 0;
    
    obj->data = (int *)malloc(sizeof(int)*k);
    if(obj->data==NULL){
        free(obj);
        return NULL;
    }
    return obj;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj == NULL || obj->count == obj->size) 
        return false;
    obj->front = (obj->front + obj->size - 1) % obj->size;
    obj->data[obj->front] = value;
    obj->count++;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj == NULL || obj->count == obj->size)
        return false;
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;
    obj->count++;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj == NULL || obj->count == 0)
        return false;
    obj->front = (obj->front + 1) % obj->size;
    obj->count--;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj == NULL || obj->count == 0)
        return false;
    obj->rear = (obj->rear + obj->size - 1) % obj->size;
    obj->count--;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj == NULL || obj->count == 0)
        return -1;
    return obj->data[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj == NULL || obj->count == 0)
        return -1;
    return obj->data[(obj->rear-1+obj->size)%obj->size];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj == NULL || obj->count == 0)
        return true;
    else
        return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj != NULL && obj->count == obj->size)
        return true;
    else
        return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if(obj != NULL){
        free(obj->data);
        obj->data = NULL;
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 暴力求解

typedef struct {
    int value;
    int count;
} ElemType;

int IsInclude(ElemType *result, int resultSize, int elem){
    int i;
    for(i=1; i<=resultSize; i++){
        if(result[i].value==elem){
            result[i].count++;
            return 1;
        }
    }
    return 0;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    ElemType *result = (ElemType*)malloc(sizeof(ElemType)*(numsSize+1));
    int resultSize = 0;

    int i, j;
    for(i=0; i<numsSize; i++){
        if(!IsInclude(result, resultSize, nums[i])){
            resultSize++;
            result[resultSize].value = nums[i];
            result[resultSize].count = 1;
        }
    }

    for(i=2; i<=resultSize; i++){
        if(result[i].count>result[i-1].count){
            result[0].count = result[i].count;
            result[0].value = result[i].value;
            for(j=i-1; result[j].count<result[0].count; j--){
                result[j+1].count = result[j].count;
                result[j+1].value = result[j].value;
            }
            result[j+1].count = result[0].count;
            result[j+1].value = result[0].value;
        }
    }

    int *retnums = (int *)malloc(sizeof(int)*k);
    for(i=1, j=0; i<=k; i++, j++){
        retnums[j] = result[i].value;
    }
    *returnSize = k;
    return retnums;
}


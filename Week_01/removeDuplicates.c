/**
 *   26.删除排序数组中的重复项
 */

int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int i, k = 0; // i工作指针,k之前包括当前位置元素均为不重复元素
    for(i=1; i<numsSize; i++){
        if(nums[i]!=nums[k])
            nums[++k] = nums[i];
        if(nums[i]==nums[numsSize-1])
            break;
    }
    return k+1;
}

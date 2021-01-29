
/** 283. 移动零 */

void moveZeroes(int* nums, int numsSize){
    int count = 0;  // 记录0元素个数
    int i;
    for(i=0; i<numsSize; i++)
        if(nums[i]!=0)
            nums[i-count] = nums[i];
        else
            count++;
    for(i=numsSize-count; i<numsSize; i++)
        nums[i] = 0;
}
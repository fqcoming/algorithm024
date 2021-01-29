/**
 *   26. 删除排序数组中的重复项
 */

int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int i, k = 0; // i����ָ��,k֮ǰ������ǰλ��Ԫ�ؾ�Ϊ���ظ�Ԫ��
    for(i=1; i<numsSize; i++){
        if(nums[i]!=nums[k])
            nums[++k] = nums[i];
        if(nums[i]==nums[numsSize-1])
            break;
    }
    return k+1;
}

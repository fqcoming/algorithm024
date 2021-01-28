/**
 * 189. Ðý×ªÊý×é
 */


void rotate(int* nums, int numsSize, int k){
    int i, j;
    int temp;
    k = k % numsSize;
    for(i=0, j=numsSize-1; i<j; i++, j--){
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    for(i=0, j=k-1; i<j; i++, j--){
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    for(i=k, j=numsSize-1; i<j; i++, j--){
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

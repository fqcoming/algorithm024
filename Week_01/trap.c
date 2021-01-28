/**
 * 42. 接雨水
 */
int trap(int* height, int heightSize){

    int max_index = 0;   // 最高山峰下标
    int max = 0;     // 记录最高山峰高度值
    int water_level = 0;
    int water = 0;
    int i;

    // 找最高山峰
    for(i=0; i<heightSize; i++)
        if(height[i]>max){
            max = height[i];
            max_index = i;
        }

    // 最高山峰的左边其水位从左到右递增,最高山峰的右边其水位从右至左是递增
    // 当前雨水量= 当前水位 - 当前山峰高度

    // 左山坡
    for(i=0; i<max_index; i++)
        if(height[i]>water_level)
            water_level = height[i];
        else
            water += water_level - height[i];

    // 右山坡
    water_level = 0;
    for(i=heightSize-1; i>max_index; i--)
        if(height[i]>water_level)
            water_level = height[i];
        else
            water += water_level - height[i];
    
    return water;
}

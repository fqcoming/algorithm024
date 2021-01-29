
/** 66. 加一 */

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize-1;
    while(i>=0 && digits[i]==9){
        digits[i--] = 0;
    }
    if(i==-1)
    {
        int * a = (int * )malloc(sizeof(int)*(digitsSize+1));
        a[0]=1;
        for(int j=1;j<=digitsSize;j++) a[j]=0;
        *returnSize = digitsSize + 1;
        return a;
    }
    else
    {
        ++digits[i];
        *returnSize=digitsSize;
        return digits;
    }
}
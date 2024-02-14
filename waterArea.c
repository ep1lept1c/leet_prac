int maxArea(int* height, int heightSize) {
   int ret = 0, max = 0, i = 0, j = 0, waterLevelHeight = 0;
    
    if (heightSize <= 2)
    {
        ret = height[0];
    }
    
    j = (heightSize-1);
    for (i = 0; i < heightSize && i < j;)
    {
        waterLevelHeight = (height[i]>height[j])?height[j]:height[i];
            
        ret = (waterLevelHeight * (j - i));
        if (max < ret)
        {
            max = ret;
        }
            
        if (height[i] > height[j])
            j--;
        else 
            i++;
    }
    return(max);
}

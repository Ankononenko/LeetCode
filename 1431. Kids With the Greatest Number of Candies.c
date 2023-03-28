bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool* res = (bool*)malloc(candiesSize * sizeof(bool));
    char max = candies[0];
    for (int i = 1; i < candiesSize; ++i) {
        max = candies[i] < max ? max : candies[i];
    }
    for (int i = 0; i < candiesSize; ++i) {
        res[i] = candies[i] + extraCandies >= max ? true : false;
    }
    *returnSize = candiesSize;
    return res;
}

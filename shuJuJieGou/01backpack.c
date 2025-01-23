#include <stdio.h>
#include <string.h>
typedef struct good
{
    char name[20];
    int peace;   // 占用空间数量
    float price; // 价格
} good;
float comPrice(good *p,int goodsNum,int backpackNum){
    int matrix[goodsNum+1][backpackNum+1];
    memset(matrix,0,sizeof(matrix));
    for(int i=1;i<=goodsNum;i++){
        for(int j=1;j<=backpackNum;j++){
            if(j>=p[i-1].peace){
                matrix[i][j] = \ 
                matrix[i-1][j]>matrix[i-1][j-p[i-1].peace]+p[i-1].price?\
                matrix[i-1][j]:matrix[i-1][j-p[i-1].peace]+p[i-1].price;  
                //最大值为计算当前物品的最大值和不计算当前物品的最大值的最大值  
            }
            else{
                matrix[i][j] = matrix[i-1][j];//如果当前物品的重量大于背包的容量，则不放入背包
                //则最大值为不计算当前物品的最大值
            } 
        } 
    }
    return matrix[goodsNum][backpackNum];
}
int main(int argc, char const *argv[]){
    good goods[3] = {
        {"苹果", 2, 3.0},
        {"香蕉", 3, 5.0},
        {"橙子", 4, 6.0}};
    good *p = goods;
    int goodsNum = 3;
    int backpackNum1 = 5;
    int backpackNum2 = 6;
    float price1 = comPrice(p,goodsNum,backpackNum1);
    float price2 = comPrice(p,goodsNum,backpackNum2);
    printf("最大价值为：%f\n",price1);
    printf("最大价值为：%f\n",price2);
    return 0;

}
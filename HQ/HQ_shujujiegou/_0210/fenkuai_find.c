#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int max;//当前块的最大值
    int post;//当前块开始下标
}index_t;
int find(int *a,int lna,index_t *b,int lnb,int f){
    int i;
    for(i=0;i<lnb;i++){
        if(f<=b[i].max){//找f所在区间
            break;
        }
    }
    if(i==lnb){//不在任何一个区间内
        return -1;
    }
    int start=b[i].post;
    int end= (i==lnb-1?lna-1:b[i+1].post-1);
    for(i=start;i<=end;i++){//在块内查找
        if(f==a[i]){
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,6,12,17,24,27,32,29,75,56,33,88,99,92};
    index_t b[]={{6,0},{27,4},{75,8},{99,13}};
    int f;
    scanf("%d",&f);
    int res=find(a,sizeof(a)/4,b,4,f);
    printf("index=%d\n",res);
    /* code */
    return 0;
}

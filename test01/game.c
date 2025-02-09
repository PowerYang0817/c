#include<stdio.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<unistd.h>
#include<time.h>
#include<conio.h>
#define TTY_PATH  "/dev/tty"
#define STTY_US  "stty raw -echo -F "
#define STTY_DEF  "stty -raw echo -F " 
#define WIDTH 15
#define HEIGHT 25
int x=5,y=5; //全局变量
int shapeIndex=0;
int map[HEIGHT][WIDTH]={0};
int moveCount =0;
int score=0;
int level=1;
struct Point{ //坐标，记录的是偏移量
	int x;
	int y;
};

//struct Point sharp1[4]={{0,0},{1,0},{0,-1},{0,-2}};
//struct Point sharp2[4]={{0,0},{1,0},{2,0},{0,1}};

struct Point shapes[19][4] = {
    {{0,0},{-1,0},{1,0},{2,0}},//横条    
    {{0,0},{0,-1},{0,1},{0,2}},//竖条    
    {{0,0},{-1,-1},{-1,0},{0,-1}},//方块   
    {{0,0},{0,-1},{0,-2},{1,0}},//正L1    
    {{0,0},{0,1},{1,0},{2,0}},//正L2
    {{0,0},{-1,0},{0,1},{0,2}},//正L3    
    {{0,0},{0,-1},{-1,0},{-2,0}},//正L4    
    {{0,0},{-1,0},{0,-1},{0,-2}},//反L1    
    {{0,0},{0,-1},{1,0},{2,0}},//反L2    
    {{0,0},{1,0},{0,1},{0,2}},//反L3    
    {{0,0},{-1,0},{-2,0},{0,1}},//反L4    
    {{0,0},{-1,0},{1,0},{0,-1}},//T1    
    {{0,0},{0,1},{0,-1},{1,0}},//T2    
    {{0,0},{-1,0},{1,0},{0,1}},//T3    
    {{0,0},{-1,0},{0,-1},{0,1}},//T4    
    {{0,0},{1,0},{0,-1},{-1,-1}},//正Z1    
    {{0,0},{1,-1},{0,1},{1,0}},//正Z2    
    {{0,0},{1,-1},{-1,0},{0,-1}},//反Z1    
    {{0,0},{-1,-1},{-1,0},{0,1}}//反Z2
};
int getChar(); //非阻塞输入
void drawPrint(int x, int y); //画一个小方块
void userCtrl(char input);//移动方块
void drawShape();//画图
void transfrom();
void createNewShape();//产生新图形
void createEdge();//边框赋值
void drawMap();//画边框
void moveLeft();//左移碰撞判定
void moveRight();//右移判定
void moveDown();//下落判定
void fallDown();//加速下落
int changeMove(int pIndex);//旋转检验
void saveShape();//存入数组
int isFull(int line);//判断是否满行
void clearLines();//循环行数
void moveLine(int src,int desc);//消行
void addLevel();//等级
int isGameOver();//判断游戏结束
int main()
{
    //屏蔽掉终端的正常输入
	system(STTY_US TTY_PATH);//"stty raw -echo -F ""/dev/tty"
	srand(time(0));//初始化随机数种子
	createEdge();//边框赋值
	
	createNewShape();
	while(1)
	{
		char c = getChar();//非阻塞输入
        //c-->'a'
		if(c == 3)//输入ctrl+c 获得到的ascii值是 3
		{
            //让终端的输入恢复正常
			system(STTY_DEF TTY_PATH);//"stty -raw echo -F ""/dev/tty"
			break;
		}
		//判断游戏是否结束
        if(isGameOver())
        {    
            printf("\033[%d;%dH",10,5);//将光标移到到10行5列的位置
            printf("\033[44;31mGame Over!!\033[0m ");//打印gameover
            fflush(stdout);
        system(STTY_DEF TTY_PATH);    //恢复非阻塞IO设置
            printf("\033[%d;%dH",27,0);//将光标移到到27行0列的位置
            sleep(3);
            return 0;
        }

		userCtrl(c);//移动方块
		//drawPrint(x,y);//画一个方块
		drawMap();
		drawShape();//画图形
		moveDown();//下落
		fflush(stdout);//清缓存
		usleep(50*1000);//延迟
		system("clear");//清屏
	}
	return 0;
}
#if 0
int getChar()	//非阻塞输入
{
    fd_set rfds;
    struct timeval tv;
    int ch = 0;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 10; 
    if (select(1, &rfds, NULL, NULL, &tv) > 0)
    {
        ch = getchar(); 
		  
    }
    return ch;
}
#endif 
int getChar() {
    if (_kbhit()) {
        return _getch();
    } else {
        return 0;
    }
}//非阻塞输入
void drawPrint(int x, int y)//打印
{
	printf("\033[%d;%dH", y+1, x*2+1);
	printf("\033[1;31m■ \033[0m");
	//printf("\033[1;33m☺ \033[0m");
	//printf("\033[1;31m♥ \033[0m");
	//printf("\033[1;31m♔ \033[0m");
	//分数
	printf("\033[%d;%dH",HEIGHT+4,0);
   printf("\033[0;34m Level:%d      Score:%d\033[0m ",level,score);

}
void userCtrl(char input)//移动方块
{
	switch (input){
		case 'a':
			moveLeft();
			break;
		case 'd':
			moveRight();
			break;
		case 's':
			fallDown();
			break;
		case 'w':
			transfrom();
			break;
    	}
}
void createEdge(){//边框赋值
	int i=0;
	for(i=0;i<WIDTH;i++){//上下
		map[0][i]=2;
		map[HEIGHT-1][i]=2;
	}
	for(i=1;i<HEIGHT-1;i++){//左右
		map[i][0]=2;
		map[i][WIDTH-1]=2;
	}
}
void drawMap(){//画边框
	int i,j;
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			if(map[i][j]){
				drawPrint(j,i);
			}
		}
	}
}

void createNewShape(){//产生新图形
	shapeIndex=rand()%19;
	x=WIDTH/2+1;
	y=2;
}
void transfrom(){//变形
	//int n=sharpIndex/4;
	//sharpIndex++;
	//sharpIndex=n*4+sharpIndex%4;
int PIndex=shapeIndex;
switch(PIndex)
	{
	case 0:
		PIndex=1;
		break;
	case 1:
		PIndex=0;
		break;
	case 2:
		break;
	case 3:
	case 4:
	case 5:
		PIndex=PIndex+1;
		break;
	case 6:
		PIndex=3;
		break;
	case 7:
	case 8:
	case 9:
		PIndex=PIndex+1;
		break;
	case  10:
		PIndex=7;
		break;
	case 11:
	case 12:
	case 13:
		PIndex=PIndex+1;
		break;
	case  14:
		PIndex=11;
		break;
	case 15:
		PIndex=16;
		break;
	case 16:
		PIndex=15;
		break;
	case 17:
		PIndex=18;
		break;
	case 18:
		PIndex=17;
		break;	
	}
	if(changeMove(PIndex)){
		shapeIndex=PIndex;
	}
}
void drawShape(){//画图
	int i;
	for(i=0;i<4;i++){
		drawPrint(shapes[shapeIndex][i].x+x,shapes[shapeIndex][i].y+y);
	}	
}
void moveLeft(){//左移碰撞判定
	int nextx,nexty,i,flag=1;
	for(i=0;i<4;i++){
		nextx=shapes[shapeIndex][i].x+x-1;
		nexty=shapes[shapeIndex][i].y+y;
		if(map[nexty][nextx]>0){
			return;
		}
	}
		x--;
}
void moveRight(){//右移判定
	int nextx,nexty,i,flag=1;
	for(i=0;i<4;i++){
		nextx=shapes[shapeIndex][i].x+x+1;
		nexty=shapes[shapeIndex][i].y+y;
		if(map[nexty][nextx]>0){
			return;
		}
	}
		x++;
}
void fallDown(){
	int nextx,nexty,i,j;
	for(i=0;i<4;i++){
		nextx=shapes[shapeIndex][i].x+x;
		nexty=shapes[shapeIndex][i].y+y+1;
		if(map[nexty][nextx]>0){
			saveShape();
			return;
		}
	}
	y++;
}
void moveDown(){//下落判定
	if(moveCount<5){
		moveCount++;
		return;
	}
	moveCount=0;
	int nextx,nexty,i,j;
	for(i=0;i<4;i++){
		nextx=shapes[shapeIndex][i].x+x;
		nexty=shapes[shapeIndex][i].y+y+1;
		if(map[nexty][nextx]>0){
			saveShape();
			clearLines();
			createNewShape();
			return;
		}
	}
	y++;
}
int isFull(int line){//判断是否满行
	//满行返回１
	int i;
	for(i=1;i<WIDTH-1;i++){
		if(map[line][i]==0){
			return 0;
		}
	}
	return 1;
}
void clearLines(){//循环行数
	//从后向前循环
	int i,count=0;
	for(i=HEIGHT-2;i>0;i--){
		if(isFull(i)){
			count++;
		}else if(count>0){
			moveLine(i,i+count);//注意思考
		}
	}
	score+=count*250;
}
void moveLine(int src,int desc){//消行
	int i;
	for(i=1;i<WIDTH-1;i++){
		map[desc][i]=map[src][i];
		map[src][i]=0;
	}
}
void saveShape(){//图像转静态
	int nextx,nexty,i,j;
	for(j=0;j<4;j++){
		map[shapes[shapeIndex][j].y+y][shapes[shapeIndex][j].x+x]=1;
	}
	createNewShape();
}
int changeMove(int pIndex){//旋转检验
	//pIndex  变形后的值
	int nextx,nexty,i;
	for(i=0;i<4;i++){
		nextx=shapes[pIndex][i].x+x;
		nexty=shapes[pIndex][i].y+y+1;
		if(map[nexty][nextx]>0){
			return 0;
		}
	}
	return 1;
}
int isGameOver(){//游戏结束
	int j=0;
	for(j=1;j<WIDTH-1;j++){
		if(map[1][j]!=0){
			return 1;
		}
	}
	return 0;
}
void addLevel(){
	if(score>500){
		level++;
		score=0;	
	}
}

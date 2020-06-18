#include "stdio.h"
#include "conio.h"
#include "windows.h"

#define LEVEL 13
#define COVER 0
#define Y_STEP 1
#define X_STEP 2
#define KEY_Esc 0x1b
int Level=-1;

char Map[36][160]={""};
//char *head =&map[725] ,*body =&map[775] ,*rarm = &map[776],*larm = &map[774],*rleg = &map[826],*lleg = &map[824],*dick =&map[825];
int Coord_Human_Y = 18, Coord_Human_X = 3;
char *Coord_Human_Body[160];
Coord_Human_Body = Map;
int Bag[20]={0};
struct Leave
{
    int id;
    char name[20];
    int batch;
};
struct Human
{
    int job;
    char name[50];
    int blood;
    int power;
    int glad;
    int skill;
}Player;
struct Human123{

    
    char head;
    char body;
    char rarm;
    char larm;
    char rleg;
    char lleg;
    char dick;
};
struct prop
{
    int id;
    int price;
    int name
};
struct Monster
{
    int id;
    char name[50];
    int blood;
    int harm;
};

/*int Draw_Background(){
    int i,j;
    for (i=0;i<1500;i++){
        Map[i][j]=' ';
    }
}*/
void Draw_Human(){
    char strhead = 'O', strbody = 'H', strrarm = '>', strlarm = '<',  strleg = 'I', strdick = ' ';
    *head = strhead,*body =strbody,*rarm = strrarm, *larm =strlarm, *rleg =strleg, *lleg = strleg,*dick=strdick;
}w

int Human_Move(int x,int y){
    //if  这里是用来判断是否撞墙
    if (*(*(Coord_Human_Body+y)+x)!='#'){
        Coord_Human_Y += y;
        Coord_Human_X += x;
    }

}

int Human_Fight(){

}
int Game_Pause(){
    //保存当前画面（）
    Draw_Pause();//画特定暂停界面
    printf("确认要退出游戏？\n");
    printf("(按Esc键退出游戏，按其他键取消)\n");
    if (getch()==KEY_Esc){
        //保存当前关卡人物信息
        Data_File_Update();
        exit(0);
    }

    //恢复之前画面
    

}
int Event_Response(){
    if(kbhit()){
            switch(getch()){
                case 'W':case 'w':Human_Move(-1,0);break;
                case 'S':case 's':Human_Move(1,0);break;

                case 'A':case 'a':Human_Move(0,-2);break;
                case 'D':case 'd':Human_Move(0,2);break;
                
                case 'F':case 'f':Human_Fight();break;//C语言怎么写默认函数
                case 'Q':case 'q':Human_Fight(Player.skill);break;

                case 'E':case 'e':Human_Change_Prop();break;

                case 'T':case 't':Game_Pause();break;

            }
        }
}

int Prop_Pick(){
    //道具拾取
}
int Partner_Follow(){
    //随从跟随
}
int Part_Fight(){
    //随从攻击
}
int Monster_Build(){
    //怪物生成
}
int Monster_Follow(){
    //怪物跟随
}
int Monster_Fight(){
    //怪物攻击
}
int Normal_Operation(){

}
int Draw_Set_Monster(){

}
int Draw_Set_Human(){

int Draw_Set_Weapon(){

}
int Draw_Set_Prop_Redorp(){

}
int Draw_Set_Bullet(){

}
int Draw_Set_Grass(){

}
int Draw_Set_Prop_Name(){

}
int Draw_Render_Interface(){
    //整体界面渲染
}

int Draw_Set_Background(){
    Back_Ground = Back_Ground_Array[Level];
}

int Render_Interface(){
    Draw_Set_Background();
    Draw_Set_Monster();
    Draw_Set_Human();
    Draw_Set_Weapon();
    Draw_Set_Prop_Redorp();
    Draw_Set_Bullet();
    Draw_Set_Grass();
    Draw_Set_Prop_Name();

    Draw_Render_Interface();
}

int Draw_Story(int level){
    for(int i=0;i<Story_Count[level];i++){
        printf("%s\n",Story[i]);
        system("pause");
    }
}

int Draw_Title(int level){
    //调整字体大小使文字居中
    //从title列表中打印当前关卡名称
    //睡眠一定时间
}
int Data_Encrypy(){
    //数据加密
}
int Data_Decode(){
    //数据解密
}

int Data_Comparison(){
    //数据对比
}
int Data_File_Check(){

}
int Data_File_New(){

}
int Data_File_Read(){

}
int Data_File_Update(){

}
int Game_Initialization(){
    if (Data_File_Check())
        Data_File_New();
    Data_File_Read();
}
int Game_Begin(){
    Draw_Tips(COVER);
    Draw_Story(Level);
    printf("尊敬的勇士，请告诉我你的名字：");
    scanf("%s",&Player.name);
    Draw_Story(Level);
}

int Game_Finish(){
    Draw_Story(Level);
    //Draw_Story(制作组，特别鸣谢，友情赞助，剧情来源，地图设计，交互设计，游戏策划，美工，项目总监，版权，联系方式)
}

int main(){
    
    system("mode con cols=160 lines=36");
    //预设控制台窗口大小
    Game_Begin();
    while (1){
        Set_Background(Level);
        if (Level>LEVEL) break;
        while (1){ 
            Event_Response();
            //事件响应
            Normal_Operation();
            //常规处理
            Render_Interface();
            //界面渲染
            if("该关卡怪物剩余批次为零"){
                Shopping();
                Goto_Next_Level();
                Level+=1;
                break;
            }
        }
    }
    Game_Finish();
}

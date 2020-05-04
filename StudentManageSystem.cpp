/****************************************
*           学生信息管理系统           *
*                                       *
*   2016年课程设计  by software20150117 *
****************************************/
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;
const char Back[5]="back";
char B[15]="admin";
char A[15]="admin";
void Read();
void Write();
void Teacher_Account(int );
void Student_Account(int );
void Admin_Account1();
void jh(char a[],char b[]){
                                char temp[15];
                                strcpy(temp,a);
                                strcpy(a,b);
                                strcpy(b,temp);
}				//交换数据
void title_Display(){
cout<<"             /****************************************"<<endl<<
"             *           学生信息管理系统            *"<<endl<<
"             *                                       *"<<endl<<
"             *   2016年课程设计         软件15.1何琦 *"<<endl<<
"             ****************************************/"<<endl<<endl;

cout<<endl<<"                  /******选择身份登入-1级********"<<
endl<<"                 | 1.管理员 2.教师 3.学生 4.Exit |"<<endl;
}         //显示系统界面

struct teacher{
    char name[15];
    char password[15];
};            //教师结构数组定义

class Teacher{
private:

public:
    teacher tea[1000];   //存储教师信息
    int ti;    //计数教师数量

    Teacher() {ti=0;}
    void Display(int i){
                    cout<<"用户名: "<<tea[i].name<<"   "<<"密码: "<<tea[i].password<<endl;
                    }
    char Get_name(int i){return tea[i].name[15];}
    char Get_password(int i){return tea[i].password[15];}
    int  Get_ti(){return ti;}
    void ti_(){ti--;}
    int  jsmm(char b[15],int i){if(!strcmp(b,tea[i].password))
                               return 1;
                               else return 0;}
    void cpy_name(char name[15],int i){
                                        strcpy(tea[i].name,name);}
    void cpy_password(char password[15],int i){
                                        strcpy(tea[i].password,password);}
    void tadd()  {
            cout<<"请输入教师信息 每条以回车结束(back返回)....."<<endl;
            cout<<"********账号  密码*********"<<endl;
            char name1[15];
			char password1[15];
            cin>>name1;
            if(strcmp(name1,Back)){
            cin>>password1;
            strcpy( tea[ti].name,name1);
			strcpy(tea[ti].password,password1);
			ti++;
            cout<<"                     添加成功！！！已返回到上一级"<<endl<<endl;
            }}
    void teaSet(){int  i;
                    if(ti==0) cout<<"没有任何教师账号"<<endl;
                    else {  cout<<"\n以下为所有教师账号\n";
                            for(i=0;i<ti;i++) Display(i);
                            cout<<endl<<"输入要修改的教师帐号以回车结束(back返回)....."<<endl;
                            char name1[15],password1[15];
                            cin>>name1;
                            if(strcmp(name1,Back)) {
                            for(i=0;i<ti&&strcmp(tea[i].name,name1);i++);
                            if(i==ti) cout<<"不存在此教师账号！"<<endl;
                            else {cout<<"将此教师账号密码修改为: ";
                                  cin>>password1;
                                  strcpy(tea[i].password,password1);
                                  cout<<"\n                     修改成功！！！已返回到上一级"<<endl<<endl;}
                                 }   }                //修改教师账号
                            }
    int jsyz(char name1[15]){ int i;
                            if(ti==0) return ti;
                            else {
                            for(i=0;i<ti&&strcmp(tea[i].name,name1);i++);
                            return i;}
                            }
};         //教师类定义
Teacher Tea;

struct Stu{
	char   num[15];
	char   zh[15];
	char   xingming[15];
	char   tel[15];
	char   password[15];
	double score[3];
};				//学生结构数组定义
class Student{
private:
public:
    int len;
    Stu stu[1000];
    Student(){len=0;}
	void cpy_num(char a[15],int i){strcpy(stu[i].num,a);}
	void cpy_password(char a[15],int i){strcpy(stu[i].password,a);}
	void Get_zh(int i){cout<<stu[i].zh;}
	void Get_password(int i){cout<<stu[i].password;}
	int  Get_len(){return len;}
	int  xsmm(char b[15],int i){if(!strcmp(b,stu[i].password))
                               return 1;
                               else return 0;}
    void tongji(int h){
            int i,z,j,k;
            char mc[10]="及格人数";
            for(k=71;k>0;k--)cout<<"_";cout<<endl;
            cout<<setw(h)<<mc;
            for(j=0;j<3;j++)
            {for(i=0,z=0;i<len;i++)
                if(stu[i].score[j]>=60)
                z++;
            cout<<setw(8)<<z;}
            cout<<endl;
            strcpy(mc,"优秀人数");
            for(k=71;k>0;k--)cout<<"_";cout<<endl;
            cout<<setw(h)<<mc;
            for(j=0;j<3;j++)
            {for(i=0,z=0;i<len;i++)
                if(stu[i].score[j]>=80)
                z++;
            cout<<setw(8)<<z;}
            cout<<endl;
            }
    void Display(int i,int num2){
	    if(num2!=12) cout<<setw(4)<<i+1;
	    cout<<setw(8)<<stu[i].num<<" ";
	    if(num2==2)cout<<setw(8)<<stu[i].zh<<" ";
            cout<<setw(10)<<stu[i].xingming<<setw(15)<<stu[i].tel;
            for(int j=0;j<3;j++)
	    cout<<setw(8)<<stu[i].score[j];
	    cout<<endl;
	    }
    void add(){  int i;
            system("cls");
            cout<<"先输入要添加学生的个数(0则不添加): ";
            cin>>i;
            if(i){
            cout<<endl<<"请输入.....每条学生信息以回车结束."<<endl;
            cout<<"    学号    姓名     联系电话     C++    高数    英语"<<endl;
            char num1[15];
			char xingming1[15];
			char tel1[15];

			double score[3];
			while(i--){
            {
			cin>>num1;
			cin>>xingming1>>tel1>>score[0]>>score[1]>>score[2];
            strcpy(stu[len].num,num1);
			strcpy(stu[len].xingming,xingming1);
			strcpy(stu[len].tel,tel1);
			strcpy(stu[len].zh,num1);
			strcpy(stu[len].password,num1);

			stu[len].score[0]=score[0];
            stu[len].score[1]=score[1];
			stu[len].score[2]=score[2];
			len++;
			}}
            cout<<"\n                     添加成功！！！已返回到上一级"<<endl<<endl;}
            }

    void stuSet(){int  i;
            if(len==0) cout<<"没有任何学生账号"<<endl;
            else {
            cout<<endl<<"输入要修改的学号以回车结束(back返回): ";
            char num1[15],password1[15];
			cin>>num1;
			if(strcmp(num1,Back)){
            for(i=0;i<len&&strcmp(stu[i].num,num1);i++);
            if(i==len) cout<<"不存在此学生账号！"<<endl;
            else {cout<<"将此学生账号密码修改为: ";
                cin>>password1;
                    strcpy(stu[i].password,password1);
			cout<<"\n                     修改成功！！！已返回到上一级"<<endl<<endl;
          }
            }                   //修改学生账号
            }
	}
    void Set(){int  i;
            if(len==0) cout<<"没有存在可修改的账号"<<endl;
            else {
            cout<<"输入要修改的学生学号及信息以回车结束....."<<endl;
            cout<<"    学号    姓名     联系电话     C++    高数    英语"<<endl;
            char num1[15];
			char xingming1[15];
			char tel1[15];
            double score[3];
			cin>>num1>>xingming1>>tel1>>score[0]>>score[1]>>score[2];
            for(i=0;i<len&&strcmp(stu[i].num,num1);i++);
            if(i==len) cout<<"没有此学生记录！"<<endl;
            else {
			strcpy(stu[i].xingming,xingming1);
			strcpy(stu[i].tel,tel1);
            stu[i].score[0]=score[0];
            stu[i].score[1]=score[1];
            stu[i].score[2]=score[2];
            cout<<"\n                     修改成功！！！已返回到上一级"<<endl<<endl;}
            }
            }                   //修改学生信息
    void alldispaly(char num1,int num2){
                                        int i,j;
                                    if(len==0)  cout<<"没有任何学生记录！"<<endl;
                                    else{
                                            if(len==1) Display(0,num2);
                                            else {
                                                  if(num1=='1')
                                                    {if(num2==1)
                                                cout<<"排名    学号      姓名        联系电话     C++    高数    英语"<<endl;
                                            else cout<<"排名    学号     账号      姓名        联系电话     C++    高数    英语"<<endl;
                                                      for(i=0;i<len-1;i++)
                                                      for(j=i+1;j<len;j++)
                                                      if(strcmp(stu[i].num,stu[j].num)>0)
                                                         { Stu t;
                                                        t=stu[i];
                                                        stu[i]=stu[j];
                                                        stu[j]=t;
                                                        }

                                                    for(i=0;i<len;i++)
                                                    {for(int k=0;k<71;k++)cout<<"_";cout<<endl;
                                                        Display(i,num2);}
                                                        if(num2==1)tongji(38);
                                                        else        tongji(47);
                                                    }
                                        if(num1=='2') { {
                                                cout<<" 选择排序科目:  1.C++  2.高数  3.英语"<<endl;
                                                int z;
                                                cin>>z;
                                                if(num2==1)
                                                cout<<"排名    学号      姓名        联系电话     C++    高数    英语"<<endl;
                                            else cout<<"排名    学号     账号      姓名        联系电话     C++    高数    英语"<<endl;
                                                for(i=0;i<len-1;i++)
                                                for(j=i+1;j<len;j++)
                                                if(stu[i].score[z-1]<stu[j].score[z-1])
                                                { Stu t;
                                                t=stu[i];
                                                stu[i]=stu[j];
                                                stu[j]=t;}
                                                    }
                                                for(i=0;i<len;i++)
                                            {for(int k=0;k<71;k++)cout<<"_";cout<<endl;
                                            Display(i,num2);}
                                            if(num2==1)tongji(38);
                                            else        tongji(47);
                                                        }
                                            }
                                        }
                                   }
    void Delete(){
              int i;char num[15];
                cout<<endl;
                if(len==0&&Tea.Get_ti()==0) cout<<"不存在任何可删除的账号！"<<endl
                    <<"正在返回上一级........"<<endl;
                else
                {   cout<<"输入要删除的账号(back返回): ";
                  cin>>num;
				  if(strcmp(num,Back))
				  {
					if(len!=0)
                    {for(i=0;i<len&&strcmp(stu[i].num,num);i++);
					{if(i==len) {
							for(i=0;i<Tea.ti&&strcmp(Tea.tea[i].name,num);i++);
							{if(i==Tea.ti) cout<<"不存在此帐号"<<endl;
							else
                            {for(;i<Tea.Get_ti()-1;i++)
                                      {
                                          teacher t;
                                          t=Tea.tea[i];
                                          Tea.tea[i]=Tea.tea[i+1];
                                          Tea.tea[i+1]=t;
                                      }
									Tea.ti_();
                                    cout<<"已删除此账号!"<<endl;}
								}}
					 else   {for(;i<len-1;i++)
                          {
                            stu[i]=stu[i+1];
                           }
							len--;
				cout<<"已删除此账号！"<<endl;}
				}}
				else
					{for(i=0;i<Tea.ti&&strcmp(Tea.tea[i].name,num);i++);
					 if(i==Tea.ti) cout<<"不存在此帐号"<<endl;
						else
							{for(;i<Tea.Get_ti()-1;i++)
                                      {
                                          teacher t;
                                          t=Tea.tea[i];
                                          Tea.tea[i]=Tea.tea[i+1];
                                          Tea.tea[i+1]=t;
                                      }
									Tea.ti_();
                                    cout<<"已删除此账号！"<<endl;}
									}
				}}

}
    void xhcz(){char num1[15];
            int i;
            if(len==0)
                cout<<"没有任何学生信息!!!"<<endl;
            else
            {cout<<"输入要查找的学号(back返回): ";
            cin>>num1;
			if(strcmp(num1,Back)){
            for(i=0;i<len&&strcmp(stu[i].num,num1);i++);
            if(i==len) cout<<"没有此学生记录!!!"<<endl;
            else {cout<<"    学号      姓名        联系电话     C++    高数    英语"<<endl;
                    Display(i,12);}
            }
	}    }           //学号查找

    int xsyz(char zh[15]){ int i;
                    if(len==0) return 0;
                    else {
                    for(i=0;i<len&&strcmp(stu[i].zh,zh);i++);
                    return i;}
        }                   //
};       //学生类定义
Student Stu;

void Admin_Account(){
    char num;
	L1:
    cout<<endl<<"                 ***********所有帐号操作-3级************"<<endl
    <<"                 | 1.管理员 2.教师 3.学生 4.删除 5.退出 |"<<endl;
    cin>>num;
    switch(num)
    {
	    case '1':{Admin_Account1();goto L1;}
        case '2':{cout<<endl<<"选择操作的功能: "<<"1.编辑教师账号 2.添加教师账号 3.退出"<<endl;
                cin>>num;
                if(num=='2') Tea.tadd();
                else if(num=='1')
                        Tea.teaSet();
				 goto L1;
				}
        case '3':{Stu.stuSet();goto L1;}
        case '4':{Stu.Delete();goto L1;}
        default:break;
    }
}

void Admin_Account1(){
    char num;
	char name[15];
	cout<<endl<<"                 ******正在操作的管理员帐号-4级******"<<endl
	<<"                 | 1.更改用户名 2.更改密码 3.退出更改 |";
	cin>>num;
	if(num=='1'||num=='2'){
    if(num=='1'){
		cout<<"现用户名: "<<A<<endl<<"  更改为: ";
		cin>>name;
		strcpy(A,name);
		cout<<endl;}
    else if(num=='2'){
		cout<<"现密码为: "<<B<<endl<<"  更改为: ";
		cin>>name;
		strcpy(B,name);
		cout<<endl;}
	cout<<"更改成功!"<<endl;}
}

void Teacher_Account(int i){
    char num;
	char name[15];
	cout<<endl<<"                  *******正在操作的教师帐号-3级*******"<<endl
	<<"                  | 1.更改用户名 2.更改密码 3.退出更改 |";
	cin>>num;
	if(num=='1'||num=='2'){
    if(num=='1'){
		cout<<"现用户名: ";cout<<Tea.tea[i].name;
		cout<<endl<<"  更改为: ";
		cin>>name;
		Tea.cpy_name(name,i);
		cout<<endl;}
    else if(num=='2'){
		cout<<"现密码为: ";cout<<Tea.tea[i].password;
		cout<<endl<<"  更改为: ";
		cin>>name;
		Tea.cpy_password(name,i);
		cout<<endl;}
        cout<<"更改成功!"<<endl;}
}

void Student_Account(int i){
    char num;
	char name[15];
	cout<<endl<<"                  *****正在操作的学生帐号-3级*****"<<endl
	<<"                  | 1.更改用户名 2.更改密码 3.退出更改 |";
	cin>>num;
	if(num=='1'||num=='2'){
    if(num=='1'){
		cout<<"现用户名: ";Stu.Get_zh(i);
		cout<<endl<<"  更改为: ";
		cin>>name;
		Stu.cpy_password(name,i);
		cout<<endl;}
    else if(num=='2'){
		cout<<"现密码为: ";Stu.Get_password(i);
		cout<<endl<<"  更改为: ";
		cin>>name;
		Stu.cpy_password(name,i);
		cout<<endl;}
	cout<<"更改成功!"<<endl;}
 }

void admin(){
            char a[15],b[15];
            char num[15];
            char num1,num2;
            while(1){
            cout<<"输入任意继续(back返回): ";//提示输入密码
            cin>>num;
	L1:
	if(!strcmp(num,Back)) break;//验证密码
    cout<<"Please enter your Account: ";
    cin>>a;
    L2:
    if(!strcmp(num,Back)) break;
    if(strcmp(a,A)) {cout<<"Unable to find this Account!!!"
					<<endl<<"输入任意继续(back返回): ";
					cin>>num;
					if(strcmp(num,Back))
						{cout<<"Please enter your Account once again: ";
						cin>>a;
						goto L2;}
					else goto L1;//返回到上一级
					}
    cout<<"Please enter your Password: ";
    cin>>b;
    if(!strcmp(b,B)){L4:cout<<endl<<"        *****************请以序号选择功能-2级*****************"<<endl
                    <<"        | 1.所有信息 2.学号查找 3.增添  4.修改 5.账号 6.退出 |"<<endl;//管理员账号权限
                        cin>>num1;
                        switch(num1){
                        case '1': {cout<<"                *********请选择排序方式—3级**********"<<endl
                        <<"               | 1.按学号小到大 2.按成绩高到低 3.返回 |"<<endl;
                                cin>>num2;
                                Stu.alldispaly(num2,2);
                                break;
                                }
                        case '2': {Stu.xhcz();break;}
                        case '3': {Stu.add();break;}
                        case '4': {Stu.Set();break;}
                        case '5': {Admin_Account();break;}
                        default:break;}
                        if(num1=='6')break;
                        else goto L4;
						}
     else {cout<<"Password Error!!!"<<endl;goto L1;}
    }
}               //管理员账号下的管理权限
void teacher1(){
    char a[15],b[15];//定义输入的密码
    char num[15];
    char num1;
    int i;
	while(1){L5:
	cout<<"输入任意继续(back返回): ";
    cin>>num;
	L1:
	if(!strcmp(num,Back)) break;
    cout<<"Please enter your Account: ";
    cin>>a;
    L2:
    if(!strcmp(num,Back)) break;
    i=Tea.jsyz(a);
    if(i==Tea.Get_ti()) {cout<<"Unable to find this Account!!!"
					<<endl<<"输入任意继续(back返回): ";
					cin>>num;
					if(strcmp(num,Back))
						{cout<<"Please enter your Account once again: ";
						cin>>a;
						goto L2;}
					else goto L1;
					}
    cout<<"Please enter your Password: ";
    cin>>b;

    if(Tea.jsmm(b,i)){L4:
                    cout<<endl<<"              *************请以序号选择功能-2级************"<<endl
                    <<"             | 1.所有信息 2.学号查找 3.编辑 4.账号 5.退出 |"<<endl;//教师权限
                        cin>>num1;
                        switch(num1){
                        case '1': {
                                cout<<"                *********请选择排序方式—3级*******"<<endl
                                <<"               | 1.按学号小到大 2.按成绩高到低 3.返回 |"<<endl;
                                cin>>num1;
                                system("cls");
                                Stu.alldispaly(num1,1);
                                break;
                                }
                        case '2':{Stu.xhcz();break;}
                        case '3':{Stu.Set();break;}
                        case '4':{Teacher_Account(i);break;}
                        default:break;}
                        if(num1=='5')break;
                        else goto L4;}
     else {cout<<"Password Error!!!"<<endl;goto L5;}
    }

}               //教师管理功能部分
void student1(){

    char a[15],b[15];//系统中的密码
    char num[15];
    char num1,i;
	while(1){L5:
	cout<<"输入任意继续(back返回): ";
    cin>>num;
	L1:
	if(!strcmp(num,Back)) break;
    cout<<"Please enter your Account: ";
    cin>>a;
    L2:
    if(!strcmp(num,Back)) break;
    if(Stu.xsyz(a)==Stu.Get_len()) {cout<<"Unable to find this Account!!!"
					<<endl<<"输入任意继续(back返回): ";
					cin>>num;
					if(strcmp(num,Back))
						{cout<<"Please enter your Account once again: ";
						cin>>a;
						goto L2;}
					else goto L1;
         }
         i=Stu.xsyz(a);

    cout<<"Please enter your Password: ";
    cin>>b;
    if(Stu.xsmm(b,i)){L4:
						cout<<endl<<"                     ********请以序号选择功能-2级********"<<endl
                    <<"                         | 1.个人信息 2.账号 3.退出 |"<<endl;
                        cin>>num1;
                        switch(num1){
                        case '1': {
                                cout<<endl<<"    学号      姓名        联系电话     C++    高数    英语"<<endl;
                                cout<<"___________________________________________________________"<<endl;
                                Stu.Display(i,12);
                                break;
                                }
                        case '2':{
                                Student_Account(i);break;
                                }
                        default:break;
                        }
                        if(num1=='3')break;
                        else goto L4;}
     else {cout<<"Password Error!!!"<<endl;goto L5;}
    }
}               //学生

int main()
{ char n;

  Read();
  title_Display();//显示系统界面
  L1:
  cin>>n;
  cout<<endl;
  while(1){system("cls");
  if(n=='1')  admin();

  else if(n=='2')  teacher1();
  else  if(n=='3') student1();
  else   if(n=='4')  break;

  cout<<endl<<"                  /******选择身份登入-1级********"<<
  endl<<"                 | 1.管理员 2.教师 3.学生 4.Exit |"<<endl;
  goto L1;
  }
    Write();
    return 0;
}
void Write()
	{
		ofstream outfile("d:\\学生管理系统数据.dat",ios::binary|ios::out);

		if(outfile==NULL)
		{    abort();
			cout<<"cant open file.";

			return ;
		}
		int i;
		outfile.write((char *)&A,sizeof(A));
		outfile.write((char *)&B,sizeof(B));//写入管理员账号和密码

		outfile.write((char *)&Stu.len,sizeof(Stu.len));
        for(i=0;i<Stu.len;i++)
			outfile.write((char *)&Stu.stu[i],sizeof(Stu.stu[i]));//写入学生学生所有信息

        outfile.write((char *)&Tea.ti,sizeof(Tea.ti));
        for(i=0;i<Tea.ti;i++)
            outfile.write((char *)&Tea.tea[i],sizeof(Tea.tea[i]));//写入教师账号密码
		outfile.close();
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                        _______________________\n";
		cout<<"                       | 本次修改的数据已存档! |\n";
		cout<<"                        _______________________\n";
	}
void Read()
	{
		ifstream infile("d:\\学生管理系统数据.dat",ios::binary|ios::in);
        if(infile==NULL)
		{
			cout<<"\n在为首次使用管理系统初始化......\n";
			cout<<"\n初始化成功!\n";

			return ;
		}
        int num;
		int i;
		infile.read((char *)&A,sizeof(A));
		infile.read((char *)&B,sizeof(B));    //读取管理员账号和密码

		infile.read((char *)&Stu.len,sizeof(Stu.len));
		for(i=0;i<Stu.len;i++)
			infile.read((char *)&Stu.stu[i],sizeof(Stu.stu[i]));//读取学生所有信息

        infile.read((char *)&Tea.ti,sizeof(Tea.ti));
		for(i=0;i<Tea.ti;i++)
			infile.read((char *)&Tea.tea[i],sizeof(Tea.tea[i]));//读取教师账号密码
			cout<<"已读入上回保存的学生信息"<<endl;
		infile.close();
	}
/*1000 李灵黛 156232423 78 88 100
1001 冷文 1358741437 94.5 93.5 68
1002 阴露萍 5779349 58 85 85.5
1003 柳兰 234827098 88 70.5 67
1004 秦水支 4524985 76 100 0
1005 李念儿 15742395 56 90 86*/

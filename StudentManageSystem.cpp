/****************************************
*           ѧ����Ϣ����ϵͳ           *
*                                       *
*   2016��γ����  by software20150117 *
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
}				//��������
void title_Display(){
cout<<"             /****************************************"<<endl<<
"             *           ѧ����Ϣ����ϵͳ            *"<<endl<<
"             *                                       *"<<endl<<
"             *   2016��γ����         ���15.1���� *"<<endl<<
"             ****************************************/"<<endl<<endl;

cout<<endl<<"                  /******ѡ����ݵ���-1��********"<<
endl<<"                 | 1.����Ա 2.��ʦ 3.ѧ�� 4.Exit |"<<endl;
}         //��ʾϵͳ����

struct teacher{
    char name[15];
    char password[15];
};            //��ʦ�ṹ���鶨��

class Teacher{
private:

public:
    teacher tea[1000];   //�洢��ʦ��Ϣ
    int ti;    //������ʦ����

    Teacher() {ti=0;}
    void Display(int i){
                    cout<<"�û���: "<<tea[i].name<<"   "<<"����: "<<tea[i].password<<endl;
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
            cout<<"�������ʦ��Ϣ ÿ���Իس�����(back����)....."<<endl;
            cout<<"********�˺�  ����*********"<<endl;
            char name1[15];
			char password1[15];
            cin>>name1;
            if(strcmp(name1,Back)){
            cin>>password1;
            strcpy( tea[ti].name,name1);
			strcpy(tea[ti].password,password1);
			ti++;
            cout<<"                     ��ӳɹ��������ѷ��ص���һ��"<<endl<<endl;
            }}
    void teaSet(){int  i;
                    if(ti==0) cout<<"û���κν�ʦ�˺�"<<endl;
                    else {  cout<<"\n����Ϊ���н�ʦ�˺�\n";
                            for(i=0;i<ti;i++) Display(i);
                            cout<<endl<<"����Ҫ�޸ĵĽ�ʦ�ʺ��Իس�����(back����)....."<<endl;
                            char name1[15],password1[15];
                            cin>>name1;
                            if(strcmp(name1,Back)) {
                            for(i=0;i<ti&&strcmp(tea[i].name,name1);i++);
                            if(i==ti) cout<<"�����ڴ˽�ʦ�˺ţ�"<<endl;
                            else {cout<<"���˽�ʦ�˺������޸�Ϊ: ";
                                  cin>>password1;
                                  strcpy(tea[i].password,password1);
                                  cout<<"\n                     �޸ĳɹ��������ѷ��ص���һ��"<<endl<<endl;}
                                 }   }                //�޸Ľ�ʦ�˺�
                            }
    int jsyz(char name1[15]){ int i;
                            if(ti==0) return ti;
                            else {
                            for(i=0;i<ti&&strcmp(tea[i].name,name1);i++);
                            return i;}
                            }
};         //��ʦ�ඨ��
Teacher Tea;

struct Stu{
	char   num[15];
	char   zh[15];
	char   xingming[15];
	char   tel[15];
	char   password[15];
	double score[3];
};				//ѧ���ṹ���鶨��
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
            char mc[10]="��������";
            for(k=71;k>0;k--)cout<<"_";cout<<endl;
            cout<<setw(h)<<mc;
            for(j=0;j<3;j++)
            {for(i=0,z=0;i<len;i++)
                if(stu[i].score[j]>=60)
                z++;
            cout<<setw(8)<<z;}
            cout<<endl;
            strcpy(mc,"��������");
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
            cout<<"������Ҫ���ѧ���ĸ���(0�����): ";
            cin>>i;
            if(i){
            cout<<endl<<"������.....ÿ��ѧ����Ϣ�Իس�����."<<endl;
            cout<<"    ѧ��    ����     ��ϵ�绰     C++    ����    Ӣ��"<<endl;
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
            cout<<"\n                     ��ӳɹ��������ѷ��ص���һ��"<<endl<<endl;}
            }

    void stuSet(){int  i;
            if(len==0) cout<<"û���κ�ѧ���˺�"<<endl;
            else {
            cout<<endl<<"����Ҫ�޸ĵ�ѧ���Իس�����(back����): ";
            char num1[15],password1[15];
			cin>>num1;
			if(strcmp(num1,Back)){
            for(i=0;i<len&&strcmp(stu[i].num,num1);i++);
            if(i==len) cout<<"�����ڴ�ѧ���˺ţ�"<<endl;
            else {cout<<"����ѧ���˺������޸�Ϊ: ";
                cin>>password1;
                    strcpy(stu[i].password,password1);
			cout<<"\n                     �޸ĳɹ��������ѷ��ص���һ��"<<endl<<endl;
          }
            }                   //�޸�ѧ���˺�
            }
	}
    void Set(){int  i;
            if(len==0) cout<<"û�д��ڿ��޸ĵ��˺�"<<endl;
            else {
            cout<<"����Ҫ�޸ĵ�ѧ��ѧ�ż���Ϣ�Իس�����....."<<endl;
            cout<<"    ѧ��    ����     ��ϵ�绰     C++    ����    Ӣ��"<<endl;
            char num1[15];
			char xingming1[15];
			char tel1[15];
            double score[3];
			cin>>num1>>xingming1>>tel1>>score[0]>>score[1]>>score[2];
            for(i=0;i<len&&strcmp(stu[i].num,num1);i++);
            if(i==len) cout<<"û�д�ѧ����¼��"<<endl;
            else {
			strcpy(stu[i].xingming,xingming1);
			strcpy(stu[i].tel,tel1);
            stu[i].score[0]=score[0];
            stu[i].score[1]=score[1];
            stu[i].score[2]=score[2];
            cout<<"\n                     �޸ĳɹ��������ѷ��ص���һ��"<<endl<<endl;}
            }
            }                   //�޸�ѧ����Ϣ
    void alldispaly(char num1,int num2){
                                        int i,j;
                                    if(len==0)  cout<<"û���κ�ѧ����¼��"<<endl;
                                    else{
                                            if(len==1) Display(0,num2);
                                            else {
                                                  if(num1=='1')
                                                    {if(num2==1)
                                                cout<<"����    ѧ��      ����        ��ϵ�绰     C++    ����    Ӣ��"<<endl;
                                            else cout<<"����    ѧ��     �˺�      ����        ��ϵ�绰     C++    ����    Ӣ��"<<endl;
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
                                                cout<<" ѡ�������Ŀ:  1.C++  2.����  3.Ӣ��"<<endl;
                                                int z;
                                                cin>>z;
                                                if(num2==1)
                                                cout<<"����    ѧ��      ����        ��ϵ�绰     C++    ����    Ӣ��"<<endl;
                                            else cout<<"����    ѧ��     �˺�      ����        ��ϵ�绰     C++    ����    Ӣ��"<<endl;
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
                if(len==0&&Tea.Get_ti()==0) cout<<"�������κο�ɾ�����˺ţ�"<<endl
                    <<"���ڷ�����һ��........"<<endl;
                else
                {   cout<<"����Ҫɾ�����˺�(back����): ";
                  cin>>num;
				  if(strcmp(num,Back))
				  {
					if(len!=0)
                    {for(i=0;i<len&&strcmp(stu[i].num,num);i++);
					{if(i==len) {
							for(i=0;i<Tea.ti&&strcmp(Tea.tea[i].name,num);i++);
							{if(i==Tea.ti) cout<<"�����ڴ��ʺ�"<<endl;
							else
                            {for(;i<Tea.Get_ti()-1;i++)
                                      {
                                          teacher t;
                                          t=Tea.tea[i];
                                          Tea.tea[i]=Tea.tea[i+1];
                                          Tea.tea[i+1]=t;
                                      }
									Tea.ti_();
                                    cout<<"��ɾ�����˺�!"<<endl;}
								}}
					 else   {for(;i<len-1;i++)
                          {
                            stu[i]=stu[i+1];
                           }
							len--;
				cout<<"��ɾ�����˺ţ�"<<endl;}
				}}
				else
					{for(i=0;i<Tea.ti&&strcmp(Tea.tea[i].name,num);i++);
					 if(i==Tea.ti) cout<<"�����ڴ��ʺ�"<<endl;
						else
							{for(;i<Tea.Get_ti()-1;i++)
                                      {
                                          teacher t;
                                          t=Tea.tea[i];
                                          Tea.tea[i]=Tea.tea[i+1];
                                          Tea.tea[i+1]=t;
                                      }
									Tea.ti_();
                                    cout<<"��ɾ�����˺ţ�"<<endl;}
									}
				}}

}
    void xhcz(){char num1[15];
            int i;
            if(len==0)
                cout<<"û���κ�ѧ����Ϣ!!!"<<endl;
            else
            {cout<<"����Ҫ���ҵ�ѧ��(back����): ";
            cin>>num1;
			if(strcmp(num1,Back)){
            for(i=0;i<len&&strcmp(stu[i].num,num1);i++);
            if(i==len) cout<<"û�д�ѧ����¼!!!"<<endl;
            else {cout<<"    ѧ��      ����        ��ϵ�绰     C++    ����    Ӣ��"<<endl;
                    Display(i,12);}
            }
	}    }           //ѧ�Ų���

    int xsyz(char zh[15]){ int i;
                    if(len==0) return 0;
                    else {
                    for(i=0;i<len&&strcmp(stu[i].zh,zh);i++);
                    return i;}
        }                   //
};       //ѧ���ඨ��
Student Stu;

void Admin_Account(){
    char num;
	L1:
    cout<<endl<<"                 ***********�����ʺŲ���-3��************"<<endl
    <<"                 | 1.����Ա 2.��ʦ 3.ѧ�� 4.ɾ�� 5.�˳� |"<<endl;
    cin>>num;
    switch(num)
    {
	    case '1':{Admin_Account1();goto L1;}
        case '2':{cout<<endl<<"ѡ������Ĺ���: "<<"1.�༭��ʦ�˺� 2.��ӽ�ʦ�˺� 3.�˳�"<<endl;
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
	cout<<endl<<"                 ******���ڲ����Ĺ���Ա�ʺ�-4��******"<<endl
	<<"                 | 1.�����û��� 2.�������� 3.�˳����� |";
	cin>>num;
	if(num=='1'||num=='2'){
    if(num=='1'){
		cout<<"���û���: "<<A<<endl<<"  ����Ϊ: ";
		cin>>name;
		strcpy(A,name);
		cout<<endl;}
    else if(num=='2'){
		cout<<"������Ϊ: "<<B<<endl<<"  ����Ϊ: ";
		cin>>name;
		strcpy(B,name);
		cout<<endl;}
	cout<<"���ĳɹ�!"<<endl;}
}

void Teacher_Account(int i){
    char num;
	char name[15];
	cout<<endl<<"                  *******���ڲ����Ľ�ʦ�ʺ�-3��*******"<<endl
	<<"                  | 1.�����û��� 2.�������� 3.�˳����� |";
	cin>>num;
	if(num=='1'||num=='2'){
    if(num=='1'){
		cout<<"���û���: ";cout<<Tea.tea[i].name;
		cout<<endl<<"  ����Ϊ: ";
		cin>>name;
		Tea.cpy_name(name,i);
		cout<<endl;}
    else if(num=='2'){
		cout<<"������Ϊ: ";cout<<Tea.tea[i].password;
		cout<<endl<<"  ����Ϊ: ";
		cin>>name;
		Tea.cpy_password(name,i);
		cout<<endl;}
        cout<<"���ĳɹ�!"<<endl;}
}

void Student_Account(int i){
    char num;
	char name[15];
	cout<<endl<<"                  *****���ڲ�����ѧ���ʺ�-3��*****"<<endl
	<<"                  | 1.�����û��� 2.�������� 3.�˳����� |";
	cin>>num;
	if(num=='1'||num=='2'){
    if(num=='1'){
		cout<<"���û���: ";Stu.Get_zh(i);
		cout<<endl<<"  ����Ϊ: ";
		cin>>name;
		Stu.cpy_password(name,i);
		cout<<endl;}
    else if(num=='2'){
		cout<<"������Ϊ: ";Stu.Get_password(i);
		cout<<endl<<"  ����Ϊ: ";
		cin>>name;
		Stu.cpy_password(name,i);
		cout<<endl;}
	cout<<"���ĳɹ�!"<<endl;}
 }

void admin(){
            char a[15],b[15];
            char num[15];
            char num1,num2;
            while(1){
            cout<<"�����������(back����): ";//��ʾ��������
            cin>>num;
	L1:
	if(!strcmp(num,Back)) break;//��֤����
    cout<<"Please enter your Account: ";
    cin>>a;
    L2:
    if(!strcmp(num,Back)) break;
    if(strcmp(a,A)) {cout<<"Unable to find this Account!!!"
					<<endl<<"�����������(back����): ";
					cin>>num;
					if(strcmp(num,Back))
						{cout<<"Please enter your Account once again: ";
						cin>>a;
						goto L2;}
					else goto L1;//���ص���һ��
					}
    cout<<"Please enter your Password: ";
    cin>>b;
    if(!strcmp(b,B)){L4:cout<<endl<<"        *****************�������ѡ����-2��*****************"<<endl
                    <<"        | 1.������Ϣ 2.ѧ�Ų��� 3.����  4.�޸� 5.�˺� 6.�˳� |"<<endl;//����Ա�˺�Ȩ��
                        cin>>num1;
                        switch(num1){
                        case '1': {cout<<"                *********��ѡ������ʽ��3��**********"<<endl
                        <<"               | 1.��ѧ��С���� 2.���ɼ��ߵ��� 3.���� |"<<endl;
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
}               //����Ա�˺��µĹ���Ȩ��
void teacher1(){
    char a[15],b[15];//�������������
    char num[15];
    char num1;
    int i;
	while(1){L5:
	cout<<"�����������(back����): ";
    cin>>num;
	L1:
	if(!strcmp(num,Back)) break;
    cout<<"Please enter your Account: ";
    cin>>a;
    L2:
    if(!strcmp(num,Back)) break;
    i=Tea.jsyz(a);
    if(i==Tea.Get_ti()) {cout<<"Unable to find this Account!!!"
					<<endl<<"�����������(back����): ";
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
                    cout<<endl<<"              *************�������ѡ����-2��************"<<endl
                    <<"             | 1.������Ϣ 2.ѧ�Ų��� 3.�༭ 4.�˺� 5.�˳� |"<<endl;//��ʦȨ��
                        cin>>num1;
                        switch(num1){
                        case '1': {
                                cout<<"                *********��ѡ������ʽ��3��*******"<<endl
                                <<"               | 1.��ѧ��С���� 2.���ɼ��ߵ��� 3.���� |"<<endl;
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

}               //��ʦ�����ܲ���
void student1(){

    char a[15],b[15];//ϵͳ�е�����
    char num[15];
    char num1,i;
	while(1){L5:
	cout<<"�����������(back����): ";
    cin>>num;
	L1:
	if(!strcmp(num,Back)) break;
    cout<<"Please enter your Account: ";
    cin>>a;
    L2:
    if(!strcmp(num,Back)) break;
    if(Stu.xsyz(a)==Stu.Get_len()) {cout<<"Unable to find this Account!!!"
					<<endl<<"�����������(back����): ";
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
						cout<<endl<<"                     ********�������ѡ����-2��********"<<endl
                    <<"                         | 1.������Ϣ 2.�˺� 3.�˳� |"<<endl;
                        cin>>num1;
                        switch(num1){
                        case '1': {
                                cout<<endl<<"    ѧ��      ����        ��ϵ�绰     C++    ����    Ӣ��"<<endl;
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
}               //ѧ��

int main()
{ char n;

  Read();
  title_Display();//��ʾϵͳ����
  L1:
  cin>>n;
  cout<<endl;
  while(1){system("cls");
  if(n=='1')  admin();

  else if(n=='2')  teacher1();
  else  if(n=='3') student1();
  else   if(n=='4')  break;

  cout<<endl<<"                  /******ѡ����ݵ���-1��********"<<
  endl<<"                 | 1.����Ա 2.��ʦ 3.ѧ�� 4.Exit |"<<endl;
  goto L1;
  }
    Write();
    return 0;
}
void Write()
	{
		ofstream outfile("d:\\ѧ������ϵͳ����.dat",ios::binary|ios::out);

		if(outfile==NULL)
		{    abort();
			cout<<"cant open file.";

			return ;
		}
		int i;
		outfile.write((char *)&A,sizeof(A));
		outfile.write((char *)&B,sizeof(B));//д�����Ա�˺ź�����

		outfile.write((char *)&Stu.len,sizeof(Stu.len));
        for(i=0;i<Stu.len;i++)
			outfile.write((char *)&Stu.stu[i],sizeof(Stu.stu[i]));//д��ѧ��ѧ��������Ϣ

        outfile.write((char *)&Tea.ti,sizeof(Tea.ti));
        for(i=0;i<Tea.ti;i++)
            outfile.write((char *)&Tea.tea[i],sizeof(Tea.tea[i]));//д���ʦ�˺�����
		outfile.close();
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                        _______________________\n";
		cout<<"                       | �����޸ĵ������Ѵ浵! |\n";
		cout<<"                        _______________________\n";
	}
void Read()
	{
		ifstream infile("d:\\ѧ������ϵͳ����.dat",ios::binary|ios::in);
        if(infile==NULL)
		{
			cout<<"\n��Ϊ�״�ʹ�ù���ϵͳ��ʼ��......\n";
			cout<<"\n��ʼ���ɹ�!\n";

			return ;
		}
        int num;
		int i;
		infile.read((char *)&A,sizeof(A));
		infile.read((char *)&B,sizeof(B));    //��ȡ����Ա�˺ź�����

		infile.read((char *)&Stu.len,sizeof(Stu.len));
		for(i=0;i<Stu.len;i++)
			infile.read((char *)&Stu.stu[i],sizeof(Stu.stu[i]));//��ȡѧ��������Ϣ

        infile.read((char *)&Tea.ti,sizeof(Tea.ti));
		for(i=0;i<Tea.ti;i++)
			infile.read((char *)&Tea.tea[i],sizeof(Tea.tea[i]));//��ȡ��ʦ�˺�����
			cout<<"�Ѷ����ϻر����ѧ����Ϣ"<<endl;
		infile.close();
	}
/*1000 ������ 156232423 78 88 100
1001 ���� 1358741437 94.5 93.5 68
1002 ��¶Ƽ 5779349 58 85 85.5
1003 ���� 234827098 88 70.5 67
1004 ��ˮ֧ 4524985 76 100 0
1005 ����� 15742395 56 90 86*/

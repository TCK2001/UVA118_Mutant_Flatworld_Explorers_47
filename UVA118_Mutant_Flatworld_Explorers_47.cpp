/*
Sample Input
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL
Sample Output
1 1 E
3 3 N LOST
2 3 S
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
//���� �Ұ� �κ��� �������� �ٽô� �Ȱ�; �׷��� 1�� ǥ����; 
using namespace std;

int main()
{
	int in1,in2;
	cin>>in1>>in2; // ũ�� �Է�; 
	int save[in1+1][in2+1]={0};
	int x,y;
	string act,f;
	while(cin>>x>>y>>f>>act) //���� �����̶� ��ġ�� �̵��Ұ� �Է�; 
	{
		for(int i=0;i<act.length();i++)
		{
			string temp; 
			temp=act[i]; //���� ���ϸ� �ȵǱ� ������ temp�� ����; 
			int itemp=save[x][y]; //�̰Ŵ� 1���� �ƴ��� �Ǵ��ϴ� �Լ�; 
			
			if((x<0||x>in1)||(y<0||y>in2)) //���� ����� ��; 
			{
				break;
			}
			
			if(temp=="R") //������; 
			{
				if(f=="E")
				{
					f="S";
				}
				else if(f=="W")
				{
					f="N";
				}
				else if(f=="N")
				{
					f="E";
				}
				else if(f=="S")
				{
					f="W";
				}
			}
			else if(temp=="L") //����; 
			{
				if(f=="E")
				{
					f="N";
				}
				else if(f=="W")
				{
					f="S";
				}
				else if(f=="N")
				{
					f="W";
				}
				else if(f=="S")
				{
					f="E";
				}
			}
			else if(temp=="F") //������; 
			{
				if(f=="E"&&(itemp!=1||x+1<=in1))
				{
					x+=1;
				}
				else if(f=="N"&&(itemp!=1||y+1<=in2))
				{
					y+=1;
				}
				else if(f=="S"&&(itemp!=1||y-1>0))
				{
					y-=1;
				}
				else if(f=="W"&&(itemp!=1||x-1>0))
				{
					x-=1;
				}
			}
		}
		if(x<0) //�״� ���ǵ�; 
		{
			cout<<x+1<<" "<<y<<" "<<f<<" "<<"LOST"<<endl;
			save[x+1][y]=1;
		}
		else if(y<0)
		{
			cout<<x<<" "<<y+1<<" "<<f<<" "<<"LOST"<<endl;
			save[x][y+1]=1;
		}
		else if(x>in1)
		{
			cout<<x-1<<" "<<y<<" "<<f<<" "<<"LOST"<<endl;
			save[x-1][y]=1;
		}
		else if(y>in2)
		{
			cout<<x<<" "<<y-1<<" "<<f<<" "<<"LOST"<<endl;
			save[x][y-1]=1;
		}
		else //��Ƴ�����; 
		{
			cout<<x<<" "<<y<<" "<<f<<endl;
		}
	}
return 0;
}


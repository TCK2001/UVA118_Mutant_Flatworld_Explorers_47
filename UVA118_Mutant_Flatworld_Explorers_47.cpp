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
//주의 할건 로봇이 죽은곳은 다시는 안감; 그래서 1을 표시함; 
using namespace std;

int main()
{
	int in1,in2;
	cin>>in1>>in2; // 크기 입력; 
	int save[in1+1][in2+1]={0};
	int x,y;
	string act,f;
	while(cin>>x>>y>>f>>act) //시작 지점이랑 위치랑 이동할곳 입력; 
	{
		for(int i=0;i<act.length();i++)
		{
			string temp; 
			temp=act[i]; //값이 변하면 안되기 때문에 temp에 저장; 
			int itemp=save[x][y]; //이거는 1인지 아닌지 판단하는 함수; 
			
			if((x<0||x>in1)||(y<0||y>in2)) //범위 벗어나면 끝; 
			{
				break;
			}
			
			if(temp=="R") //오른쪽; 
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
			else if(temp=="L") //왼쪽; 
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
			else if(temp=="F") //앞으로; 
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
		if(x<0) //죽는 조건들; 
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
		else //살아남을시; 
		{
			cout<<x<<" "<<y<<" "<<f<<endl;
		}
	}
return 0;
}


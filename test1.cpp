//Îå×ÓÆå
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int position[8][2]={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
bool isvail(vector<string>& vin)
{
    for(int i=0;i<20;++i)
    {
        for(int j=0;j<20;++j)
        {
            if(vin[i][j]=='*'||vin[i][j]=='+')
            {
                for(int k=0;k<8;++k)
                {
                    int count=1;
                    int nx=i+position[k][0];
                    int ny=j+position[k][1];
                    while(nx>=0&&nx<20&&ny>=0&&ny<20&&vin[i][j]==vin[nx][ny])
                    {
                        ++count;
                        nx+=position[k][0];
                        ny+=position[k][1];
                    }
                    if(count>=5)
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    vector<string> vin;
    vin.resize(20);
    while(cin>>vin[0])
    {
        for(int i=1;i<20;++i)
        {
            cin >> vin[i];
        }
        if(isvail(vin))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}
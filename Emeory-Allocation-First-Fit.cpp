#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
	int memory[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
	int copyMemory[10] = {9500,7000,4500,8500,3000,9000,1000,5500,1500,500};
	vector<pair<int,int> > jobs;
	int t1,t2;
	int totalTime = 0;
	while(true)
     {
          cin>>t1;
          if(t1==-1)
               break;
          cin>>t2;
          jobs.push_back(t1,t2);
          totalTime+=t1;
     }
     for(int time=0;time<=totalTime;time++)
     {
          for(int i=0;i<jobs.size();i++)
          {
               for(int j=0;j<10;j++)
               {
                    if(jobs[i].second <= memory[j] && memory[j] == copyMemory)
                    {
                         me
                    }
               }

          }
     }
	return 0;
}

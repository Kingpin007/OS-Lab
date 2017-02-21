#include<bits/stdc++.h>
using namespace std;

class sched{
public:
    double n,burstTime[10],arrivalTime[10],TotalArrivalTime[10],waitTime[10],runTime[10],finish[10],totalWaitTime,tTotalArrivalTime,total,ct;
     void computeRR(){
          cout<<"Enter no. of processes\n";
          cin>>n;
          cout<<"Enter the burst times and arrival times in order :\n";
          for(int i=0;i<n;i++)
               cin>>burstTime[i]>>arrivalTime[i];
          total=0;
          totalWaitTime=0;
          tTotalArrivalTime=0;
          for(int i=0; i<n; i++){
               runTime[i]=burstTime[i];
               finish[i]=0;
               waitTime[i]=0;
               TotalArrivalTime[i]=0;
               total+=burstTime[i];
          }
          double time;
          int old,next=0;
          cout<<"Enter Context Switching Time:\n";
          cin>>ct;
          for(time=0;time<total;)
          {
               old = next;
               next = getNextProcess(time);
               if(old==next)
               {
                    runTime[next]=runTime[next]-1;
                    if(runTime[next]==0)
                         finish[next]=1;
                    for(int i=0;i<n;i++)
                         if(i!=next && finish[i]==0 && arrivalTime[i]<=time)
                              waitTime[i]+=1;
                    time++;
               }
               else
               {
                    time+=ct+1;
                    total+=ct;
                    runTime[next]=runTime[next]-1;
                    if(runTime[next]==0)
                         finish[next]=1;
                    for(int i=0;i<n;i++)
                         if(i!=next && finish[i]==0 && arrivalTime[i]<=time)
                              waitTime[i]+=(1+ct);
               }
          }
          for(int i=0;i<n;i++)
          {
               totalWaitTime+=waitTime[i];
               TotalArrivalTime[i]=waitTime[i]+burstTime[i];
               tTotalArrivalTime+=TotalArrivalTime[i];
               cout<<"Waiting time for P"<<(i+1)<<" = "<<waitTime[i]<<", Turnaround time = "<<TotalArrivalTime[i]<<endl;
          }
          cout<<"Avg Waiting time = "<<(double)totalWaitTime/n<<" and Avg Turnaround time = "<<(double)tTotalArrivalTime/n<<endl;
          cout<<"Scheduling complete\n";
     }
     int getNextProcess(int time)
     {
          int i,low;
          for(i=0;i<n;i++)
               if(finish[i]==0){low=i; break; }
          for(i=0;i<n;i++)
               if(finish[i]!=1)
                    if(runTime[i]<runTime[low] && arrivalTime[i]<=time)
                         low=i;
          return low;
    }
};


int main()
{
    sched s;
    s.computeRR();
}

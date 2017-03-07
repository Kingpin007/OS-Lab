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
          double time,q,dec=0;
          cout<<"Enter the time quantum:\n";
          cin>>q;
          cout<<"Enter Context Switching Time:\n";
          cin>>ct;
          for(time=0;time<total;)
          {
               for(int i=0;i<n;i++)
               {
                    if(arrivalTime[i]<=time && finish[i]==0)
                    {
                         if(runTime[i]<q)
                              dec=runTime[i];
                         else
                              dec=q;
                         runTime[i]=runTime[i]-dec;
                         if(runTime[i]==0)
                              finish[i]=1;
                         for(int j=0;j<n;j++)
                              if(j!=i && finish[j]==0 && arrivalTime[j]<=time)
                                   waitTime[j]+=(ct+dec);
                         time=time+dec+ct;
                         total+=ct;
                    }
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
};


int main()
{
    sched s;
    s.computeRR();
}

#include <bits/stdc++.h>

using namespace std;

class Job
{
public:
    double bt,jsize,wt,mwt,rt,art,tat,finish,allocated;
    Job()
    {
        bt=jsize=wt=mwt=rt=art=tat=finish=allocated=0;
    }
};

class Memory
{
public:
    double msize,mfree,mallocated,mjob;
    Memory()
    {
        msize=mfree=mallocated=mjob=0;
    }
    void init()
    {
        mfree = msize;
        mallocated = 0;
    }
};

void JobScheduler(Job *j,Memory *m,int nj,int nm);
void allocateJob(Job *j,Memory *m,int nj,int nm);
void FCFS(Job *j,Memory *m,int nj,int nm,double time,int jn);

int main()
{
    int nj,nm;
    cout<<"Enter number of Jobs: ";
    cin>>nj;
    Job *j = new Job[nj];
    cout<<"Enter number of memory blocks: ";
    cin>>nm;
    Memory *m = new Memory[nm];
    cout<<"Enter "<<nj<<" job details with Time and Size respectively:\n";
    double t1,t2;
    for(int i=0;i<nj;i++)
        cin>>j[i].bt>>j[i].jsize;
    cout<<"Enter "<<nm<<" memory Size respectively:\n";
    for(int i=0;i<nm;i++)
    {
        cin>>m[i].msize;
        m[i].init();    //initalize Memory block
    }
    double total=0,time=0;
    for(int i=0;i<nj;i++)
    {
        total += j[i].bt;
        j[i].rt=j[i].bt;
    }
    int next;
    for(time=0;time<total;time++)
    {
        JobScheduler(j,m,nj,nm);
        cout<<"Block\tSize\tFree\tAllocated\tJob\n";
        for(int i=0;i<nm;i++)
        {
            cout<<(i+1)<<"\t"<<m[i].msize<<"\t"<<m[i].mfree<<"\t"<<m[i].mallocated<<"\t\t";
            if(m[i].mallocated==0)
            {
                cout<<"None\n";
            }
            else
            {
                cout<<m[i].mjob+1<<endl;
            }
        }
        for(int i=0;i<nj;i++)
        {
            if(j[i].finish == 0)
            {
                next = i;
                break;
            }
            if(i==10)
                next=-1;
        }
        if(next==-1)
            break;
        for(int i=0;i<nm;i++)
        {
            if(m[i].mjob==next)
            {
                j[(int)m[i].mjob].finish = 1;
                m[i].mfree = m[i].msize;
                m[i].mallocated = 0;
                time += j[i].bt-1;
                j[(int)m[i].mjob].rt = time;
                m[i].mjob = 0;
                for(int k=0;k<nj;k++)
                {
                    if(j[k].finish==0)
                    {
                        if(j[k].allocated==0)
                        {
                            j[k].wt += j[i].bt;
                        }
                        else
                        {
                            j[k].mwt += j[i].bt;
                        }
                    }
                }
                cout<<"\nJob No. "<<next+1<<"\tExecution Time: "<<time+1<<"\tBurst Time: "<<j[next].bt<<endl;
                break;
            }
        }
    }
    double twt=0,tmwt=0,ttwt=0,tat=0;
    for(int i=0;i<nj;i++)
    {
        twt += j[i].wt;
        tmwt += j[i].mwt;
        tat += j[i].rt;
        cout<<"Waiting time for J"<<(i+1)<<" before memory allocation = "<<j[i].wt<<"\nTurnaround time = "<<j[i].rt<<endl;
        cout<<"Waiting time for J"<<(i+1)<<" in memory = "<<j[i].mwt<<endl;
    }
    cout<<"Avg Waiting time before memory allocation = "<<(double)twt/nj<<" and Avg Turnaround time = "<<(double)tat/nj<<endl;
    cout<<"Avg Waiting time in memory = "<<(double)tmwt/nj<<endl;
    return 0;

}

void JobScheduler(Job *j,Memory *m,int nj,int nm)
{
    for(int i=0;i<nj;i++)
    {
        if(j[i].finish==0 && j[i].allocated==0)  //Job not finished and not allocated
        {
            allocateJob(j,m,i,nm);
        }
    }
}

void allocateJob(Job *j,Memory *m,int nj,int nm)
{
    for(int i=0;i<nm;i++)
    {
        if(m[i].mallocated==0)
        {
            if(m[i].mfree>=j[nj].jsize)
            {
                m[i].mallocated = j[nj].jsize;
                m[i].mjob = nj;
                m[i].mfree = m[i].msize - m[i].mallocated;
                j[nj].allocated = 1;
                break;
            }
        }
    }
}



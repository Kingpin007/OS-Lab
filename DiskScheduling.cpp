#include <bits/stdc++.h>

using namespace std;

double seekTime(double t)
{
    return 10+0.1*t;
}

double sectorTime(double t1,double t2)
{
    if(t1>=t2)
        return t1-t2;
    else
        return t2-t1;
}

void FCFS(vector<double> a,vector<double> tr,vector<double> s);
void SSTF(vector<double> a,vector<double> tr,vector<double> s);
void LOOK(vector<double> a,vector<double> tr,vector<double> s);
void CLOOK(vector<double> a,vector<double> tr,vector<double> s);
void displayTime(double t,vector<double> a,vector<double> tr,vector<double> s,int i);

double tracks=200,sectors=8,siceOfSector=25;
double rotationTime=8,transferTime=1;

int main()
{

    vector<double> a;
    vector<double> tr;
    vector<double> s;
    double t1,t2,t3;
    while(true)
    {
        cin>>t1>>t2>>t3;
        if(t1==-1)
            break;
        a.push_back(t1);
        tr.push_back(t2);
        s.push_back(t3);
    }

    int ch;
    do{
        cout<<"\n\nSchedule using :\n1.FCFS\n2.SSTF\n3.LOOK\n4.C-LOOK\n5.Exit\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            FCFS(a,tr,s);
            break;
        case 2:
            SSTF(a,tr,s);
            break;
        case 3:
            LOOK(a,tr,s);
            break;
        case 4:
            CLOOK(a,tr,s);
            break;
        case 5:
            break;
        default:
            cout<<"ERROR! Try Again";
        }
    }while(ch!=5);
    return 0;
}

void displayTime(double t,vector<double> a,vector<double> tr,vector<double> s,int i)
{
    cout<<"Time: "<<t<<"\tArrival Time: "<<a[i]<<"\tTrack no. :"<<tr[i]<<"\tSector :"<<s[i]<<endl;
}

void FCFS(vector<double> a,vector<double> tr,vector<double> s)
{
    double time = 0;
    double head = 0,headSector=0;
    vector<double> tarray;
    for(int i=0;i<tr.size();i++)
    {
        if(time<a[i])
            time=a[i];
        cout<<"TIme before request: "<<i+1<<endl;
        displayTime(time,a,tr,s,i);
        time += seekTime(tr[i]-head);
        time += sectorTime(headSector,s[i]);
        time += transferTime;
        tarray.push_back(time);
        head=tr[i];
        headSector=s[i];
        cout<<"Time after request: "<<i+1<<endl;
        displayTime(time,a,tr,s,i);
    }
    double variance=0;
    for(int i=0;i<tarray.size();i++)
    {
        variance += ((double)time/tr.size()-tarray[i])*((double)time/tr.size()-tarray[i]);
    }
    cout<<"\nAverage Time: "<<(double)time/tr.size();
    cout<<"\nVariance : "<< variance/tr.size();
    cout<<"\nStandard Deviation: "<<sqrt(variance/tr.size())<<endl;
}

void SSTF(vector<double> a,vector<double> tr,vector<double> s)
{
    double time = 0;
    double head = 0,headSector=0;
    int next=0;
    vector<double> tarray;
    for(int i=0;i<tr.size();i++)
    {
        cout<<"TIme before request: "<<next+1<<endl;
        displayTime(time,a,tr,s,next);
        time += seekTime(abs(tr[next]-head));
        time += sectorTime(headSector,s[next]);
        time += transferTime;
        head=tr[next];
        headSector=s[next];
        cout<<"Time after request: "<<next+1<<endl;
        displayTime(time,a,tr,s,next);
        a[next]=-1;
        int nxtt=next;
        int nextTime = -1;
        for(int j=0;j<tr.size();j++)
        {
            if(a[j]!=-1)
            {
                if(a[j]<time)
                {
                    if(nextTime==-1)
                    {
                        nextTime=abs(tr[j]-head);
                        next=j;
                    }
                    else if(nextTime>abs(tr[j]-head))
                    {
                        nextTime = abs(tr[j]-head);
                        next=j;
                    }
                }
            }
        }
        tarray.push_back(time);
        if(nxtt==next)
            next++;
        if(time<a[next])
            time=a[next];
    }
    double variance=0;
    for(int i=0;i<tarray.size();i++)
    {
        variance += ((double)time/tr.size()-tarray[i])*((double)time/tr.size()-tarray[i]);
    }
    cout<<"\nAverage Time: "<<(double)time/tr.size();
    cout<<"\nVariance : "<< variance/tr.size();
    cout<<"\nStandard Deviation: "<<sqrt(variance/tr.size())<<endl;
}

void LOOK(vector<double> a,vector<double> tr,vector<double> s)
{
    double time = 0;
    double head = 0,headSector=0;
    int next=0;
    vector<double> tarray;
    for(int i=0;i<tr.size();i++)
    {
        cout<<"TIme before request: "<<next+1<<endl;
        displayTime(time,a,tr,s,next);
        time += seekTime(abs(tr[next]-head));
        time += sectorTime(headSector,s[next]);
        time += transferTime;
        head=tr[next];
        headSector=s[next];
        cout<<"Time after request: "<<next+1<<endl;
        displayTime(time,a,tr,s,next);
        a[next]=-1;
        int nxtt=next;
        int nextTime = -1;
        for(int j=0;j<tr.size();j++)
        {
            if(a[j]!=-1)
            {
                if(a[j]<time)
                {
                    if(nextTime==-1)
                    {
                        nextTime=abs(tr[j]-head);
                        next=j;
                    }
                    else if(nextTime>abs(tr[j]-head))
                    {
                        nextTime = abs(tr[j]-head);
                        next=j;
                    }
                }
            }
        }
        tarray.push_back(time);
        if(nxtt==next)
            next++;
        if(time<a[next])
            time=a[next];
    }
    double variance=0;
    for(int i=0;i<tarray.size();i++)
    {
        variance += ((double)time/tr.size()-tarray[i])*((double)time/tr.size()-tarray[i]);
    }
    cout<<"\nAverage Time: "<<(double)time/tr.size();
    cout<<"\nVariance : "<< variance/tr.size();
    cout<<"\nStandard Deviation: "<<sqrt(variance/tr.size())<<endl;
}

void CLOOK(vector<double> a,vector<double> tr,vector<double> s)
{
    double time = 0;
    double head = 0,headSector=0;
    int nexta[]={0,1,5,4,2,3};
    int next=0,nextc=0;;
    vector<double> tarray;
    for(int i=0;i<tr.size();i++)
    {
        cout<<"TIme before request: "<<next+1<<endl;
        displayTime(time,a,tr,s,next);
        time += seekTime(abs(tr[next]-head));
        time += sectorTime(headSector,s[next]);
        time += transferTime;
        head=tr[next];
        headSector=s[next];
        cout<<"Time after request: "<<next+1<<endl;
        displayTime(time,a,tr,s,next);
        next = nexta[nextc++];
        tarray.push_back(time);
        if(time<a[next])
            time=a[next];
    }
    double variance=0;
    for(int i=0;i<tarray.size();i++)
    {
        variance += ((double)time/tr.size()-tarray[i])*((double)time/tr.size()-tarray[i]);
    }
    cout<<"\nAverage Time: "<<(double)time/tr.size();
    cout<<"\nVariance : "<< variance/tr.size();
    cout<<"\nStandard Deviation: "<<sqrt(variance/tr.size())<<endl;
}



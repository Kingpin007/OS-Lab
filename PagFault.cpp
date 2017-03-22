#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> pageFrame,int s)
{
    for(int i=0;i<pageFrame.size();i++)
        if(pageFrame[i]==s)
            return true;
    return false;
}

void displayQueue(queue<pair<int,int> > q)
{
    queue<pair<int,int> > q2;
    while(!q.empty())
    {
        q2.push(q.front());
        cout<<q.front().first<<"\t\t"<<q.front().second<<endl;
        q.pop();
    }
    while(!q2.empty())
    {
        q.push(q2.front());
        q2.pop();
    }
}

int main()
{
    vector<int> words;
    int t,n;
    cout<<"Enter the number of word requests: ";
    cin>>n;
    cout<<"Enter the word requests: ";
    for(int i=0;i<n;i++)
    {
        cin>>t;
        words.push_back(t);
    }
    queue<pair<int,int> > pageFrame;
    vector<int> pageTable;
    cout<<"Enter Page Frame Size: ";
    cin>>t;
    int pageTableSize = ceil(460/t);
    for(int i=0;i<=pageTableSize;i++)
        pageTable.push_back(0);
    n = ceil(200/t);    // n is the number of page frames in total in memory
    int pageFrameCount=0,pageFaultCount=0,frequencyCount=0,pageFramePosition=0;
    for(int i=0;i<words.size();i++)
    {
        int x = words[i]/t;
        if(pageTable[x] == 0)
        {
            pageFaultCount++;
            if(pageFrameCount>=n)
            {
                pageTable[pageFrame.front().first]=0;
                int temp = pageFrame.front().second;
                pageFrame.pop();
                pageFrame.push(make_pair(x,temp));
                pageTable[x]=1;
            }
            else
            {
                pageFrame.push(make_pair(x,pageFramePosition++));
                pageTable[x]=1;
                pageFrameCount++;
            }
        }
        else
        {
            frequencyCount++;
        }
        cout<<"Current Page Table:\nFrame\tValid\n";
        for(int j=0;j<=pageTableSize;j++)
            cout<<j<<"\t"<<pageTable[j]<<"\n";
        cout<<"Frequency count: "<<frequencyCount<<endl;
        cout<<"Queue:\nFrame Number\tFrame Pos\n";
        displayQueue(pageFrame);
    }
    cout<<"\n\n\nNumber of Page faults: "<<pageFaultCount<<"\nTotal Page Requests : "<<words.size();
    cout<<"\nPage Fault Frequency: "<<((double)pageFaultCount/words.size())*100<<"%\n";
    cout<<"\nSuccess Frequency: "<<((double)frequencyCount/words.size())*100<<"%\n";
    return 0;
}

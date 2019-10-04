#include <iostream>
using namespace std;

int t,n;
int gate1,gate2,gate3;
int p1,p2,p3;
int a[100];
int L = 0,R = 1;

int absdiff(int x,int y)
{
int ans = (x > y) ? x-y : y-x;
return ans; 
}

void copyarr()
{
for(int i=0;i<n;i++)
a[i] = 0;
}

int cost(int pos,int pref)
{
  int fp,sp;
  int f = 999999,s = 999999;
  if(pref == L)
  {
     for(int i=pos;i>=0;i--)
     {
        if(a[i] == 0)
        {
          fp = i;
          f = absdiff(pos,i)+1;
          break;
        }
     }
     for(int i=pos;i<n;i++)
     {
        if(a[i] == 0)
        {
          sp = i;
          s = absdiff(pos,i)+1;
          break;
        }
     }
     if(f < s)
     {
       a[fp] = 1;
       return f;
     }
     else
     {
       a[sp] = 1;
       return s;
     }
  }
  else
  {
     for(int i=pos;i<n;i++)
     {
        if(a[i] == 0)
        {
          fp = i;
          f = absdiff(pos,i)+1;
          break;
        }
     }
   
    for(int i=pos;i>=0;i--)
     {
        if(a[i] == 0)
        {
          sp = i;
          s = absdiff(pos,i)+1;
          break;
        }
     }
    
     if(f < s)
     {
       a[fp] = 1;
       return f;
     }
     else
     {
       a[sp] = 1;
       return s;
     }
  }

}


int first(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 0,s = 0,t = 0;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int second(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 0,s = 0,t = 1;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int third(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 0,s = 1,t = 0;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int fourth(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 0,s = 1,t = 1;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int fifth(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 1,s = 0,t = 0;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int sixth(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 1,s = 0,t = 1;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int seventh(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 1,s = 1,t = 0;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int eighth(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int cst = 0;
int f = 1,s = 1,t = 1;
for(int i=0;i<p1;i++)
{
cst += cost(gate1,f);
f = !f;
}
for(int i=0;i<p2;i++)
{
cst += cost(gate2,s);
s = !s;
}
for(int i=0;i<p3;i++)
{
cst += cost(gate3,t);
t = !t;
}
return cst;
}

int f(int gate1,int gate2,int gate3,int p1,int p2,int p3)
{
int ans = 999999;
ans = min(ans,first(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,second(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,third(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,fourth(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,fifth(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,sixth(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,seventh(gate1,gate2,gate3,p1,p2,p3));
copyarr();
ans = min(ans,eighth(gate1,gate2,gate3,p1,p2,p3));
copyarr();

return ans;
}

int main()
{

cin>>t;
while(t--)
{
cin>>n;
cin>>gate1>>p1;
cin>>gate2>>p2;
cin>>gate3>>p3;
gate1--,gate2--,gate3--;
int ans = 999999;
copyarr();
ans = min(ans,f(gate1,gate2,gate3,p1,p2,p3));
ans = min(ans,f(gate3,gate2,gate1,p3,p2,p1));
ans = min(ans,f(gate2,gate1,gate3,p2,p1,p3));
ans = min(ans,f(gate2,gate3,gate1,p2,p3,p1));
ans = min(ans,f(gate1,gate3,gate2,p1,p3,p2));
ans = min(ans,f(gate3,gate1,gate2,p3,p1,p2));

cout<<ans<<endl;

}


return 0;
}

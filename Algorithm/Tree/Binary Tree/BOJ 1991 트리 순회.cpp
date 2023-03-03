#include<iostream>
#include<map>
#include<utility>
using namespace std;
map<char,pair<char,char>> tree;
void trv1(char c)
{
    cout<<c;
    if(tree[c].first!='.')
        trv1(tree[c].first);
    if(tree[c].second!='.')
        trv1(tree[c].second);    
}
void trv2(char c)
{
    if(tree[c].first!='.')
        trv2(tree[c].first);
    cout<<c;
    if(tree[c].second!='.')
        trv2(tree[c].second);    
}
void trv3(char c)
{
    if(tree[c].first!='.')
        trv3(tree[c].first);
    if(tree[c].second!='.')
        trv3(tree[c].second);   
    cout<<c;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char a,b,c;
        cin>>a>>b>>c;
        tree[a]=make_pair(b,c);
    }
    trv1('A');
    cout<<'\n';
    trv2('A');
    cout<<'\n';
    trv3('A');
}

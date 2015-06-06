#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> SET;
typedef vector<SET> PowerSet;

void printPowerSet(PowerSet& ps)
{
	for(int i=0; i< ps.size(); i++)
	{
		cout << "{ " ;
		for(int j=0; j< ps[i].size(); j++)
		{
			cout << ps[i][j] << ",";
		}
		cout << " }" << endl;
	}
}

void powerset(int n,SET& s, PowerSet& r)
{
	if(n==s.size())
	{
		return;
	}
	else
	{
		powerset(n+1,s,r);
		int len = r.size();
		for(int i=0; i<len; i++)
			r.push_back(r[i]);
		for(int i=len; i<r.size(); i++)
		{
			r[i].push_back(s[n]);
		}
		r.push_back(SET(1,s[n]));
	}
}
int main()
{
	int a[]={1,2,3};
	SET v(a,a+3);
	PowerSet res;
	powerset(0,v,res);
	printPowerSet(res);

}

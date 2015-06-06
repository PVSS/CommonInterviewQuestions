#include <iostream>
#include <vector>

using namespace std;

template<typename BeginIter,typename EndIter>
void print(BeginIter b, EndIter e)
{
	while(b < e)
		std::cout << *b++ << "\t";
}

void reverse(int start,int end,vector<int>& v)
{
	while(start < end)
	{
		swap(v[start],v[end]);
		start++;
		end--;
	}
}


void nextPermutation(vector<int>& v)
{
	int suffix=v.size()-1;
	while((suffix > 0) && (v[suffix] < v[suffix-1]))
	{
		suffix--;
	}
	int indexToSwap = suffix-1;
	if(indexToSwap == -1)
	{
		reverse(0,v.size()-1,v);
		return;
	}


	int indexForSwap = v.size()-1;
	while(v[indexForSwap] <= v[indexToSwap])
		indexForSwap--;

	swap(v[indexToSwap],v[indexForSwap]);

	reverse(suffix,v.size()-1,v);
}

int main()
{
	int a[]={1,2,3};
	vector<int> v(a,a+3);
	nextPermutation(v);
	print(v.begin(),v.end());
}
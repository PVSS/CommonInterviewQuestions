#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<string> >& v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << ",";
		}
		std::cout << std::endl;
	}
}

bool IsPalindrome(const string&s,int start, int end)
{
	bool result = true;
	while(start < end)
	{
		if(s[start] == s[end])
		{
			start++;
			end--;
		}
		else
		{
			result = false;
			break;
		}
	}

	return result;

}

void PalindromicPartitionHelper(const string& s,int start,vector<string>& v, vector<vector<string> >&res)
{
	if(start == s.size())
	{
		res.push_back(v);
	}
	else
	{
		for(int i=start; i< s.size(); i++)
		{
			string ss = s.substr(start,i+1-start);
			if(IsPalindrome(ss,0,ss.size()-1))
			{
				v.push_back(ss);
				PalindromicPartitionHelper(s,i+1,v,res);
				v.pop_back();
			}
		}
	}
}
void PalindromicPartition(const string& s)
{
	vector<string> p;
	vector<vector<string> > result;
	PalindromicPartitionHelper(s,0,p,result);
	print(result);
	
}

int main()
{
	string s("1881");
	PalindromicPartition(s);
	
}

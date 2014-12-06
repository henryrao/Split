// Split.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <vector>

namespace HR
{
	using namespace std;

	typedef string::size_type(string::*find_t)(const string& delim, string::size_type offset) const;

	/*����s��ΪҪ�ֽ���ַ���*/
	/*����match��ΪҪƥ����ַ���*/
	/*����removeEmpty��Ϊ�Ƿ�Ҫɾ�����ַ�*/
	/*����fullMatch��Ϊ�Ƿ���ȫƥ����ַ���*/
	vector<string> Split(const string& s,
		const string& match,
		bool removeEmpty = false,
		bool fullMatch = false)
	{
		vector<string> result;
		string::size_type start = 0;
		string::size_type skip = 1;
		find_t pfind = &string::find_first_of;
		if (fullMatch)
		{
			skip = match.length();
			pfind = &string::find;
		}

		while (start != string::npos)
		{
			string::size_type end = (s.*pfind)(match, start);
			if (skip == 0)
				end = string::npos;
			string token = s.substr(start, end - start);
			if (!(removeEmpty && token.empty()))
			{
				result.push_back(token);
			}

			if ((start = end) != string::npos)
				start += skip;
		}

		return result;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


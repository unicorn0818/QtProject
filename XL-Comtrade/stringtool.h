#ifndef STRINGTOOL_H
#define STRINGTOOL_H

#include<vector>
#include<string>

using namespace std;

//vector<string> stringSplit(string& str, const char* c)
//{
//	char *cstr, *p;
//	vector<string> res;
//	cstr = new char[str.size() + 1];
//	strcpy(cstr, str.c_str());
//	p = strtok(cstr, c);
//	while (p != NULL)
//	{
//		res.push_back(p);
//		p = strtok(NULL, c);
//	}
//	return res;
//}

vector<string> stringSplit(string& str, const char* c)
{
	vector<string> res;
	char p[256 + 1];//预先开辟256个字符
	str.copy(p, str.size(), 0);//这里5代表复制几个字符，0代表复制的位置，
	*(p + str.size()) = '\0';//注意手动加结束符！！！
	char*pos = strstr(p, c);
	char*lastPos = p;
	int len = 0;
	while (pos != NULL)
	{
		len = pos - lastPos;
		if (len>0)
		{
			char buffer[256] = { 0 };
			int i = 0;
			for (i = 0; i < len; i++)
			{
				buffer[i] = lastPos[i];  
			}
			buffer[i] = '\0';
			string tmp;
			tmp = buffer;
			res.push_back(tmp);
		}
		else
		{
			res.push_back(" ");
		}
		lastPos = pos + strlen(c); //新的字串首 是在上一次找到的地址位置+分割符长
		pos = strstr(lastPos, c); //再从新的字串地址开始查找 下一个分割符位置
		if (res.size()>=1 && pos == NULL)
		{
			if (strlen(lastPos)>0)
				res.push_back(lastPos);
			else
				res.push_back("");
		}
	}
	return res;
}

 int str_to_int(const char* buf)
{
	if (!buf)
	{
		printf(" buf is null\n");
		return -1;
	}
	return atoi(buf);
}

 double str_to_double(const char* buf)
{
	if (!buf)
	{
		printf(" buf is null\n");
		return 0xFFFFFFFF;
	}
	return atof(buf);
}

 //char* str_to_upper(char* str)
 //{
	// int len = strlen(str);
 //    

 //}

 void revstr(char *str) //字符串反转
 {
	 int i = 0, h, j;
	 h = j = strlen(str) - 1;
	 char *p = str, c;
	 while (i <= h / 2)
	 {
		 c = *(p + i);
		 *(p + i) = *(p + j);
		 *(p + j) = c;
		 i++; j--;
	 }
 }

 int substring(char *res, int pos, int len, char *substr)//从pos开始取len个字符到substr中
 {
	 char *p = res;
	 int i = 0;
	 if (pos > strlen(res))
		 return 0;
	 pos--;
	 while (i < len)
	 {
		 substr[i++] = res[pos++];
		 if (pos > strlen(res))
		 {
			 substr[i] = '\0';
			 break;
		 }
	 }
	 substr[i] = '\0';
	 return 1;
 }


 int strindex(char *res, int pos, char *substr)  //返回substr在resource中在pos后出现的第一个位置
 {
	 int i = pos, c = 0;
	 char *p = res + (i - 1), *q = substr;
	 while (*p != '\0')
	 {
		 q = substr;
		 while (1)
		 {
			 if (*p == *q)
			 {
				 if (*(q + 1) == '\0')
				 {
					 i = i - strlen(substr);
					 return i + 1;
				 }
				 p++;
				 q++;
				 ++i;
				 c++;
				 continue;
			 }
			 else
			 {
				 if (c > 0)
				 {
					 p = p - c + 1;
					 i = i - c + 1;
					 c = 0;
					 break;
				 }
				 else
				 {
					 p++;
					 i++;
					 break;
				 }
			 }
		 }
	 }
	 return 0;
 }


 int del_substr(char *res, int pos, int len)//从res的pos位置开始删除len个字符
 {
	 int i = 0;
	 if (pos>strlen(res))
		 return 0;
	 char *p = res + (pos - 1), *q = res + (pos + len - 1);
	 do
	 {
		 *p++ = *q++;
	 } while (*q != '\0');
	 *p = '\0';
	 return 1;
 }


 int str_count(char *res, char  *substr)//统计res中的substr出现的次数
 {
	 int l, j = 1, c = 0;
	 l = strlen(substr);
	 do
	 {
		 j = strindex(res, j, substr);
		 if (j == 0)
			 return c;
		 c++;
		 j += l;//后移l个长度
	 } while (j != 0);
 }

 int  cut_str(char *res, char *mark, int pos, char *substr) //取res中第pos个mark前的串
 {
	 int pos1, pos2 = 1, j = 1, c = 0, i = 0;
	 if (str_count(res, mark) == 0 || pos == 0)
		 return 0;
	 do
	 {
		 pos1 = j - 1;
		 j = strindex(res, j, mark);
		 c++;//累计第几次出现
		 if (c == str_count(res, mark) + 1)
		 {
			 substring(res, pos2 + 1, 50, substr);
			 return 1;
		 }
		 pos2 = j;
		 j++;
		 if (pos2 > pos1&&c == pos)
		 {
			 pos1 += (strlen(mark) - 1);
			 while (pos1 < pos2 - 1)
			 {
				 substr[i++] = res[pos1++];
			 }
			 break;
		 }
	 } while (j != 0);
	 substr[i] = '\0';
	 return 1;
 }

 int strpa_cat(char **arr, int i, char *str) //把arr字符指针数组(长度为i)包含的串拼接成一个串,存入str
 {
	 int j;
	 char *p;
	 if (i < 1)
		 return 0;
	 for (j = 0; j < i; j++)
	 {
		 p = arr[j];
		 while (*p != '\0')
		 {
			 *str++ = *p++;
		 }
		 *str = '\0';
	 }
	 return 1;
 }
 int replacate(char *res, int n, char const *str) //产生n个重复的str(串或者字符)存入res
 {
	 int i, j = 0;
	 char const *p = str;
	 if (n < 1)
		 return 0;
	 for (i = 0; i < n; i++)
	 {
		 p = str;
		 while (*p != '\0')
		 {
			 res[j++] = *p++;
		 }
	 }
	 res[j] = '\0';
	 return 1;
 }


 int strIsNumer(char*res)
 {
	 if (res == NULL)
		 return 0;

	 int len = strlen(res);
	 for (int i = 0; i < len; i++)
	 {
		 if (!isdigit(res[i]))
			 return 0;
	 }
	 return 1;
 }


#endif STRINGTOOL_H

string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
	if(!str)
      return 0;

    return pcre_match(str,"^\\p{Han}+$");
}


// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
/* rewritten by Snowcat */

// #pragma optimize

inherit F_DBASE;

int DB(int hi, int lo)
{
    return (((hi)&0xFF) << 8 | (lo)&0xFF);
}

int inGBrange(int x)
{
    return 1;
}

int inBIGrange(int x)
{
    return 0;
}

int SC_HB(int x)
{
    return (((x)>>8) & 0xFF);
}

int SC_LB(int x)
{
    return ((x) & 0xFF);
}

int SC_ISFIRSTBYTE(int c)
{
    return ((c)>=0xA1);
}

int SC_IS_GB_SYMBOL(int x)
{
    return 1;
}

int SC_IS_BIG_SYMBOL(int x)
{
    return 0;
}

/* Add a code to the table or the multiple mapping table. 
会和F_DBASE中的add冲突。未发现有使用此函数的代码*/
void add1(int *a1, mixed *am, int i, int code)
{
	int *tmp;
    	int n = 0;
    	int x;

    	if (!a1[i]) a1[i] = code;     /* no code, just add it */
    	else if (a1[i]==code) return;   /* already there, return */
    	else if (am[i])        /* already has multiple mappings */
    	{
   		while (x=am[i][n])
   		{
       			if (x==code) return;
       			else n++;
   		}
   		tmp = (int *) allocate (n+2);
   		tmp[n] = code;
   		tmp[n + 1] = 0;
   		am[i] = tmp;
    	}
    	else
    	{
		am[i] = (int *) allocate (2);
   		am[i][0] = code;
   		am[i][1] = 0;
    	}
}

/* Process the mapping entry line.  */
int do_line (int lcnt, string sbuffer)
{
    	int c1 = sbuffer[0], c2 = sbuffer[1];
    	int i = 2, total = 0;
    	while (c1=sbuffer[i++])
    	{
   		reset_eval_cost();
   		c2 = sbuffer[i++];
   		if (!(c1&&c2)) break;
   		total++;
    	}
    	return(total);
}

int  sc_inittab()
{
    int total = 0;
    return(total);
}

void sc_add_tab_entry(int mode, int code, int cmapping)
{
	return;
}

/*
  Look up the code in the single/multiple mapping table for index i,
  and put the result in the result array of size n.
*/
int cvrt(int *a1, mixed *am, int i, int *result, int n)
{
    int k = 0;
    int x, codeDes = a1[i];

   if (codeDes == 0) return(0);
    result[0] = codeDes;
    if (am[i])
   while (x = am[i][k])
   {
       if (k>=n) break;
       result[++k] = x;
   }
    return k + 1;
}


int sc_convert(int mode, int codeSrc, int *result, int n)
{
    if (n<=0) return -2;
    return(-1);     /* unconverted due to error */
}

string to_str (int i)
{
    string s = " ";
    s[0] = i;
    return s;
}

mixed *result = allocate (256);

string sc_convert_fp(string sin, int mode, int do_mult)
{
    int i, j, c1, c2, n;
    int unconverted = 0;
    string sout = "";

    i = 0;
    j = strlen(sin);
    while (i < j)
    {
   	c1 = sin[i++];
   	if (!SC_ISFIRSTBYTE(c1)) sout += to_str(c1);
   	else
   	{
       		c2 = sin[i++];
       		if ((n=sc_convert(mode, DB(c1, c2), result, 256))<=0)
     			++unconverted;
		sout += to_str('<');
     		for (c1=0; c1<n; c1++)
     		{
        		sout += to_str(SC_HB(result[c1]));
         		sout += to_str(SC_LB(result[c1]));
     		}
     		sout += to_str('<');
   	}
    }
    return sout;
}

string GB2BIG (string str)
{
	return str;
}

string BIG2GB (string str)
{
	return str;
}

string input (string str, object me)
{
    return str;
}

string output (string str, object me)
{
    return str;
}

void create()
{
	seteuid(getuid());
	set("channel_id", "字码精灵");
}

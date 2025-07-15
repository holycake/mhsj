//Cracked by Roath
int help(object me); 
mapping passwd = ([ 
"zen":"W4NqflHNhQOuQ" 
]); 
//32-47,58-64,91-96,123-126, 特殊字符 
//48-57数字 
//65-90大写 
//97-122小写 
string *spe, *upper, *lower, *num, str; 
string word(string c); 
int do_crack(string str, string arg); 
int cancel(string arg); 
int main(object me, string arg) 
{ 
        int i, j; 
  
        seteuid(getuid()); 
        if( !arg || sscanf(arg,"%s&%s",str, arg) < 1) return help(me); 
        if( !arg ) return help(me); 
        spe = allocate(33); 
        upper = allocate(26); 
        lower = allocate(26); 
        num = allocate(10); 
        for( i = 32; i < 48; i++, j++) spe[j] = sprintf("%c",i); 
        for( i = 58; i < 65; i++, j++) spe[j] = sprintf("%c",i); 
        for( i = 91; i < 97; i++, j++) spe[j] = sprintf("%c",i); 
        for( i = 123; i < 127; i++, j++) spe[j] = sprintf("%c",i); 
        j =0;for( i = 48; i < 58; i++, j++) num[j] = sprintf("%c",i); 
        j =0;for( i = 65; i < 91; i++, j++) upper[j] = sprintf("%c",i); 
        j =0;for( i = 97; i < 123; i++, j++) lower[j] = sprintf("%c",i); 
        //printf("spe%O\num%O\nupper%O\nlower%O",spe,num,upper,lower);write("\n" 
; 
        input_to("cancel"); 
        do_crack( str, arg); 
        return 1; 
} 
  
int cancel( string arg) 
{ 
        destruct(this_object()); 
        return 1; 
} 
  
string word(string c) 
{ 
        int i, j; 
        if( c != "s" && c != "n" && c != "u" && c != "l" && c != "w" && c != "o") 
 { 
                i = random(4); 
                switch(i){ 
                        case 0: c="s";break; 
                        case 1: c="n";break; 
                        case 2: c="u";break; 
                        case 3: c="l";break; 
                } 
        } 
        if( c == "w") { 
                i = random(2); 
                switch(i){ 
                        case 0: c="u";break; 
                        case 1: c="l";break; 
                } 
        } 
        if( c == "o") { 
                i = random(2); 
                switch(i){ 
                        case 0: c="s";break; 
                        case 1: c="n";break; 
                } 
        } 
        switch(c){ 
                case "s":       { 
                        j = random(33); 
                        if( j < 0) j =0; 
                        if( j > 32) j = 32; 
                        return spe[j]; 
                } 
                case "n":       { 
                        j = random(10); 
                        if( j < 0) j =0; 
                        if( j > 9) j = 9; 
                        return num[j]; 
                } 
                case "u":       { 
                        j = random(26); 
                        if( j < 0) j =0; 
                        if( j > 25) j = 25; 
                        return upper[j]; 
                } 
                case "l":       { 
                        j = random(26); 
                        if( j < 0) j =0; 
                        if( j > 25) j = 25; 
                        return lower[j]; 
                } 
        } 
        return ""; 
} 
  
int do_crack(string str, string arg) 
{ 
        int go, i, j, k; 
        string id, psw1, psw2, *name; 
        write(arg+"\n"); 
        k = sizeof(arg); 
        go =1; 
while(go++){ 
        if(( go % 100) == 0){ 
                reset_eval_cost(); 
                if( (go%10000) ==0)log_file("get_psw",sprintf("已经尝试了%d个密码 %s\n",go, str+psw1)); 
        } 
        psw1 =""; 
        for(i = 0; i< k ; i++) psw1 += word(sprintf("%c",arg[i])); 
        for(i = 0;i < sizeof(name); i++){ 
                name = keys(passwd); 
                psw2 = passwd[name[i]]; 
        if( crypt(str+psw1, psw2) == psw2 ) { 
                write("密码找到！\n"); 
                write(id+":"+str+psw1+" "+psw2+"\n"); 
                write("共尝试了"+(string)go+"个密码！\n"); 
                log_file("get_psw",id+":"+str+psw1+" "+psw2+"\n"); 
                return 1; 
        } 
        } 
} 
        write("密码没找到！\n"); 
        write("共尝试了"+(string)go+"个密码！\n"); 
        log_file("get_psw",psw1+"\n"); 
        return 1; 
} 
int help(object me) 
{ 
        write(@HELP 
指令格式：guess <密码档> <位数> <密码组成> 
  
这个指令专门用来破解unix的8位密码，仅供程序学习之用， 
请勿用于非法用途，对使用本指令不当的后果，应该自负其 
责。 
  
位数是指可能的密码位数，一般使用5-8位，超过8位没有意义， 
而低于5位属于傻瓜密码，不属于本指令探索的范围。 
  
密码组成是指密码的字符组成，形式是： 
 <小写数目> <大写数目> <数字数目> <特殊字符数目> 
这是针对高素质的密码必须同时具备以上三种组成而言的，譬如一个好的密码： 
        xA 01M+y 
则可以使用组成：2 2 2 2 
如果某一项指定为0，则指令将尝试可能的数目。 
如果不指定组成，则指令将使用暴力穷举的方式进行对照―― 
如果时间和机器允许的话。:( 

HELP 
        ); 
        return 1; 
} 

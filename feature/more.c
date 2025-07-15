// more.c

#include <ansi.h>

void more(string cmd, string *text, int line)
{
	int i;

	switch(cmd) {
	case "b":
	      line = line - 46;
	      if(line<-22) return;
	      for(i=line + 23; line < i;line++)
		write(text[line]+"\n");
	      break;
	case "q":
		return;
	case "":
        default:  // mon changed default to forward. 9/7/98
			for(i=line + 23; line<sizeof(text) && line<i; line++)
				write(text[line] + "\n");
			if( line>=sizeof(text) ) return;
			break;
	}
	printf("== 未完继续 " HIY "%d%%" NOR 
	  " == (ENTER 继续下一页，q 离开，b 前一页)",
		(line*100/sizeof(text)) );
	input_to("more", text, line);
}

void start_more(string msg)
{
        if(!msg || strlen(msg)<1) // no messages.
	  return;
	//11/13/97 try to prevent crash by mon.

	more("", explode(msg, "\n"), 0);
}

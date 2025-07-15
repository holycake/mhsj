讲故事并发奖励系统说明：
  
     COPY文件storyd.c到/adm/daemons/下，
在/adm/etc/perload中加入/adm/daemons/storyd.c语句，
把gift文件架copy到/clone/下。即可自动运行，如没自动运行，
可以update /adm/daemons/storyd.c，使其运行。如有问题可来信询问。
别的文件放入clone/gift
在include/globals.h
     #define STORY_DIR	        "/clone/gift/"
     #define STORY_D	        "/adm/daemons/storyd"


此程序由海洋II上海站巫师hxsd提供
欢迎来星月传奇（www.lywin.com）下载mud资源
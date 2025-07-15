#ifndef __MUDLIB__
#define __MUDLIB__

//  The base distribution mudlib name.  

#define MUDLIB_NAME                             "DHXY-QD"
#define MUDLIB_VERSION_NUMBER	"1.2"
#define MUDLIB_VERSION			(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
#define HOTSADDRESS                    "localhost"
#define INTERMUD_MUD_NAME               "DHXY-QD"
#define INTERMUD_NAME                   "大话西游青岛站"
#define CHINESE_MUD_NAME                "大话西游青岛站"
#define MUD_ADMIN                       "sjxy2000@sina.com"
#define MUD_WEB                           "http://sjxy.51.net"
#define MUDLIB_ENCODING                    "GB"

#endif

// mon 4/27/98 for "vote" command and the piggy room.
#define MAX_VOTES_PER_SITE   100
// maximum votes accepted for one site.
#define VOTER_SITE   1
// this defines what is one voting site. can either be 0 or 1.
// 0: use the first 3 fields of numerical IP as a site.
// 1: use the full 4 fileds of numerical IP as a site.

#define GB_AND_BIG5
// define this to allow both GB and BIG5 players.
// undefine will only allow GB players.

#undef INTERMUD_ALL_MUD
// define this if want to connect with ALL muds.
// undef this if only want to connect with Chinese Muds.
// Chinese muds is defined as either their mudlib is ES2 or they
// have ENCODING field set.

//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)
#include "ansi.h"
#define JOB_OB(x)		("/d/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
// Directories

#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"

// Daemons
#define NEWS_D		        "/cmds/usr/news"
#define RTIME_D	        "/cmds/usr/rtime"
#define BJTIME_D	        "/cmds/usr/bjtime"
#define WIZLIST_D	        "/cmds/usr/wizlist"

#define TOPTEN_D	        "/adm/daemons/toptend"
#define ALIAS_D			"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D		"/adm/daemons/convertd"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define CLUB_D			"/adm/daemons/clubd"
// mon@xiyouji 10/19/98
#define MISC_D		        "/adm/daemons/miscd"
// added by snowcat 6/20/1997
#define MONITOR_D		"/adm/daemons/monitord"
#define NATURE_D		"/adm/daemons/natured"
#define OBSTACLE_D              "/adm/daemons/obstacled"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		        "/adm/daemons/spelld"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define BAN_D		 "/adm/daemons/band.c"
#define MONEY_D		 "/adm/daemons/moneyd.c"
#define TASK_D                  "/adm/daemons/questd"
#define CRON_D                  "/adm/daemons/cron"
#define MAPS_D       "/adm/daemons/maps"
#define NPC_D           "/adm/daemons/npcd"
#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define CONDITION_D(x)	("/daemon/condition/" + x)


// Clonable/Non-inheritable Standard Objects
#define COIN_OB			"/obj/money/coin"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define SILVER_OB		"/obj/money/silver"
#define GOLD_OB		"/obj/money/gold"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"
#define LOCATION_D			"/adm/daemons/locationd"


// Inheritable Standard Objects
#define BANK			"/std/room/bank"
#define BULLETIN_BOARD	"/std/bboard"
#define BBS_BOARD		"/std/bbsboard"
#define CHARACTER		"/std/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP			"/std/equip"
#define FORCE			"/std/force"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM			"/std/item"
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			"/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER			"/std/medicine/powder"
#define QUEST			"/std/quest"
#define ROOM			"/std/room"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"


// User IDs
#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"


// Features
#define SKILL_MODEL_UNARMED    "/maxim/skill_model_unarmed.c"
#define SKILL_MODEL_WEAPON     "/maxim/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT    "/maxim/skill_model_default.c"


#define F_ACTION		"/feature/action.c"
#define F_ALIAS			"/feature/alias.c"
#define F_APPRENTICE	"/feature/apprentice.c"
#define F_ATTACK		"/feature/attack.c"
#define F_ATTRIBUTE		"/feature/attribute.c"
#define F_AUTOLOAD		"/feature/autoload.c"
#define F_CLEAN_UP		"/feature/clean_up.c"
#define F_COMMAND		"/feature/command.c"
#define F_CONDITION		"/feature/condition.c"
#define F_DAMAGE		"/feature/damage.c"
#define F_DBASE			"/feature/dbase.c"
#define F_EDIT			"/feature/edit.c"
#define F_ENCODING		"/feature/encoding.c"
#define F_EQUIP			"/feature/equip.c"
#define F_FINANCE		"/feature/finance.c"
#define F_FOOD			"/feature/food.c"
#define F_LIQUID		"/feature/liquid.c"
#define F_MASTER		"/std/char/master.c"
#define F_MESSAGE		"/feature/message.c"
#define F_MORE			"/feature/more.c"
#define F_MOVE			"/feature/move.c"
#define F_NAME			"/feature/name.c"
#define F_ONEOWNER		"/feature/oneowner.c"
#define F_SAVE			"/feature/save.c"
#define F_BACKUP		"/feature/backup.c"
#define F_SKILL			"/feature/skill.c"
#define F_TEAM			"/feature/team.c"
#define F_TREEMAP		"/feature/treemap.c"
#define F_UNIQUE		"/feature/unique.c"
#define F_VENDOR		"/feature/vendor.c"
#define F_VENDOR_SALE		"/feature/vendor_sale.c"
#define STORY_DIR	        "/clone/gift/"
#define STORY_D	        "/adm/daemons/storyd.c"
#define EVENT_D		"/adm/daemons/eventd"
#define COLOR_D    "/adm/daemons/colord"
#define F_VI "/feature/vi"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS

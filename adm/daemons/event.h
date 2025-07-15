//By waiwai@mszj 2000/11/13
// event.h
 
#ifndef __EVENT_H__
#define __EVENT_H__
 
#define CONFIG_FILE "/adm/etc/event.list"
#define ERROR_FILE  "/log/event_err"
 
#define INTERVAL 60
 
// event type
#define YEARLY  "yearly"
#define MONTHLY "monthly"
#define WEEKLY  "weekly"
#define DAILY   "daily"
#define HOURLY  "hourly"
#define ONCE    "once"
 
#define MUD_TIME  0
#define REAL_TIME 1
 
#define NOUSE -1
 
// function prototype
int remove_event(int event_id);
int add_event(mapping event);
 
#endif

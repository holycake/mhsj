//#
//#  The definition of mission list
//#  Format:
//#       type                    event type
//#       flag                    0: mud time, 1: real time
//#       year                    year     (-1 means no use)
//#       month                   month    (1~12, -1 means no use)
//#       date                    date     (1~31, -1 means no use)
//#       week                    week     (0~6,  -1 means no use)
//#       hour                    hour     (0~23, -1 means no use)
//#       file                    file
//#       func                    function
//#       arg                     argument (-1 means no use)
//#
//# Note the valid type is "once", "hourly", "daily", "weekly", "monthly",
//#                        "yearly".
//#
//# some defines:
//#	YEARLY, MONTHLY, WEEKLY, DAILY, HOURLY, ONCE
//#	MUD_TIME, REAL_TIME, NOUSE

#include <event.h>
#include <localtime.h>
 
int     id=0;
mapping *events;
string  *valid_event_type=({ HOURLY, DAILY, WEEKLY, MONTHLY, YEARLY, ONCE });
 
 
private mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;
 
        line = explode(read_file(file), "\n");
        data = ({});
        for (i=0; i<sizeof(line); i++)
        {
                if (line[i]=="" || line[i][0]=='#') continue;
                if (!pointerp(field))
                {
                        field = explode(line[i], ":");
                        continue;
                }
                if (!pointerp(format))
                {
                        format = explode(line[i], ":");
                        continue;
                }
                break;
        }
 
        for (rn=0, fn=0; i<sizeof(line); i++)
        {
                if (line[i]=="" || line[i][0]=='#') continue;
                if (!fn)
                {
                	data += ({allocate_mapping(sizeof(field))});
                	data[rn]["id"] = id++;
                }
                sscanf(line[i], format[fn], data[rn][field[fn]]);
                fn = (++fn)%sizeof(field);
                if (!fn) ++rn;
        }
        return data;
} // read_table()
 
 
int remove_event(int event_id)
{
	mapping event;
        foreach (event in events)
		if (event["id"] == event_id &&
		    (!previous_object() ||
		     geteuid(previous_object()) == ROOT_UID ||
		     event["owner"] == base_name(previous_object())) )
		{
#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O removed event %d\n",
		previous_object()? previous_object(): this_object(), event_id) );
#endif
			events -= ({ event });
			return 1;
		}
	return 0;
} // remove_event()
 
 
private void perform_event(mapping event)
{
	object ob;
	string err;
	
	if (!find_object(event["file"]) && (err=catch(event["file"]->foo())) )
	{
		write_file(ERROR_FILE, sprintf("[%s] can't load %s: %s\n",
			ctime(time()), event["file"], err) );
		remove_event(event["id"]);
		return;
	}
	ob = find_object(event["file"]);
	seteuid(getuid(ob));
	if (event["arg"]==NOUSE || event["arg"]=="-1")
		err = catch(call_other(event["file"], event["func"]));
	else
		err=catch(call_other(event["file"], event["func"], event["arg"]));
	if (err)
	{
		write_file(ERROR_FILE, sprintf("[%s] %s->%s(%O): %s\n", ctime(time()),
			event["file"], event["func"], event["arg"], err) );
		remove_event(event["id"]);
	}
#ifdef DEBUG
	else
	{
		mixed *local=localtime(time());
		set("id", sprintf("%d:%d", local[2], local[1]) );
		if (event["arg"]==NOUSE || event["arg"]=="-1")
			CHANNEL_D->do_channel(this_object(), "sys",
				sprintf("performed event: %s->%s()",
					event["file"], event["func"]) );
		else
			CHANNEL_D->do_channel(this_object(), "sys",
				sprintf("performed event: %s->%s(%O)",
					event["file"], event["func"], event["arg"]) );
	}
#endif
	seteuid(getuid());
} // perform_event()
 
 
private void check_event()
{
	int	current_time=time();
	mixed  *local, *last;
	mapping event;
 
	remove_call_out("check_event");
	foreach (event in events)
	{
		int  match=0;
		
		if (event["flag"])		// real time
		{
			local = localtime(current_time);
			last  = localtime(event["last_perform"]);
		}
		else				// mud time
		{
			local = localtime(current_time);
			last  = localtime(event["last_perform"]*60);
		}
		switch (event["type"])
		{
		case ONCE:
			if (event["year"] == NOUSE ||
			    (event["flag"] && event["year"]==local[LT_YEAR] &&
			     last[LT_YEAR] != local[LT_YEAR]) ||
			    (!event["flag"] && event["year"]==local[LT_YEAR]+208 &&
			     last[LT_YEAR] != local[LT_YEAR]+208) )
			    	match++;
			if (event["week"] == NOUSE ||
			    (event["week"] == local[LT_WDAY] &&
			     last[LT_WDAY] != local[LT_WDAY]) )
			     	match++;
		case YEARLY:
			if ((event["type"] == ONCE &&
			     event["month"] == NOUSE) ||
			    (event["month"] == local[LT_MON]+1 &&
			     last[LT_MON] != local[LT_MON]) )
				match++;
		case MONTHLY:
			if ((event["type"] == ONCE &&
			     event["date"] == NOUSE) ||
			    (event["date"] == local[LT_MDAY] &&
			     last[LT_MDAY] != local[LT_MDAY]) )
				match++;
		case DAILY:
			if (event["hour"] == local[LT_HOUR] &&
			    last[LT_HOUR] != local[LT_HOUR])
				match++;
			break;
		case WEEKLY:
			if (event["week"] == local[LT_WDAY] &&
			    last[LT_WDAY] != local[LT_WDAY])
				match++;
			if (event["hour"] == local[LT_HOUR] &&
			    last[LT_HOUR] != local[LT_HOUR])
				match++;
			break;
		case HOURLY:
			break;
		default:
			write_file(ERROR_FILE, sprintf("[%s] illegal event type: %s.\n",
				ctime(time()), event["type"]) );
			remove_event(event["id"]);
			continue;
		} // switch
		if ((event["type"]==YEARLY && match>=3) ||  // m/d/h
		    (event["type"]==MONTHLY && match>=2) || // d/h
		    (event["type"]==WEEKLY && match>=2) ||  // w/h
		    (event["type"]==DAILY && match>=1) ||   // h
		    (event["type"]==ONCE && match>=5) ||    // y/m/w/d/h
		    (event["type"]==HOURLY) )
		{
			event["last_perform"] = current_time;
			perform_event(event);
		}	
	} // foreach
	call_out("check_event", INTERVAL);
} // check_event()
 
 
void create() 
{
	seteuid(getuid());
#ifdef DEBUG
	set("name", "时间事件管理系统");
       set("channel_id", "时间事件管理系统(timemaster)");
#endif
	events = read_table(CONFIG_FILE);
	check_event();
} // create()
 
 
int add_event(mapping event)
{
	if (!stringp(event["type"]) ||
	    member_array(event["type"], valid_event_type)<0)
		return -1;
	if (!intp(event["flag"])) return -1;
	switch (event["type"])
	{
	case YEARLY:
		if (!intp(event["month"]) || event["month"]<1 || event["month"]>12)
			return -1;
	case MONTHLY:
		if (!intp(event["date"]) || event["date"]<1 || event["date"]>31)
			return -1;
	case DAILY:
		if (!intp(event["hour"]) || event["hour"]<0 || event["hour"]>23)
			return -1;
		break;
	case WEEKLY:
		if (!intp(event["week"]) || event["week"]<0 || event["week"]>6 ||
		    !intp(event["hour"]) || event["hour"]<0 || event["hour"]>23)
			return -1;
		break;
	case ONCE:
		if (!intp(event["year"]) && !intp(event["month"]) && !intp(event["week"]) &&
		    !intp(event["date"]) && !intp(event["hour"]) )
			return -1;
		if (event["hour"] == NOUSE) return -1;
		break;
	case HOURLY:
	} // switch
	if (!stringp(event["file"]) || !stringp(event["func"]) )
		return -1;
	event["id"] = id++;
	event["owner"] = base_name(previous_object());
	events += ({ event });
#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O added event %d\n",
		previous_object(), event["id"]) );
#endif
	return event["id"];
} // add_event()
 
 
mapping *query_events()
{
//	if (geteuid(previous_object()) != ROOT_UID &&
//	    geteuid(previous_object()) != MUDLIB_UID)
//		return 0;
	return events;
} // query_events()

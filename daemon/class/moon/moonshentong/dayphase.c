// dayphase.c
// figure out the current phase of a day
// ref /adm/daemons/natured.c

nosave int DP_DAWN = 5;
nosave int DP_SUNRISE = 1;
nosave int DP_MORNING = 2;
nosave int DP_NOON = 0;
nosave int DP_AFTERNOON = 1;
nosave int DP_EVENING = 2;
nosave int DP_NIGHT = 3;
nosave int DP_MIDNIGHT = 4;

// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

nosave mapping *day_phase = NATURE_D->query_day_phase();

int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time());
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
	if (t>=day_phase[i]["length"])
	    t -= (int)day_phase[i]["length"];
	else
	    break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}

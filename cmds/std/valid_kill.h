// by mon

void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
     if(userp(victim) && userp(killer)) {
	 if ((int)killer->query_condition("no_pk_time")>480) 
            return notify_fail(
		    "你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
/*	 
	 if(!no_list) 
	     set_my_killer_list(killer, victim);
	     */
     }
	   
     return 1;
}

void set_my_killer_list(object killer, object victim)
{
     string *list, *listk;
     string kill;

         listk=killer->query_temp("my_killer_list");
	 if(listk && arrayp(listk)) {
	     if(member_array(victim->query("id"),listk)!=-1) {
		 // the victim issued kill on the killer first.
		 // so not mark the killer. mon 10/24/98
		 return;
	     }
	 }

	 // this list contains all the players initiaite killing
	 // to the victim.  -mon 8/4/98
         list=victim->query_temp("my_killer_list");
	 kill=killer->query("id");
	 if(!list) list=({kill});
	 else if(member_array(kill, list)==-1)
	     list+=({kill});
	 if(sizeof(list)>100)
	     list=list[1..<1]; // remove the first element.
	 victim->set_temp("my_killer_list", list);
}


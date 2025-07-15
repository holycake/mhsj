//Cracked by Roath

inherit F_CLEAN_UP;

#define SYNTAX "命令格式: encrypt [-d ]<file> <key>\n"
#define LOW 33
#define HIGH 126
// Would use 0 - 255 but read_file() reads ctrl's as spaces. 8-(

private void do_encrypt( mixed a );
private void save_file( mixed a );

int main(object me,mixed a)
{
  string oldfile, filename, key, euid, del;
  object player;
  mixed tmp;
  int j, sj;

  player = this_player();
  euid = geteuid( previous_object() );
  seteuid( euid );
  if( a && sscanf( a, "-d %s", del ) ) a = del;
  if( !a || sscanf( a, "%s %s", filename, key ) < 2 )
  {
    notify_fail( SYNTAX );
    return 0;
  }
  filename = resolve_path( player->query("cwd"), filename );
  if( file_size( filename ) < 0 ) 
  {
    notify_fail( filename + " is not a file.\n" );
    return 0;
  }
  oldfile = read_file( filename );
  if( !oldfile )
  {
    notify_fail( filename + " is empty.\n" );
    return 0;
  }
  sj = strlen( key );
  tmp = ({ });
  for( j = 0 ; j < sj ; j++ )
    tmp += ({ key[j] - 97 });
  tmp += ({ 3, 4, 2, 17, 24, 15, 19 });
  a = ({ oldfile, "", tmp, 0, strlen( oldfile ), filename, euid, player, del });
  write( "加密开始... ("+a[4]+" lines)\n" );
  do_encrypt( a );
  return 1;
}

private void do_encrypt( mixed a )
{
  int i, s, k, *key;
  string newfile, oldfile;

  oldfile = a[0]; newfile = a[1]; key = a[2]; i = a[3];

  s = i + 1000;
  if( s > a[4] ) s = a[4];
  for( ; i < s ; i++ )
  {
    k = oldfile[i];
    if( ( k < LOW ) || ( k > HIGH ) )
    {
      newfile += oldfile[i..i];
    } else {
      k += key[(i - 3*(i/3) )];
      k += key[(i - 7*(i/7) )];
      if( k > HIGH ) k += (LOW - HIGH);
      newfile += sprintf( "%c", k );
    }
  }
  a[1] = newfile;
  a[3] = i;
  if( s == a[4] ) save_file( a );
  else {
    call_out( "do_encrypt", 1, a );
    if( a[7] ) tell_object( a[7], i + "...\n" );
  }
}

private void save_file( mixed a )
{
  string newfile, filename, euid, del;
  object player;

  newfile = a[1]; filename = a[5]; euid = a[6]; player = a[7]; del = a[8];

  seteuid( euid );
  if( del ) rm( filename );
  filename += ".x";
  rm( filename );
  write_file( filename, newfile );
  if( player ) tell_object( player,
    "Encrypted version written to " + filename + "\n" );
}

string help()
{
  return( SYNTAX +
    "命令：  encrypts file <file> to <file>.x\n"+
    "        <key> 参数为加密必须的密码字.\n"+
    "        如果加上“-d”参数, 则<file>.c会被删除。.\n"+
    "        加密速度为每秒1000字节。\n"+
  "" );
}

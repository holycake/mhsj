//Cracked by Roath

inherit F_CLEAN_UP;

int main(object me)

{

string *weapon_dir = ({"/d/obj/weapon/hammer/","/d/obj/weapon/fork/"});

  string weapon,ran_dir;

  string *weapon_file;

  ran_dir = weapon_dir[random(2)];

   weapon_file = get_dir(ran_dir+"*.c");

  weapon = weapon_file[random(sizeof(weapon_file))];

  write(ran_dir+weapon+"\n");

  return 1;

 }
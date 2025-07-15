int singing()
{
 if(present("qu pu", this_object())){
 switch(random(6)) {
       case 0 : command("chang yuanyuan_qu"); break;
       case 1 : command("chang wenshi_jian"); break;
       case 2 : command("chang dielian_hua"); break;
       case 3 : command("chang wanghai_chao"); break;
       case 4 : command("chang chunjiang_huayueye"); break;
       case 5 : command("chang jiangjin_jiu"); break;
     }
   return 1;
 }
 else command("say 好无聊耶 :(\n");
 return 1;
}
void kill_ob(object me)
{
      object ob;
      ob = this_object();
      if (!present("jinzhong shan",ob))
                carry_object("/u/fly/jinshan")->wield();
      if(me->query("id")!="fly")
      me->set_temp("kill_fly", 1);            
      command("hui " + me->query("id"));
              switch(random(4)) {
       case 0 : me->set("title", BLU"登徒子"NOR); break;
       case 1 : me->set("title", BLU"披着羊皮的狼"NOR); break;
       case 2 : me->set("title", BLU"瞎眼色狼"NOR); break;
       case 3 : me->set("title", BLU"绣花枕头一包草"NOR); break;
       }
                     command("chat " + me->query("name") + "是个臭流氓！");
                     me->apply_condition("killer", 100); 
}
string ask_tea()
{
        object me,obj;
        me=this_player();
        if( !objectp(obj = present("maofeng", me)) ){
        command(":)");
        command("say 好的，小女子这就给您沏茶。\n");
        new("/u/fly/tea")->move(me);
        message_vision("$N端上一碗新沏的毛峰给$n。\n",this_object(),me);
        return "请慢慢品尝。\n";
        }
        else return "不是刚给了你吗？\n";
}
int do_mo(string target)
{
     object me,ob;
     me = this_player();
     ob = this_object();
      if( !target ) return 0;
      if(target == "xue" || 
         target == "xue baochai" || 
         target == "daiyu" || 
         target == "baochai") {
        if((string)me->query("id")=="fly")
            {
                switch(random(4)) 
                {           
                case 0 : command("kiss fly");break;
                case 1 : command("blush"); break;
                case 2 : command("xixi fly"); break;
                case 3 : command("lover fly"); break;  
                }               
                return 0;
                }
        if ((string)me->query("gender") == "女性") { 
                command("hmm " + me->query("id"));
                message_vision("$N说道：好个轻薄女子！\n",ob);
                return 1;
                          }
        else {
          message_vision("$N轻轻啐了一口：好个无理之徒，赶他出去！\n",ob);
          message_vision("只见几个家丁跑进来，把$N乱棒赶了出去。\n",me);
          command("chat " + me->query("name") + "是个无耻下流之徒！");
          me->move("/d/city/kezhan");
          me->receive_damage("qi", 100);
          me->receive_wound("qi", 50);
          message_vision(me->name() + "被人乱棒打了出来。\n",me);
          return 1;
              }
        }
}

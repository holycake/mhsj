#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *sxy = ({ 
         ([ "sxy":"泾水之滨","where":"/d/changan/wside1"]),   
         ([ "sxy":"泾水桥北","where":"/d/changan/nbridge"]),   
         ([ "sxy":"大官道","where":"/d/changan/broadway1"]),   
         ([ "sxy":"南岳","where":"/d/changan/nanyue"]),   
         ([ "sxy":"南海之滨","where":"/d/changan/southseashore"]),   
         ([ "sxy":"高家大门","where":"/d/gao/gate"]),   
         ([ "sxy":"汴京铁塔","where":"/d/kaifeng/tieta"]),   
         ([ "sxy":"尧王街","where":"/d/kaifeng/yao5"]),   
         ([ "sxy":"古亭道","where":"/d/kaifeng/guting3"]),   
         ([ "sxy":"西湖路","where":"/d/kaifeng/xihu6"]),    
         ([ "sxy":"禹王道","where":"/d/kaifeng/yuwang1"]),    
         ([ "sxy":"辰龙道","where":"/d/city/southjie3"]),    
         ([ "sxy":"开封城门","where":"/d/kaifeng/chengmen"]),    
         ([ "sxy":"望南街","where":"/d/eastway/wangnan5"]),
         ([ "sxy":"十字街头","where":"/d/city/center"]),
         ([ "sxy":"青龙大街","where":"/d/city/qinglong-e1"]),   
         ([ "sxy":"青龙大街","where":"/d/city/qinglong-e2"]),   
         ([ "sxy":"青龙大街","where":"/d/city/qinglong-e3"]),   
         ([ "sxy":"长安城东门","where":"/d/city/dongmen"]),   
         ([ "sxy":"玄武大街","where":"/d/city/xuanwu-n1"]),   
         ([ "sxy":"朝阳门","where":"/d/huanggong/chaoyangmen"]),   
         ([ "sxy":"朱雀大街","where":"/d/city/zhuque-s1"]),   
         ([ "sxy":"朱雀大街","where":"/d/city/zhuque-s2"]),   
         ([ "sxy":"朱雀大街","where":"/d/city/zhuque-s3"]),   
         ([ "sxy":"朱雀大街","where":"/d/city/zhuque-s4"]),   
         ([ "sxy":"南城口","where":"/d/changan/nanchengkou"]),   
         ([ "sxy":"白虎大街","where":"/d/city/baihu-w1"]),   
         ([ "sxy":"白虎大街","where":"/d/city/baihu-w2"]),   
         ([ "sxy":"白虎大街","where":"/d/city/baihu-w3"]),    
         ([ "sxy":"长安城西门","where":"/d/city/ximen"]),    
         ([ "sxy":"背阴巷","where":"/d/city/beiyin1"]),    
         ([ "sxy":"背阴巷","where":"/d/city/beiyin2"]),    
         ([ "sxy":"背阴巷","where":"/d/city/beiyin3"]),    
         ([ "sxy":"背阴巷","where":"/d/city/beiyin4"]),    
         ([ "sxy":"背阴巷","where":"/d/city/beiyin5"]),    
         ([ "sxy":"长安民居","where":"/d/city/minju1"]),   
         ([ "sxy":"长安民居","where":"/d/city/minju2"]),   
         ([ "sxy":"长安民居","where":"/d/city/minju3"]),   
         ([ "sxy":"长安民居","where":"/d/city/minju4"]),   
         ([ "sxy":"长安望南街","where":"/d/eastway/wangnan1"]),   
         ([ "sxy":"长安望南街","where":"/d/eastway/wangnan2"]),   
         ([ "sxy":"长安望南街","where":"/d/eastway/wangnan3"]),   
         ([ "sxy":"长安望南街","where":"/d/eastway/wangnan4"]),   
         ([ "sxy":"长安望南街","where":"/d/eastway/wangnan5"]),   
         ([ "sxy":"回春药铺","where":"/d/city/yaopu"]),   
         ([ "sxy":"鞋帽店","where":"/d/city/xiemao"]),   
         ([ "sxy":"老孙皮货店","where":"/d/city/maohuo"]),   
         ([ "sxy":"吉祥杂货铺","where":"/d/city/zahuopu"]),   
         ([ "sxy":"长安武馆","where":"/d/city/wuguan"]),   
         ([ "sxy":"长安武馆","where":"/d/city/wuguanzhong"]),   
         ([ "sxy":"兵器铺","where":"/d/city/bingqipu"]), 
         ([ "sxy":"化生寺","where":"/d/city/huashengsi"]), 
         ([ "sxy":"大雄宝殿","where":"/d/city/baodian"]), 
         ([ "sxy":"方丈室","where":"/d/city/fangzhang"]), 
         ([ "sxy":"袁氏草堂","where":"/d/city/caotang"]), 
         ([ "sxy":"小雁塔内","where":"/d/eastway/xyt1"]), 
         ([ "sxy":"小雁塔内","where":"/d/eastway/xyt10"]), 
         ([ "sxy":"大雁塔内","where":"/d/eastway/dyt1"]), 
         ([ "sxy":"大雁塔内","where":"/d/eastway/dyt3"]), 
         ([ "sxy":"大雁塔内","where":"/d/eastway/dyt5"]),    
                });
                
mapping query_sxy()
{
        return sxy[random(sizeof(sxy))];
}

int update_condition(object me, int duration)
{
        mapping sxy,sxywhere;
        object ob;
        sxy = this_object()->query_sxy();
        sxywhere = sxy["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIB "你的守卫长安任务时限到了，快回去报告吧\n" NOR );     
      me->delete("job/sxy");
      me->set("job/sxy-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "大呼道：守城不利，天亡我大唐呀！！\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然城里有人大呼，在" + sxy["sxy"] + "发现了妖怪的踪迹！\n" NOR );
        ob = new("/d/obj/npc/yaoguai");
        ob->move(sxywhere);
   }

   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "你的守长安任务时限到了，快回去报告吧\n" NOR );
      me->delete("job/sxy");
      me->set("job/sxy-done",1);        
      return 0;
   }
   return CND_CONTINUE;
}

//make.c
//by happ@YSZZ

#include <ansi.h>

int do_bian(object me);

void done(object me);
int main(object me, string arg)
{
        object ob;
        int lv;
        lv=me->query_skill("medical",1);

        seteuid(getuid());

        if( me->is_busy() )
        return notify_fail("你正忙着呢。\n");

        if( !arg )
        return notify_fail("你要制什么药？\n");

        if( me->is_fighting() )
        return notify_fail("你正在战斗，制什么药啊？\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("你正忙着呢，没时间制药。\n");

     switch (arg)
      {
      case "hugu":
        if( ! present("hu gu", me) || ! present("du huo", me) || 
            ! present("fang feng", me) || ! present("danggui", me) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 30 )
        return notify_fail("你的医术不足制出虎骨酒。\n");
done(me);
        ob=new("/clone/medicine/hugu.c");
        ob->move(me);
        me->start_busy(3);
        break;

        case "jinyinhua":
        if( ! present("jinyin hua", me) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 30 )
        return notify_fail("你的医术不足制出金银花露。\n");
done(me);
        ob=new("/clone/medicine/jyhua.c");
        ob->move(me);
        me->start_busy(3);
      break;
        
        case "meirandan":
        if( ! present("shenglong gu", me) || ! present("xuejie",me) ||
            ! present("lurong",me) || ! present("ha fen", me) ||
            ! present("honghua",me) || ! present("shouwu",me) ||
            ! present("renshen",me) || ! present("fu zi", me) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 150 )
        return notify_fail("你的医术不足制出七宝美髯丹。\n");
done(me);
        ob=new("/clone/medicine/qibao.c");
        ob->move(me);
        me->start_busy(3);
        break;
  
        case "tongmai":
        if( ! present("chuanwu", me) || ! present("chenpi", me) ||
            ! present("moyao", me) || ! present("danggui", me) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 100 )
        return notify_fail("你的医术不足制出贯气通脉丹。\n");
done(me);
        ob=new("/clone/medicine/tongmai.c");
        ob->move(me);
        me->start_busy(3);
        break;


        case "huojin":
        if( ! present("chuanwu", me) || ! present("honghua", me) ||
             ! present("shengdi", me) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 80 )
        return notify_fail("你的医术不足制出活筋舒血丸。\n");
done(me);
        ob=new("/clone/medicine/huojin.c");
        ob->move(me);
        me->start_busy(3);
        break;


        case "wuchangdan":
        if( ! present("tianqi", me) || ! present("xiongdan",me) ||
            ! present("xuelian",me) || ! present("renshen",me))
        return notify_fail("你的药材不齐全。\n");
        if( lv < 80 )
        return notify_fail("你的医术不足制出无常丹。\n");
done(me);
        ob=new("/clone/medicine/wuchang.c");
        ob->move(me);
        me->start_busy(3);
        break;

        case "baoming":
        if( ! present("shouwu", me) || ! present("xuelian",me) ||
            ! present("lurong",me) || ! present("renshen",me)  ||
            ! present("honghua",me) || ! present("chenpi",me ))
        return notify_fail("你的药材不齐全。\n");
        if( lv < 150 )
        return notify_fail("你的医术不足制出天王保命丸。\n");
done(me);
        ob=new("/clone/medicine/baoming.c");
        ob->move(me);
        me->start_busy(3);
        break;

        case "liushen":
        if( ! present("niu huang", me) || ! present("xiongdan",me) ||
            ! present("bingpian",me) || ! present("chansu",me ))
        return notify_fail("你的药材不齐全。\n");
        if( lv < 50 )
        return notify_fail("你的医术不足制出六神丸。\n");
done(me);
        ob=new("/clone/medicine/liushen.c");
        me->start_busy(3);
        ob->move(me);
        break;

        case "sancai":
        if( ! present("tiandong", me) || ! present("gan cao",me) ||
            ! present("huang bo",me) || ! present("gui wei",me ) ||
            ! present("renshen",me ) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 190 )
        return notify_fail("你的医术不足制出三才封髓丹。\n");
done(me);
        ob=new("/clone/medicine/sancai.c");
        me->start_busy(3);
        ob->move(me);
        break;

        case "zaizao":
        if( ! present("renshen", me) || ! present("xuejie",me) ||
            ! present("juhua",me) || ! present("da huang",me ) ||
            ! present("chuanshan jia",me ) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 150 )
        return notify_fail("你的医术不足制出人参再造丸。\n");
done(me);
        ob=new("/clone/medicine/zaizao.c");
        me->start_busy(3);
        ob->move(me);
        break;

        case "duomei":
        if( ! present("hupo", me) || ! present("gan shiliu",me) ||
            ! present("ha fen",me ) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 170 )
        return notify_fail("你的医术不足制出琥珀多寐丸。\n");
done(me);
        ob=new("/clone/medicine/hpdm.c");
        ob->move(me);
        me->start_busy(3);
        break;


        case "zhengqi":
        if( ! present("huo zao", me) || ! present("lingzhi",me) ||
            ! present("gan cao",me ) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 220 )
        return notify_fail("你的医术不足制出正气水。\n");
done(me);
        ob=new("/clone/medicine/zhengqi.c");
        me->start_busy(3);
        ob->move(me);
        break;

        case "qingxin":
        if( ! present("chuanwu", me) || ! present("gan shiliu",me) ||
            ! present("shancha",me ) )
        return notify_fail("你的药材不齐全。\n");
        if( lv < 180 )
        return notify_fail("你的医术不足制出清心解毒丸。\n");
done(me);
        ob=new("/clone/medicine/qingxin.c");
        me->start_busy(3);
        ob->move(me);
        break;

        case "sanhua":
        if( ! present("honghua",me) || ! present("zihua",me) ||
            ! present("lanhua",me ) || ! present("jiu zi",me) )
        return notify_fail("你的药材不齐全。\n");

        if( lv < 110 )
        return notify_fail("你的医术不足制出三花九子膏。\n");
done(me);
        ob=new("/clone/medicine/sanhua.c");
        ob->move(me);
        me->start_busy(3);
        break;

        default:   notify_fail("你没有能力制这种药。\n");
        
        }

        return 1;
}


void done(object me)
{
        int i;
        object *inv; 
               inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("done"))
                        destruct(inv[i]);
                }
message_vision( HIC "只见$N驱真气于药材之上，不多会药材便消失了。\n" NOR,me);
                me->start_busy(6);
return;
}

// liandan_tongzi.c

#include <ansi.h>

inherit NPC;

mixed ask_caiyao();

void create()
{
        set_name("伙计", ({"huo ji", "huoji"}));
        set("gender", "男性");
        set("age", 14);
        set("long",
                "这是药房负责管理药材的伙计。他年纪不大，但看起来\n"
                "显得少年老成。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 21);
        set("int", 22);
        set("con", 23);
        set("dex", 22);
        set("kee", 600);
        set("max_kee", 600);
        set("sen", 400);
        set("max_sen", 400);
        set("neili", 1200);
        set("max_neili", 1200);

        set("inquiry", ([
                "药材" : (: ask_caiyao :),
                "药"   : (: ask_caiyao :),
                "采药" : (: ask_caiyao :),
                "草药" : (: ask_caiyao :),
                "yaocai" : (: ask_caiyao :),
        ]) );
        set("caiyao", 12);

        setup();
}

mixed ask_caiyao()
{  
        object me = this_player();

        switch (me->query_temp("caiyao"))
        {
        case 1:
                return "快去聚宝山采药(cai yao)去吧！";

        case 2:
                return "药采来了？给我吧。";
        }

        switch (me->query_temp("liandan"))
        {
        case 1:
                // 已经打听过了练丹的消息了
                break;

        case 2:
                return "药材已经准备好，可以去了。";

        case 3:
                return "你不是在里面炼药吗？怎么出来了。";

        case 4:
                return "还是先去复命吧。";

        default:
                return "你又不炼药，要药材干什么？";
        }

        message_vision(CYN "伙计对$N" CYN "说道：好吧，那你"
                       "去聚宝山上挖(cai yao)几样新鲜的草药来。\n" NOR, me);
        me->set_temp("caiyao", 1);
        add("caiyao", -1);
        return "有劳你了。";
}

int accept_object(object me, object ob)
{
        if (me->query_temp("caiyao") < 1)
                command("say 我什么时候叫你拿这个给我的？");
        else
        if (me->query_temp("caiyao") == 1)
                command("say 是谁帮你找的东西来敷衍我，别以为好骗。");
        else
        if (ob->query("id") != "cao yao")
                command("say 你欺我小啊？拿这种东西骗我。");
        else
        {
                command("say 好吧，让我来给你加工。");
                command("say 加工好了，你去那边炼丹（liandan）吧。");
                me->delete_temp("caiyao");
                me->set_temp("liandan", 2);
                me->add("combat_exp", 20 + random(30));
                me->imrpove_potential(20 + random(50));

                destruct(ob);
                return -1;
        }

        return 0;
}

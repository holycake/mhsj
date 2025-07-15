        object lingpai;

        restore();

        if(query("banghui"))    {

                lingpai=new("/obj/lingpai");

                lingpai->create(query("banghui"));

                if(lingpai->query("no_use"))    {

                        delete("banghui");

                        save();

                        destruct(lingpai);

                }

                else    destruct(lingpai);

        }

        set_name(query("name"),({query("id")}));

	set("max_force",(int)query_skill("force")*10);

	set("max_kee",220+(int)query_skill("force")*10/4);

	set("bellicosity",0);

        set("kee",query("max_kee"));

        set("eff_kee",query("max_kee"));

        set("gin",query("max_gin"));

        set("eff_gin",query("max_gin"));

        set("sen",query("max_sen"));

        set("eff_sen",query("max_sen"));

        set("force",query("max_force"));


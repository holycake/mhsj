int update_condition(object me, int duration)

{

me->receive_wound("sen", 20+random(10));

me->receive_wound("kee", 20+random(10));

              me->start_busy(2+random(2));

        me->set_temp("death_msg","被黑白无常请去作客了。\n");

        me->apply_condition("hell_zhua", duration - 1);

        if( (int)me->query("kee") < (int)me->query("max_kee")/4 )

                message_vision("$N蒙蒙胧胧中看见黑白无常在眼前晃动。\n", me);

        else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )

                message_vision("$N觉得爪痕象要爆开来一样，全身抽搐不听。\n", me);

        else 

          message_vision("$N觉得爪痕一阵巨痛，不由全身一阵抽搐。\n", me);

        if( duration < 1 ) return 0;

return 1;

}


调用某个文件下的函数
call /adm/daemons/natured->outdoor_room_description()

查看人物的基础信息
call verno->query_entire_dbase()
call verno->query_entire_temp_dbase()

当出现save_svalue: unknown type 64 ignored.的错误时，执行call /adm/daemons/cron->autosave()查看是否此触发了错误。

轩辕古墓宝库迷宫走法
在第1个宝库门口e;e;e;n;e;ne;n;e;s;s;w

五庄观八卦桥走法
在第1个桥上ne;ne;w;se;ne;nw;sw

/adm/daemons/logind.c中设置玩家初始年龄后，还需在/obj/user.c中修改update_age的基准年龄。否则每次更新角色年龄时会在默认14的基础上加上增加的年龄得到最终年龄。

在/cmds/std/learn和study两个指令中设置了当技能等级大于武学经验/550时，由于实战经验不足无法学习。

长安客栈的小二设置了给可装水的容器后再给1silver可将容器装满桂花酒

南京城里得来的裙子是两截衣裳的女子下装。游戏原有裙子是和衣服相同类型的cloth。

###现有获取潜能升级技能，技能等级的设置和武学经验、道行的设定不合理。现实生活中技能只会有生疏、熟练等几个级别的差别。武学经验和道行的存在除了限制技能等级上限和一些条件检查外，没有实际意义。可以改成修仙体系。
修改了使用内功后的技能经验增长，几乎不需要学习了。
修道会奖励潜能

修改了月宫砍树、爬树的奖励，可将基础和特殊武功提升至150级。采莲可将基础和特殊武功提升至200级。拜痴梦如果失败，可采莲，掉到湖底后即可再拜。
修改了轩辕古墓做人头、修行和模仿木人
门派练习福利的技能和武学、潜能的奖励按此标准执行。
if ( (int)me->query_skill("baihua-zhang", 1)< 150 && (string)me->query("family/family_name")=="月宫") me->improve_skill("baihua-zhang", random((int)me->query_skill("baihua-zhang",1)/10));
if ( (int)me->query_skill("snowsword", 1)< 150 && (string)me->query("family/family_name")=="月宫") me->improve_skill("snowsword", random((int)me->query_skill("snowsword",1)/10));
me->add("combat_exp",random(100));	//之前为500，砍树和爬树完会有三百万的武学。预计100会有六十万，和差不多等级的门派NPC相当。
me->add("potential",random(20));

/d/obj/book/san	三字经	literate	20	
/d/obj/book/girlbook	女儿经	literate	0-50	
/d/obj/book/qian	千字文	literate	0-50	
/d/obj/book/luny	论语	literate	120	开封天蓬府经阁可捡
/d/obj/book/poem	太白自选集	literate	100-140	
/d/obj/book/parry_book	格斗秘诀	parry	60	
/d/obj/book/chaizhao	拆招秘籍	parry	70	开封天蓬府经阁可捡
/d/obj/book/parrybook2	少林拆招秘诀	parry	100-140	
/d/obj/book/forcebook	伏魔山心经	force	30	送1朵花给东方二小姐即可
/d/obj/book/forcebook2	伏魔山心经	force	100-140	
/d/obj/book/windwater	风水	spells	20	
/d/obj/book/nowords	无字天书	spells	40	
/d/obj/book/daode	道德经	spells	50	
/d/obj/book/mihou-book	猕猴手记	spells	100-140	拿个果给六耳狝猴,书只能学5小时
/d/obj/book/basic_unarmed	拳法入门	unarmed	20	长安书店买
/d/obj/book/jianpu	青莲剑谱	sword	50	非牛皮酒袋给5个左右
/d/obj/book/basic_blade	刀法入门	blade	20	
/d/obj/book/stickbook	碎布头	stick	30	杀了方寸练功室的老道,或给他一个松果
/d/obj/book/spearbook	枪法简介	spear	60	
/d/obj/book/staffbook	杖法简要	staff	60	
/d/obj/book/rake	基本钯法	rake	120	
	九股托天叉	fork	61	龙宫秘室里拿到,再找龟八斗要金龙符,apply fork or apply hammer,别人给的无效
	八瓣梅花锤	hammer	61
/d/obj/book/misc	旧书	随机	20	长安城南捡
/d/obj/book/qujing	无字经	自选	250	取经通关后送
/d/obj/book/makeupbook	檀香扇	makeup	150	蓬莱
/d/obj/book/yishu	华佗医书	medical	180	魔幻轶事找老人送书
/d/obj/book/quanjing	拳经	changquan	50	改成长拳，50级前可用pfm
/d/obj/book/xuanhu-blade	玄狐长恨刀法	xuanhu-blade	200	将moon和xuanyuan的此技能pfm合并
/d/obj/book/kugu-1	空白帐本	kugu-blade	50	门派专有技能
/d/obj/book/kugu-2	空白帐本	kugu-blade	80-120	门派专有技能
/d/obj/book/kugu-3	空白帐本	kugu-blade	130-180	门派专有技能
/d/obj/book/chunyang	纯阳心得	taiyi	40	门派专有技能
/d/obj/book/taiyi-book	太乙真经	taiyi	50	门派专有技能，五庄观掌门才能拿到
/d/obj/book/tiaobo	挑拨离间之技	tiaobo	120	门派专有技能
/d/obj/book/xbuddhism	佛法真经	xbuddhism	60	门派专有技能
/d/obj/book/jingang	金刚经	buddhism	40	门派专有技能


study book;study book;study book;study book;study book;study book;study book;study book;study book;hp;sk
if jingshen_current and jingshen_max and neili_current then
  if neili_current < 300 then
    echo("\n[study_loop] 内力不足（<300），停止读书开始打坐。\n")
    expandAlias("dza")
    disableTimer("ts")
    return
  else
    if inbusy == 1 then
      return
    else
      if jingshen_current / jingshen_max < 0.9 then
        expandAlias("rr")
      end
      send("learn moonshentong from fairy for 500;sk;hp")
    end
  end
end


auto_dazuo
行功完毕
你行功完毕，吸一口气，缓缓站了起来。
if dz_auto_running then
  dz_auto_step3()
end


auto_dazuo
function dz_auto_step1()
  if not dz_auto_running then return end
  expandAlias("dz")  -- 打坐命令
end

function dz_auto_step3()
  expandAlias("rr")  -- 恢复气血精神
  tempTimer(1, function()
    send("hp")  -- 更新状态
    tempTimer(1.5, dz_auto_check)
  end)
end

function dz_auto_check()
  if not dz_auto_running then return end

  local max = tonumber(neili_max)
  local cur = tonumber(neili_current)
  if not max or not cur then
    echo("[dz_auto] 内力数据缺失，终止！\n")
    dz_auto_running = false
    disableTrigger("auto_dazuo")
    return
  end

  local threshold = math.floor(max * 1.1)
  echo(string.format("[dz_auto] 当前内力：%d / %d（目标：>%d）\n", cur, max, threshold))

  if cur > threshold then
    echo("[dz_auto] 内力已恢复充足，停止自动打坐。\n")
    dz_auto_running = false
    disableTrigger("auto_dazuo")
  else
    dz_auto_step1()
  end
end


自动打坐
^dza$
dz_auto_running = true
enableTrigger("auto_dazuo")
echo("\n[dz_auto] 自动打坐开始...\n")
dz_auto_step1()


停止打坐
^dzs$
dz_auto_running = false
disableTrigger("auto_dazuo")
echo("\n[dz_auto] 自动打坐已手动终止。\n")


修道
你的道行增加了
if jingshen_current/jingshen_max<0.8 then
  expandAlias("rr")
end
if baozi == 0 then
  echo("没包子了，再要两个。\n")
  send("fill hulu;yao")
end
send("eat bao zi;drink hulu;hp;xiudao")

你现在神智不清，再炼恐怕要走火入魔
send("yao;eat bao zi;fill hulu;drink hulu")

包子\(Bao zi\)
baozi = baozi + 1

你闭上眼睛，盘膝坐下，嘴里默默念念不知在说些什么。
baozi = 0
send("i")
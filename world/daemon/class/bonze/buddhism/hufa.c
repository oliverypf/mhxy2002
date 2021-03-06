// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// invocation.c

inherit SSERVER;

int cast(object me, object target)
{   
        int invocation_time;
        object soldier;

        if( !me->is_fighting() )
                return notify_fail("好象没有人要杀你！\n");
   
    if((string)me->query("family/family_name")!="南海普陀山")
                return notify_fail("你不是普陀山的弟子，普陀山的护法是不会来保护你的。\n");
        if(me->query("combat_exp")>500000)
                return notify_fail("你的武功足以自保，还要护法干什么?\n");
        invocation_time=100-(int)me->query_skill("spells");
        if(invocation_time<20) invocation_time=20;
        if((time()-me->query("last_invocation"))<invocation_time)
       return notify_fail("你刚叫过护法，还是让他休息一会儿吧！\n");

        if( (int)me->query("mana") < 50 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 40 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语，叫到：韦陀尊者现身！\n", me);

        me->add("mana", -50);
        me->receive_damage("sen", 40);

        seteuid(getuid());
        soldier = new("/d/nanhai/npc/zunzhe");
        soldier->move(environment(me));
        soldier->invocation(me);
        me->set("last_invocation",time());
        me->start_busy(2+random(2));

        return 8+random(5);
}

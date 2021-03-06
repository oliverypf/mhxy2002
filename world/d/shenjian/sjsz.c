//By tianlin@mhxy for 2002.1.13

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);           
int do_hear();

void create()
{
        set("short", "神剑山庄");
        set("long", @LONG
这里就是武林中人尽皆知的神剑山庄，历经江湖中两百多年的风起云
涌，鉴证了武林中两百年来的沧海桑田。高大的门楼和院墙树立，因为不
断有人进进出出，丈高的朱木大门敞开着，门前排着几排上马石、栓马桩
。门的上方高挂着一个金漆大匾，上面苍劲有力的写着:

                 [37;40m┏━━━━━━━━━┓[0m
                 [37;40m┃[31m   神 剑 山 庄  [37;40m  ┃[0m
                 [37;40m┗━━━━━━━━━┛[0m

LONG
        );
        set("exits", ([ 
   "south" : __DIR__"sroad3",
   "north" : __DIR__"rroad",
]));
  set("objects", ([
		__DIR__"npc/guard4" : 4,
		__DIR__"npc/zhangmen" : 1,
              	]));
  set("outdoors", __DIR__);
  setup();
        
}
void init()
{
   object where=this_object();

    remove_call_out("check_time");
   check_time(where);
   add_action("do_hear","hear");
}
void check_time(object where)                
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   if(phase==4&&(!query("jiangjing"))) jiang_jing(where);
   if(phase==5&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",HIW+"¤"HIC"神剑山庄"NOR+HIW"¤"NOR+HIY"掌门大弟子[Zhang men]:"HIG"神剑山庄弟子听命,现在开始传授本门最深机密.(Hear) \n"+NOR,users());
   tell_object(where,"雪影仙法可谓是谢晓峰创造出来的奇特的仙法.\n");
   set("jiangjing",1);
     set ("long", @LONG

这里就是武林中人尽皆知的神剑山庄，历经江湖中两百多年的风起云
涌，鉴证了武林中两百年来的沧海桑田。高大的门楼和院墙树立，因为不
断有人进进出出，丈高的朱木大门敞开着，门前排着几排上马石、栓马桩
。门的上方高挂着一个金漆大匾，上面苍劲有力的写着:

                 [37;40m┏━━━━━━━━━┓[0m
                 [37;40m┃[31m   神 剑 山 庄  [37;40m  ┃[0m
                 [37;40m┗━━━━━━━━━┛[0m

LONG);
}
void finish_jing(object where)
{
   set("jiangjing",0);
}
int do_hear()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("还没开始授法呢.\n");              
   if((string)me->query("family/family_name")!="神剑山庄")
      return notify_fail(CYN"掌门大弟子说:外派弟子不得来听讲。\n"NOR);
    if(me->query("faith")>400)
      return notify_fail("你觉得自己不用再听讲了。\n");
    tell_object(me,"你全神贯注的在听，简直都入了迷。\n");
   me->start_busy(3);
   me->add("faith",1);
   me->add("combat_exp",12);
   me->add("potential",3);
   me->improve_skill("xueying-xianfa",100);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}                                                                    


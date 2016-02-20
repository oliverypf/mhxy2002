#include <ansi.h> 
inherit ITEM;    
int do_open(string arg);
void create()
{
  set_name(HIG "礼物" NOR,({"liwu"}));
  set("long","这是一份礼物，你可以试着打开("+HIR+"pick"+NOR+")来看看。"); 
  set("unit","份"); 
  set("value", 50000000); 
setup();
}
void init()
{
if(!wizardp(this_player())){
    set("no_get","这个东西拿不起来。\n"); 
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","这东西不能卖。\n");
}
    if(this_player()==environment())
      add_action("do_open", "pick"); 
}
int do_open(string arg)
{
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("你要打开什么?\n"); 
  if (me->query("newyear_liwu")) return notify_fail("你已经拿过礼物了，怎么还想要？\n"); 
  message_vision(HIR"$N把礼物盒轻轻的打开，恭喜～～恭喜～～！！\n" NOR,me); 
  me->add("potential",100000); 
  me->add("combat_exp",100000); 
  me->add("daoxing",100000); 
  me->add("rsg_eaten",5);  
  tell_object(me,HIW"你被奖励了：\n" +
  chinese_number(100000) + "点武学。\n"+        
  chinese_number(200000) + "点潜能。\n"+
  chinese_number(100)    + "年道行。\n"+ 
  "五个人参果！\n" NOR); 
  me->set("newyear_liwu",1);
  destruct(this_object());
  return 1; 
}
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33m内殿[m");
  set ("long", @LONG
这里就是玉帝的宝座了，仍然是空无一人，宝座豪光四射，你不禁也想
    上去坐坐。
LONG);

  set("exits", ([ /* sizeof() == 1 */
]));


  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

void init()
{
        object me=this_player();
                remove_call_out("greeting");
                call_out("greeting",5, me);

}

void greeting(object me)
{            int kar,con;

        kar=me->query("kar");
        con=me->query("con");
        if( !me || environment(me) != this_object() ) return;

   message_vision("忽然你脚上一阵钻心的疼痛，一只全身乌黑的大狗已经死死的咬住了你的小腿
，你刚想摆脱，脑后又被一物砸中！\n", me);
   message_vision("背后传来一个苍老的声息：尝尝老夫金刚琢的厉害！\n",me);  
  if (random(kar+con)<40)
 {      
   me->set_temp("death_msg","擅闯灵霄宝殿，中哮天犬与金刚琢暗算死了。\n");
   me->die();
   me->save();}
   else  
  { me->unconcious();
   me->move("/d/sky/zhanyaotai");}
   return;
}

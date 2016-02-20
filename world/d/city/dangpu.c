//Cracked by Roath
//by tianlin 2001.5.1
#include <room.h>
inherit HOCKSHOP;

void create ()
{
  set ("short", "董记当铺");
  set ("long", @LONG

这是长安城里最大的一家当铺了。素来以买卖公平着称。门口挂了一
块牌子 [1;33m(paizi)[2;37;0m。董老板是个很精明的生意人，见你走了进来，很客
气地和你寒暄，但眼睛里却没有什么笑意，很审慎地打量着你。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhuque-s1",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客官可以在这里：
    [1;35m＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊[2;37;0m
    [1;35m＊	[1;37m典当(pawn)[2;37;0m		[1;35m＊[2;37;0m
    [1;35m＊	[1;37m卖断(sell)[2;37;0m		[1;35m＊[2;37;0m
    [1;35m＊	[1;37m估价(value)[2;37;0m		[1;35m＊[2;37;0m
    [1;35m＊  [1;37m赎回(retrieve stamp)[2;37;0m	[1;35m＊[2;37;0m
    [1;35m＊	[1;37m购买(buy) 用list查看。[2;37;0m	[1;35m＊[2;37;0m
    [1;35m＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊[2;37;0m
各种货物，[33m铜钱、[1;37m银两、[1;33m黄金、[2;37;0m[37m银票[2;37;0m一概通用。

"]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pablo" : 1,
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}


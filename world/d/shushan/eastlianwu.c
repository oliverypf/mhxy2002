// dwuchang1.c by yushu-2000.10

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIG "东武场" HIR "」" NOR);
	set("long", @LONG
这是露天练武场，好多人在这里辛苦的练着，你走在场中，没有人
回头看你一眼，都在聚精汇神的练着自己的功夫。
LONG
	);
              set("outdoors", 2);
        set("exits", ([
	    "north" : __DIR__"eastlianwu1",
                    "west" : __DIR__"changlang",
	]));

            setup();
}


// Room: /shulin/lin5.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǹ�ս������ַ�ˣ���˵�����й����û���㻹�����ߣ��ѵ��뱻����Ե�ô��
LONG );
        set("exits", ([
                "east" : __DIR__"mi4",
                "west" : __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __DIR__"mi6",
        ]));
                 set("objects", ([
        ]));
set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


inherit ROOM;
void create()
{
set("short","[1;33m������[m");
set("long",@LONG

    ����������Ѿ����ںö����ˣ�����ԴԴ���ϵĹ�Ӧ��
�ɵ���Ϊ槼��������������ĺ����������У��������ǣ���
������С����һ���ӣ�Ҳû�гԹ��Լ����ĵ�����Ϊ槼���
���͵���ɵ��ߣ�ɱ���⣡�����Ҳ���������Ǿ�������
��С�����������������ɡ�

LONG);
set("exits", ([
       "east" : __DIR__"road4",
]));
set("objects", ([
    __DIR__"npc/danfox" :1,
        __DIR__"obj/tool" :1,
]));
setup();

}
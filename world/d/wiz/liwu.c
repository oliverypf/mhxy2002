// �����﷿
// idea@yqyl
inherit ROOM;
#include <ansi.h>

void yyy(string arg);
string file;

void create()
{
	set("short", "��Ʒ��");
	set("long", @LONG
��������ʦ����Ʒ����ҵķ���(song)��
LONG
	);
	
	set("exits", ([
		"west" : __DIR__"wizroom"
	]));
	
	setup();
}

void init()
{
	add_action("do_song", "song");
	add_action("do_sheding", "sheding");
}

int do_song()
{
	object who = this_player();
	object present;
	if ( wiz_level(who)<wiz_level("(arch)") ) 
		return notify_fail("Ҫarch��������ʦִ�С�\n");
	if (!file) return notify_fail("���趨��ɶ(sheding <file>)\n");
	
	present = load_object(file);
	if (!present) return notify_fail("û��"+file+"���������\n");
	
	write(present->query("name")+"("+present->query("id")+")��ÿ���ˣ�ȷ����[Y/N]\n");
	input_to ((: yyy :));
	return 1;
}

void yyy(string arg)
{
	object *allp = users();
	object present;
	int i;
	
          log_file("liwu",sprintf("%s  ��������%s���泩%s\n",ctime(time()),file
		,this_player()->query("id") ));
	if (arg == "y" || arg == "Y")
	{
		for(i=0;i<sizeof(allp);i++)
		{
			present = new(file);
			present->move(allp[i]);
                          tell_object(allp[i],HIY"��ʦ����Ʒඣ����ϵ��¸�"NOR+present->query("name")
				+HIY"���������С�\n"NOR);
			log_file("liwu",sprintf("%s(%s)get it\n",allp[i]->query("name")
			,allp[i]->query("id")));
		}
	} else write("ȡ����\n");
}

int do_sheding(string arg)
{
	object who=this_player();
	object present;
	if ( wiz_level(who)<wiz_level("(arch)") ) 
		return notify_fail("Ҫarch��������ʦִ�С�\n");
		
	if (!arg ) return notify_fail("���趨��ɶ(sheding <file>)\n");
	
	present = load_object(arg);
	if (!present) return notify_fail("û��"+arg+"���������\n");
	
	file = arg;
	write("ok\n");
	return 1;
}
//By waiwai@mszj 2000/10/10

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name(HIW"ս����̽����"NOR, ({ "tance" }) );
	set_weight(300);
	set("unit", "��");
	set("long",
		HIC"����ר�õ�ս����̽�����������������̽�� "+HIR"(tance)"HIC" ���˵���ѧֵ��\n");
	set("value", 50000);
	set("no_put", 1);
	set("type", "misc");
	set("apply", ([
		"ͷ��":	0,
	]) );
}

void init()
{
	add_action("do_tance", "tance");
}

int do_tance(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

      if (this_player()->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( !ob ) return notify_fail(HIG"��Ҫ̽��˭��ս������\n"NOR);

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf(HIC"̽������ʾ"+HIB" %s "+HIC"��ս�����ǣ� "+HIR"%d\n"NOR,
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );
  tell_object(ob,HIR"��ͻȻ�е�����" HIY+ this_player()->name() +HIR "���ڹ��������̽����......\n"NOR);
      	this_player()->start_busy(3);

	return 1;
}

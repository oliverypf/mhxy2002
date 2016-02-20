#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE; 
inherit SWORD;

void create()
{
    set_name(HIY "���佣" NOR, ({ "zhenwu jian","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 0);
        	set("no_drop", "1");
        	set("no_get", "1");
                        set("no_sell", "1");
                         set("no_give", "1");
                          set("no_put", "1");
                          set("material", "iron");
        	set("long", "����һ���������е�������ֻ�����������ͣ�����ӵ����ѱ�����\n");
        	set("wield_msg","$N�͵ذγ�$n����˳���ڿ��ж��˸�������\n");
        	set("unwield_msg", "$N���е�$nͻȻ�ڿ��л��˵����磬���佣��֮��ؽ����С�\n");
	}
    	init_sword(200);
	setup();
}

void destruct_me(object where, object me)
{
  message_vision("һ������������$n��ͻ��������ϼ�������ˣ�\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  ::init();
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}


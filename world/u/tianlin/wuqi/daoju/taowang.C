// mihoutao.c ⨺���

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//   set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
 //   set("no_give","��ô����ҩ�����������ˣ�\n");
 //   set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
 //   set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIM"����⨺�����"NOR, ({"mihou taowang","mihoutaowang","taowang"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����ǧ��⨺�������ʮ�����档\n");
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(10);
      me->add_maximum_mana(10);
  message_vision(HIG "$N����һ��⨺��������̲�סץ�����������˵�ֱ�뷭��ͷ�� \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shanwan2.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ��ش���һЩ����������ˮ����Ϫˮ�������졣��������
�ɵ�����أ����ſ�֦��Ҷ���Ĵ���ɽ�ͣ�·�������Եÿ�
��һЩ�������ƽ̹��

LONG);

  set("exits", ([
        "northwest"  : "/d/qujing/baigudong/yelu3",
        "northup"    : __DIR__"shan2",
        "southup"    : __DIR__"shan4",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if (who->query("combat_exp") < 2000 && dir == "northwest")
  {
    message_vision ("һ���ȷ紵����$N��ʱͷ�ؽ��ᡣ\n",who);
    call_out ("fall_down",1,who,environment(who));
    who->start_busy(1,1);
    return
    notify_fail("�����ס�����˼��£�����ͻȻһ����\n");
  }
  return 1;
}

void fall_down (object who, object where)
{
  who->move(where);
  who->unconcious();
}

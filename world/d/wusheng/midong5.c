// changan wusheng
// midong5.c

inherit ROOM;

void create ()
{
  set ("short", "��ʥ�ܶ�");
  set ("long", @LONG

������߼�Ϊ΢��������ǿ�ؿ�����������ԼԼ��һЩ������
ȴ�ֿ��ò���ʮ��������㲻������������Ŷ��ڣ�С�ĵ���
�����ж���Ϊʲô����ʥ�Ż�������ܶ����ѵ������б��

LONG);

  set("exits", ([
        "down" : __DIR__"room7",
      ]));
  set ("sleep_room",1);

  setup();
}



//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", "�������Թ�");                                   
  set ("long", @LONG                                                 
������ʯ�ڵ��Թ���һ��ŨŨ�����������ڿ����                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "north" : __DIR__"three2",                                                                             
  "down" : __DIR__"stairs2",
                                     
]));                                                                 
    set("objects",([
        __DIR__"npc/yao1" : 3,
        __DIR__"npc/yao2" : 3,
    ]));                                                                     
  setup();         
}                                  
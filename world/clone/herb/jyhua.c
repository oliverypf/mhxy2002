// jinying.c

#include "herb.h"

void create()
{
        set_name(HIY "������" NOR, ({ "jinyin hua", "herb_jyhua" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 300);
                set("weight", 50);
set("base_unit","��");
        }
        setup();
}
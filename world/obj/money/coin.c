// coin.c
// by tianlin 2001.5.1

inherit MONEY;

void create()
{
	set_name("[33mǮ[2;37;0m", ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����Ǯ��ֵ��һ�����ӡ�\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
	}
	set_amount(1);
}


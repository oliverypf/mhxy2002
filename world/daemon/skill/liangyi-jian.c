//liangyi-jian.c ���ǽ���
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "name":   "��������",
    "action" : "$N���⽣â������һ�С��������ء�������$w�����´󿪴��أ�
һ����������$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N����Ȧת��һ�С�����������������$wƽչ�´̣�һ�����Ữ
��$n��$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "Ԩ����ǳ",
    "action" : "$N����������������������������$wʹ��һʽ��Ԩ����ǳ������$n��
$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 350,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "ˮ�����",
    "action" : "$N������ָ��������ת��һ�С�ˮ����ơ�ֱȡ$n��$l",
    "force" : 150,
    "dodge" : 15,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�ƺ�����",
    "action" : "$N��â���£��������ߣ�����$wʹ��һʽ���ƺ����¡����������
����$n��$l",
    "force" : 130,
    "dodge" : 25,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���ѵ�ׯ",
    "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
�����ѵ�ׯ��ԾԾ����Ʈ��$n��$l",
    "force" : 120,
    "dodge" : 25,
    "damage" : 320,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ���������ǡ�������
����֮�ƣ�����$n��$l",
    "force" : 110,
    "dodge" : 15,
    "lvl" : 0,
    "damage" : 400,
    "damage_type" : "����"
]),
([      "name":   "��ϵ�̳�",
    "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ�ǡ���ϵ�̳�������
���ϴ���$n��$l",
    "force" : 150,
    "dodge" : 35,
    "damage" : 400,
    "lvl" : 0,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 800)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("wudang-force", 1) < 80)
		return notify_fail("����䵱�ķ����̫ǳ��\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("liangyi-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
     return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("kee") < 50)
   return notify_fail("����������������ǽ�����\n");
    me->receive_damage("kee", 10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liangyi-jian/" + action;
}
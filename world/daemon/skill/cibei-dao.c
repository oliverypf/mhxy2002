// cibei-dao.c 慈悲刀
// Modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([  "action" : "$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
    "force" : 120,
    "dodge" : -10,
    "lvl" : 0,
    "skill_name" : "停车问路",
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
    "force" : 130,
    "dodge" : -10,
    "damage" : 5,
    "lvl" : 8,
    "skill_name" : "童子挂画",
    "damage_type" : "割伤"
]),
([  "action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
    "force" : 140,
    "dodge" : -5,
    "damage" : 15,
    "lvl" : 16,
    "skill_name" : "推窗望月",
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈
向$n",
    "force" : 160,
    "dodge" : 5,
    "damage" : 25,
    "lvl" : 24,
    "skill_name" : "开门见山",
    "damage_type" : "割伤"
]),
([  "action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸
口",
    "force" : 180,
    "dodge" : 10,
    "damage" : 30,
    "lvl" : 33,
    "skill_name" : "临溪观鱼",
    "damage_type" : "割伤"
]),
([  "action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向
$n",
    "force" : 210,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 42,
    "skill_name" : "张弓望的",
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的
$l",
    "force" : 240,
    "dodge" : 5,
    "damage" : 50,
    "lvl" : 51,
    "skill_name" : "风送轻舟",
    "damage_type" : "割伤"
]),
([  "action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全
身涌去",
    "force" : 280,
    "dodge" : 20,
    "damage" : 60,
    "lvl" : 60,
    "skill_name" : "停车问路",
    "damage_type" : "割伤"
]),
});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，无法学习慈悲刀。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀才能练习慈悲刀。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("cibei-dao");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上刀法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练慈悲刀有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练慈悲刀有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍慈悲刀。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("bonze") + "/cibei-dao/"+func;
}
��


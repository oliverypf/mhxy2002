//【蜀山派】mhxy-yushu 2001/2
inherit NPC;
inherit F_MASTER;
int ask_back();
int send_back(object me);
#include <ansi.h>
void create()
{
       set_name("静虚老祖", ({"master jingxu","jingxu", "master"}));
       set("title",HIC"蜀山派开山祖师"NOR);
       set("gender", "男性");
       set("age", 220);
	set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 8000000);
       set_skill("literate", 160);
       set_skill("dodge", 300);
       set_skill("parry", 300);
       set_skill("unarmed", 290);
       set_skill("fumozhang", 290); 
	set_skill("sword", 300);
	set_skill("songhe-sword", 300);
	set_skill("spells", 300);
	set_skill("xianfeng-spells", 300);
	set_skill("yujianshu", 300);
	set_skill("shushan-force", 300);
	set_skill("force", 300);
       set_skill("zuixian-steps", 300);
       map_skill("force", "shushan-force");
	map_skill("sword", "yujianshu");
       map_skill("spells","xianfeng-spells");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "zuixian-steps");
	map_skill("whip", "snowwhip");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
        set("inquiry", ([
                 "回去" : (: ask_back :),
                 "back" : (: ask_back :),
		         "shushan" : (: send_back :),
				 "蜀山" : (: send_back :),
         ]) );
        create_family("蜀山派", 1, "弟子");
        setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/shushan/obj/shenxue")->wear();
}

void attempt_apprentice(object ob)
{	ob=this_player();
       if( (string)ob->query("family/family_name")=="蜀山派") {
	if ((int)ob->query("daoxing") < 800000 ) {
  	command("say 你的道行还不够，对我的招法难以领悟。\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 250 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的仙风云体术还不到火候,你还是找剑圣他们练着吧!\n");
	command("sigh");
	return;
	}
       command("smile");
       command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
       command("recruit " + ob->query("id") );
       ob->set("shushan/wanjian_perform",1);
       return;
	}
       command("shake");
       command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山静虚老祖传人");

}

        return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "蜀山派")
    {
    command("say 你又不是蜀山派的，你问这个干吗！");
    return 1;
    }
    if(ob->query("shushan/tuoqiao_cast"))
    { 
    command("say 你不是知道了吗? ");
    return 1;
    }
    if(ob->query("family/master_name") == "静虚老祖" )
    {
    command("say 你想出去啊！好吧!我教你一招「金蝉脱壳」!");
    command("say 用(cast tuoqiao)就能出去!");
    command("say 下次进来时就不要那么麻烦了,去藏经阁(push 书架)就可以了。");
    ob->set("shushan/tuoqiao_cast",1);
    return 1;
    }
}
int send_back(object me)
{
	me=this_player();
	command("sigh " + me->query("id"));
	command("say " + "又是一根木头...好，你这就去吧。\n");
	tell_object(me,"\n静虚老祖轻舒长袖，在你眼前一拂...\n\n你揉揉眼睛，醒了过来。\n\n");
	me->move("/d/shushan/shanmen");
	return 1;
}



�

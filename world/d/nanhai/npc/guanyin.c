// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996
//BY tianlin@mhxy for 2002.1.20,修改技能全部恢复正常
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
int do_drop(object, object);

void create()
{
        set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
        set("title", "救苦救难大慈大悲");
        set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
        set("gender", "女性");
        set("age", 35);
        set("attitude", "peaceful");
        set("rank_info/self", "贫僧");
        set("rank_info/respect", "菩萨娘娘");
        set("class", "bonze");
        set("str",24);
        set("per",100);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 145);
        set("max_mana", 3000);
        set("mana", 6000);
        set("mana_factor", 150);
        set("combat_exp", 2000000);
        set("daoxing", 10000000);

        set_skill("literate", 180);
        set_skill("spells", 200);
        set_skill("buddhism", 200);
        set_skill("unarmed", 180);
        set_skill("blade", 200);
        set_skill("cibei-dao", 200);
        set_skill("huadao", 200);
        set_skill("jienan-zhi", 200);
        set_skill("dodge", 200);
        set_skill("lotusmove", 200);
        set_skill("parry", 200);
        set_skill("force", 180);
        set_skill("lotusforce", 200);
        set_skill("staff", 200);
          set_skill("lunhui-zhang", 200);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
        set("inquiry", ([
//        "回去"    : (: kick_back :),
//        "back"  : (: kick_back :),
         "职位": (: rank_me :),
      "净瓶": "前些天，福星借我的净瓶用，到现在也没有还，你去看看吧。" ]));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );
        //hehe, since guanyin was killed several times
        //let's use cast bighammer to protect her...weiqi:)
        create_family("南海普陀山", 1, "菩萨");

        setup();
        carry_object("/d/nanhai/obj/jiasha")->wear();
        carry_object("/d/nanhai/obj/nine-ring")->wield();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "普陀山弘法大师")
                return notify_fail("你已经是掌门人了，还来要什么职位．\n");
        if( (string)me->query("family/family_name") == "南海普陀山"){
                if( exp <= 100000 ){
                        me->set("title", HIB"南海普陀山"HIY"知客小和尚"NOR);
                 } else if(exp <= 1000000 ){
                        me->set("title", HIB"南海普陀山"HIY"戒律院首座"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", HIB"南海普陀山"HIY"罗汉堂首座"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", HIB"南海普陀山"HIY"观音护法"NOR);
                } else {
                        me->set("title", HIB"南海普陀山"HIY"逍遥菩萨"NOR);
                }
                tell_object(me, "观音菩萨对你说：你可以做"+me->query("title")+"。\n");
                tell_room(environment(me),
"观音菩萨对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","现授予本门弟子"+me->query("name")+""+me->query("title")+HIC"一职。恭请各位仙长多加捧场！");
     me->save();  
        }
        return 1;
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
                write("看样子观音菩萨对你未剃度出家颇为不快。\n");
                return;
        }       
        if (((int)ob->query_skill("buddhism", 1) < 100 )) {
                command("say " + RANK_D->query_respect(ob) + "不在佛法上苦修，恐怕难成正果。\n");
                return;
        }
        command("pat " + ob->query("id") );
        command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");

        command("recruit " + ob->query("id") );
        return; 
}
void die()
{
        int i;
        string file;
        object *inv;

        if( environment() ) {
        message("sound", "\n\n观音菩萨摇头叹道：刚离迷障，又入魔障，世间疾苦，何人度之！\n\n", environment());
        command("sigh");
        message("sound", "\n观音菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("no_drop")) continue;
                do_drop(this_object(), inv[i]);
//              if (stringp(file = find_command("drop")) && 
//                      call_other(file, "do_drop", this_object(), inv[i])) ;
        }
        }

        destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
            else {
                 message_vision( sprintf("$N丢下一%s$n。\n",
                 undefinedp(obj->query_temp("unit"))?
                         "个":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
           else {
             message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在
                   。\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}

int accept_object(object me,object ob)
{       object who;
        me=this_object();
        who=this_player();
        if (ob->query("id")=="sheng lingzhu" ){
        if(who->query("obstacle/niulang")!="done")
         return 0;
        if(who->query("obstacle/shenglingzhu")=="done") {
                command("say "+RANK_D->query_respect(who)+ "已替我取回了圣灵珠，真是辛苦了！\n");
                call_out("destroy", 1, ob);
 return 1;
        }       
                call_out("announce_success", 3, me, who);
                call_out("destroy", 1, ob);
                return 1;
        }
        return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void announce_success(object me,object who)
{//disabled announce and reward...
    int i;
  who->add("obstacle/number",1);
  who->set("obstacle/shenglingzhu","done");
  who->delete_temp("obstacle/shenglingzhu");
  i = random(800);
  who->add("daoxing",i+8000);
  command("chat "+who->query("name")+"替我取回圣灵珠，真是可喜可贺！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第三十七关！\n"NOR,users());//this is by tianlin 2001.5.8
tell_object(who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}



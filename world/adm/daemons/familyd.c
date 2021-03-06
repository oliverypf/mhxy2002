//负责存放各门派之间的“友好度”。
//Qyz
//By tianlin@mhxy for 2002.1.3
#include <ansi.h>

inherit F_SAVE;

#define FAMILY_ENEMY    2
#define FAMILY_FRIEND   1

mapping ALL_FAMILYS=(["方寸山三星洞":1,
                 "南海普陀山":1,
                 "天蓬帅府":1,//By tianlin@mhxy for 2001.7.2
                 "将军府":1,
                 "五庄观":1,
                 "武当派":1,//By tianlin@mhxy for 2001.9.27
		   "武圣门":1,//已修改过
                 "蜀山派":1,//已更新
                 "少林派":1,//By tianlin@mhxy for 2001.12.13.在1月中旬完成制作
                 "神剑山庄":1,//By tianlin@mhxy for 2001.12.13.
                 "阎罗地府":0,
                 "天空界":0,
                 "月宫":0,
                 "灵界":0,
                 "东海龙宫":0,
		   "龙宫":0,
                 "移花宫":0,//在2001.11月前完成制作
                 "盘丝洞":-1,
                 "大雪山":-1,
                 "魔教":-1,
                 "火云洞":-1,//moyun-shou增强,并修改加其pfm 2个
                 "轩辕古墓":-1,//修改完毕
                 "翠云山芭蕉洞":-1,//暂不开放
                 "陷空山无底洞":-1,
                 "乱石山碧波潭":-1, 
]);

mapping MASTERS=(["方寸山三星洞":"菩提老祖",
                 "南海普陀山":"观音菩萨",
                 "将军府":"秦琼",
                 "五庄观":"镇元大仙",
                 "阎罗地府":"阎罗王",
                 "月宫":"嫦娥",
                 "东海龙宫":"傲广",
                 "大雪山":"大鹏明王",
                 "陷空山无底洞":"玉鼠精",
                 "天蓬帅府":"猪八戒",
                 "武当派":"张三丰",
                 "武圣门":"孔武大帝",
                 "蜀山派":"剑圣",
                 "神剑山庄":"谢晓峰",
                 "盘丝洞":"紫霞仙子",
                 "火云洞":"黄飞虎",
                 "轩辕古墓":"妲己",
                 "灵界":"八叶的老师",
                 "魔教":"无恨",
]);

mapping family;

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(family) ){
        family = ([]);
    }
}

int remove()
{
    save();
    return 1;
}

int family_relation(string your_fam,string my_fam )
{
        return ALL_FAMILYS[your_fam]*ALL_FAMILYS[my_fam];
}

string query_save_file() { return DATA_DIR + "familyd"; }

int set_relation(string my_fam, mapping relation)
{
    family[my_fam] = relation;
    save();
    return 1;
}

int add_family_enemy( string my_fam, string name, int score )
{
    if( undefinedp( family[my_fam] ) )
        family[my_fam] = ([ name : score ]);
    if( !undefinedp(family[my_fam][name] ) )
        family[my_fam][name] += score;
    else family[my_fam] += ([ name : score ]);
    save();
    return 1;
}

int remove_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] ) ) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
    {
        map_delete(family[my_fam] , name);
        save();
            return 1;
    }
    else return 0;
}

int is_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name])&&family[my_fam][name]>100)
        return 1;
    else return 0;
}

int query_enemy_quantity( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
        return family[my_fam][name];
    else return 0;
}
        
mapping query_relation(string my_fam)
{
    if ( !undefinedp(family[my_fam]) )
        return family[my_fam];
    else
        return ([]);
}

int deal_family_relation( object victim, object killer )
{
    mapping my_family, your_family;
   
    int c_score, y_relation, m_relation; 
    string my_fam, your_fam, my_id, your_id, declare;

    string* sname;
    int i;

    your_id = killer->query("id");
    if( your_family = killer->query("family") )
    {
        your_fam = your_family["family_name"];
        my_id = victim->query("id");    
        if( !undefinedp(family[your_fam]) &&
        !undefinedp(family[your_fam][my_id]) )
        {
            killer->add("daoxing" , (victim->query("daoxing")/100) );
            {
                declare = sprintf("[33m%s[37m杀死本门仇敌[32m%s[m，真乃大快人心。\n",
                                killer->name(1), victim->name(1) );
                message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());
            }
            map_delete(family[your_fam] , my_id );
            return 1;
        }

        if( my_family = victim->query("family") )
        {
            my_fam = my_family["family_name"];
            c_score = victim->query("faith");
            if( my_fam == your_fam )
            {
                killer->add("daoxing", -(victim->query("daoxing")/100));
                if(c_score > 30 )  
                {
                    declare = sprintf("[32m%s[37m不可再屠戮本门师兄弟，切不可窝里反！。\n", killer->name(1) );
                    message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());                    
                }     
                return 1;                                             
            }
            else
            {    
                if( userp( killer ) )
                    add_family_enemy( my_fam, your_id, c_score );
                if( y_relation = family_relation( your_fam, my_fam ) )
                {                                           
                    if( y_relation == FAMILY_ENEMY )
                    {
                        killer->add("daoxing" , (victim->query("daoxing")/100) );
                        killer->add("relation/"+my_fam,c_score/100);
                        sname=keys(ALL_FAMILYS);
                        if(c_score > 30 )
                        {
                            declare = sprintf("[32m%s[37m杀死了本门对头[33m%s[37m的[35m%s，[m功德无量也！\n",
                                    killer->name(1), my_fam, victim->name(1) );
                            message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());                            
                        }
                    }
                    else if( y_relation == FAMILY_FRIEND )
                    {
                        killer->add("daoxing" , (victim->query("daoxing")/100) );
                        killer->add("relation/"+my_fam,-c_score/100);       
                        if(c_score > 30 )
                        {
                            declare = sprintf("[0;37m本门弟子应该与[33m%s[37m的弟子和睦相处，不应互相杀戮。\n",
                                        my_fam );
                            message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());
                        }
                    }
                }
                if( m_relation = family_relation( my_fam, your_fam ))
                {
                    if( m_relation == FAMILY_ENEMY )
                    declare = sprintf("[0;37m本门与[32m%s[m势不两立，弟子们要切记仇恨啊！\n",
                                        your_fam );
                    else
                    declare = sprintf("[0;37m本门[31m%s[37m被[33m%s[37m的[32m%s[37m杀死了，同门弟子皆应以报仇为己任！\n",
                                    victim->name(1), your_fam, killer->name(1) );
           
                    message("channel:chat",GRN+MASTERS[my_fam]+declare+NOR,users());
                }
                return 1;                                              
            }             
        }
        else return 0;
    }
    else if( my_family = victim->query("family") )                   
    {
        my_fam = my_family["family_name"];
        c_score = victim->query("faith");
        if( userp(killer) )
            add_family_enemy( my_fam, your_id, c_score );
       killer->add("relation/"+my_fam,c_score/100);
        {
            declare = sprintf("[0;37m本门弟子被[32m%s[37m杀死了。\n", killer->name(1) );
            message("channel:chat",GRN+MASTERS[my_fam]+declare+NOR,users());
        }
        return 1;
    }
    else return 0;
}

void clear_all_family_relation( string id )
{
    int i;
    string *familys = keys(ALL_FAMILYS);
    for( i = 0; i<sizeof(familys); i++ )
    {
        if( undefinedp( family[familys[i]] ) ||
            undefinedp( family[familys[i]][id] ) )
        continue;
        map_delete( family[familys[i]], id );
    }
}
 

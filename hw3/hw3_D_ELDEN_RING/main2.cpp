#include <iostream>
using namespace std;
#define MAX_STONES 50
#define MAX_WEAPONS 1000
class Weapon
{
private:
    static int magic;
    string name;
    int level;
    static void print_magic();

protected:
    string get_name() const;
    int get_level() const;
    void upgrade();

public:
    static void set_magic(int _magic);
    ~Weapon();
    Weapon(string name);
};
class SmithingStone
{
private:
    static int magic;
    int level, number;
    static void print_magic();

protected:
    void add_amount(int amount);
    bool greater_equal(int need) const;
    int get_level() const;

public:
    SmithingStone();
    SmithingStone(int level);
    ~SmithingStone();
    static void set_magic(int _magic);
};

class NormalWeapon : public Weapon{
    public : 
    static int index;
    int grade;
    NormalWeapon(string name);
    // NormalWeapon(NormalWeapon&& other);
    // NormalWeapon & operator=(NormalWeapon && other );
    bool find_name(string name);
    int find_level();
    void upgrade_normal_weapon();
    void c_upgrade_normal_weapon(int start);
    ~NormalWeapon();
};
class SomberWeapon : public Weapon{
    public :
    static int index;
    int grade;
    SomberWeapon(string name);
    // SomberWeapon & operator = (NormalWeapon && other);
    ~SomberWeapon();
    bool find_name(string name);
    int find_level();
    void upgrade_somber_weapon();
    void c_upgrade_somber_weapon(int start);
};
class NormalSmithingStone : public SmithingStone{
    public :
    // NormalSmithingStone();
    NormalSmithingStone(int level);
    ~NormalSmithingStone();
    // NormalSmithingStone & operator=(NormalSmithingStone&& other);
    void add_stone(int amount);
    bool enough_stone(int needed);
    void substract_stone(int needed);
    bool should_destroy();
};

class SomberSmithingStone : public SmithingStone{
    public :
    // SomberSmithingStone();
    SomberSmithingStone(int level);
    ~SomberSmithingStone();
    // NormalSmithingStone & operator=(NormalSmithingStone&& other);
    void add_stone(int amount);
    void substract_stone();
    bool should_destroy();
};

class Tarnished
{
private:
    NormalWeapon *normal_weapons[MAX_WEAPONS];
    SomberWeapon *somber_weapons[MAX_WEAPONS];
    NormalSmithingStone *normal_smithing_stones[MAX_STONES];
    SomberSmithingStone *somber_smithing_stones[MAX_STONES];
public:
    Tarnished();
    ~Tarnished();
    void pick_up_stone(int type, int level, int number);
    void pick_up_weapon(int type, string name);
    void upgrade_weapon(int target, string name);
};

int NormalWeapon::index =0;

NormalWeapon::NormalWeapon(string name) : Weapon(name){
    grade = 0;
    index++;
}
NormalWeapon::~NormalWeapon(){
    if(get_level() ==0)
        std::cout<<"Normal weapon "<<get_name()<<" was destroyed."<<std::endl;
    else 
        std::cout<<"Normal weapon "<<get_name()<<"+"<<get_level()<<" was destroyed."<<std::endl;
}

bool NormalWeapon::find_name(string name){
    return get_name() == name;
}
int NormalWeapon::find_level(){
    return get_level();
}
void NormalWeapon::upgrade_normal_weapon(){
    upgrade();
    if(get_level()==1)
    std::cout<<"Normal weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<std::endl;
    else 
    std::cout<<"Normal weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
}
void NormalWeapon::c_upgrade_normal_weapon(int start){
    if(start == 0)
    std::cout<<"Upgrade "<<get_name()<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
    else
    std::cout<<"Upgrade "<<get_name()<<"+"<<start<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
}
int SomberWeapon::index =0;

SomberWeapon::SomberWeapon(string name):Weapon(name){
    index++;
}

SomberWeapon::~SomberWeapon(){
    if(get_level()==0)
    std::cout<<"Somber weapon "<<get_name()<<" was destroyed."<<std::endl;
    else 
    std::cout<<"Somber weapon "<<get_name()<<"+"<<get_level()<<" was destroyed."<<std::endl;

}
bool SomberWeapon::find_name(string name){
    return get_name()==name;
}
int SomberWeapon::find_level(){
    return get_level();
}

void SomberWeapon::upgrade_somber_weapon(){
    upgrade();
    if(get_level() == 1)
    std::cout<<"Somber weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl; 
    else 
    std::cout<<"Somber weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl; 
}

void SomberWeapon::c_upgrade_somber_weapon(int start){
    if(start == 0)
    std::cout<<"Upgrade "<<get_name()<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
    else
    std::cout<<"Upgrade "<<get_name()<<"+"<<start<<" to "<<get_name()<<"+"<<get_level()<<" Successfully."<<std::endl;
}

// SomberWeapon& SomberWeapon::operator=(SomberWeapon&& other){
// }

NormalSmithingStone::NormalSmithingStone(int level): SmithingStone(level){
};

NormalSmithingStone::~NormalSmithingStone(){
    std::cout<<"Normal smithing stone "<<get_level()<<" was destroyed."<<std::endl;
};

void NormalSmithingStone::add_stone(int amount){
    add_amount(amount);
};

bool NormalSmithingStone::enough_stone(int needed){
    if(this==nullptr) return false;
    return greater_equal(needed);
}

void NormalSmithingStone::substract_stone(int needed){
    add_amount(-needed);
    std::cout<<"Normal Smithing stone"<<get_level()<<" was substracted with "<<needed<<"."<<std::endl;
}

bool NormalSmithingStone::should_destroy(){
    return !greater_equal(1);
};

SomberSmithingStone::SomberSmithingStone(int level): SmithingStone(level){
};

SomberSmithingStone::~SomberSmithingStone(){
    std::cout<<"Somber smithing stone "<<get_level()<<" was destroyed."<<std::endl;
};

void SomberSmithingStone::substract_stone(){
    add_amount(-1);
    std::cout<<"Somber smithing stone "<<get_level()<<" was substracted with 1."<<std::endl;
}

void SomberSmithingStone::add_stone(int amount){
    add_amount(amount);
};

bool SomberSmithingStone::should_destroy(){
    return !greater_equal(1);
};
int Weapon::magic = 0;

Weapon::~Weapon()
{
    print_magic();
    cout << "Weapon destroyed: " << name << endl;
}


Weapon::Weapon(string name) : name(name), level(0)
{
    print_magic();
    cout << "Weapon created: " << name << endl;
}

void Weapon::upgrade()
{
    print_magic();
    cout << "Weapon upgraded: " << name << endl;
    level++;
}

string Weapon::get_name() const
{
    return name;
}

int Weapon::get_level() const
{
    return level;
}

void Weapon::set_magic(int _magic)
{
    magic = _magic;
}
void Weapon::print_magic()
{
    cout << "[magic=" << magic << "] ";
}
int SmithingStone::magic = 0;

SmithingStone::~SmithingStone()
{
    print_magic();
    cout << "Smithing stone " << level << "(" << number << ") was destroyed" << endl;
}

SmithingStone::SmithingStone(int level) : level(level), number(0)
{
    print_magic();
    cout << "Smithing stone " << level << " was created" << endl;
}

void SmithingStone::add_amount(int amount)
{
    print_magic();
    cout << "Smithing stone " << level << " from " << number << " to " << number + amount << endl;
    number += amount;
}

bool SmithingStone::greater_equal(int need) const
{
    return number >= need;
}

int SmithingStone::get_level() const
{
    return level;
}


void SmithingStone::set_magic(int _magic)
{
    magic = _magic;
}
void SmithingStone::print_magic()
{
    cout << "[magic=" << magic << "] ";
}


Tarnished::Tarnished(){

};
/*
所有操作结束后，褪色者会销毁（析构）所有物品，销毁不同武器时，按照获得顺序析构；销毁不同等级锻造石时，按照等级从低到高顺序销毁；
总的销毁顺序为普通锻造石、失色锻造石、普通武器、失色武器。
*/
Tarnished::~Tarnished(){
    //for(int i=1;i<=NormalSmithingStone::index;i++)
    for(int i=1;i<MAX_STONES;i++){
        if(normal_smithing_stones[i]) {delete normal_smithing_stones[i]; normal_smithing_stones[i] = nullptr;}
    }
    for(int i=1;i<MAX_STONES;i++){   
        if(somber_smithing_stones[i]) {delete somber_smithing_stones[i]; somber_smithing_stones[i] = nullptr;}
    }
    for(int i=1;i<=NormalWeapon::index;i++){
        delete normal_weapons[i];
        normal_weapons[i] = nullptr;
    };
    for(int i =1;i<=SomberWeapon::index;i++){
        delete somber_weapons[i];
        somber_weapons[i] = nullptr;
    }
};

void Tarnished::pick_up_stone(int type, int level, int number){
    if(type == 0){
        if(normal_smithing_stones[level] == nullptr){//created 멘트 날려야됨
            normal_smithing_stones[level] = new NormalSmithingStone(level);
            std::cout<<"Normal smithing stone "<<level<<" was created."<<std::endl;
        }
        normal_smithing_stones[level]->add_stone(number);
        std::cout<<"Normal smithing stone "<<level<<" was added with "<<number<<"."<<std::endl;
    } else {//type ==1
        if(somber_smithing_stones[level]==nullptr){
            somber_smithing_stones[level] = new SomberSmithingStone(level);
            std::cout<<"Somber smithing stone "<<level<<"was created."<<std::endl;
        }
        somber_smithing_stones[level]->add_stone(number);
        std::cout<<"Somber smithing stone "<<level<<" was added with "<<number<<"."<<std::endl;
    }
};

void Tarnished::pick_up_weapon(int type, string name){
    if (type ==0){
        normal_weapons[NormalWeapon::index] = new NormalWeapon(name);
        std::cout<<"Normal weapon "<<name<<" was created."<<std::endl;
    } else {
        somber_weapons[SomberWeapon::index] = new SomberWeapon(name);
        std::cout<<"Somber weapon "<<name<<" was created."<<std::endl;
    }
};

void Tarnished::upgrade_weapon(int target, string name){
    int index  = 0;
    for(int i=1;i<=SomberWeapon::index;i++){
        if(somber_weapons[i] == nullptr) continue;
        if(somber_weapons[i]->find_name(name)){
            index = i;
            break;
        }
    }
    if(index!=0){
        int grade = somber_weapons[index]->find_level();
        if(target<=grade) {
            std::cout<<"Stay calm!"<<std::endl; 
            return;
        }
        bool will_upgrade = false;
        for(int i=grade+1;i<=target;i++){
            if(somber_smithing_stones[i]==nullptr){
                std::cout<<"Upgrade failed for lacking somber smithing stone "<<i<<"."<<std::endl;
                return;
            }
            if(i==target) will_upgrade = true;
        }
        if(will_upgrade){
            for(int i=grade+1;i<=target;i++){
                somber_smithing_stones[i]->substract_stone();
                if(somber_smithing_stones[i]->should_destroy()) {
                    delete somber_smithing_stones[i];
                    somber_smithing_stones[i] = nullptr;
                }
                somber_weapons[index]->upgrade_somber_weapon();
            }
            somber_weapons[index]->c_upgrade_somber_weapon(grade);
            return;
        }
    } else {//somber_weapons 에 없을떄(index == 0)
        for(int i=1;i<=NormalWeapon::index;i++){
            if(normal_weapons[i] == nullptr) continue;
            if(normal_weapons[i]->find_name(name)){
                index = i;
                break;
            }
        }
        if(index!=0){
            int grade = normal_weapons[index]->find_level();
            if(target<=grade){
                std::cout<<"Stay calm!"<<std::endl;
                return;
            }
            bool will_upgrade = false;
            int size = target - grade;
            int *upgrade_step = new int[size];
            int count = 0;
            for(int i=grade+1;i<=target;i++){
                int stage = (i-1)/3 + 1;
                int needed = 0;
                int total_needed = 0;
                while((i-1)/3+1 == stage && i<=target){
                    if(i%3 == 1) needed =2;
                    else if (i%3 == 2) needed =4;
                    else needed = 6;
                    upgrade_step[count++] = needed;
                    total_needed+=needed;
                    i++;
                }
                i--;
                if(normal_smithing_stones[stage]==nullptr||!normal_smithing_stones[stage]->enough_stone(total_needed)){
                    std::cout<<"Upgrade failed for lacking somber smithing stone "<<stage<<"."<<std::endl;
                    delete [] upgrade_step;
                    return;
                }
                if(i==target) will_upgrade = true;
            }
            if(will_upgrade){
                for(int i=0;i<size;i++){
                    int k = (grade+i)/3+1;
                    normal_smithing_stones[k]->substract_stone(upgrade_step[i]);
                    if(normal_smithing_stones[k]->should_destroy()){
                        delete normal_smithing_stones[k];
                        normal_smithing_stones[k] = nullptr;
                    }
                    normal_weapons[index]->upgrade_normal_weapon();
                }
                normal_weapons[index]->c_upgrade_normal_weapon(grade);
                delete [] upgrade_step;
                return;
            }
        } else {//무기 존재안함
            std::cout<<"You don't have the right!"<<std::endl;
            return;
        }
    }
};

int main()
{
    Tarnished *you = new Tarnished();
    int n, operation, type, target, level, number;
    int magic;
    string name;
    cin >> n >> magic;
    // set global magic number
    Weapon::set_magic(magic);
    SmithingStone::set_magic(magic);
    // operate
    while (n--)
    {
        cin >> operation;
        if (operation == 0)
        {
            cin >> type >> level >> number;
            you->pick_up_stone(type, level, number);
        }
        else if (operation == 1)
        {
            cin >> type >> name;
            you->pick_up_weapon(type, name);
        }
        else if (operation == 2)
        {
            cin >> target >> name;
            you->upgrade_weapon(target, name);
        }
    }
    delete you;
    return 0;
}

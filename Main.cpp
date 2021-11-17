#include <stdio.h>

/*
���z�֐�
�p�����̃N���X�̊֐������z�֐��ɂ��Ă����ƁA
�p����ŏ��������������邱�Ƃ��ł���B

// ���z�֐��ɂ��Ȃ��ꍇ
class ParentClass
{
public:
    ParentClass() {}
    void Print(){ printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    ChildClass() {}
    void Print(){ printf("Child\n"); }
};
*/
/*
class ParentClass
{
public:
    ParentClass() {}
    void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    void Print() { printf("Child\n"); }
};

int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}
*/
/*
��L�̂悤�ɁA
ParentClass�^�ɓ���Ă���̂ŁA
���RParentClass�̏������Ăяo�����B
���̂��߁APrint�̓��e��Parent�ƂȂ�B
���z�֐��ɂ���Ɠ��������ł��A
�p����̏������s����悤�ɂȂ�B
���̂��߂ɂ́Avirtual�����邱�ƂŎ�������B
*/
/*
class ParentClass
{
public:
    ParentClass() {}
    virtual void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    void Print() { printf("Child\n"); }
};

int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}
*/
/*
��L�����s����ƁA
Print�̌��ʂ��ς���Ă��邱�Ƃ��m�F�ł���Ǝv���܂��B
���̂悤�ɁA�������O�̊֐��ł��邪�A
�p���悲�ƂɈႤ�U�镑���������邱�Ƃ��A
�|�����[�t�B�Y���Ƃ����܂��B
*/

/*
�ȉ��̂悤��CalcAdd�N���X���쐬���p�����A
Calc�������Z���s���悤�ɂ���CalcSub�N���X���쐬���Ă��������B
*/
/*
class CalcAdd
{
public:
    virtual int Calc(int x, int y)
    {
        int ans;
        ans = x + y;
        printf("%d + %d = %d\n", x, y, ans);
        return ans;
    }
};

class CalcSub : public CalcAdd
{
public:
    int Calc(int x, int y)
    {
        int ans;
        ans = x - y;
        printf("%d - %d = %d\n", x, y, ans);
        return ans;
    }
};

int main()
{
    CalcAdd add;
    CalcSub sub;

    add.Calc(10, 5);
    sub.Calc(10, 5);
}
*/

/*
�킴�킴��L�̂悤�ȕϐ��̐錾�̂����͂��Ȃ��A
�Ǝv����������܂��񂪁A
�Ⴆ�Ί֐��ɓn���悤�ȏꍇ�́A
�|�C���^�Ŏ󂯎��̂ŁA
���z�֐��ō���Ă����Ȃ��ƁA
�]�񂾌��ʂ������Ȃ��ꍇ������̂ŁA
�p����ł��ꂼ�ꋓ����ς������ꍇ�́A
���z�֐��ō��悤�ɂ��܂��傤�B
*/
/*
// Object�N���X���p�����āAPlayer,Enemy�����
class Object
{
public:
    Object() {}
    virtual ~Object() { printf("Exec Object Destructor.\n");  }
public:
    virtual void Update() {}
};

class Player : public Object
{
public:
    Player() {}
    ~Player() { printf("Exec Player Destructor.\n"); }
public:
    void Update() { printf("Player Update.\n");  }
};

class Enemy : public Object
{
public:
    Enemy() {}
    ~Enemy() { printf("Exec Enemy Destructor.\n"); }
public:
    void Update() { printf("Enemy Update.\n"); }
};

void DoUpdate(Object * obj)
{
    obj->Update();
}

int main()
{
    Player player;
    Enemy enemy;

    DoUpdate(&player);
    DoUpdate(&enemy);
}
*/
/*
���̂悤�ɉ��z�֐�������Ă���΁A
DoUpdate��Player�N���X���AEnemy�N���X��Update���Ăяo����B
�������Ă��Ȃ������ꍇ�A
DoPlayerUpdate�֐���DoEnemyUpdate�֐������Ȃ���΂Ȃ�Ȃ��Ȃ�܂��B
(������Object�N���X���p���������̂𑝂₵���ꍇ�A
�����Ɗ֐��𑝂₳�Ȃ���΂Ȃ�Ȃ�)
���̂悤�Ɍp�����ŉ��z�֐���p�ӂ��Ă����΁A
�p������n���Ă��p����̏������s�����Ƃ��ł��A
�����̊Ǘ����ƂĂ��ȒP�ɂȂ�܂��B
*/

/*
TIPS:
�Ƃ肠�����f�X�g���N�^�ɂ�virtual�����悤
�p����̃f�X�g���N�^�����s����Ȃ��ꍇ������̂ŁA
�p�����̃f�X�g���N�^�ɂ�virtual�����Ă����܂��傤�B
virtual�����Ă����Čp�������Ȃ������ꍇ�ł��A
��肪�N���邱�Ƃ͂Ȃ��̂ŁA
���S�̂��߂ɂƂ肠����virtual�����Ă����Ă����ł��B
*/
/*
// ChildClass�̃f�X�g���N�^���Ă΂�Ȃ�
class ParentClass
{
public:
    ParentClass() {}
    ~ParentClass() { printf("Exec ParentClass Destructor.\n"); }
    virtual void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    ChildClass() {}
    ~ChildClass() { printf("Exec ChildClass Destructor.\n"); }
    void Print() { printf("Child\n"); }
};

int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}
*/

// �f�X�g���N�^��virtual������ƌĂяo�����B
/*
class ParentClass
{
public:
    ParentClass() {}
    virtual ~ParentClass() { printf("Exec ParentClass Destructor.\n"); }
    virtual void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    ChildClass() {}
    ~ChildClass() { printf("Exec ChildClass Destructor.\n"); }
    void Print() { printf("Child\n"); }
};

int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}
*/


/*
�y���z
�O��쐬����PoliceCar���C�����Ă��������B
�C�����e��Car��SetAcceleration�̏���Ɖ����̒l��(-100,50)��
�ύX����-10�ȉ��A5�ȏオ�ݒ�ł���悤�ɂ��Ă��������B
���̎�SetAcceleration��virtual�����ď������������Ă��������B
*/ 
class Object
{

public:
    virtual void Update(float num)
    {
        x += num;
        printf("x=%f\n", x);
        printf("y=%f\n", y);
        printf("z=%f\n", z);
    };
private:
    int x = 0;
    int y = 0;
    int z = 0;
};
class Vehicle : public Object
{

public:
    virtual void setSpeed(float s)
    {
        speed += accel;
        return speed;
    };
    virtual void Update()
    {
        x += speed;
        printf("%f\n", speed);
    };

    int speed = 10;
    int accel = 1;

private:
    
        
};

class Car : public Vehicle
{
public:
    Car()
    {
        speed = 5;
        accel = 5;
    };
    void Update()
    {
        Vehicle::Update();
    }
private:

};
int main()
{
    Car car;
    for (int i = 0; i < 10; i++)
    {
        car.setSpeed();
        car.Update();
    }
}



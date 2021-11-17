#include <stdio.h>

/*
仮想関数
継承元のクラスの関数を仮想関数にしておくと、
継承先で処理を書き換えることができる。

// 仮想関数にしない場合
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
上記のように、
ParentClass型に入れているので、
当然ParentClassの処理が呼び出される。
そのため、Printの内容はParentとなる。
仮想関数にすると同じ処理でも、
継承先の処理が行われるようになる。
そのためには、virtualをつけることで実現する。
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
上記を実行すると、
Printの結果が変わっていることが確認できると思います。
このように、同じ名前の関数であるが、
継承先ごとに違う振る舞いをさせることを、
ポリモーフィズムといいます。
*/

/*
以下のようなCalcAddクラスを作成を継承し、
Calcを引き算を行うようにしたCalcSubクラスを作成してください。
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
わざわざ上記のような変数の宣言のやり方はやらない、
と思うかもしれませんが、
例えば関数に渡すような場合は、
ポインタで受け取るので、
仮想関数で作っておかないと、
望んだ結果が得られない場合があるので、
継承先でそれぞれ挙動を変えたい場合は、
仮想関数で作るようにしましょう。
*/
/*
// Objectクラスを継承して、Player,Enemyを作る
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
このように仮想関数を作っていれば、
DoUpdateでPlayerクラスも、EnemyクラスもUpdateを呼び出せる。
こうしていなかった場合、
DoPlayerUpdate関数とDoEnemyUpdate関数を作らなければならなくなります。
(もっとObjectクラスを継承したものを増やした場合、
もっと関数を増やさなければならない)
このように継承元で仮想関数を用意しておけば、
継承元を渡しても継承先の処理を行うことができ、
処理の管理がとても簡単になります。
*/

/*
TIPS:
とりあえずデストラクタにはvirtualをつけよう
継承先のデストラクタが実行されない場合があるので、
継承元のデストラクタにはvirtualをつけておきましょう。
virtualをつけておいて継承をしなかった場合でも、
問題が起きることはないので、
安全のためにとりあえずvirtualをつけておいていいです。
*/
/*
// ChildClassのデストラクタが呼ばれない
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

// デストラクタにvirtualをつけると呼び出される。
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
【問題】
前回作成したPoliceCarを修正してください。
修正内容はCarのSetAccelerationの上限と下限の値を(-100,50)に
変更して-10以下、5以上が設定できるようにしてください。
この時SetAccelerationはvirtualをつけて処理を実現してください。
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



## GW1

### Part 1
#### lambda sort:
##### run
compile command: g++ lambda-sort.cc -std=c++17 -o lambda_sort\
output:\
```c++
-9 -6 -4 0 1 2 3 5 7 8 : sort using the default operator<
8 7 5 3 2 1 0 -4 -6 -9 : sort using a standard library compare function object
-9 -6 -4 0 1 2 3 5 7 8 : sort using a custom function object
8 7 5 3 2 1 0 -4 -6 -9 : sort using a lambda expression
0 1 2 3 -4 5 -6 7 8 -9 : sort using a lambda expression
```
##### analyse
- sort 默认的排序比较函数
- 标准库中的比较函数
- 使用结构体中的局部定义的函数
- 使用lambda表达式定义的函数
- 调用abssort，在adssort中定义和使用lambda表达式定义的函数

#### lambda capture (error)
##### Errors in lambda-capture-err.cc
- 对于前面四个函数，其问题都在于Captured by value 的参数不能被赋值,此问题修正：1. 清除lambda函数中对captured by value 变量的赋值操作\
- 前面四个函数放在一起时，产生另一个问题：lambda函数不能重载，因此应该将四个函数分别命名为不同的名称
- 对于第五个函数，使用了mutable关键字时，其前面的形参列表为空时不能省略
##### run lambda-capture.cc
compile: g++ lambda-capture.cc -std=c++17 -o lambda-capture
output: 
```c++
x: 0
y: 42
x: 0
y: 43
x: 0
y: 43
x: 1
y: 44
x: 1
y: 45
x: 2
y: 45
x: 3
y: 45
```

#### lambdal capinit
##### run
compile: g++ lambda-capinit.cc -std=c++17 -o lambda-capinit
output:
```c++
x:6 y:7
```
##### analyse
- Capture: & id [init]     表示用新的id引用捕捉[init]变量，对新id赋值会作用到init中
- Capture: id [init]    表示按值捕捉，init中可以使用表达式，对 id 进行初始化

#### lambda this

### Part 2
#### lambda in Cpp
##### HigherOrder Function
对ppt Fundamentals 的 page7 中的高阶函数例子进行实现：
```c++
    auto f1 = [](int x){
        auto f0 = [](int y){return y + 1;};
        return f0(f0(x));
    };
```
可以看见，f0即为λy, f1即为λx。
##### Reduction Strategies
对ppt Fundamentals 的 page26 中的例子修改为(λx.p)((λy.y)z)进行实现：
```c++
    int p = 4;
    int z = 1;
    auto fy = [](int a)-> int {return a;};
    auto fx = [p](int a){return p;};
    cout << "z = 1, p = 4; f returns: " << fx(fy(z)) << endl; 

```
由上面的例子可见，
实际上c++的执行过程中，会先对调用的函数内部进行规约，求值后带入外侧的函数进行计算，因此c++中lambda表达式的规约策略是Application-order
##### Modify Non-local Variables
实际上Part1中的改错部分已经体现这一特征：
```c++
int main () {
    int x = 0;
    int y = 0;
    cout << "x = 0, y = 0" << endl;
    auto p = [x]() mutable{
        x++;
    };
    p();
    cout << "after p(), x = " << x << endl;
    auto pp = [=]() mutable{
        x++;
    };
    pp();
    cout << "after pp(), x = " << x << endl;
    auto ppp = [&x]() {
        x++;
    };
    ppp();
    cout << "after ppp(), x = " << x << endl;
    auto pppp = [&x, y] () mutable {
        x++;
        y++;
    };
    pppp();
    cout << "after pppp(), x = " << x << ", y = " << y << endl;
    auto ppppp = [&] () {
        x++;
        y++;
    };
    ppppp();
    cout << "after ppppp(), x = " << x << ", y = " << y << endl;
    return 0;
}
```
```c++
// outputs:
x = 0, y = 0
after p(), x = 0
after pp(), x = 0
after ppp(), x = 1
after pppp(), x = 2, y = 0
after ppppp(), x = 3, y = 1
```
由上可见，c++的lambda 表达式中，按值抓取的非局部变量在函数中的改变不会对函数外部产生影响，但是按引用抓取的变量在函数中赋值和改变会作用到原变量。

对于c++ python中lambda表达式和lambda演算的异同点总结如下：

相同点: 
1. λ演算的一个显著特征是函数没有名字，c++与python中的λ表达式属于匿名函数，也不需要名字；
2. 在λ演算中，表示某个变量的符号一般不重要,将同一约束变元进行替换含义不变，这个法则称为α-等价。c++与python中的λ表达式是个匿名函数，自然也支持遵循α-等价法则,可近似于函数的定义阶段的形参设置规则；
3. λ演算另一法则是β-归约，可以把一个数带入到λ项当中。 c++与python中的λ表达式也支持β-归约，相当于给匿名函数的形参赋予实参值；

不同点：  
1. λ演算的另一个特征是只能接受一个变量，如果想接受多个变量需要写成复合函数的形式，也就是第一个函数的输出结果是紧接着第二个函数的输入变量;而c++和python的λ表达式可以接受多种数据类型的多个变量。
2. 目前发现λ演算和python中的λ表达式不能修改非局部变量，而c++的λ表达式可以用引用捕获外部变量修改非局部变量值；
3. λ演算中高阶函数的运算规则和c++中λ表达式表示的高阶函数类似，c++中函数名可以作为返回函数的参数；python由于λ表达式的简洁性，返回值只能是一个表达式，而且若要返回函数，上一层嵌套函数必须要声明该函数为参数。


### Part 3
#### 类型
Type中新增Num类型

Term中新增：
- Num of int 表示整数
- Plus of t * t 表示加法运算
- Times of t * t 表示乘法运算
#### 类型检查
- 为静态语义
- 对于整数的类型检查只需直接返回其类型即可：Term.Num n -> Some Type.Num
- 加法和乘法相似，由于其有两个参数，因此需要对这两个参数分别进行检查，首先检查第一个参数是否为整数类型，如果符合条件再检查第二个参数是否为整数类型，如果符合则返回整数类型，表示这个表达式类型为整数：
```
(*以加法为例*)
  | Term.Plus (a, b) ->
    (match typecheck a with
    | Some Type.Num -> (match typecheck b with
                       | Some Type.Num -> Some Type.Num
                       | _ -> None)
    | _ -> None)
```

#### 求值
- 为动态语义
- 对于整数求值直接返回其本身即可： Term.Num n -> Term.Num n
- 对于加法和乘法的求值，以加法为例，将其两个参数匹配为两个整数，对整数进行加法运算之后返回一个整数:
```
  | Term.Plus (a, b) -> 
    (match (eval a, eval b) with
     | (Term.Num x, Term.Num y) -> Term.Num (x + y)
     | _ -> raise Unreachable)
```

#### 检验
检查整数本身的类型和值：
```
let t4 = Term.Num 3 in 
assert (typecheck t4 = Some Type.Num);
assert (eval t4 = Term.Num 3);
```

检查加法乘法的基本运算以及嵌套：
```
  let t5 = Term.Plus (Term.Num 3, Term.Times (Term.Num 2, Term.Num 5)) in
  assert (typecheck t5 = Some Type.Num);
  assert (eval t5 = Term.Num 13);

  let t6 = Term.Plus (Term.Z, Term.Num 1) in
  assert (typecheck t6 = None)
```

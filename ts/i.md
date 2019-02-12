# ts Documentation

> 你不扔掉中文文档，就永远看不懂英文文档。

这表示enum类型是可以互相转换的，num & str。

```ts
enum Color {Red = 1, Green, Blue}
let colorName: string = Color[2];

console.log(colorName) // 'Green'
```

But variables of type Object only allow you to assign any value to them - you can’t call arbitrary methods on them, even ones that actually exist:

类型断言好比其它语言里的 类型转换(type cast)，但是不进行特殊的数据检查和解构。 它没有运行时的影响，只是在编译阶段起作用。 TypeScript会假设你，程序员，已经进行了必须的检查。

闭包中用的是同一个值的，所以下面可以改变闭包中的值。

```js
function f() {
    var a = 10;
    return function g() {
        var b = a++;
        return b;
    }
}
var g = f();
console.log(g());
console.log(g());
console.log(g());
// 10
// 11
// 12
```

这段代码就有点神奇了，输出10个10，我不奇怪，我奇怪的是居然是陆续输出的，这就证明只有回调函数那里i 都是 10，后面的100 * i还是从0开始的。

```js
for (var i = 0; i < 10; i++) {
    setTimeout(function() { console.log(i); }, 100 * i);
}
```

这里是因为我们已经在city的作用域中拿到了city，所以就算if块结束了，还是能拿到city的值。

```js
function theCityThatAlwaysSleeps() {
    let getCity;
    if (true) {
        let city = "Seattle";
        getCity = function() {
            return city;
        }
    }
    return getCity();
}
console.log(theCityThatAlwaysSleeps())
// Seattle
```

you will lose methods when you spread instances of an object

```js
class C {
  p = 12;
  m() {
  }
}
let c = new C();
let clone = { ...c };
clone.p; // ok
clone.m(); // error!
```

`String.prototype.search()` 返回正则匹配的index，没有返回-1，参数可以不是正则，这时它会被`new RegExp(obj)`包装。

In TypeScript, each member is public by default.

a class declaration creates two things: a type representing instances of the class and a constructor function.

Arrow functions capture the this where the function is created rather than where it is invoked.

泛型接口，泛型类

a class has two sides to its type: the static side and the instance side.

泛型可以继承接口：`function loggingIdentity<T extends Lengthwise（这是一个接口）>(arg: T): void { }`

`Open–closed principle 开放封闭原则： 软件中的对象应该对于扩展是开放的，但是对于修改是封闭的`，你应该尽量去使用接口代替类型别名。

TypeScript共有两种可用的模块解析策略：Node和Classic。

null表示"没有对象"，即该处不应该有值。undefined表示"缺少值"，就是此处应该有一个值，但是还没有定义。js最初只设计了null，没有 undefined ，但由于JavaScript的数据类型分成原始类型（primitive）和合成类型（complex）两大类，所以又设计了undefined。null是一个表示"无"的对象，转为数值时为0；undefined是一个表示"无"的原始值，转为数值时为NaN。

```js
Number(null)
// 0
5 + null
// 5

Number(undefined)
// NaN
5 + undefined
// NaN
```

类装饰器应用于类构造函数，可以用来监视，修改或替换类定义。


没使用extends而是使用implements。 把类当成了接口，仅使用Disposable和Activatable的类型而非其实现。

```js
class SmartObject implements Disposable, Activatable {
```


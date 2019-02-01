# ts Documentation

> 你不扔掉中文文档，就永远看不懂英文文档。

- fundamental a 基本的
- denote v 表示
- arbitrary a 任意的
- respective a 分别的，各自的
- alleviate v 减轻
- elaborate v 详细描述
- cause v 引起
- exacerbate v 使恶化
- frustration n 挫折
- intimate a 亲密的
- precise a 精确的
- dive v 潜水
- distinct a 明显的，清楚的
- accidental a 意外的
- intuition n 直觉
- In effect 实际上
- drastically ad 彻底地
- imply v 意味，暗示
- broad a 广阔的，宽的
- rationale n 基本原理
- other than 除了
- consult v 请教，商议
- majority n 多数
- parenthese n 圆括号
- colon n 冒号


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





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```





```js

```










```ts

```


```js

```

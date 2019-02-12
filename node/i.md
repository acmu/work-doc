# node 深入浅出

js位运算参照java实现，但java是在int型基础上进行的，而js中只有double型数据类型，所以js在位运算的时候，需要把double型转为int型在进行运算，故效率不高。

在编译过程中，node会对js文件进行头尾包装，如下：（书中P19）

```js
(function(exports, require, module, __filename, __dirname) {
    // 模块源码
});
```

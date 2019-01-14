## Overview

- 跨浏览器兼容。
- polyfill 是浏览器端的 shim。
- v0.11.0 会舍弃旧的API。

## API Basics

使它受控，用 EditorState 来显示， Editor core 里实现了onChange。

当你改变选中，或编辑数据时 EditorState 就会改变， 这里保存的是 immutable 的数据


## Rich Styling

Editor core 会帮你管理 EditorState ，当然，因为顶级组件是你自己的，你也可以改变 EditorState

handleKeyCommand 可以监听按键。 RichUtils 可以实现一些样式，如加粗。



## draft-js-image-plugin

有这个库，处理 draft image

```js
/* eslint-disable */
这没有lint
/* eslint-enable */
```

# React 视图更新机制浅析

> 参考《深入react技术栈》第三章 基于React v15.0.2

## 一：setSate异步更新

state 是 React 中重要的概念。React 是通过管理状态来实现对组件的管理。它通过 this.state 来访问 state，通过 this.setState() 方法来更新 state。当this.setState() 被调用的时候，React 会重新调用 render 方法来重新渲染 UI。


- 为什么不用`this.state.val`更新？

首先

## 二：Virtual DOM

## 三：Diff 算法

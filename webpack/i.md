# my webpack

## install

```shell
yarn init -y

yarn add webpack webpack-cli webpack-dev-server html-webpack-plugin --dev

yarn add style-loader css-loader less less-loader --dev

yarn add typescript ts-loader --dev
```

哇，今天总算自己用了一下wp，还不错嘛，就配置了ts + less，目前来说就够了，config贴一下就睡了，明天继续努力~


```js
// webpack.config.js

const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './src/index.ts',
  output: {
    filename: 'bundle.[hash:4].js',
    path: path.resolve('dist')
  },
  mode: 'development',
  plugins: [
    new HtmlWebpackPlugin({
      template: './src/index.html',
      hash: true,
    })
  ],
  module: {
    rules: [
      {
        test: /\.less$/,
        use: ['style-loader', 'css-loader', 'less-loader'],
        exclude: /node_modules/
      },
      {
        test: /\.ts$/,
        use: ['ts-loader'],
        exclude: /node_modules/
      }
    ]
  }
};
```

























```shell

```



```shell

```



```shell

```



```shell

```



```shell

```



```shell

```



```shell

```

```shell

```


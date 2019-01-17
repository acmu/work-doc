# 每天30页

## 第一章

### 1.1
web是建立在http协议上通信的。

### 1.2
SGML 标准通用标记语言

### 1.3
http属于tcp/ip内部的一个子集

tcp/ip 4层：应用层、传输层、网络层、数据链路层。

应用层：ftp、dns、http

传输层：tcp、udp

网络层：处理网络上流动的数据包

链路层：处理连接网络硬件部分：操作系统，硬件，网卡

![](./img/1.png)


### 1.4

负责传输的IP协议

IP网际协议位于网络层

ARP解析地址的协议，根据通信方的IP地址就可以反查出对应的mac地址

确保可靠性的TCP协议

TCP协议把大数据分割成报文段，能够确认最终是否能送达对方

三次握手：1.syn标志 2.syn ack 标志  3.ack标志

dns：域名到IP地址解析

![](./img/3.png)


## 第二章

### 2.2

请求报文由请求方法，请求uri，协议版本，可选的请求首部字母和内容实体构成。

响应报文由协议版本，状态码，解释状态码的原因短语，可选的响应首部字段以及实体主体构成

### 2.3

http是无状态的，因为这样可以处理大量事务，确保协议的可伸缩性。但有了cookie就可以管理状态了。

### 2.5

If-Modified-Since: 时间 -> 返回时间以后更新过的资源，如未更新 状态码是304 not modified

302 暂时重定向

PUT：传输文件

HEAD：获得报文首部

http/1.1 PUT 和 DELETE不带验证机制 所以一般不使用

OPTIONS：询问支持的方法

TRACE：追踪路径

CONNECT：要求用隧道协议连接代理

### 2.7

http协议初版，每进行一次http通信，就要断开一次TCP连接

![](./img/2.png)

故 http/1.1 和部分 http/1.0 想出持久连接：只要任意一端没有明确提出断开连接，则保持TCP连接 -> 建立一次TCP连接后进行多次请求和响应的交互

http/1.1 默认都是持久连接

持久连接使得多数请求可以并发发送

### 2.8

cookie：通过在请求和响应中写入cookie信息来控制客户端的状态

响应报文：Set-Cookie的首部字段信息，通知客户端保存cookie，客户端在请求报文加入Cookie值后发送。服务端拿到cookie后，对比记录，拿到以前的相应状态信息。




## 第三章

### 3.1

http报文：报文首部 报文主体（可选） 两者由空行划分



### 3.4

MIME多用途因特网邮件扩展

1. multipart/form-data
2. multipart/byteranges 状态码206（partial content）


### 3.5

为防止网络中断，重新下载的情况，可以指定范围发送请求，叫范围请求：会用到首部字段Range来指定资源的byte范围。

Range: bytes=5001-10000

Range: bytes=5001-

Range: bytes=-3000， 5000-7000

针对范围请求，响应返回206，多重范围，首部字段Content-Type 有 multipart/byteranges，服务器无法响应范围请求，会返回200和完整数据



### 3.6

内容协商：相同URI出现不同语言

内容协商基准
- Accept
- Accept-Charset
- Accept-Encoding
- Accept-Language
- Content-Language


## 第四章


### 4.2

204 No Content 请求成功，但没有资源返回

206 范围请求

301 永久重定向

302 临时重定向

303 请求的资源存在另一个URI上，且用get方法获取资源

![](./img/4.png)

304 服务端允许请求访问资源，但未满足条件，就会返回304，不包含任何响应主体部分。这个与重定向无关

307 临时重定向，与302类似，不会把post变化成get


400 请求报文存在错误

401 请求需要通过http认证

403 请求资源被服务器拒绝

500 服务器错误

503 服务器超负载，或在进行停机维护




## 第五章

### 5.1

单台虚拟主机可以实现多个域名访问，但是dns解析后ip地址会相同，所以必须要在请求首部指定Host，即主机名或域名的URI



### 5.2

通信数据转发程序：代理、网关、隧道

![](./img/5.png)

网关可以连接数据库，使用sql语句查询数据


## 第六章


通用首部字段： Via: 代理服务器的相关信息

请求首部：If-Match 响应首部：Etag

Cache-Control 能操控缓存的工作机制

Cache-Control: public

Cache-Control: private

Cache-Control: no-cache 防止从缓存中返回过期的资源，若响应首部指定参数值（no-cache=Location），那么浏览器不能使用缓存，否则可以

Cache-Control: no-store 完全不缓存， no-cache 是防止从缓存中返回过期的资源，不要搞混

Cache-Control: s-maxage=1000 （单位：秒） 适用于供多位用户使用的公共缓存服务器

Cache-Control: max-age=1000 （单位：秒）当参数值为0，会将请求转发给源服务器


Cache-Control: max-fresh=60 （单位：秒）过了60秒的资源都无法作为响应返回


Cache-Control: max-stale=3600 （单位：秒）缓存资源，过期也会接收（处于 max-stale 指定的时间内过期）


Cache-Control: only-if-cached 只有在缓存服务器本地缓存了目标资源的情况下才要求返回，接收只要缓存过的数据，如果没有缓存过的，返回504


Cache-Control: must-revalidate 代理会向源服务器再次验证即将返回的响应 缓存目前是否仍然有效。使用这个会忽略max-stale

Cache-Control: no-transform 缓存不能改变实体主体的媒体类型，防止缓存或代理压缩图片等类似操作。


Connection: 不再转发给代理的首部字段名


Connection：close 管理持久连接


Connection：Keep-Alive 兼容http1.0的非持久连接


Date： 表名http报文的时间

Pragme： no-cache 历史遗留

Trailer： 事先说明在报文主体或记录了哪些首部字段

Transfer-Encodin： 传输报文主体时采用的编码方式，仅对分块传输编码有效


Accept: 用户代理能够处理的媒体类型

From: 邮箱

Host: 必须包含的首部字段

只有当If-Match跟ETag匹配一致时，服务器才会接收请求，否则返回412


If-Modiafied-Since: 时间   在此时间后未更新过，返回304 Not Modified，更新过返回数据并有Last-Modified首部字段

If-None-Match 只有ETag中不存在这个的时候，服务器才返回

实体标记（ETag）

If-Range 若跟ETag或更新的日期时间匹配一致，就作为范围请求，否则，返回全部资源

![](./img/6.png)


If-Unmodified-Since: 时间 只有在指定时间之后，没更新的情况下，才处理请求。否则返回402

Max-Forwards: 最多转发次数

![](./img/7.png)

Range: bytes=5001-10000 范围请求，成功返回206，无法处理范围请求，返回200和全部资源

Referer： 请求的URI是从哪个Web页面发起的。正确写法Referrer，但沿用这个错误的。


**响应首部字段**

Accept-Ranges： 能否处理范围请求 bytes 或 none

Age: （秒） 服务器在多久前创建了响应。


ETag: 实体资源用唯一的字符串标识

强Etage（第一个，很细微的变化都会改变） 若ETage（第二个，发生了根本变化，才会改变，有W）

ETag: "usage-1234"

ETag: W/"usage-1234"

Location: 重定向到的地址

Retry-After： 告知客户端多久之后再次发送请求

Server： 服务端信息

Vary： p125














### 4.1






### 4.1



![](./img/4.png)



## 第四章




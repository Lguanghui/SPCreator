# SPCreator

SPCreator 是一个命令行工具，用于创建 Swift Package 并生成工程模板。

## 简介

在 Xcode Project 里，我们创建的文件一般都带有固定格式的 header，比如：

```swift
//
//  MyFile.swift
//  MyModule
//
//  Created by MyName on 2023/3/26.
//  Copyright © 2023 My Company. All rights reserved.
//
```

其中， copyright 是设置了 Organization 才会有。我们也可以设置类的前缀（Class Prefix），这样每次新创建的 Class 都会带有一个固定的前缀。

![img.png](images/project_config.png)

但是在 Swift Package 里面，类前缀、copyright 甚至是文件 header 这些都是无法直接设置的，需要通过一个 IDETemplateMacros.plist 文件设置。

光秃秃的文件 header ⬇️:

```swift
//
//  FileName.swift
//  
//
//  Created by Your Name on 2022/2/20.
//
```

而 IDETemplateMacros.plist 文件不会在创建 package 时自动被创建，需要咱们手动创建并填写信息，步骤较繁琐。

SPCreator 就是为了简化这些步骤而诞生的。它不仅能创建 swift package，还能自动在合适位置创建 IDETemplateMacros.plist 文件，并填写、格式化好里面的内容。

## 安装方法

### Homebrew

Tap:

```shell
brew tap Lguanghui/tap
```

Core:

```shell
brew install spcreator
```

## 使用方法

| 命令行参数               | 说明                                    |
|---------------------|---------------------------------------|
| --help 或者 -H        | 帮助文档                                  |
| --name 或者 -N        | 指定要创建的 package 名字                     |
| --classPrefix 或者 -P | 指定在 package 中新建 class 时的前缀            |
| --authorName 或者 -A  | 指定作者名字或者组织名字，用于文件 header 中的 copyright |

举例：

```shell
spcreator -N TestPackage -P GH -A Guanghui Liang
```
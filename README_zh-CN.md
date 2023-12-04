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

其中 copyright 是设置了 Organization 才会有。我们也可以设置类的前缀（Class Prefix），这样每次新创建的 Class 都会带有一个固定的前缀。

![img.png](images/project_config.png)

但是在 Swift Package 里面，类前缀、copyright 甚至是文件 header 这些都是无法直接设置的，需要通过一个 IDETemplateMacros.plist 文件设置。

而 IDETemplateMacros.plist 文件不会在创建 package 时自动被创建，需要咱们手动创建并填写信息，步骤较繁琐。

SPCreator 工具不仅能创建 swift package，还能自动在合适位置创建 IDETemplateMacros.plist 文件，并填写、格式化好里面的内容。

## 使用方法



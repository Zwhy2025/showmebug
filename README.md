# showmebug C++ 基础脚手架 (macOS)

这个脚手架用于 LeetCode/面试刷题，提供：
- CMake 构建
- VS Code 调试与任务
- Git 分支切题工作流
- 默认题目模板

## 目录结构
- `src/solution.hpp` 题解实现
- `src/main.cpp` 本地运行入口
- `templates/src/` 默认模板
- `scripts/lc` 一键切题脚本
- `.vscode/` VS Code 配置

## 快速开始
1. 配置并编译
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

2. 运行
```bash
./build/showmebug
```

或者使用脚本（编译并运行）：
```bash
./run.sh
```

## 推荐工作流
日常只记两条命令：

```bash
./scripts/lc new palindrome-linked-list "回文链表"
./scripts/lc done
```

你平时这样用：

```bash
./scripts/lc new palindrome-linked-list "回文链表"
./run.sh
./scripts/lc done
```

说明：
- `new` 会创建题目分支；如果这题已经做过，会直接切回那条分支
- `done` 会自动执行 `git add src` 和 `git commit`
- `done` 默认提交信息是 `update <slug>`，也可以自己写：`./scripts/lc done "solve palindrome-linked-list"`
- 想回看旧题时，重复执行 `./scripts/lc new <slug>` 就行

可选命令：

```bash
./scripts/lc list
./scripts/lc template
```

## VS Code 使用
- 任务：
  - `cmake: configure`
  - `cmake: build`
  - `run: showmebug`
- 调试：选择 `Debug showmebug` 直接 F5

## 说明
- 默认 C++ 标准为 C++17
- 生成 `compile_commands.json` 供智能感知

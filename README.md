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
保持 `src/` 只放“当前正在做的一题”，每道题对应一个 git 分支。

如果这个目录还没初始化 git：
```bash
git init -b main
git add .
git commit -m "init showmebug"
chmod +x ./scripts/lc
```

开始一题：
```bash
./scripts/lc new palindrome-linked-list "回文链表"
```

做题时：
```bash
./run.sh
git add src
git commit -m "solve palindrome-linked-list"
```

以后想继续做这题：
```bash
git switch codex/lc-palindrome-linked-list
```

查看已有题目分支：
```bash
./scripts/lc list
```

切回模板分支：
```bash
./scripts/lc template
```

说明：
- `./scripts/lc new ...` 会从 `main` 创建题目分支，并把 `src/` 重置成模板
- 如果题目分支已经存在，脚本会直接切过去
- 切分支前要求工作区干净，避免题解被覆盖

## VS Code 使用
- 任务：
  - `cmake: configure`
  - `cmake: build`
  - `run: showmebug`
- 调试：选择 `Debug showmebug` 直接 F5

## 说明
- 默认 C++ 标准为 C++17
- 生成 `compile_commands.json` 供智能感知

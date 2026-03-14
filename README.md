# showmebug C++ 基础脚手架 (macOS)

这个脚手架用于 LeetCode/面试刷题，提供：
- CMake 构建
- VS Code 调试与任务
- 本地运行入口
- 当前分支提交脚本

## 目录结构
- `src/solution.hpp` 题解实现
- `src/main.cpp` 本地测试入口
- `scripts/commit.sh` 提交当前分支代码
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
日常只需要这两条命令：

```bash
./run.sh
./scripts/commit.sh
```

说明：
- `run.sh` 会配置、编译并运行当前题目的本地测试入口
- `commit.sh` 会只提交 `src/` 下的代码
- 提交信息格式是 `当前分支名/当前时间`
- 例如：`codex/hot100-118-杨辉三角/20260314-183000`

## VS Code 使用
- 任务：
  - `cmake: configure`
  - `cmake: build`
  - `run: showmebug`
- 调试：选择 `Debug showmebug` 直接 F5

## 说明
- 默认 C++ 标准为 C++17
- 生成 `compile_commands.json` 供智能感知

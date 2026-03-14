# showmebug

这个仓库用于 LeetCode Hot 100 二刷和面试速练。

## 当前结构
- `src/solution.hpp`：题解实现
- `src/main.cpp`：本地伪造输入和校验入口
- `run.sh`：配置、编译并运行当前题目
- `commit.sh`：提交当前分支的 `src/` 改动
- `.vscode/`：VS Code 配置和 C++ 代码片段

## 分支规则
- `main`：基线分支
- `codex/hot100/类型/难度/题号-题目名`：每道题一个分支
- 例如：`codex/hot100/链表/简单/141-环形链表`

切换题目示例：

```bash
git switch 'codex/hot100/双指针/简单/283-移动零'
```

## 日常用法
平时基本只用这两条：

```bash
./run.sh
./commit.sh
```

说明：
- `run.sh` 会生成 `build/`，然后编译并运行当前题目的本地测试
- `commit.sh` 只提交 `src/`
- 提交信息格式：`当前分支名/当前时间`
- 例如：`codex/hot100/链表/简单/141-环形链表/20260314-203000`

## 本地做题方式
- 在 `src/main.cpp` 里补伪造输入和 `expected`
- 在 `src/solution.hpp` 里写解法
- 本地跑通后执行 `./commit.sh`

## VS Code
- 任务：`cmake: configure`、`cmake: build`、`run: showmebug`
- 调试：选择 `Debug showmebug` 后按 `F5`
- 代码片段：见 `.vscode/cpp.code-snippets`

## 说明
- C++ 标准为 C++17
- 会生成 `compile_commands.json` 供智能感知使用

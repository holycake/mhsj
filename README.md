[![en](https://img.shields.io/badge/lang-en-blue.svg)](./README_EN.md)
[![zh](https://img.shields.io/badge/lang-zh-green.svg)](./README.md)

# 魔幻世纪（MHSJ）

基于 FluffOS 2019 驱动的类西游记题材 文字MUD 游戏服务端 （UTF-8 编码版本）。

> ⚠️ 本项目由原 GB2312 编码的魔幻世纪 lib 移植而来，经过大量手动修复和调试，现已基本稳定运行。

---

## 多语言说明
- [中文版 README](README.md)
- [English README](README_EN.md)

---
## 📦 启动方式

- 驱动程序版本：`fluffos 20240714-4a59909c-4a6fafb5`
- 建议从 [FluffOS 官方仓库](https://github.com/fluffos/fluffos) 下载最新版构建
- 启动方法：

```bash
driver.exe config.ini
````

---

## 🖥️ 客户端建议

* 推荐使用 [Mudlet 4.19.1](https://www.mudlet.org/) 进行连接体验

---

## ⚠️ 已知问题

游戏自动保存过程中有可能出现提示：

   ```
   save_svalue: unknown type 64 ignored.
   ```

   触发源未知，原因是自动保存的对象上存在着非法格式的数据，但 **不会影响游戏运行**。

---

## ✅ 已完成的兼容与功能修复调整

### 系统与架构

* 修复大量因从 MudOS 迁移至 FluffOS 2019 后的兼容性问题
* 支持 UTF-8 编码，适配现代编辑器与终端显示

### 游戏逻辑调整

1. **初始年龄修改**

   * 玩家创建后年龄从 8 岁开始
   * 修改文件：

     * `/adm/daemons/logind.c`：设置初始年龄
     * `/obj/user.c`：调整 `update_age()` 的基准值

2. **技能学习机制调整**

   * `/cmds/std/learn` 与 `study` 命令中，技能等级超过 **武学经验 / 550** 时将无法继续学习

3. **地图与交互改动**

   * **新增场景：明代南京城**
     参考古籍地图复原，增添沉浸感

   * **长安客栈的小二交互增强**

     * 玩家需先提供可装水容器
     * 再支付 `1 silver` 可灌满桂花酒

4. **人物描述系统**

   * 丰富的人物体型与容貌设定
   * 支持细粒度等级描述（依性别、体型、容貌值组合）

5. **月宫与古墓调整**

   * **采莲、砍树、爬树奖励机制优化**

     * 采莲：可将基础及特殊武功提升至 **200 级**
     * 砍/爬树：可将武功提升至 **150 级**
   * **痴梦拜师失败后可重试机制**

     * 若失败后掉入湖底，则可再次拜师
   * **轩辕古墓人头与模仿木人修行流程调整**

     * 更符合逻辑，提升可玩性

---

## 🧩 附加说明

* 本项目为学习交流用途，推荐在私服部署使用
* 本项目发布只是为了分享mud lib代码。后续不会进行任何更新、维护。

---

## 🔗 相关资源

* FluffOS 驱动：[https://github.com/fluffos/fluffos](https://github.com/fluffos/fluffos)
* Mudlet 客户端：[https://www.mudlet.org](https://www.mudlet.org)

---

> 版本维护人：HolyCake
> 更新时间：2025 年 7 月
